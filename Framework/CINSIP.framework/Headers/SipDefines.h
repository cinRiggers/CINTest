//
//  CINSipDefines.h
//  CINSipApp
//
//  Created by wushengjun on 16/2/2.
//  Copyright © 2016年 BJCINCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define CODEC_LIB_WEBRTC
#define CODEC_LIB_CINRTC

#ifdef CODEC_LIB_WEBRTC
  #define SURPPORT_WEBRTC
  #import <WebRTC/RTCEAGLVideoView.h>
  #import <WebRTC/RTCMTLVideoView.h>
#endif

#ifdef CODEC_LIB_CINRTC
#define SURPPORT_CINRTC
#endif

/**
 SIP Registe Status
 RegistrationNone = 0,no registe leg
 RegistrationProgress , SIP Registering
 RegistrationOk , SIP registe success
 RegistrationCleared ,SIP clear registe leg
 RegistrationFailed, SIP registe failed
 */
typedef enum emRegistrationState {
    RegistrationNone = 0,
    RegistrationProgress ,
    RegistrationOk ,
    RegistrationCleared ,
    RegistrationFailed
} emRegistrationState;


/**
 SIP Call Status
 Idle  = 0, the init status,a call is idle
 IncomingReceived, when a call is coming
 OutgoingProgress, a call is out going
 OutgoingRinging, the other side is ring a call
 Connected, a call has connect with SIP
 Error, a call occurs some error
 CallEnd, a call end normally
 CallReleased,a call has released
 */
typedef enum emCallState {
    Idle  = 0,
    IncomingReceived,
    OutgoingInit,
    OutgoingProgress,
    OutgoingRinging,
   // OutgoingEarlyMedia,
    Connected,
    StreamsRunning,
   // Pausing,
   // Paused,
   // Resuming,
   // Refered,
    Error,
    CallEnd,
   // PausedByRemote,
   // CallUpdatedByRemote,
   // CallIncomingEarlyMedia,
   // CallUpdating,
    CallReleased
} emCallState;

/**
 Protocol type carrying SIP message transmission
 TransferMode_Udp, UDP protocol
 TransferMode_WebSocket, WebScocket protocol
 TransferMode_GM, GM_WebScocket protocol
 TransferMode_Tcp, (NOT Support currently)
 TransferMode_Tls,(NOT Support currently)
 */
enum emTransferMode {
    TransferMode_Udp,
    TransferMode_WebSocket,
    TransferMode_GM,
    TransferMode_Tcp,
    TransferMode_Tls
};
typedef enum emTransferMode emTransferMode;


/**
 The transmission protocol type used for uploading logs
 Protocol_HTTP, Using HTTP transmission
 Protocol_HTTPS,Using HTTPS transmission
 */
enum emLogUploadProtocol {
    Protocol_HTTP,
    Protocol_HTTPS
};
typedef enum emLogUploadProtocol emLogUploadProtocol;


/**
 Identification settings for reconnection methods
 Use_PCINCallID, Using P-CIN-CallId as reconnect identification
 Use_CallID,Using Call-ID as reconnect identification
 */
enum emReconnectType {
    Use_PCINCallID,
    Use_CallID
};
typedef enum emReconnectType emReconnectType;

/**
 Media types for audio and video calls,
 NoneVoice, no media for use
 AgoraVoice, Agora media protocol
 RTPVoice,RTP media protocol
 WebrtcVoice, WebRTC meida protocol
 */
enum emMediaType {
    NoneVoice,
    AgoraVoice,
    RTPVoice,
    WebrtcVoice
};
typedef enum emMediaType emMediaType;


/**
 Video encoding resolution
 */
enum emVideoSize {
    VD_320x240,
    VD_480x360,
    VD_640x360,
    VD_640x480,
    VD_840x480,
    VD_960x720,
    VD_1280x720
};
typedef enum emVideoSize emVideoSize;

/**
 Set video rendering mode
 Webrtc_Fit, Adaptive mode
 Webrtc_Full, Full screen stretching mode
 Webrtc_Balanced ( has discarded)
 */
enum emVideoMode {
    Webrtc_Fit,
    Webrtc_Full,
    Webrtc_Balanced
};
typedef enum emVideoMode emVideoMode;


