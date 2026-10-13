/*
 * function: COMM_ENTRY_MENU_AddMember
 * address:  0x021CD624
 * packet:   pkt_ov021_021CD624
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: MYSTATUS_Copy (arm9 unlabelled thumb tail-call stub, the integrator's:
 * ldr r3,=0x02082D44; movs r2,#0x20; bx r3) has no witness outside the range.
 * Verified C for the leaf: void MYSTATUS_Copy(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * (verified EXACT, 12 bytes, thumb, with func_02082D44 0x02082D44 arm.)
 *
 * symbols:
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_02082D44  0x02082D44  arm
 *   COMM_ENTRY_MENU_ClearPendingBits  0x021CEA84  thumb  ov021
 *   COMM_ENTRY_MENU_QueueSend  0x021CEAB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02098.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MYSTATUS_Copy(void *src, void *dst);
extern void func_02082D44(void *src, void *dst, int n);
extern void COMM_ENTRY_MENU_ClearPendingBits(u8 *p, int n);
extern void COMM_ENTRY_MENU_QueueSend(u8 *p);

void COMM_ENTRY_MENU_AddMember(u8 *p, int i, u32 a, u32 b, void *c)
{
    u8 *e;

    e = p + 0x50 + i * 0x2c;
    MYSTATUS_Copy((void *)a, e);
    e[0x20] = 1;
    e[0x21] = b;
    func_02082D44(c, e + 0x23, 6);
    COMM_ENTRY_MENU_ClearPendingBits(p, (u8)i);
    COMM_ENTRY_MENU_QueueSend(p);
    if (((struct Obj02098 *)p)->f48C) {
        (*(void (**)(u32, u32, void *))(p + 0x48c))(((struct Obj02098 *)p)->f488, a, c);
    }
}
