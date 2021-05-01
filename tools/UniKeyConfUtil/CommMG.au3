#include-once
#AutoIt3Wrapper_OutFile_X64=N
;Opt("mustdeclarevars", 1) ;testing only
#cs
    UDF for commg.dll
#ce

Global $mgdebug = false
#cs
    Version 2.1.1 Added missing declarations which caused problems in scripts using Opt("MustDeclareVars",1) - thanks to Hannes
    Version 2.1 Thanks to jps1x2 for the read/send bte array incentive and testing.
    Version 2.0.2 beta changed readbytearray so returns no of bytes read
    Version 2.0.1 beta
    added _CommSendByteArray and _CommReadByteArray
    Version 2.0 - added _CommSwitch. Can now use up to 4 ports.
    Version 2.2 - add rts, dtr to setport
    added option for flow control = NONE to _CommSetPort
    version 2.3 use commg.dll v2.3 which allows any baud rate up to 256000.
    Version 2.4 added setTimeouts, SetXonXoffProperties
    Version 2.5 add _CommsetTimeouts, _CommSetXonXoffProperties
    Version 2.6 added _CommSetRTS, _CommSetDTR
    change switch so up to 50 com ports can be open at a time
    Version 2.7 added _CommSetDllPath
    Version 2.8 17th April 2010
    add GetLineStates for CTS, DSR, Ring Indicator and DCD
    Corrected return of functions _CommSetRTS and _CommSetDTR to be -1 on error
    Version 2.81 add sleep(20) in CommGetLine to reduce CPU usage. Thanks to jimg.
    Version 2.82 Correct error in _ComSetPort which could prevent _CommSetDllPath working.
    Version 2.83 add function _CommSetBufferSizes
    added ComGetPortNames around these versions but not sure when.
    Version 2.84 modify ReadByte to allow for error, probable cause is a timeout triggered by values set in _CommSetTimeouts
    Removed CloseDll in _CommClosePort so one port can be closed and others still used.
    Version 2.85 Fix error in _CommClosePort
	version 2.86 change return from GetByte so that if result of call to dll is a string longer than 2 chara assume it is an error message.
	Version 2.87 corrected _CommReadByte which would not return characters with ACSII codes > 99. Now returns 0 to 255 inclusive.
	             Added sleep(20)Cto end of While loop in _CommGetLine which greatly reduced CPU usage.
				 Thanks to adrianhudson for bring these problems to my attention.
    Version 2.88 Made the sleep added the _CommGetLine only happen if no character received so that reading
	             is not slower.
	Version 2.89 Corect typo in V2.88
	Version 2.90 Change _CommClosePort. Requires the use of Commg.dll version 2.79 or later. Thanks to tfabris for telling me about the error.
#ce
Const $sUDFVersion = 'CommMG.au3 V2.90'
#cs
    AutoIt Version: 3.2.3++
    Language:       English

    Description:    Functions for serial comms using commg2_4.dll or later
    Works with COM ports, USB to Serial converters, Serial to RS424 etc

    Functions available:
    _CommGetVersion
    _CommSetDllPath
    _CommListPorts
    _ComGetPortNames
    _CommSetPort
    _CommPortConnection
    _CommClearOutputBuffer
    _CommClearInputBuffer
    _CommGetInputcount
    _CommGetOutputcount
    _CommSendString
    _CommGetString
    _CommGetLine
    _CommReadByte
    _CommReadChar
    _CommSendByte
    _CommSendBreak; not tested!!!!!!!!!!
    _CommCloseport
    _CommSwitch
    _CommSendByteArray
    _CommReadByteArray
    _CommSetTimeouts
    _CommSetXonXoffProperties
    _CommSetRTS
    _CommSetDTR
    _CommGetLineStates
    _CommSetBufferSizes

    Author: Martin Gibson
#ce
#include-once

Global $fPortOpen = False
Global $hDll
Global $DLLNAME = 'commg.dll'


;===============================================================================
;
; Function Name:  _CommSetDllPath($sFullPath)
; Description:    Sets full path to th edll so that it can be in any location.
;
; Parameters:     $sFullPath -  Full path to the commg.dll e.g.  _CommSetDllPath("C:\COMMS\commg.dll")
; Returns;  on success 1
;           on error -1 if full path does not exist
;===============================================================================
Func _CommSetDllPath($sFullPath)
    If Not FileExists($sFullPath) Then Return -1

    $DLLNAME = $sFullPath
    Return 1

EndFunc   ;==>_CommSetDllPath


;===============================================================================
;
; Function Name:  _CommListPorts($iReturnType=1)
; Description:    Gets the list of available ports seperated by '|' or as an array
;
; Parameters:     $iReturnType -  integer:if $iReturnType = 1 then return a string with the list of COM ports seperated by '|'
;                                         if $iReturnType <> 1 then return an array of strings, with element [0] holding the number of COM ports
; Returns;  on success - a string eg 'COM1|COM8', or array eg ['2','COM1','COM2']
;           on failure - an empty string and @error set to 1 if dll could not list any ports
;                                            @error set to 2 id dll not open and couldn't be opened

