//
//  CINSipCore.h
//  CINSipApp
//
//  Created by wushengjun on 16/2/1.
//  Copyright © 2016年 BJCINCC. All rights reserved.
//

#import "SipDefines.h"

//////////////////////
//// NYC 1.2
//////////////////

@interface SipPhoneCtrl : NSObject

#pragma mark - SIP attributes
/**
 SIP Server IP,it also can be domain string
 */
-(NSString*)GetServer;
-(void)SetServer:(NSString*)sValue;

/**
 SIP Server domain,it also can be IP address. Usually the same as Sip Server
 */
-(NSString*)GetDomain;
-(void)SetDomain:(NSString*)sValue;

/**
 SIP Server port
 */
-(int)GetServerPort;
-(void)SetServerPort:(int)nValue;

/**
 Backup SIP Server IP,it also can be backup domain string.
 Currently only used for UDP Transport Protocol
 */
-(NSString*)GetBackServer;
-(void)SetBackServer:(NSString*)sValue;

/**
 Backup SIP Server domain,it also can be IP address. Usually the same as Sip Serve.
 Currently only used for UDP Transport Protocol
 */
-(NSString*)GetBackDomain;
-(void)SetBackDomain:(NSString*)sValue;

/**
 Backup SIP Server port
 */
-(int)GetBackServerPort;
-(void)SetBackServerPort:(int)nValue;


/**
 Set Stun Server for check net useable,if  callback for Initial is not null
 */
-(NSString*)GetStunServer;
-(void)SetStunServer:(NSString*)sValue;

/**
 Password for SIP Server,In some cases, a third party will do Call Auth,then it could be set to @""
 */
-(NSString*)GetPassWord;
-(void)SetPassWord:(NSString*)sValue;

/**
 Phone number,in the SIP Call,it show as calling number
 */
-(NSString*)GetNumber;
-(void)SetNumber:(NSString*)sValue;

/**
 Name for Authing the SIP Call,it usually the same as number
 */
-(NSString*)GetAuthName;
-(void)SetAuthName:(NSString*)sValue;

/**
 Authentication type,0、no Auth;1、DEGIST(default)
 */
-(int)GetAuthType;
-(void)SetAuthType:(int)nValue;

/**
 Default Audio codec ,ENUM TYPE： codec,0、ulaw;8、alaw;102、ilbc;120、opus
 It only works when the meida type set to RTP or WebRTC
 */
-(int)GetDefaultCodec;
-(void)SetDefaultCodec:(int)sValue;


/**
 All support codecs,it is a codec set string,such as '0|8|102|120'
 */
-(NSString*)GetSurpportCodecs;
-(void)SetSurpportCodecs:(NSString*)sValue;

/**
 The attribute is used only in called mode.The prerequisite is to register first.
 If set autoAnswer to true,when a SIP Call incoming,the SDK will answer Server automatically
 */
-(int)GetAutoAnswer;
-(void)SetAutoAnswer:(int)nValue;

/**
 When registering, add a message header for special projects, such as adding a message header format: "Token: 123213213213213"
 */
-(NSString*)GetServiceKey;
-(void)SetServiceKey:(NSString*)sValue;

/**
 String[] :All codecs supported by SIP phone only support get AllCodecs, currently supporting:
 "Ulaw;0", "Alaw;8", "ILbc;102", "Opus;120"
 */
-(NSArray*)GetAllCodecs;

/**
 Business primary key, used for special businesses, provided by the platform
 Temporarily meaningless
 */
-(NSString*)GetRouteKey;
-(void)SetRouteKey:(NSString*)sValue;

/**
 Temporarily meaningless
 */
-(void)SetAppKey:(NSString*)sValue;

/**
 Protocol type carrying SIP message transmission,ENUM Type
 */
-(emTransferMode)GetTransMode;
-(void)SetTransMode:(emTransferMode)mode;

/**
 Media types for audio and video calls,ENUM Type
 */
-(emMediaType)GetMeidaType;
-(void)SetMeidaType:(emMediaType)mediaType;

/**
 SIP message encryption method Type.0、 no Encrypt;1、Encrypt
 Temporarily not use
 */
-(int)GetSipEncryptType;
-(void)SetSipEncryptType:(int)nValue;

/**
 Heartbeat interval for SIP Connect
 */
-(int)GetHeartBeatInterval;
-(void)SetHeartBeatInterval:(int)nValue;

/**
 Heartbeat sending message type,ENUM Type:
 0:\r\n  1:option
 */
-(int)GetHeartBeatType;
-(void)SetHeartBeatType:(int)nValue;

/**
 Set whether the current call supports video or not
 It only works when the meida type set to RTP or WebRTC
 */
-(void)SetSurpportVedio:(bool)bValue;
-(bool)GetSurpportVedio;

/**
 The route path when connecting with Server. It is a Business attributes
 */
-(NSString*)GetXPath;
-(void)SetXPath:(NSString*)sValue;

/**
 Set whether to directly do SIP registration after initialization is completed
 */
-(bool)GetAutoRegister;
-(void)SetAutoRegister:(bool)bValue;


