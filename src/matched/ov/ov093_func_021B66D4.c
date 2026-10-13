/*
 * unit: yes
 * function: BTL_MAIN_StartSetupTask, BTL_MAIN_StartCleanupTask
 * address: 0x021B66D4
 * size: 324
 * packet: pkt_ov093_021B66D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initializer stores first, second, object, state; object-first reallocates all tails.
 * symbols:
 *   BTL_MAIN_TaskSetupSingle 0x021B6AAC thumb ov093
 *   BTL_MAIN_TaskSetupDouble 0x021B6C5C thumb ov093
 *   BTL_MAIN_TaskSetupMulti 0x021B6DD0 thumb ov093
 *   BTL_MAIN_TaskSetupTriple 0x021B7050 thumb ov093
 *   BTL_MAIN_TaskSetupRotation 0x021B71D4 thumb ov093
 *   BTL_MAIN_TaskCommSingle 0x021B734C thumb ov093
 *   BTL_MAIN_TaskCommDouble 0x021B73C4 thumb ov093
 *   BTL_MAIN_RunSetupSeqKind3 0x021B7518 thumb ov093
 *   BTL_MAIN_RunSetupSeqKind1 0x021B7488 thumb ov093
 *   BTL_MAIN_TaskCleanup 0x021B6C08 thumb ov093
 */
#include "../include/Obj07741.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void (*first)(void); u32 second; u8 *object; u32 state; } Callback;
extern void BTL_MAIN_TaskSetupSingle(void), BTL_MAIN_TaskSetupDouble(void), BTL_MAIN_TaskSetupMulti(void), BTL_MAIN_TaskSetupTriple(void);
extern void BTL_MAIN_TaskSetupRotation(void), BTL_MAIN_TaskCommSingle(void), BTL_MAIN_TaskCommDouble(void), BTL_MAIN_RunSetupSeqKind3(void), BTL_MAIN_RunSetupSeqKind1(void), BTL_MAIN_TaskCleanup(void);
static inline void init(Callback *a, u8 *p, void (*f)(void))
{
    a->first = f; a->second = 0; a->object = p; a->state = 0;
}
#define INIT(f) init(a, p, f)
void BTL_MAIN_StartSetupTask(Callback *a, u8 *p, u8 *q)
{
    u32 i;
    for (i = 0; i < 6; i++) p[0x428 + i] = 4;
    if (!q[0x20]) {
        switch (((struct Obj07741 *)q)->f4) {
        case 0: INIT(BTL_MAIN_TaskSetupSingle); return;
        case 1:
            if (!q[0x22]) { INIT(BTL_MAIN_TaskSetupDouble); return; }
            else { INIT(BTL_MAIN_TaskSetupMulti); return; }
        case 2: INIT(BTL_MAIN_TaskSetupTriple); return;
        case 3: INIT(BTL_MAIN_TaskSetupRotation); return;
        default: INIT(BTL_MAIN_TaskSetupSingle); return;
        }
    } else {
        switch (((struct Obj07741 *)q)->f4) {
        case 0: INIT(BTL_MAIN_TaskCommSingle); return;
        case 1: INIT(BTL_MAIN_TaskCommDouble); return;
        case 2: INIT(BTL_MAIN_RunSetupSeqKind3); return;
        case 3: INIT(BTL_MAIN_RunSetupSeqKind1); return;
        default: INIT(BTL_MAIN_TaskSetupSingle); return;
        }
    }
}
void BTL_MAIN_StartCleanupTask(Callback *a, u8 *p, u8 *q)
{
    INIT(BTL_MAIN_TaskCleanup);
}
