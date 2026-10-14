#ifndef BTLV_EFFVM_TYPES_H
#define BTLV_EFFVM_TYPES_H

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/*
 * Work area of the battle effect script VM.
 * Allocated by BTLV_EFFVM_Create (size 0x2AC), fetched from the VM with VM_GetUserData.
 */

/* Bit flags in the first word of the work area. Bits not listed are unused. */
typedef union BtlvEffVmFlags {
    u32 word;
    struct {
        u32 flipSides : 1; /* effect sides are swapped (attacker and target exchanged) */
        u32 cameraOverride : 1; /* camera effect with a custom path is active */
        u32 seVolumeRamp : 1; /* sound effect volume ramp is running */
        u32 sePanRamp : 1; /* sound effect pan ramp is running */
        u32 gfxReloadPending : 1; /* battle graphics must be reloaded when the script ends */
        u32 blendActive : 1; /* blend register 0x04000050 was set by the effect */
        u32 fallbackScript : 1; /* default script is loaded in place of the requested one */
        u32 blockedOnTask : 1; /* script is blocked until a task clears this bit */
        u32 bgFadeActive : 1; /* background fade task is running */
        u32 fading : 1; /* palette fade is running */
        u32 fadeRestart : 1; /* a second fade was requested while one runs */
        u32 particleTaskActive : 1; /* particle task is running */
        u32 stopSeOnEnd : 1; /* stop all sound effects when the script ends */
        u32 cameraOffset : 1; /* camera is displaced from its default position */
        u32 : 1;
        u32 cameraLocked : 1; /* camera commands are ignored */
        u32 particleSysActive : 1; /* particle system is active */
        u32 fallbackPending : 1; /* default script is to be loaded on the next end */
        u32 keepBackground : 1; /* background state is kept when the effect ends */
    } bit;
} BtlvEffVmFlags;

typedef struct BtlvEffVmVec {
    int x;
    int y;
    int z;
} BtlvEffVmVec;

typedef struct BtlvEffVmVec16 {
    s16 x;
    s16 y;
    s16 z;
} BtlvEffVmVec16;

/* Orientation record written to an emitter: mode word, then the direction. */
typedef struct BtlvEffVmEmitterDir {
    u16 mode; /* 2 while the direction is followed, 0 when the angle to the target is near a quarter turn */
    BtlvEffVmVec16 dir;
} BtlvEffVmEmitterDir;

/* Battler positions that a target group lists, per side (0x30 bytes: 4 rows of 3). */
typedef struct BtlvEffVmTargetTable {
    int row[4][3];
} BtlvEffVmTargetTable;

struct ParticleSys;

/* Projection setup passed to PARTICLE_InitCamera (same layout as arm9 struct ParticleCameraParams). */
struct ParticleCameraParams {
    u32 projType;
    u32 fovSin;
    u32 fovCos;
    u32 aspect;
    u32 orthoExtent;
    u32 nearZ;
    u32 farZ;
    u32 projScale;
};

/* Effect parameters 9 to 15 selectable by the script, copied as one block from the caller. */
typedef struct BtlvEffVmParams {
    u8 kind;
    u8 variant;
    u8 option;
    u8 side;
    int argA;
    int argB;
    u16 typeCode;
    u8 pad[2];
} BtlvEffVmParams;