/**
 Automatic Gain Control,It only works when the meida type set to RTP
 */
-(void) SetAgcEnable:(Boolean) enable;
- (Boolean) GetAgcEnable;
/**
 Noise suppression,It only works when the meida type set to RTP
 */
- (void) SetNsEnable:(Boolean) enable;
- (Boolean) GetNsEnable;
/**
 Auto echo cancellation,It only works when the meida type set to RTP
 */
- (void) SetEcEnable:(Boolean) enable;
- (Boolean) GetEcEnable;

/**
 Call parametric statistics
 It only works when the meida type set to RTP or WebRTC
 */
- (void) SetCallStatics:(Boolean) enable;
- (Boolean) GetCallStatics;

/**
 Set video rendering mode,ENUM Type
 It only works when the meida type set to  WebRTC
 */
-(emVideoMode)GetVideoMode;
-(void)SetVideoMode:(emVideoMode)videoMode;

/**
 Set video encoding resolution,ENUM Type
 It only works when the meida type set to  WebRTC
 */
-(emVideoSize)GetVideoSize;
-(void)SetVideoSize:(emVideoSize)videoSize;

/**
 Set the save path for log upload
 */
-(void)SetLogPath:(NSString*)sValue;

/**
 The Negotiation Mode of WebRTC with SIP Server,ENUM Type
 It only works when the meida type set to  WebRTC
 */
-(void)SetWebRtcCallMode:(emWebrtcCallMode)mode;

/**
 The transmission protocol type used for uploading logs,ENUM Type
 */
-(void)SetLogUploadProtocol:(emLogUploadProtocol) uploadProtocol;

/**
 Identification settings for reconnection methods,ENUM Type
 */
-(void)SetReconnectType:(emReconnectType) reconnectType;

/**
 Set the unique business identifier of the SDK. For uploading logs and so on.
 */
-(void)SetSdkId:(NSString *) sdkId;

/**
 Set detect networkquality during call or not. default is NO
 */
-(void)SetNetworkQualityDetect:(BOOL) detect;

/**
 Set detect mediaQuality during call or not.default is NO
 */
-(void)SetMediaQualityDetect:(BOOL) detect;

/**
 Set whether to play local ringtones while loading the bundle file
 */
-(void)SetSoundPlay:(BOOL) isPlay;


#pragma mark GM Encryption
/**
 The name of the CA certificate
 When using TransferMode_GM,this attribute will take effect
 */
-(NSString*)GetCaFileName;
-(void)SetCaFileName:(NSString*)sValue;

/**
 The name of the Certificate
 When using TransferMode_GM,this attribute will take effect
 */
-(NSString*)GetCertificateFileName;
-(void)SetCertificateFileName:(NSString*)sValue;

/**
 The private key of the Certificate
 When using TransferMode_GM,this attribute will take effect
 */
-(NSString*)GetPrivateKeyFileName;
-(void)SetPrivateKeyFileName:(NSString*)sValue;


#pragma mark - Method

/**
 Set logging level
 @param flags 0: No log;1: Core log;2: SIP Protocol log;3: All logs
 */
-(void) SetSipTraceFlag:(int)flags;

/**
 Set whether logs are recorded in files or not
 @param flag
 0: Do not write files, report through the OnDebugMessage event.TraceFlag is 0, logs are not reported
 1: Write a file without reporting, you can upload it through UploadLogFile
 */
-(void) SetSipFileLogFlag:(int)flag;

/**
 Set server information for automaticlly uploading logs
 @param sServer log server ip or domain
 @param nPort log server port
 */
-(void) SetLogServer:(NSString *)sServer Port:(int)nPort;

/**
 Obtain the version number of the current SIP SDK
 */
-(NSString *) GetVersion;


/**
 Obtain the default User-Agent value for call server
 */
-(NSString *) GetDefaultUserAgent;

/**
 Initialize SIP control Objects
 @param initcb Initialization Result block
 */
-(int) Initial:(OneIntParamCallBack)initcb;

/**
 Deconstructing SIPcontrol  Objects
 */
-(int) UnInitial;

/**
 Registe to SIP Server
 */
-(int) Register;

/**
 UnRegiste from SIP Server
 */
-(int) UnRegister;

/**
 Make call to others
 @param strNum the number you want to call
 @param extraHeader Customized extension protocol headers have been added during outbound calls to facilitate business expansion. Multiple protocol headers are separated by '|||' in the following format:
 “AAAA:899889|||BBBB:34534534”
 */
-(int) DoCall:(NSString*)strNum extraHeader:(NSString*)extra;

/**
 Do IM Connect with Server (Temporarily meaningless)
 */
-(int) DoIMCall:(NSString*)strNum content:(NSString*)content extraHeader:(NSString*)extra;

/**
 Answer a call
 */
-(int) Answer;

/**
 Hang up a call
 */
-(int) Disconnect;

/**
 Refuse to answer calls
 It only works in wake-up mode
 */
-(int) Reject:(NSString*)destNum;

/**
 Sending SIP Message msg during a call
 */
-(int) SendMessage:(NSString*)msg;

