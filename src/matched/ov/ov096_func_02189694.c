/*
 * function: TR_AI_CmdLoadHasType
 * address:  0x02189694
 * packet:   pkt_ov096_02189694
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTLV_CORE_GetHighByte  0x021E8CFC  thumb  ov093
 *   BTLV_CORE_GetLowByte  0x021E8D04  thumb  ov093
 */
#include "../include/Obj13664.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern u8 BTLV_CORE_GetHighByte(int);
extern int BTLV_CORE_GetLowByte(int x);

int TR_AI_CmdLoadHasType(struct Cursor *a, int b) {
    int r;
    u8 k;
    int t;
    int p;
    u8 s;
    r = VM_GetU32(a);
    k = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, r);
    p = BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke((u8 *)b, s));
    if (k == BTLV_CORE_GetHighByte(p) || k == BTLV_CORE_GetLowByte(p)) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13664 *)b)->f38 = t;
    return ((struct Obj13664 *)b)->fC4;
}