;===============================================================================
Func _CommListPorts($iReturnType = 1)
    Local $vDllAns, $lpres
    If Not $fPortOpen Then
		ConsoleWrite($DLLNAME & @LF)
        $hDll = DllOpen($DLLNAME)
        If $hDll = -1 Then
            SetError(2)
            ;$sErr = 'Failed to open commg2_2.dll'
            Return 0;failed
        EndIf
        $fPortOpen = True
    EndIf
    If $fPortOpen Then
        $vDllAns = DllCall($hDll, 'str', 'ListPorts')
        If @error = 1 Then
            SetError(1)
            Return ''
        Else

            ;mgdebugCW($vDllAns[0] & @CRLF)
            If $iReturnType = 1 Then
                Return $vDllAns[0]
            Else
                Return StringSplit($vDllAns[0], '|')
            EndIf


        EndIf
    Else
        SetError(1)
        Return ''
    EndIf


EndFunc   ;==>_CommListPorts


;===============================================================================
;
; Function Name:  _Commgetversion($iType = 1)
; Description:    Gets the version of the dll if $iType = 1
;                   Or the version of this UDF if $iType = 2
; Parameters:     $iType - integer: = 1 to reurn the commg2_2.dll version
;                                  = 2 to return the UDF version
; Returns;  on success - a string eg 'V1.3'
;           on failure - an empty string and @error set to 1

;===============================================================================


Func _CommGetVersion($iType = 1)
    Local $vDllAns
    If $iType = 2 Then Return $sUDFVersion

    If $fPortOpen Then
        $vDllAns = DllCall($hDll, 'str', 'Version')

        If @error = 1 Then
            SetError(1)
            mgdebugCW('error in get version' & @CRLF)
            Return ''
        Else
            ;mgdebugCW('length of version is ' & stringlen($vDllAns[0]) & @CRLF)
            Return $vDllAns[0]

        EndIf
    Else
        $vDllAns = DllCall($DLLNAME, 'str', 'Version')
        If @error = 1 Then
            SetError(1)
            mgdebugCW('error in get version' & @CRLF)
            Return ''
        Else
            ;mgdebugCW('length of version is ' & stringlen($vDllAns[0]) & @CRLF)
            Return $vDllAns[0]
        EndIf
    EndIf


EndFunc   ;==>_CommGetVersion

;===============================================================================
;
; Function Name:  _CommSwitch($channel)
;switches functions to operate on channel 1, 2, 3 to 50
;returns  on succes the channel switched to ie 1 or 2
;         on failure -1
;Remarks  on start up of script channel 1 is selected, so if you only need one COM port
;         you don't need to use _CommSwitch
;         each channel needs to be set up with _CommSetPort
;         The same COM port cannot be used on more than one channel.
;When switch is used the first time on a channel number that port will be inactive
; and the port name will be '' (an empty string) until it is set with _CommSetport.
;The exception is that on creation channel 1 is always created and used as the
;port so switch is not needed unless more than one port is used.
;         The channel number is not related to the COM port number, so channel 1 can
;         be set to use COM2 and channel 4 can be set to use COM1 or any available port.
;Any channel number in the range 1 - 50 can be used, so it is possible to use
; the same channel number as the port number, ie switch(21) switches to COM21
;======================================================================================
Func _CommSwitch($channel)
    Local $vDllAns
    #cs remove section after fixing? comclose in dll
        If Not $fPortOpen Then
        SetError(1)
        Return 0
        EndIf
    #ce
    If $channel > 50 Then Return -1
    $vDllAns = DllCall($hDll, 'int', 'switch', 'int', $channel)

    If @error <> 0 Then
        SetError(1)
        Return -1
    Else
        mgdebugCW("COM port selected now is " & _CommPortConnection() & @CRLF)
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSwitch



