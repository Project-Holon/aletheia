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
 * Allocated by func_021F93F4 (size 0x2AC), fetched from the VM with func_02011324.
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
    void *emitters[16]; /* 0x00C: particle systems by slot */
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

typedef char BtlvEffVmWorkSizeCheck[(sizeof(BtlvEffVmWork) == 0x2AC) ? 1 : -1];

#endif