/**
 Sending SIP Info msg during a call
 @param conType The format of sending messages needs to be agreed with the server. For example: text/plain
 @param msg Text type messages cannot contain Chinese
 */
-(int) SendInfo:(NSString*)conType Msg:(NSString*)msg;

/**
 Set whether to enable face detection during calls
 It only works when the meida type set to  WebRTC
 */
-(int) EnableFaceDetection:(bool)bValue;

/**
 Negotiation of screen sharing in specific business scenarios.
 Start or stop screen share
 */
-(int) StartScreenRecord;
-(int) StopScreenRecord;

/**
 Temporarily meaningless
 */
-(int) Share:(NSString*)srcType;

/**
 Switch video audio mode during a call
 Temporarily meaningless
 @param bValue YES:video call;NO:audio call
 */
-(int) Update:(bool)bVideo;

/**
 Mute a call
 It only works when the meida type set to RTP or WebRTC
 @param bValue YES:mute;NO:unmute
 */
-(int) Mute:(bool)bValue;

/**
 Secondary dialing
 @param tapKey Secondary dialing key values:
 1(1),2(2),3(3),4(4),5(5),6(6),
 7(7),8(8),9(9),10(*),0(0),11(#),
 12(A),13(B),14(C),15(D)
 @param dtmfType Secondary dialing method
 0: Info message, application/dtmf relay
 1: Info message, application/dtmf
 2: In band
 */
-(int) SendDtmf:(int)tapKey DtmType:(int)dtmfType;

/**
 After the call is connected, switch between "hands-free" and "earphone" modes
 It only works when the meida type set to RTP or WebRTC
 */
-(Boolean) SetSpeakMode;

/**
 During the call, you can obtain the current routing status
 It only works when the meida type set to RTP or WebRTC
 */
-(Boolean) GetSpeakMode;

/**
 After the video call is connected, switch between the "front camera" and "rear camera" modes
 It only works when the meida type set to  WebRTC
 */
-(Boolean) ChangeCamera;

/**
 Set whether to send and receive video streams during calls
 It only works when the meida type set to  WebRTC
 @param bSend Sender View
 @param bRecv Receiver View
 */
-(Boolean) SetVedioPlay:(Boolean)bSend Recv:(Boolean)bRecv;


#pragma mark about wake call
/**
 Temporarily meaningless
 */
-(int) WakeUp;

/**
 Register with the wake-up server for use in wake-up calls
 @param application UIApplication instance
 @param cb a result block for token string
 */
-(void) RegisterToRemotePushSever:(UIApplication *)application CallBack:(OneStringParamCallBack)cb;

/**
 Transparent token to SDK
 @param pToken device push token
 */
-(void) didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)pToken;


#ifdef SURPPORT_WEBRTC
/**
 Set up local and remote video rendering
 It only works when the meida type set to  WebRTC
 @param localView local view container
 @param remoteView remote view container
 */
-(void) SetVedioView:(RTCEAGLVideoView*)localView VvRemote:(RTCEAGLVideoView*)remoteView;

/**
 Set external video source from screen
 It only works when the meida type set to  WebRTC
 @param sampleBuffer screen stream
 */
-(void) SetOutSideBuffer:(CMSampleBufferRef) sampleBuffer;
#endif

/**
 Set up local and remote video rendering
 It only works when the meida type set to RTP
 @param localView local view container
 @param remoteView remote view container
 */
-(void) SetVedioComView:(UIView*)localView VvRemote:(UIView*)remoteView;

/**
 Set the result of Agora call joining the call
 @param strKey result type string:
 "OnAgoraVoiceJoinSuccess": Successfully joined the Agora meeting;
 "OnAgoraVoiceError": Failed to join the Agora meeting;
 @param strParam fail reason, error code from agora
 */
-(void)  SetMediaConsultationResult:(NSString*)strKey Param:(NSString*)strParam;

/**
 Get keywords in the call.
 @param strKey the key in SIP Invite message
 */
-(NSString*) GetSpKey:(NSString*)strKey;

/**
 Get SIP Call core object
 */
-(SipCoreCall*) GetSipCoreCall;

/**
 Manually upload local record logs
 @param sServer log server ip or domain
 @param nPort log server port
 */
-(NSString*) UploadLogFile:(NSString *)sServer Port:(int)nPort;

/**
 Manually upload local record logs for upload result
 @param sServer log server ip or domain
 @param nPort log server port
 @param uploadLogcb the upload result block
 */
-(void) UploadLogFile:(NSString *)sServer Port:(int)nPort uploadLogcb:(OneUploadLogCallBack) uploadLogcb;

/**
 Customized writing to log files for easy troubleshooting
 @param logMessage custom log text
 */
-(void) SetLogMessage:(NSString *) logMessage;

/**
 Delegate for call events
 */
-(void)SetDelegate:(id<SIPEventDelegate>) delegate;

/**
 SipPhone Instance Init (recommend)
 */
-(id)init;
-(void)dealloc;

/**
 Obtain Single Instance
 */
+(id) getInstance;
/**
 Destroy single instance
 */
+(void) releaseInstance;


@end