;===========================================================================================================
;
; Function Name:    _CommSetport($iPort,ByRef $sErr,$iBaud=9600,$iBits=8,$ipar=0,$iStop=1,$iFlow=0,$RTSMode = 0,$DTRMode = 0)
;   Description:    Initialises the port and sets the parameters
;    Parameters:    $iPort - integer = the port or COM number to set. Allowed values are 1 or higher.
;                         NB WIndows refers To COM10 Or higher`as \\.\com10 but only use the number 10, 11 etc
;                  $sErr - string: the string to hold an error message if func fails.
;                  $iBaud - integer: the baud rate required. With commg.dll v2.3 and later any value allowed up to 256000.
;                           With v2.4 any value??
;                          If using commg.dll before V2.3 then only allowed values are one of
;                         50, 75, 110, 150, 600, 1200, 1800, 2000, 2400, 3600, 4800, 7200, 9600, 10400,
;                         14400, 15625, 19200, 28800, 38400, 56000, 57600, 115200, 128000, 256000
;                  $iBits - integer:  number of bits in code to be transmitted
;                  $iParity - integer: 0=None,1=Odd,2=Even,3=Mark,4=Space
;                  $iStop - integer: number of stop bits, 1=1 stop bit 2 = 2 stop bits, 15 = 1.5 stop bits
;                  $iFlow - integer: 0 sets hardware flow control,
;                                    1 sets XON XOFF control,
;                                    2 sets NONE i.e. no flow control.

; 					$RTSMode 0= turns on the RTS line when the device is opened and leaves it on
;         					 1= RTS handshaking. The driver raises the RTS line when the "type-ahead" (input) buffer is less than one-half full and lowers the RTS line when the buffer is more than three-quarters full.
;         					 2 = the RTS line will be high if bytes are available for transmission. After all buffered bytes have been sent, the RTS line will be low.
;         					 3 = turns off the RTS line when the port is opened and leaves it off
;					$DTRMode  0 = turns on the DTR line when the port is opened and leaves it on
;					          1 = enables DTR handshaking
;  					          2 = disables the DTR line when the device is opened and leaves it disabled.
; Returns;  on success - returns 1 and sets $sErr to ''
;           on failure - returns 0 and with the error message in $sErr, and sets @error as follows
;                           @error             meaning error with
;                             1               dll call failed
;                             2               dll was not open and could not be opened
;                            -1               $iBaud
;                            -2               $iStop
;                            -4               $iBits
;                            -8               $iPort = 0 not allowed
;                           -16               $iPort not found
;                           -32               $iPort access denied (in use?)
;                           -64               unknown error
;Remarks     You cannot set the same COM port on more than one channel
;===========================================================================================================

Func _CommSetPort($iPort, ByRef $sErr, $iBaud = 9600, $iBits = 8, $iPar = 0, $iStop = 1, $iFlow = 0, $RTSMode = 0, $DTRMode = 0)
    Local $vDllAns
    $sErr = ''

    mgdebugCW("$fPortOpen = " & $fPortOpen & @CRLF)
    If Not $fPortOpen Then
        $hDll = DllOpen($DLLNAME)
        If $hDll = -1 Then
            SetError(2)
            $sErr = 'Failed to open commg.dll'
            Return 0;failed
        EndIf
        $fPortOpen = True
    EndIf
    mgdebugCW('port = ' & $iPort & ', baud = ' & $iBaud & ', bits = ' & $iBits & ', par = ' & $iPar & ', stop = ' & $iStop & ', flow = ' & $iFlow & @CRLF)

    $vDllAns = DllCall($hDll, 'int', 'SetPort', 'int', $iPort, 'int', $iBaud, 'int', $iBits, 'int', $iPar, 'int', $iStop, 'int', $iFlow, 'int', $RTSMode, 'int', $DTRMode)
    If @error <> 0 Then
        $sErr = 'dll SetPort call failed'
        SetError(1)
        Return 0
    EndIf

    If $vDllAns[0] < 0 Then
        SetError($vDllAns[0])
        Switch $vDllAns[0]
            Case -1
                $sErr = 'undefined baud rate'
            Case -2
                $sErr = 'undefined stop bit number'
            Case -4
                $sErr = 'undefined data size'
            Case -8
                $sErr = 'port 0 not allowed'
            Case -16
                $sErr = 'port does not exist'
            Case -32
                $sErr = 'access denied, maybe port already in use'
            Case -64
                $sErr = 'unknown error accessing port'
        EndSwitch
        Return 0
    Else
        Return 1
    EndIf

EndFunc   ;==>_CommSetPort


;===================================================================================
;
; Function Name:  _CommPortConnection()
; Description:    Gets the port connected to the selected channel - see _CommSwitch
; Parameters:     None
; Returns;  on success - a string eg 'COM5'
;           on failure - an empty string and @error set to the rerror set by DllCall
; Remarks - Can be used to verify the port is connected

;====================================================================================

Func _CommPortConnection()
    Local $vDllAns

    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf


    $vDllAns = DllCall($hDll, 'str', 'Connection');reply is port eg COM8

    If @error <> 0 Then
        SetError(@error)
        Return ''
    Else
        Return $vDllAns[0]
    EndIf


EndFunc   ;==>_CommPortConnection



;=====================================================================================
;
; Function Name:  _CommSendString($sMGString,$iWaitComplete=0)
; Description:    Sends a string to the connected port on the currently selected channel
; Parameters:     $sMGString: the string to send sent without any extra CR or LF added.
;                 $iWaitComplete- integer:0 = do not wait till string sent
;                                        1 = wait till sent
; Returns:  always 1
;           on success-  @error set to 0
;           on failure - @error set to the error returned from DllCall
;======================================================================================

Func _CommSendString($sMGString, $iWaitComplete = 0)
    ;sends $sMGString on the currently open port
    ;returns 1 if ok, returns 0 if port not open/active
    Local $vDllAns
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf
    If $sMGString = '' Then Return
    mgdebugCW("pre sendstring " & @CRLF)
    $vDllAns = DllCall($hDll, 'int', 'SendString', 'str', $sMGString, 'int', $iWaitComplete)
    If @error <> 0 Then
        mgdebugCW("past sendstring(1)" & @CRLF)
        SetError(@error)
        Return ''
    Else
        mgdebugCW("past sendstring(2)" & @CRLF)
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSendString



;================================================================================
;
; Function Name:  _CommGetstring()
; Description:    Get whatever characters are available received by the port for the selected channel
; Parameters:     none
; Returns:  on success the string and @error is 0
;           if input buffer empty then empty string returned
;           on failure an empty string and @error set to the error set by DllCall
; Notes: Use _CommGetLine to get a whole line treminated by @CR or a defined character.
;=================================================================================

Func _Commgetstring()
    ;get a string NB could be part of a line depending on what is in buffer
    Local $vDllAns

    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    ;$sStr1 = ''
    ;$vDllAns = DllCall($hDll,'str','GetByte')
    $vDllAns = DllCall($hDll, 'str', 'GetString')

    If @error <> 0 Then
        SetError(1)
        mgdebugCW('error in _commgetstring' & @CRLF)
        Return ''
    EndIf
    Return $vDllAns[0]
EndFunc   ;==>_Commgetstring


;====================================================================================
;
; Function Name:  _CommGetLine($EndChar = @CR,$maxlen = 10000, $maxtime = 10000)
; Description:    Get a string ending in $EndChar
; Parameters:     $EndChar the character to indicate the end of the string to return.
;                     The $EndChar character is included in the return string.
;                 $MaxLen - integer: the maximum length of a string before
;                                     returning even if $linEnd not received
;                                    If $maxlen is 0 then there is no max number of characters
;                  $maxtime - integer:the maximum time in mS to wait for the $EndChar before
;                                     returning even if $linEnd not received.
;                                    If $maxtime is 0 then there is no max time to wait
;
; Returns:  on success the string and @error is 0
;           If $maxlen characters received without the $lineEnd character, then these
;            characters are returned and @error is set To -1.
;           If $maxtime passes without receiving the $lineEnd character, then the characters
;            received so far are returned and @error is set To -2.
;           on failure returns any characters received and sets @error to 1
;======================================================================================
Func _CommGetLine($sEndChar = @CR, $maxlen = 0, $maxtime = 0)
    Local $vDllAns, $sLineRet, $sStr1, $waited, $sNextChar, $iSaveErr

    If Not $fPortOpen Then
        SetError(1)
        mgdebugCW("Port not open" & @CRLF)
        Return 0
    EndIf

    $sStr1 = ''
    $waited = TimerInit()

    While 1;stringinstr($sStr1,$EndChar) = 0
        If TimerDiff($waited) > $maxtime And $maxtime > 0 Then
            SetError(-2)
            mgdebugCW("Time Too long" & @CRLF)
            Return $sStr1
        EndIf


        If StringLen($sStr1) >= $maxlen And $maxlen > 0 Then
            SetError(-1)
            mgdebugCW("String to long" & @CRLF)
            Return $sStr1
        EndIf
        ;$ic =  _CommGetInputCount()


        $sNextChar = _CommReadChar()
        $iSaveErr = @error
        If $iSaveErr <> 0 Then
            mgdebugCW("$iSaveErr = " & $iSaveErr & @CRLF)
        EndIf

        If $iSaveErr = 0 And $sNextChar <> '' Then

            $sStr1 = $sStr1 & $sNextChar
            mgdebugCW($sStr1 & @CRLF)
            If $sNextChar = $sEndChar Then ExitLoop

        EndIf

        If $iSaveErr <> 0 And $iSaveErr <> 3 Then
            SetError(1)
            mgdebugCW("Errors" & @CRLF)
            Return $sStr1
        EndIf

      if $snextchar = '' then sleep(20)
    WEnd



    Return $sStr1
EndFunc   ;==>_CommGetLine





;============================================================================
;
; Function Name:  _CommGetInputCount()
; Description:    Get the number of characters available to be read from the port.
; Parameters:     none
; Returns:  on success a string conversion of the number of characters.(eg '0', '26')
;           on failure returns an empty string and sets @error to 1
;===============================================================================

Func _CommGetInputCount()
    Local $vDllAns
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

mgdebugCW("to dll getipcount");
    $vDllAns = DllCall($hDll, 'str', 'GetInputCount')

    If @error <> 0 Then
        SetError(1)
        Return 0
    Else
        Return $vDllAns[0]

    EndIf


EndFunc   ;==>_CommGetInputCount



;============================================================================
;
; Function Name:  _CommGetOutputCount()
; Description:    Get the number of characters waiting to be sent from the port.
; Parameters:     none
; Returns:  on success a string conversion of the number of characters.(eg '0', '26')
;           on failure returns an empty string and sets @error to 1
;===============================================================================
Func _CommGetOutputCount()
    Local $vDllAns
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf


    $vDllAns = DllCall($hDll, 'str', 'GetOutputCount')

    If @error <> 0 Then
        SetError(1)
        Return ''
    Else
        Return $vDllAns[0]
    EndIf


EndFunc   ;==>_CommGetOutputCount


;================================================================================================
;
; Function Name:   _CommReadByte($wait = 0)

; Description:    Reads the byte as a string
; Parameters:     $wait:integer if 0 then if no data to read then return -1 and set @error to 1
;                               if <> 0 then does not return until a byte has been read
; Returns:  on success a string conversion of the value of the byte read.(eg '0', '20')
;           on failure
;                      if port not open or wait = 0 and no data to read sets @error to 1 and returns an empty string
;                      if DllCall failed returns empty string and sets @error to 2
;                      if $wait is 0 and no data to read returns an empty string and sets @error to 1 if
;                      if $wait is not 0 returns a string containing imnformation on the $error if known
;                                        and sets @error to 3.
;
;
;;NB could hang if nothing rec'd when wait is <> 0
;==================================================================================================

Func _CommReadByte($wait = 0)
    Local $iCount, $vDllAns
    If Not $fPortOpen Then
        SetError(1)
        Return ''
    EndIf

mgdebugCW("599 before get input count");
    If Not $wait Then
        $iCount = _CommGetInputCount()
        If @error = 1 Or $iCount = 0 Then
            SetError(1)
            Return ''
        EndIf
    EndIf
mgdebugCW("to dll getbyte");
    $vDllAns = DllCall($hDll, 'str', 'GetByte');GetByte returns the ascii code in string format for the next char

    If @error <> 0 Then
        mgdebugCW("readbyte error = " & @error & @CRLF)
        SetError(2)
        Return ''
    EndIf

    If StringLen($vDllAns[0]) > 3 or $vDllAns[0] > 255 Then ;Execute($vDllAns[0]) > 999 Then ;
       ; mgdebugCW
		mgdebugCW("getbyte call returned >" & $vDllAns[0] & @CRLF)
        Return SetError(3, 0, $vDllAns[0])
    EndIf
;consolewrite("getbyte call returned >" & $vDllAns[0] & @CRLF)
    Return $vDllAns[0]

EndFunc   ;==>_CommReadByte

;============================================================================
;
; Function Name:   _CommReadChar($wait = 0)

; Description:    Reads the next Character as a string
; Parameters:     $wait:integer if 0 then if no data to read then return -1 and set @error to 1
;                               if <> 0 then does not return until a byte has been read
; Returns:  on success a string of 1 character
;           on failure returns empty string and sets @error to 1
;
;
;;NB could hang if nothing rec'd when wait is <> 0
;===============================================================================

Func _CommReadChar($wait = 0)
    Local $sChar, $iErr
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf
mgdebugCW("will read byte");
    $sChar = _CommReadByte($wait)

    $iErr = @error
    ;

    If $iErr > 2 Then
        mgdebugCW("$iErr = " & $iErr & @CR)
        SetError(1)
        Return ''
    EndIf
	mgdebugCW(Chr(Execute($sChar)) & @CRLF)
    If $iErr == 0 Then Return Chr(Execute($sChar))
EndFunc   ;==>_CommReadChar


;============================================================================
; Function Name:   SendByte($byte,$iWaitComplete=0)

; Description:    Sends the byte value of $byte. $byte must be in range 0 to 255
; Parameters:     $byte the byte to send.
;                 $iWaitComplete - integer: if 0 then functions returns without
;                                  waiting for byte to be sent
;                                  If <> 0 then waits till byte sent.
; Returns:  on success returns 1
;           on failure returns -1 and sets @error to 1
;
;;NB could hang if byte cannot be sent and $iWaitComplete <> 0
;===============================================================================
Func _CommSendByte($byte, $iWaitComplete = 0)
    Local $vDllAns
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    $vDllAns = DllCall($hDll, 'int', 'SendByte', 'int', $byte, 'int', $iWaitComplete)
    If @error <> 0 Then
        SetError(1)
        Return -1
    Else
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSendByte


;===============================================================================
; Function Name:   _CommSendByteArray($pAddr,$iNum,$iWait)

; Description:    Sends the bytes from address $pAddress
; Parameters:     $iNum the number of bytes to send.
;                 $iWaitComplete - integer: if 0 then functions returns without
;                                  waiting for bytes to be sent
;                                 if <> 0 then waits until all bytes are sent.
; Returns:  on success returns 1
;           on failure returns -1 and sets @error to 1
;
;;NB could hang if byte cannot be sent and $iWaitComplete <> 0
;    could lose data if you send more bytes than the size of the outbuffer.
;    the output buffer size is 2048
;===============================================================================
Func _CommSendByteArray($pAddr, $iNum, $iWait)
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    Local $vDllAns = DllCall($hDll, 'int', 'SendByteArray', 'ptr', $pAddr, 'int', $iNum, 'int', $iWait)
    If @error <> 0 Or $vDllAns[0] = -1 Then
        SetError(1)
        Return -1
    Else
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSendByteArray



;====================================================================================
; Function Name:   _CommReadByteArray($pAddr,$iNum,$iWait)
;
; Description:    Reads bytes and writes them to memory starting at address $pAddress
; Parameters:     $iNum the number of bytes to read.
;                 $iWaitComplete - integer: if 0 then the functions returns
;                                   with the available bytes up to $iNum.
;                                  if 1 then waits until the $iNum bytes received.
; Returns:  on success returns the Number of bytes read.
;           on failure returns -1 and sets @error to 1
;
;;NB could hang if bytes are not received and $iWaitComplete <> 0
;    the input buffer size is 4096
;====================================================================================
Func _CommReadByteArray($pAddr, $iNum, $iWait)
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    Local $vDllAns = DllCall($hDll, 'int', 'ReadByteArray', 'ptr', $pAddr, 'int', $iNum, 'int', $iWait)
    If @error <> 0 Or $vDllAns[0] = -1 Then
        SetError(1)
        Return -1
    Else
        Return $vDllAns[0]
    EndIf



EndFunc   ;==>_CommReadByteArray




;===============================================================================
; Function Name:   ClearOutputBuffer()

; Description:    Clears any characters in the out put queue5
; Parameters:     none
; Returns:  on success returns 1
;           on failure returns -1 and sets @error to 1
;
;===============================================================================
Func _CommClearOutputBuffer()
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    Local $vDllAns = DllCall($hDll, 'int', 'ClearOutputBuffer')

EndFunc   ;==>_CommClearOutputBuffer

Func _CommClearInputBuffer()
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    Local $vDllAns = DllCall($hDll, 'int', 'ClearInputBuffer')
    If @error <> 0 Then
        Return -1
    Else
        Return 1
    EndIf

EndFunc   ;==>_CommClearInputBuffer


;===============================================================================
; Function Name:   ClosePort()@@@@@@@@@to be improved or replaced. Should have parameter for channel to close and new fn for closedown
; Parameters
;            TODO ?? $fAll if set to true or non zero then

; Description:    closes currently selected port
; Remarks:
;
; Parameters:     none

; Returns:  no return value
;===============================================================================
Func _CommClosePort($fAll = False)
    Local $closeAll
    ;mgdebugCW("Closing port" & @CRLF)
    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    If $fAll Then
        $closeAll = 1
    Else
        $closeAll = 0
    EndIf


    _CommClearOutputBuffer()
    _CommClearInputBuffer()

        DllCall($hDll, 'int', 'CloseDown', 'int', $closeAll);close all ports

        If @error <> 0 Then ConsoleWrite("Error closing dll" & @CRLF)
        $fPortOpen = False
		if $fAll then DllClose($hDll)

EndFunc   ;==>_CommClosePort



;================================================================================================
; Function Name:   SendBreak($iDowTime,$iUpTime)
; NB Simulates the break signal used by some equipment to indicate the start of a sequence
;     Not tested so might Not work. Any feedback welcome - PM martin on Autoit forum

; Description:    sets the TX line low for $iDowTime, then sets it high for $iUpTime

; Parameters:     $iDowTime - integer: the number of ms to hold the TX line down
;                 $iUpTime   - integer: the number of ms to hold the line up for before returning
;                  if $iDowTime or $iUpTime is zero then does nothing and returns
; Returns:  on success returns 1
;           on failure returns 0 and sets @error to
;                                          = 1 if one of params is zero
;                                          = 2 1 unable to use the DLL file,
;                                          = 3 unknown "return type" from dll
;                                          = 4 "function" not found in the DLL file.

; Notes : Not tested!
;================================================================================================
Func _CommSendBreak($iDowTime, $iUpTime);requirescommg2_2.dllv2.0 or later
    Local $vDllAns
    If $iDowTime = 0 Or $iUpTime = 0 Then
        SetError(1)
        Return 0
    EndIf

    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf
    $vDllAns = DllCall($hDll, 'int', 'SendBreak', 'int', $iDowTime, 'int', $iUpTime)
    If @error <> 0 Then
        SetError(@error + 1)
        Return 0
    Else
        ;mgdebugCW('done setbreak' & @CRLF)
        Return 1;success
    EndIf

EndFunc   ;==>_CommSendBreak


;=========== _CommSetBufferSizes ========================================================================================================
; Description: Sets the buffer sizes for the current channel
;Parameters - $InputLen    - the maximum number of bytes which can be received and waiting to be read
;           - $OutPutLen   - the number of bytes which can be qued waiting to be transmitted;
;Return 1 on success
;       0 on failure
;=============================================================================================================================================================
Func _CommSetBufferSizes($InPutLen, $OututLen = 2048)
    Local $vDllAns = DllCall($hDll, 'int', 'SetBufSizes', 'int', $InPutLen, 'int', $OututLen)
    If @error <> 0 Then
        SetError(@error + 1)
        Return 0
    Else
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSetBufferSizes

;=========== _CommSetTimeouts ========================================================================================================
; Description: Sets the timeouts for the current channel
;Parameters - ReadInt    - maximum time allowed to elapse between the arrival of two characters
;           - ReadMult   - multiplier used to calculate the total timeout period for read operations.
;                          For each read operation, this value is multiplied by the requested number of bytes to be read.
;           - ReadConst  - constant used to calculate the total timeout period for read operations.
;                          For each read operation, this value is added to the product of the ReadMultiplier member and the requested number of bytes.
;           - WriteMult  - multiplier used to calculate the total timeout period for write operations.
;                          For each write operation, this value is multiplied by the number of bytes to be written.
;           - WriteConst - constant used to calculate the total time-out period for write operations.
;                          For each write operation, this value is added to the product of the WriteMultiplier member and the number of bytes to be written.
; if a parameter is set to 0 it means that timeout will not be used. All values are at zero when a port is opened.
; Return 1 on success
;        0 on failure
;=============================================================================================================================================================
Func _CommSetTimeouts($ReadInt = 0, $ReadMult = 0, $ReadConst = 0, $WriteMult = 0, $WriteConst = 0)
    Local $vDllAns

    If Not $fPortOpen Then
        SetError(1)
        Return 0
    EndIf

    $vDllAns = DllCall($hDll, 'int', 'SetTimeouts', 'int', $ReadInt, 'int', $ReadMult, 'int', $ReadConst, 'int', $WriteMult, 'int', $WriteConst)
    If @error <> 0 Then
        SetError(@error + 1)
        Return 0
    Else
        Return $vDllAns[0]
    EndIf
EndFunc   ;==>_CommSetTimeouts


;====================== SetXonXoffProperties =======================================================================
; Description: Set the values used for the XON and XOFF characters, and when these charactyers are to be transmitted
; Parameters - $XonChar - the ASCII code for the character to be sent to indicate the port is ready to receive
;            - $XoffChar - the ASCII code for the character to be sent to stop receiving
;            - $XonStart - when the number of characters in the input buffer falls below this value the XonChar will be sent
;            - $XoffStop - when the number of bytes free in the input buffer falls below this value the XoffChar will be sent
;When a port is opened the values are as the defaults for the function.
;Return - on success 1
;       - on error   0 if error making dllcall and @error set to 1
;                   -1  illegal XonChar value
;                   -2  illegal XoffChar value
;
Func _CommSetXonXoffProperties($XonChar = 0x11, $XoffChar = 0x13, $XonStart = 0, $XoffStop = 0)
    Local $vDllAns



    If $XonChar > 255 Or $XonChar < 0 Then Return -1
    If $XoffChar > 255 Or $XoffChar < 0 Then Return -2


    $vDllAns = DllCall($hDll, 'int', 'SetXonXoffProperties', 'byte', $XonChar, 'byte', $XoffChar, 'int', $XonStart, 'int', $XoffStop)
    If @error <> 0 Then
        SetError(@error + 1)
        Return 0
    Else
        Return $vDllAns[0]
    EndIf

EndFunc   ;==>_CommSetXonXoffProperties

Func mgdebugCW($sDB)
    If Not $mgdebug Then Return
    ConsoleWrite($sDB)

EndFunc   ;==>mgdebugCW



;===================================================================================
;
; Function Name:  _CommSetRTS()
; Description:    Sets or restets the RTS signal for to the selected channel - see _CommSwitch
; Parameters:     $iSet = 1 to set 0 to reset
; Returns;  1 on success
;           on failure -1 and @error set to 1
; Notes     Only works if flow control is set to NONE or XON/XOFF. Ie not for hardware handshaking.
;====================================================================================

Func _CommSetRTS($iSet)
    Local $vDllAns

    If Not $fPortOpen Then
        SetError(1)
        Return -1
    EndIf


    $vDllAns = DllCall($hDll, 'int', 'SetRTS', 'int', $iSet)

    If @error <> 0 Then
        SetError(1)
        Return -1
    Else
        Return 1
    EndIf


EndFunc   ;==>_CommSetRTS


;===================================================================================
;
; Function Name:  _CommSetDTR()
; Description:    Sets or restets the DTR signal for to the selected channel - see _CommSwitch
; Parameters:     $iSet = 1 to set 0 to reset
; Returns;  1 on success
;           on failure -1 and @error set to 1
; Notes     Only works if flow control is set to NONE or XON/XOFF. Ie not for hardware handshaking.
;====================================================================================

Func _CommSetDTR($iSet)
    Local $vDllAns

    If Not $fPortOpen Then
        SetError(1)
        Return -1
    EndIf


    $vDllAns = DllCall($hDll, 'int', 'SetDTR', 'int', $iSet)

    If @error <> 0 Then
        SetError(1)
        Return -1
    Else
        Return 1
    EndIf


EndFunc   ;==>_CommSetDTR

;===================================================================================
;
; Function Name:  _CommGetLIneStates()
; Description:    Gets the states of 4 signals
; Parameters:     none
; Returns;   on success
;               returns an array with 4 elements giving the state of the lines CTS, DSR, Ring Indicator and DCD
;               in that order. Value True = ON, value False = OFF
;           on failure
;            returns -1 and @error set to 1
;====================================================================================
Func _CommGetLineStates()
    Local $vDllAns
    Local $iL, $aStates[4]

    If Not $fPortOpen Then
        SetError(1)
        Return -1
    EndIf


    $vDllAns = DllCall($hDll, 'int', 'GetLineStates')

    If @error <> 0 Then
        SetError(1)
        Return -1
    EndIf
    mgdebugCW($vDllAns[0] & @CRLF)
    For $iL = 0 To 3
        $aStates[$iL] = BitAND($vDllAns[0], 2 ^ $iL) <> 0
    Next
    Return $aStates

EndFunc   ;==>_CommGetLineStates


; =====================================================================================================================
; Name........................: _ComGetPortNames
; Description ................: Lists all com ports or a single com port and the names to a 2D array
; Syntax......................: _GetComPorts($sComPort = 0)
; Parameters .................: $sComPort - Either 0 or "" for all ports or a number for a particular port, eg 12 or a string "COM12"
; Return on success ..........:  an array (size depends on $sComPort)
; Return on Failure ..........: an empty string "" and sets @error to
;                                  -1 incorrect parameter
;                                  1 no COM Ports found
;                                  2 specified COM port not found.
; Author .....................: funkey, 2010, Nov 29th
; Modified....................: by martin and renamed from  _GetComPorts to _ComGetPortNames, 14th December 2010
; Remarks ....................:
; Related ....................:
; Link to original function...: http://www.autoitscript.com/forum/topic/122663-getcomports/page__view__findpost__p__851620
; Example ....................: Yes see below
;
; ========================================================================================================================


Func _ComGetPortNames($sComPort = "")

    Local $objWMIService, $colItems, $stempName, $aTemp, $sRet, $iCount

    If IsInt($sComPort) Then
        If $sComPort = 0 Then
            $sComPort = ""
        Else
            $sComPort = "COM" & $sComPort
        EndIf
    EndIf


    If $sComPort <> "" And Not StringIsInt(StringReplace($sComPort, "COM", "")) Then Return SetError(-1, 0, "")

    $objWMIService = ObjGet("winmgmts:\\localhost\root\CIMV2")
    $colItems = $objWMIService.ExecQuery("SELECT * FROM Win32_PnPEntity WHERE Name LIKE '%(COM%" & StringReplace($sComPort, "COM", "") & ")'", "WQL", 48)

    For $objItem In $colItems
        $sRet &= $objItem.Name & @CR
    Next

    If $sRet = "" Then Return SetError(1, 0, "")

    If $sComPort <> "" And Not StringInStr($sRet, "(" & $sComPort & ")") Then Return SetError(2, 0, "")


    $aTemp = StringSplit($sRet, @CR, 2)
    Dim $aRet[UBound($aTemp) - 1][2]

    $iCount = 0
    For $i = 0 To UBound($aTemp) - 2
        $stempName = StringTrimLeft($aTemp[$i], StringInStr($aTemp[$i], "(", 0, -1) - 1);StringTrimRight(, 1)

        If $sComPort = "" Or $stempName = "(" & $sComPort & ")" Then
            $aRet[$i][0] = StringTrimRight(StringTrimLeft($stempName, StringInStr($stempName, "(", 0, -1)), 1)
            $aRet[$i][1] = StringLeft($aTemp[$i], StringInStr($aTemp[$i], "(", 0, -1) - 2)
            $iCount += 1
        EndIf
    Next

    ReDim $aRet[$iCount][2]
    Return $aRet
EndFunc   ;==>_ComGetPortNames
;=======================================================================================================================


#cs =============_ComGetPortNames example start===============================
    #include <array.au3>

    Local $aComPort = _ComGetPortNames()
    _ArrayDisplay($aComPort)
    Local $sComPort = _ComGetPortNames("COM1")
    If @error Then
    MsgBox(16, "Error " & @error, "No matching COM port found.")
    Else
    ConsoleWrite($sComPort & @CRLF)
    EndIf
#ce =============_GetComPorts example end===============================
Opt("MustDeclareVars", 0)