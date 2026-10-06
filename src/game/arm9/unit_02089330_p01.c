/*
 * file:     unit_02089330_p01.c
 * unit:     yes
 * function: func_02089330, func_02089350, func_02089378, func_02089398, func_020893B8, func_020893D0, func_020893E8, func_02089400, func_0208941C, func_02089438, func_02089454, func_02089470, func_0208948C, func_020894B4, func_020894DC, func_02089540, func_02089580
 * address:  0x02089330
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PushCommand_impl  0x02089804  arm
 *   func_02089804  0x02089804  arm
 *   func_020897B4 0x020897B4 arm
 *   func_020897DC 0x020897DC arm
 *   SNDi_IncAlarmId   0x02089FC0  arm
 *   SNDi_SetAlarmHandler  0x02089FE0  arm
 */
struct SNDBankData;
typedef unsigned long u32_02089330;

typedef unsigned long u32_02089350;

typedef unsigned int u32_02089378;

typedef unsigned long u32_02089398;

typedef unsigned int   u32_4;

typedef unsigned int   u32_5;

typedef unsigned int   u32_6;

typedef unsigned int   u32_7;

typedef unsigned int   u32_8;

typedef unsigned int   u32_9;

typedef unsigned int   u32_10;

typedef unsigned int   u32_11;

typedef unsigned long u32_0208948C;

typedef unsigned long u32_020894B4;

typedef unsigned long u32_020894DC;

typedef unsigned long u32_02089540;

typedef void (*SNDAlarmHandler)(void *arg);

typedef unsigned long u32_02089580;

extern void PushCommand_impl(int id, u32_02089330 arg0, u32_02089330 arg1, u32_02089330 arg2, u32_02089330 arg3);
extern int func_02089804(int code, u32_02089378 a, u32_02089378 b, u32_02089378 c, u32_02089378 d);
extern void func_020897B4(int playerNo, u32_4 offset, u32_4 data, int size);
extern void func_020897DC(int playerNo, u32_7 trackBitMask, u32_7 offset, u32_7 data, int size);
extern void SNDi_IncAlarmId(int alarmNo);
extern unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
void func_02089330(int playerNo);
int func_02089378(u32_02089378 a);
void func_02089398(int playerNo, int flag);
asm void SND_SetPlayerTempoRatio(void);
asm void SND_SetPlayerVolume(void);
asm void SND_SetPlayerChannelPriority(void);
asm void SND_SetTrackVolume(void);
asm void SND_SetTrackPitch(void);
asm void SND_SetTrackPan(void);
asm void SND_SetTrackModDepth(void);
asm void SND_SetTrackModSpeed(void);
void func_0208948C(int playerNo, u32_0208948C trackBitMask, u32_0208948C chBitMask);
void func_020894B4(u32_020894B4 chBitMask, u32_020894B4 capBitMask, u32_020894B4 alarmBitMask, u32_020894B4 flags);
void func_020894DC(u32_020894DC chBitMask, u32_020894DC capBitMask, u32_020894DC alarmBitMask, u32_020894DC flags);
void func_02089540(int alarmNo, u32_02089540 tick, u32_02089540 period, SNDAlarmHandler handler, void *arg);
void func_02089580(int playerNo, u32_02089580 trackBitMask, int flag);


/*
 * sdk:      SND_StopSeq (snd_interface.o)
 */
void func_02089330(int playerNo)
{
    PushCommand_impl(1, (u32_02089330)playerNo, 0, 0, 0);
}


/*
 * sdk:      SND_PrepareSeq (snd_interface.o)
 */
void func_02089350(int playerNo, const void *base, u32_02089350 offset, struct SNDBankData *bank)
{
    PushCommand_impl(2, (u32_02089350)playerNo, (u32_02089350)base, offset, (u32_02089350)bank);
}


int func_02089378(u32_02089378 a)
{
    u32_02089378 z = 0;

    return func_02089804(3, a, z, z, z);
}


/*
 * sdk:      SND_PauseSeq (snd_interface.o)
 */
void func_02089398(int playerNo, int flag)
{
    PushCommand_impl(4, (u32_02089398)playerNo, (u32_02089398)flag, 0, 0);
}


asm void SND_SetPlayerTempoRatio(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #0x1a
    mov	r3, #2
    bx	ip
}


asm void SND_SetPlayerVolume(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #6
    mov	r3, #2
    bx	ip
}


asm void SND_SetPlayerChannelPriority(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #4
    mov	r3, #1
    bx	ip
}


asm void SND_SetTrackVolume(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #2
    mov	r2, #0xa
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}


asm void SND_SetTrackPitch(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #2
    mov	r2, #0xc
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}


asm void SND_SetTrackPan(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #1
    mov	r2, #9
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}


asm void SND_SetTrackModDepth(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #1
    mov	r2, #0x1a
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}


asm void SND_SetTrackModSpeed(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #1
    mov	r2, #0x19
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}


/*
 * sdk:      SND_SetTrackAllocatableChannel (snd_interface.o)
 */
void func_0208948C(int playerNo, u32_0208948C trackBitMask, u32_0208948C chBitMask)
{
    PushCommand_impl(9, (u32_0208948C)playerNo, trackBitMask, chBitMask, 0);
}


/*
 * sdk:      SND_StartTimer (snd_interface.o)
 */
void func_020894B4(u32_020894B4 chBitMask, u32_020894B4 capBitMask, u32_020894B4 alarmBitMask, u32_020894B4 flags)
{
    PushCommand_impl(0xc, chBitMask, capBitMask, alarmBitMask, flags);
}


/*
 * sdk:      SND_StopTimer (snd_interface.o)
 */
void func_020894DC(u32_020894DC chBitMask, u32_020894DC capBitMask, u32_020894DC alarmBitMask, u32_020894DC flags)
{
    int alarmNo;
    u32_020894DC mask;

    mask = alarmBitMask;
    for (alarmNo = 0; alarmNo < 8 && mask != 0; alarmNo++, mask >>= 1) {
        if (mask & 1) {
            SNDi_IncAlarmId(alarmNo);
        }
    }
    PushCommand_impl(0xd, chBitMask, capBitMask, alarmBitMask, flags);
}


/*
 * sdk:      SND_SetupAlarm (snd_interface.o)
 */
void func_02089540(int alarmNo, u32_02089540 tick, u32_02089540 period, SNDAlarmHandler handler, void *arg)
{
    unsigned char id = SNDi_SetAlarmHandler(alarmNo, handler, arg);

    PushCommand_impl(0x12, (u32_02089540)alarmNo, tick, period, id);
}


/*
 * sdk:      SND_SetTrackMute (snd_interface.o)
 */
void func_02089580(int playerNo, u32_02089580 trackBitMask, int flag)
{
    PushCommand_impl(8, (u32_02089580)playerNo, trackBitMask, flag ? 3 : 0, 0);
}
