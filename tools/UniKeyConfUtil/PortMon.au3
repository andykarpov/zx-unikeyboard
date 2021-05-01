#include 'CommMG.au3'
#include <GUIConstants.au3>
#include <GuiComboBox.au3>

HotKeySet("{ESC}", "alldone")

$result = ''
Const $settitle = "COM port setting", $maintitle = "COM port monitor"
Dim $FlowType[3] = ["Hardware (RTS, CTS)", "XOn/XOff", "NONE"]
Dim $ParityType[5] = ["NONE", "ODD", "EVEN", "MARK", "SPACE"]

$Form1 = GUICreate($maintitle, 252, 350, 100, 100, BitOR($WS_MAXIMIZEBOX, $WS_MINIMIZEBOX, $WS_SIZEBOX, $WS_THICKFRAME, $WS_SYSMENU, $WS_CAPTION, $WS_OVERLAPPEDWINDOW, $WS_TILEDWINDOW, $WS_POPUP, $WS_POPUPWINDOW, $WS_GROUP, $WS_TABSTOP, $WS_BORDER, $WS_CLIPSIBLINGS))
$Edit1 = GUICtrlCreateEdit("", 16, 20, 220, 290, BitOR($ES_AUTOVSCROLL, $ES_AUTOHSCROLL, $ES_READONLY, $ES_WANTRETURN, $WS_HSCROLL, $WS_VSCROLL))
$BtnSetPort = GUICtrlCreateButton("Set COM-port", 16, 312, 220, 30, $BS_FLAT)
GUICtrlSetColor(-1, 0x008000)
GUISetState(@SW_SHOW)


While setport(0) = -1
    If MsgBox(4, 'Port configuration is not finished !', 'Do you want to quit the program?') = 6 Then Exit
WEnd


Events()
_CommSetXonXoffProperties(11, 13, 100, 100)
GUICtrlSetState($Edit1, $GUI_FOCUS)

While 1

    $instr = _CommGetString()

    If ($instr <> '')  Then
        GUICtrlSetData($Edit1, $instr, 1)
    Else
        Sleep(20)
    EndIf

WEnd

Alldone()



Func Events()
    Opt("GUIOnEventMode", 1)
    GUISetOnEvent($GUI_EVENT_CLOSE, "justgo")
    GUICtrlSetOnEvent($BtnSetPort, "SetPortEvent")
EndFunc   ;==>Events


Func SetPortEvent()
    setport();needed because a parameter is optional for setport so we can't use "setport" for the event
EndFunc   ;==>SetPortEvent




Func justgo()
    Exit
EndFunc   ;==>justgo


Func AllDone()
    _Commcloseport(true)
    Exit               
EndFunc   ;==>AllDone


