/*
 * function: TR_AI_CmdIfFieldSlotInUse
 * address:  0x0218979C
 * packet:   pkt_ov096_0218979C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   BTL_FIELD_IsStaticSlotInUse  0x021EF948  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj21971.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTL_FIELD_IsStaticSlotInUse(int);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);

int TR_AI_CmdIfFieldSlotInUse(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    r = VM_GetU32(a);
    r2 = VM_GetU32(a);
    t = BTL_FIELD_IsStaticSlotInUse(r);
    TR_AI_Compare((u8 *)a, 2, t, 1, r2);
    return ((struct Obj21971 *)b)->fC4;
}
