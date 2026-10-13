/*
 * file:     field_map_change.c
 * unit:     yes
 * function: func_021643AC, func_021643E8, func_02164454, func_0216445C, func_02164464, func_0216446C, func_02164474, func_0216447C
 * address:  0x021643AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Map change helpers (guess) and the thunks that follow them.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0215E428 0x0215E428 thumb ov010
 *   func_0215E3A0 0x0215E3A0 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_0201433C 0x0201433C thumb
 *   func_0215E33C 0x0215E33C thumb ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02013F6C  0x02013F6C  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   func_0215E364  0x0215E364  thumb ov010
 *   func_02164728  0x02164728  thumb ov010
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0215E34C  0x0215E34C  thumb  ov010
 */

struct GameData;
struct SaveControl;
struct Situation;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

typedef unsigned int u32;

extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern void *func_0200D418(struct SaveControl *saveControl);
extern u16 func_02188C9C(u8 *p);
extern void func_0215E428(int a0, int a1);
extern void func_0215E3A0(void *);
extern void *func_0201296C(const struct GameData *gameData);
extern void func_0201433C(char *, int);
extern int func_0215E33C(int a0);
extern MmdlSys *func_02012B38(const struct GameData *gameData);
extern u32 func_02013F6C(u32 id);
extern void FIELD_STATUS_SetFlashActive(MmdlSys *mmdlSys, u8 value);
extern void func_0215E364(void *object);
extern void  func_02164728(void *a);
extern u32 func_02013FFC(u32 id);
extern struct Situation *func_02008854(struct SaveControl *saveControl);
extern void func_02008988(struct Situation *situation, u16 value);
extern int func_0215E34C(int a0);
void func_021643AC(struct GameData *gameData, void *zoneHeader);
void func_021643E8(struct GameData *gameData, u32 zoneId);
int func_02164454(int object, int unused);
int func_0216445C(int object, int unused);
int func_02164464(int object, int unused);
int func_0216446C(int object, int unused);
void func_02164474(void *object, int unused);
void func_0216447C(int system, u16 zoneId);

/*
 * interface: func_02188C9C reads the u16 field at +0xD8;
 * func_0215E428 forwards its second argument to func_0200D45C,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy ov010_func_021643E8 declaration uses a pointer for this ID.
 */
void func_021643AC(struct GameData *gameData, void *zoneHeader) { void *saveWork=func_0200D418(func_02012EBC(gameData)); func_0215E428((int)saveWork,func_02188C9C((u8 *)zoneHeader)); func_0215E3A0(gameData); func_0201433C((char *)func_0201296C(gameData),0x964); func_0215E33C((int)zoneHeader); }

/*
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * Addresses are Black-image addresses.
 */
void func_021643E8(struct GameData *gameData, u32 zoneId)
{
    MmdlSys *mmdlSys = func_02012B38(gameData);
    void *eventWork;
    if ((func_02013F6C(zoneId) & 3) == 0) {
        FIELD_STATUS_SetFlashActive(mmdlSys, 0);
    }
    func_0215E428((int)func_0200D418(func_02012EBC(gameData)), (int)zoneId);
    func_0215E364(gameData);
    eventWork = func_0201296C(gameData);
    func_0201433C(eventWork, 0x964);
    func_02164728(eventWork);
    if (func_02013FFC(zoneId) == 0) {
        func_02008988(func_02008854(func_02012EBC(gameData)), 0);
    }
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 1 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164454(int object, int unused)
{
    return func_0215E34C(object);
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 3 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216445C(int object, int unused)
{
    return func_0215E34C(object);
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 2 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164464(int object, int unused)
{
    return func_0215E34C(object);
}

/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216446C(int object, int unused)
{
    return func_0215E34C(object);
}

/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_02183DE4.
 */
void func_02164474(void *object, int unused)
{
    func_0215E364(object);
}

/*
 * Empty function after the veneer run; the only Thumb code at this address
 * in any overlay window, called from ov021 func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_0216447C(int system, u16 zoneId)
{
}