typedef struct BtlvEffVmWork {
    BtlvEffVmFlags flags; /* 0x000: status bits */
    int scriptVar; /* 0x004: script variable, read back by selector 16 */
    void *owner; /* 0x008: task owner for the effect tasks */
    struct ParticleSys *emitters[16]; /* 0x00C: particle systems by slot */
    int voiceIds[16]; /* 0x04C: voice ids by slot, -1 = free */
    int soundHandles[16]; /* 0x08C: sound handles by voice slot */
    int resources[4]; /* 0x0CC: sprite resources, -1 = free */
    int attackerPos; /* 0x0DC: battler position of the user */
    int defenderPos; /* 0x0E0: battler position of the target, 0xFF = none */
    int savedAttackerPos[16]; /* 0x0E4: call stack of attackerPos, indexed by callDepth */
    int savedDefenderPos[16]; /* 0x124: call stack of defenderPos */
    int savedScriptBuf[16]; /* 0x164: call stack of scriptBuf (as int) */
    int savedScriptVar[16]; /* 0x1A4: call stack of scriptVar */
    int waitFrames; /* 0x1E4: frame countdown of the wait command */
    void *scriptBuf; /* 0x1E8: loaded script file */
    void *pendingScriptBuf; /* 0x1EC: script file queued to replace scriptBuf */
    int pendingScriptOffset; /* 0x1F0: entry offset in pendingScriptBuf */
    void *allocBuffers[16]; /* 0x1F4: heap buffers freed at the end */
    int allocBufferCount; /* 0x234: used entries of allocBuffers */
    u16 heapId; /* 0x238: heap of every allocation */
    u8 pad23A[0x2];
    int result; /* 0x23C: return value of every script command */
    u32 waitMode; /* 0x240: condition checked by the wait callback */
    int layoutMode; /* 0x244: selects the camera reset routine */
    BtlvEffVmParams params; /* 0x248: effect parameters */
    u16 effectId; /* 0x258: effect script id */
    u8 pad25A[0x2];
    int typeSource; /* 0x25C: where the effect type comes from (8 = typeCode, 9 = attackerPos, else the value) */
    int callDepth; /* 0x260: depth of the call stack */
    int bg3ScrollX; /* 0x264: saved BG3 scroll */
    int bg3ScrollY; /* 0x268: saved BG3 scroll */
    int seVoiceIds[6]; /* 0x26C: sound effect voice ids, -1 = free */
    int camVecSaved; /* 0x284: camEye and camTarget hold a valid pair */
    BtlvEffVmVec camEye; /* 0x288: saved camera position */
    BtlvEffVmVec camTarget; /* 0x294: saved camera target */
    int scratchVar; /* 0x2A0: script variable selected by 55 */
    u32 lastEffectId; /* 0x2A4: effectId of the last request */
    u32 lastSlot; /* 0x2A8: attackerPos of the last request */
} BtlvEffVmWork;

/* Request record of one particle effect (0x5C bytes), filled by the start-particle script commands. */
typedef struct BtlvEffVmParticleReq {
    struct ScriptVm *vm; /* 0x00 */
    int srcKey; /* 0x04: source battler slot or anchor id */
    int dstKey; /* 0x08: target slot or anchor id, 8 = fixed position */
    BtlvEffVmVec offset; /* 0x0C: offset added to the positions */
    int arcAngle; /* 0x18 */
    int arcScale; /* 0x1C */
    int motionKind; /* 0x20: 0 = none, 1..6 = path shape (see the emitter callbacks) */
    int travelTime; /* 0x24 */
    BtlvEffVmVec fixedSrc; /* 0x28: source position when srcKey = 8 */
    BtlvEffVmVec fixedDst; /* 0x34: target position when dstKey = 8 */
    int mode; /* 0x40 */
    int scaleX; /* 0x44: multiplier of the emitter scale, 0 = unchanged */
    int alphaScale; /* 0x48 */
    int angleScale; /* 0x4C */
    int posScale; /* 0x50 */
    int wobbleScale; /* 0x54 */
    int flip; /* 0x58: mirror the emitter direction */
} BtlvEffVmParticleReq;

/* Task record of a delayed sound effect (allocated 0x24 bytes by BTLV_EFFVM_StartSePlayTask). */
typedef struct BtlvEffVmSePlayJob {
    BtlvEffVmWork *work;
    u32 seId;
    int slot; /* 5 = pick a free slot */
    int pan; /* 127 right, -128 left, 0 centre */
    int delay; /* frames before the sound starts */
    int pitch;
    int volume;
    int modDepth;
    int modSpeed;
} BtlvEffVmSePlayJob;

/* Task record that ramps the pitch, volume or pan of a sound slot (0x38 bytes). */
typedef struct BtlvEffVmSeRampJob {
    BtlvEffVmWork *work;
    int slot;
    int mode; /* 0 = one pass, 1 = ping-pong */
    int param; /* 0 = pitch, 1 = volume, 2 = pan */
    int from;
    int to;
    int current; /* fx32 value */
    int delta; /* fx32 step */
    int startDelay; /* frames before the first step */
    int stepsLeft; /* counts down, reloaded from stepCount for each pass */
    int stepCount; /* steps from "from" to "to" */
    int frameCounter;
    int framesPerStep;
    int passes; /* doubled pass count of the ping-pong ramp, bit 0 selects the clamp target */
} BtlvEffVmSeRampJob;

