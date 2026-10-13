/*
 * function: TR_AI_CmdLoadPokeValue12
 * address:  0x02189434
 * packet:   pkt_ov096_02189434
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13660.h"

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
extern int func_021D59B4(u8 *p, int k);

int TR_AI_CmdLoadPokeValue12(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, t);
    t = func_021D59B4(TR_AI_GetPoke((u8 *)b, s), 0x12);
    ((struct Obj13660 *)b)->f38 = t;
    return ((struct Obj13660 *)b)->fC4;
}
