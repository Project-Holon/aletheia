#ifndef VCT_TYPES_H
#define VCT_TYPES_H
/*
 * ov013 voice chat library (packet magic "TCV_", module VCT): shared types and data declarations.
 *
 * The library has four parts that all work on the objects below:
 *   engine glue   (vct_main.c): lifecycle, microphone and stream callbacks, ADPCM codecs, send path
 *   audio path    (vct_audio.c, vct_audio.c, vct_audio.c): encode, receive, jitter queues, peer table
 *   session       (vct_audio.c, vct_session.c): peer state machine and control packets
 *   frame pool    (vct_session.c, vct_session.c) and signal path / entry points (vct_dsp.c)
 *
 * No Nintendo vendor library holds this code (checked against the sdk archives and libmatch);
 * the four small functions the SDK classifier names after OS_, CTRDG_ and DWCi_ objects are
 * coincidental byte matches of 16 to 24 byte accessors and belong to this library.
 */

#include "../types.h"

/* Voice chat constants. */
#define HW_BUTTON_XY_BUF 0x02FFFFA8
#define PAD_DETECT_FOLD_MASK 0x8000
#define PAD_DETECT_FOLD_SHIFT 15

/* Size in bytes of the microphone ring and of each playback buffer. */
#define VCT_BUFFER_BYTES 0x880
/* Frame size in bytes of one microphone frame (PCM, 16 bit mono). */
#define VCT_FRAME_BYTES 0x440
/* Every packet slot holds one frame plus its header. */
#define VCT_PACKET_SLOT_BYTES 0x460
/* Bytes of receive queue per peer: eight packet records of 0x478 bytes. */
#define VCT_PEER_QUEUE_BYTES 0x23C0
#define VCT_PACKET_MAGIC 0x5F564354
#define VCT_MAX_MEMBERS 3
/* One 60 Hz frame in microseconds. */
#define VCT_FRAME_MICROSECONDS 16666

/* Events the engine reports to the registered callback (names are guesses from the handlers). */
enum {
    VCT_EVENT_REQUEST_RECEIVED = 1,
    VCT_EVENT_REQUEST_CANCELLED = 2,
    VCT_EVENT_REQUEST_TIMED_OUT = 3,
    VCT_EVENT_CONNECTION_CLOSED = 4,
    VCT_EVENT_PEER_JOINED = 7,
    VCT_EVENT_REQUEST_REFUSED = 8,
    VCT_EVENT_PEER_LEFT = 9,
    VCT_EVENT_ENGINE_ERROR = 11,
    VCT_EVENT_ENGINE_STOPPED = 12
};

/* ---- session ---- */

/* One peer link record (0x18 bytes). mode is copied from the session mode when the record is set up; 0 means unused. */
typedef struct VctPeer {
    u32 mode;
    u8 peerId;
    u8 floorHolderId;
    u8 pad6[2];
    u32 memberMask;
    int phase;
    u32 pad10;
    struct VctPeer *next;
} VctPeer;

typedef void (*VctEventCallback)(int aid, int event, VctPeer *peer, int arg);

/* gVctPeerPool: peer records. freePeers is the free list, activeHead the list of peers in use (host mode),
 * active the single record used in client mode, rejectPeer a scratch record for replies to unknown peers. */
typedef struct VctPeerPool {
    VctPeer *freePeers;
    VctPeer *activeHead;
    void *tickFunc;
    u32 rngMul;
    u32 rngAdd;
    VctPeer rejectPeer;
    VctPeer active;
} VctPeerPool;

/* gVctSession: session state. mode 1 = host, 2 = client, 3 = receive only (guess). */
typedef struct VctSession {
    u8 localId;
    u8 hostId;
    u8 pad2[2];
    VctEventCallback eventCallback;
    int callbackArg;
    int sharedSession;
    int mode;
    u32 sessionFlags;
} VctSession;

/* gVctState: library state. The session sits at +0xC; gVctSession names the same bytes. */
typedef struct VctLibState {
    s32 tickCount;
    s32 audioFrameCount;
    s32 initialized;
    VctSession session;
} VctLibState;

/* gVctGroup: peers that take part in the session (peerCount is the member count, 3 is full)
 * and the tick of the last announcement. */
typedef struct VctGroup {
    int peerCount;
    int peerMask;
    u64 announceTick;
} VctGroup;

/* Control packet, 0x10 bytes. kind: 0xFF to the group, 0 to one peer (0x4n are audio frames). */
typedef struct VctPacket {
    u32 magic;
    u8 kind;
    u8 protocol;
    u8 command;
    u8 reserved7;
    u8 srcId;
    u8 dstId;
    u8 flag;
    u8 floorHolderId;
    u32 memberMask;
} VctPacket;