/**
 Negotiate media type with server
 mediaNone, no meida
 mediaAudio, only audio media
 mediaVedio, only video media
 mediaAudioVedio, meida with audio and video
 mediaAgora,meida with agrao type
 */
enum emMediaState {
    mediaNone,
    mediaAudio,
    mediaVedio,
    mediaAudioVedio,
    mediaAgora
};
typedef enum emMediaState emMediaState;


/**
 The call end reason
 NoCall = -1, non-existent call
 NoAnswerCall = 0,the call no one answered
 RejectCall =1, the call has been rejected
 ConnectCall =2, the call connected success
 OtherFailureCall = 3 the call end with some error
 */
typedef enum emCallEndCause {
    NoCall = -1,
    NoAnswerCall = 0,
    RejectCall =1,
    ConnectCall =2,
    OtherFailureCall = 3
} emCallEndCause;


/**
 Define exceptions to media Rtcp
 */
typedef enum emMediaException {
    RttException = 0,
    JitterException,
    NoPacketSendException,
    NoPacketReceiveException,
    PacketSendException,
    PacketReceiveException,
    NoneException
} emMediaException;


/**
 The Negotiation Mode of WebRTC with SIP Server
 WebrtcCall_Passive, Active negotiate with SIP Server for WebRTC sdp
 WebrtcCall_Active,no sdp mode,wait for sdp negotiation from SIP Server
 */
enum emWebrtcCallMode {
    WebrtcCall_Passive,
    WebrtcCall_Active
};
typedef enum emWebrtcCallMode emWebrtcCallMode;

/**
 Get push token string
 @param sValue token string
 */
typedef  void (^OneStringParamCallBack)(NSString *sValue);

/**
 Initialization Result block
 @param code the init result code,200、success; others: failed
 */
typedef  void (^OneIntParamCallBack)(int code);

/**
 The upload result block
 @param code the result string from server response
 */
typedef  void (^OneUploadLogCallBack)(NSString *code);
//typedef  void (^OneIntParamCallBack)(int code，NSString *sValue);

#pragma mark CallState
@interface CallState : NSObject
{
    @public
    emCallState callState;
}

- (NSString*) ToString;
-(id)init;

@end

#pragma mark RTPCodec
@interface RTPCodec : NSObject
{
@public
    int codec;
}

- (NSString*) ToString;
-(id)init;

@end

#pragma mark RegistrationState
@interface RegistrationState : NSObject
{
    @public
    emRegistrationState regState;
}

-(NSString*) ToString;
-(id)init;

@end

#pragma mark CallEndCause
@interface CallEndCause : NSObject
{
@public
    emCallEndCause endCause;
}

-(NSString*) ToString;
-(id)init;

@end

#pragma mark RtpMediaType
@interface RtpMediaType : NSObject
{
@public
    emMediaType mediaType;
}

-(NSString*) ToString;
-(id)init;

@end

#pragma mark MediaCallStatistics
@interface MediaCallStatistics : NSObject
{
@public
    //Network packet loss rate
    int fractionLost;
    //Accumulated packet loss rate
    int cumulativeLost;
    //maximum delay
    int extendedMax ;
    //Jitter rate
    int jitterSamples ;
    //Network Delay
    long rttMs ;
    //the bytes has sent
    long bytesSent ;
    //the pockets has sent
    int packetsSent ;
    //the bytes has received
    long bytesReceived ;
    //the pocket has received
    int packetsReceived;
}

-(id)init;

@end

#pragma mark MediaState
@interface MediaState : NSObject
{
@public
    emMediaState mediaState;
}

-(NSString*) ToString;
-(id)init;

@end


/**
 SIP Call core object
 */
@interface SipCoreCall : NSObject
{
    @public
    //register status
    RegistrationState* regState;
    
    RtpMediaType  *mediaType;
    MediaState *mediaState;
    CallState* callState;
    CallEndCause* endCause;
    RTPCodec*  aCodec;
    MediaCallStatistics* callMediaStatistics;

    //the phone number
    NSString*   sNum;
    //call session id
    NSString*   sCurID;
    //call error code
    int         nCode;
    //error des
    NSString*   sDescription ;
    //registe code
    int         regCode;
    //is a wake type call
    Boolean     bWakeupCall;
    //has be initialed
    Boolean     bInitial;
    //call record id
    NSString*   sRecordID;
}
-(id)init;
@end