;Function SetPort($mode=1)
;Creates a form for the port settings
;Parameter $mode sets the return value depending on whether the port was set
;Returns  0 if $mode <> 1
;          -1 If` the port not set and $mode is 1
Func SetPort($mode = 1);if $mode = 1 then returns -1 if settings not made
    Local $sportSetError
    Opt("GUIOnEventMode", 0);keep events for $Form1, use GuiGetMsg for $Form2

    $Form2 = GUICreate("COMMG Example - set Port", 422, 279, 329, 268, BitOR($WS_MINIMIZEBOX, $WS_CAPTION, $WS_POPUP, $WS_GROUP, $WS_BORDER, $WS_CLIPSIBLINGS, $DS_MODALFRAME), BitOR($WS_EX_TOPMOST, $WS_EX_WINDOWEDGE))
    $Group1 = GUICtrlCreateGroup("Set COM Port", 18, 8, 288, 252)
    $CmboPortsAvailable = GUICtrlCreateCombo("", 127, 28, 145, 25, BitOR($GUI_SS_DEFAULT_COMBO, $CBS_SORT))
    $CmBoBaud = GUICtrlCreateCombo("115200", 127, 66, 145, 25, BitOR($CBS_DROPDOWN, $CBS_AUTOHSCROLL, $CBS_SORT, $WS_VSCROLL))
    GUICtrlSetData(-1, "  9600| 19200| 38400| 57600")
    $CmBoStop = GUICtrlCreateCombo("1", 127, 141, 145, 25)
    GUICtrlSetData(-1, "2|1.5")
    $CmBoParity = GUICtrlCreateCombo("", 127, 178, 145, 25)
    GUICtrlSetData(-1, "NONE|ODD|EVEN|MARK|SPACE")
    GUICtrlSetData(-1, "none")
    $Label2 = GUICtrlCreateLabel("Port", 94, 32, 23, 17)
    $Label3 = GUICtrlCreateLabel("Baud", 89, 70, 28, 17)
    $Label4 = GUICtrlCreateLabel("Stop bits", 75, 145, 50, 17)
    $Label5 = GUICtrlCreateLabel("Parity", 88, 182, 29, 17)
    $CmboDataBits = GUICtrlCreateCombo("8", 127, 103, 145, 25)
    GUICtrlSetData(-1, "7")
    $Label7 = GUICtrlCreateLabel("No. of Data Bits", 41, 107, 79, 17)
    $ComboFlow = GUICtrlCreateCombo("NONE", 127, 216, 145, 25)
    GUICtrlSetData(-1, "Hardware (RTS, CTS)|XOn/XOff")
    $Label1 = GUICtrlCreateLabel("Flow control", 59, 220, 58, 17)
    GUICtrlCreateGroup("", -99, -99, 1, 1)
    $BtnApply = GUICtrlCreateButton("Apply", 315, 95, 75, 35, $BS_FLAT)
    GUICtrlSetFont(-1, 12, 400, 0, "MS Sans Serif")
    $BtnCancel = GUICtrlCreateButton("Cancel", 316, 147, 76, 35, $BS_FLAT)
    GUICtrlSetFont(-1, 12, 400, 0, "MS Sans Serif")
    GUISetState(@SW_SHOW)


    WinSetTitle($Form2, "", $settitle);ensure a change to Koda design doesn't stop script working
    $mainxy = WinGetPos($Form1)
    WinMove($Form2, "", $mainxy[0] + 20, $mainxy[1] + 20)

    $portlist = _CommListPorts(0);find the available COM ports and write them into the ports combo
    If @error = 1 Then
        MsgBox(0, 'trouble getting portlist', 'Program will terminate!')
        Exit
    EndIf

    For $pl = 1 To $portlist[0]
        $portnum = StringReplace($portlist[$pl], "COM", '')
        if StringLen($portnum) = 1 then $portnum = $portnum & ' '
        $portlist[$pl] = 'COM' & $portnum
        GUICtrlSetData($CmboPortsAvailable, $portlist[$pl]);_CommListPorts())
    Next
    GUICtrlSetData($CmboPortsAvailable, $portlist[1]);show the first port found

    _GUICtrlComboBox_SetMinVisible($CmBoBaud, 10);restrict the length of the drop-down list


    $retval = 0

    While 1
        $msg = GUIGetMsg()
        If $msg = $BtnCancel Then
            If Not $mode Then $retval = -1
            ExitLoop
        EndIf


        If $msg = $BtnApply Then

            $comboflowsel = GUICtrlRead($ComboFlow)
            For $n = 0 To 2
                If $comboflowsel = $FlowType[$n] Then
                    $setflow = $n
                    ConsoleWrite("flow = " & $setflow & @CRLF)
                    ExitLoop
                EndIf

            Next
            $setport = StringReplace(GUICtrlRead($CmboPortsAvailable), 'COM', '')


            $ParitySel = GUICtrlRead($CmBoParity)
            For $n = 0 To 4
                If $ParitySel = $ParityType[$n] Then
                    $SetParity = $n
                    ExitLoop
                EndIf
            Next

            $setStop = StringReplace(GUICtrlRead($CmBoStop), '.', '');replace 1.5 with 15 if needed

            $resOpen = _CommSetPort($setport, $sportSetError, GUICtrlRead(StringReplace($CmBoBaud, ' ','')), GUICtrlRead($CmboDataBits), $SetParity, $setStop, $setflow)

            if $resOpen = 0 then
                Exit
            EndIf

            Sleep(1000)
            ;next
            $mode = 1;
            ExitLoop
        EndIf

        ;stop user switching back to $Form1
        If WinActive($maintitle) Then
            If WinActivate($settitle) = 0 Then MsgBox(0, 'not found', $settitle)
        EndIf


    WEnd
    GUIDelete($Form2)
    WinActivate($maintitle)
    Events()
    Return $retval


EndFunc   ;==>SetPort