/* Result of packet handling, handed to the event callback. */
typedef struct VctEvent {
    int code;
    VctPeer *peer;
} VctEvent;

/* First bytes of every received frame: magic and frame type. */
typedef struct VctFrameHeader {
    u32 magic;
    u8 type;
} VctFrameHeader;

/* Argument of the library init function. peerBuffer and peerCount give the peer record area.
 * frameBuffer stays an int: the signed remainder test on it is part of the original code. */
typedef struct VctInitParams {
    VctPeer *peerBuffer;
    u32 peerCount;
    s32 mode;
    u8 localId;
    u8 pad0D[3];
    int frameBuffer;
    int frameBufferSize;
    VctEventCallback eventCallback;
    int callbackArg;
} VctInitParams;

/* ---- ADPCM ---- */

typedef struct AdpcmState {
    s16 predictor;
    u8 stepIndex;
} AdpcmState;

/* Four byte header that precedes ADPCM payloads on the wire. */
typedef struct AdpcmHeader {
    s16 predictor;
    u8 stepIndex;
    u8 zero;
} AdpcmHeader;

/* ---- audio frames and receive path ---- */

/* One voice frame as sent on the wire: 0x0C byte header, then the encoded
 * samples. Two of them sit in VctSendBuffer (double buffer). type is 0x40 for
 * a voice frame and 0x41 for a silence descriptor. flags holds the codec
 * mode in bits 0..6 and the talk-spurt marker in bit 7. flags is volatile:
 * the wireless layer reads it while the frame is being finished. */
typedef struct VctAudioFrame {
    u32 magic;
    u8 type;
    volatile u8 flags;
    u16 seq;
    u32 timestamp;
    u8 data[VCT_PACKET_SLOT_BYTES - 0xC];
} VctAudioFrame;

/* gVctSendBuffer: send side. Frames are produced into frames[], then sent to
 * the peers in pendingMask a few at a time per tick. */
typedef struct VctSendBuffer {
    VctAudioFrame frames[2];
    int readCount;          /* 0x8C0: frames consumed by the encoder */
    u32 writeCount;         /* 0x8C4: frames captured by the mic */
    VctAudioFrame *sendFrame;    /* 0x8C8: frame being sent, 0 when idle */
    u32 pendingMask;        /* 0x8CC: peers still to receive sendFrame */
    int scheduleStep;       /* 0x8D0 */
    int scheduleRow;        /* 0x8D4: peer count - 1 */
} VctSendBuffer;

/* gVctSendState: send side state. The two request flags are volatile: other code
 * (the send switch, the peer add and remove paths) sets them while the encoder runs. */
typedef struct VctSendState {
    u16 sequence;
    u8 pad2[2];
    u32 memberMask;
    volatile u32 markerRequestNoVad;   /* set when sending is switched off */
    u32 packetBytes;
    u16 adpcmPredictor;
    u8 adpcmStepIndex;
    u8 pad13;
    volatile u32 markerRequest;        /* set when the first member joins or the last one leaves */
    u32 echoSuppressEnabled;           /* echo suppression and playback reference copy */
    int codecMode;
    int memberCount;
    u32 frameBytes;
    int lastGateResult;
} VctSendState;

/* One received packet, in the pending list and then in a per-slot ready
 * queue (sorted by seq). It is also the pool element of the frame allocator
 * (the first word is the free-list link). */
typedef struct VctRxPacket {
    struct VctRxPacket *freeLink;
    struct VctRxPacket *prev;
    struct VctRxPacket *next;
    int codecMode;
    u8 senderAid;
    u8 queueIndex;
    u8 pad12[2];
    u32 payloadSize;
    u32 seq;
    u8 buffer[0x45c - 0x1c];
    u32 marker;
    u32 timestamp;
    u64 arrivalTick;
    u64 playTick;
    void *payload;
} VctRxPacket;

typedef struct VctRxPacketList {
    VctRxPacket *head;
    VctRxPacket *tail;
} VctRxPacketList;

/* gVoiceFramePool: frame buffer pool. */
typedef struct VctFramePool {
    VctRxPacket *freeHead;
    VctRxPacket *base;
} VctFramePool;

/* gVctGroup as vct_audio.c sees it: the VctGroup without its trailing announceTick.
 * Declaring it 16 bytes long there makes the compiler reach gVctPeerPool (16 bytes further)
 * from the same base register and changes the code, so that file keeps the 8 byte view. */