/**
 Statistics of media sending and receiving parameters for RTP or webrtc
 */
@interface RtcStatistics : NSObject
{
    @public
        int audioBytesSent;
        int audioBytesReceived;
        int audioPacketsSent;
        int audioPacketsReceived;
        int videoBytesSent;
        int videoBytesReceived;
        int videoPacketsSent;
        int videoPacketsReceived;
    }
    -(id)init;
@end

/**
 Statistical media transmission for RTP or webrtc quality
 */
@interface RtcQuality : NSObject
{
    @public
        int audioRtt;
        int audioJitter;
        int audioQuality;
        int videoRtt;
        int videoJitter;
        int videoQuality;
        int fractionLost;
        int cumulativeLost;
        int extendedMax;
    }
    -(id)init;
@end


@protocol SIPEventDelegate <NSObject>

@required

/**
 Occurs when sip register status changed.
 @param state RegistrationState  object.
 @param message  descprition of register
*/
- (void)OnRegistrationStateChanged:(RegistrationState*)state Message:(NSString *)message;

/**
 Occurs when sip call status changed.
 @param sipcall SipCoreCall  object.
 @param state CallState  object
 @param message  descprition of caller
*/
- (void)OnCallStateChanged:(SipCoreCall*)sipcall State:(CallState*)state Message:(NSString *)message;

/**
 Occurs when debug info output.
 @param sMsg  debug info
*/
- (void)OnDebugMessage:(NSString*)msg;

/**
 Occurs when recieve special message for sdk or server
 @param code  message type.
 @param msg  message content.
*/
- (void)OnMessage:(int)code Message:(NSString*)msg;

/**
 Occurs when recieve special message for sdk or server
 @param code  message type.
 @param msg  message content.
*/
- (void)OnInfo:(NSString*)conType Message:(NSString*)msg;

/**
 Occurs when sdk wakeup by apns
 @param callNumber  come call key.
 @param backGround  backgroud flag.
*/
- (void)OnWakeUp:(NSString*)callNumber BackGround:(Boolean)backGround;

@optional
/**
 Occurs when mediatype is agora call coming
 @param key  call key.
 "JoinAgroraAudio": Join Agrora meetings
 "LeafAgroraAudio": Exit the agora meeting
 @param param  call param.Agora：agora-AgoraAppId-AgoraChannelId-AgoraUid-AgoraCertification-AgoraTokenExpires-AgoraChannelKey-AgoraDataEncrypt-AgoraToken
 @param indentity  call legid.
*/
- (void)OnMediaConsultation:(NSString*)key Param:(NSString*)param Indentity:(NSString*)indentity ;

/**
 Occurs initial success when Occurs transfer
 @param code  code value.
 @param des  code description.
*/
- (void)OnInitialStatusChange:(int)code Des:(NSString*)des;

/**
 Occurs where camera check faces
 @param faces  count value.
 @param rects  faces rect.
*/
- (void)OnFacePositionChanged:(int)faces Rects:(NSArray*)rects;

/**
 Occurs when screen record begin or stop
 @param key : begin|end
 it only works in Special business scenarios
*/
- (void)OnScreenRecord:(NSString*)key ;

@optional
/**
 Callback statistics of media sending and receiving parameters for RTP or webrtc
 */
- (void)OnCallStatistics:(NSString*)indentity RtcStatistics: (RtcStatistics *) rtcStatistics;

/**
 Callback of media transmission quality statistics for RTP or webrtc
 */
- (void)OnRtcpCallStatistics:(NSString*)indentity RtcQuality:(RtcQuality *) rtcQuality;

/**
 Callback network quality dure call
 @param qualityLevel : networkQuality,from 0 to 6;
 @param qualityDesc : the description to qualityLevel
 */
- (void) OnNetworkQuality:(int) qualityLevel QualityDesc:(NSString *) qualityDesc;

/**
 Media abnormal feedback
@param mediaException: Enumerated values for media exceptions. Detail in emMediaException define.
 */
- (void) OnMediaException:(emMediaException) mediaException;

/**
 Pre call network quality warning
@param netConnType: Current network type, below 4G
 */
- (void) OnPreCallNetworkQualityWarning:(NSString *) netConnType;

@end