/* Circular motion record of one particle emitter (0x40 bytes), made by the circle-particle script commands. */
typedef struct BtlvEffVmCircleMotion {
    int anchorKind; /* 0x00: 0 and 1 center on the user, 2 and 3 on the target, 4 and 5 on the origin; bit 0 runs the circle backwards */
    BtlvEffVmVec center; /* 0x04 */
    int radiusX; /* 0x10 */
    int radiusZ; /* 0x14 */
    int phase; /* 0x18: 16.16 fraction of a turn */
    int phaseStep; /* 0x1C: 0x10000 / stepsPerCycle */
    int stepsLeft; /* 0x20: steps left in the current cycle */
    int stepsPerCycle; /* 0x24 */
    int intervalCounter; /* 0x28: frames until the next step */
    int interval; /* 0x2C: frames per step */
    int scriptArg12; /* 0x30: operand stored by the script command, never read by the callbacks */
    int pauseCounter; /* 0x34: frames left in the pause between cycles */
    int pauseFrames; /* 0x38 */
    int projectToScreen; /* 0x3C: the position is converted to screen space */
} BtlvEffVmCircleMotion;

/* One variant slot of a script file; the first word is the offset of its commands. */
typedef struct BtlvEffVmScriptVariant {
    u32 entryOffset;    /* 0x00: byte offset of the first command */
    u8 unknown04[0x34]; /* 0x04: not read by the effect VM */
} BtlvEffVmScriptVariant;

/* Battle effect script file (archive 0x42/0x43 member). */
typedef struct BtlvEffVmScriptFile {
    u8 variantCount;    /* 0x00: variants, selected by BtlvEffVmParams.variant */
    u8 pad01[3];
    BtlvEffVmScriptVariant variant[1]; /* 0x04 */
} BtlvEffVmScriptFile;

/* Head of a particle archive member as read by the effect script. */
typedef struct BtlvEffVmParticleResHeader {
    u8 reserved0[8];    /* 0x00: not read by the effect script */
    u16 soundHandle;    /* 0x08: copied to BtlvEffVmWork.soundHandles */
} BtlvEffVmParticleResHeader;

/* Task record of the palette fade (0x10 bytes, allocated by BTLV_EFFVM_StartFade). */
typedef struct BtlvEffVmFadeJob {
    BtlvEffVmFlags *flags; /* flags word of the work area */
    int current; /* fx32 brightness, steps toward target */
    int target; /* fx32 brightness at the end */
    int step; /* fx32 step per frame */
} BtlvEffVmFadeJob;

/* Task record that waits for the cry voices to end before the second fade (4 bytes). */
typedef struct BtlvEffVmFadeWaitJob {
    BtlvEffVmWork *work;
} BtlvEffVmFadeWaitJob;

/* Task record of a delayed cry playback (0x20 bytes). */
typedef struct BtlvEffVmCryJob {
    BtlvEffVmWork *work;
    int battlerPos; /* battler whose cry is played */
    int pitch;
    int pan;
    int chorusParamA; /* passed through to the voice player */
    int chorusParamB;
    int chorusParamC;
    int delay; /* frames before the cry starts */
} BtlvEffVmCryJob;

/* Task record of the window wipe over the screen (0x28 bytes). */
typedef struct BtlvEffVmWindowWipeJob {
    BtlvEffVmWork *work;
    int state; /* 0 = set up the window registers, 1 = move the edge */
    int direction; /* 0 = edge Y up, 1 = edge Y down, 2 = edge X left, 3 = edge X right */
    int edgeX; /* window edge in 8.8 form: high byte first coordinate, low byte second */
    int edgeY;
    int windowBits; /* layer enable bits written to WININ and WINOUT */
    int stepsLeft;
    int frameCounter;
    int framesPerStep;
    int keepWindow; /* 0 = window display is switched off again at the end */
} BtlvEffVmWindowWipeJob;

/* Task record that clears slots from a mask, two slots apart (0xC bytes). */
typedef struct BtlvEffVmSlotSweepJob {
    BtlvEffVmWork *work;
    int side; /* 0 = even slots, else odd slots */
    int doneMask; /* slots already handled */
} BtlvEffVmSlotSweepJob;

/* Task record that starts the particle load handlers after the picture is drawn (12 bytes). */
typedef struct BtlvEffVmParticleLoadJob {
    BtlvEffVmWork *work;
    void *emitter;
    void *resource;
} BtlvEffVmParticleLoadJob;

typedef char BtlvEffVmWorkSizeCheck[(sizeof(BtlvEffVmWork) == 0x2AC) ? 1 : -1];

#endif