typedef struct VctGroupCount {
    int peerCount;
    int peerMask;
} VctGroupCount;

/* Per-sender receive state (one per slot, three slots at gVctReceiveSources).
 * The sequence, jitter and drift fields follow RFC 3550 receiver state. */
typedef struct VctReceiveSource {
    u32 latency;
    u32 playoutDelay;
    u32 queueDepth;
    int drift;
    u32 lastSeq;
    u32 dropped;
    int jitterOut;
    u32 reordered;
    u32 playedFrames;
    int codecMode;
    u32 lastLatency;
    u32 latencyFilter;
    u32 noiseLevel;
    u32 queueIndex;
    int peerAid;
    VctRxPacket *lastPacket;
    u32 lastPacketSize;
    u64 tick0;
    u32 timestamp0;
    u32 prevTimestamp;
    u32 maxSeq;
    u32 lastPlayedSeq;
    u32 probation;
    u32 cycles;
    u32 badSeq;
    u16 baseSeq;
    u16 padSeq;
    u32 count;
    u32 pendingSkips;
    int avg;
    int base;
    int jitter;
    int transit;
    int hold;
    int lo;
    u32 hi;
    u32 lowCount;
} VctReceiveSource;

/* gVctFrameSpecs rows: a packet carries blocks of 0x44 bytes plus extra bytes after its 12 byte header. */
typedef struct VctFrameSpec {
    u8 blocks;
    u8 extraBytes;
} VctFrameSpec;

/* ---- engine glue ---- */

/* Microphone auto-sampling parameters (MICAutoParam layout). */
typedef struct VctMicParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loopEnable;
    void *fullCallback;
    void *fullArg;
} VctMicParam;

struct VctWork;

/* Heap block behind gVctWork. */
typedef struct VctWork {
    u8 micRing[VCT_BUFFER_BYTES];
    void *frameMemory;
    u8 playbackBuffers[2][VCT_BUFFER_BYTES];
    void (*exitCallback)(void);
    VctPeer enginePeer;
    int peerActive[2];
    int mode;
    int linkState;
    u16 sendPaused;
    u16 muted;
    u8 pad19B4[4];
    u8 audioStream[100];
    VctPeer *pendingPeer;
    VctMicParam micParam;
    u64 lastTick;
    s32 microsecondDebt;
    u16 requestCooldown;
    u8 streamPhase;
    u8 micRestartPending;
} VctWork;

typedef void (*VctStreamCallback)(int status, int channelCount, void **buffers, u32 length, int format, struct VctWork *work);

/* ---- signal path ---- */

/* gVoiceGateConfig: voice gate configuration. voiceActive is shared with the mic callback. */
typedef struct VoiceGateConfig {
    volatile u32 voiceActive;
    u32 lastLevel;
    s32 hangoverFrames;
    s32 hangoverBytes;
} VoiceGateConfig;

/* gVoiceGateConfig is declared with a size under four bytes so that every access
 * to it falls in the unknown-memory set of the compiler (see the voice gate update). */
#ifdef __MWERKS__
extern u8 gVoiceGateConfig;
#define VAD_CFG (*(VoiceGateConfig *)&gVoiceGateConfig)
#else
extern VoiceGateConfig gVoiceGateConfig; /* the PC build declares the full object */
#define VAD_CFG gVoiceGateConfig
#endif

/* gVoiceGateState: voice gate state. */
typedef struct VoiceGateState {
    volatile u32 threshold;
    u32 ringIndex;
    s32 quietFrames;
} VoiceGateState;

/* gEchoState: echo suppression state with its delay ring buffer (ringBuf sits at +0x484). */
struct EchoState {
    s16 attenuationShift;
    s16 pad2;
    s32 highPassPrevInput;
    s32 ringReadIndex;
    s32 ringWriteIndex;
    s32 highPassPrevOutput;
    s32 firCoeffs[6];
    s32 firDelay[6];
    u8 reserved44[0x440];
    s16 ringBuf[2048];
};

/* ---- data shared between the files of the library ---- */
extern VctLibState gVctState;
extern VctSession gVctSession;
extern VctPeerPool gVctPeerPool;
extern VctFramePool gVoiceFramePool;
extern VctSendState gVctSendState;
extern VctSendBuffer gVctSendBuffer;
extern VctReceiveSource gVctReceiveSources[3];
extern const VctFrameSpec gVctFrameSpecs[];
extern int gVctSendEnabled;
extern VctRxPacketList gVctPendingList;
extern int gVctPendingCount[3];

#endif
