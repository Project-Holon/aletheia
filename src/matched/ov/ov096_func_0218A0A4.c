/*
 * function: TR_AI_CompareStat
 * address:  0x0218A0A4
 * packet:   pkt_ov096_0218A0A4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int TR_AI_Compare(u8 *, int, int, int, int);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

int TR_AI_CompareStat(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    u8 s;
    t = VM_GetU32(a);
    n = VM_GetU32(a);
    s = TR_AI_GetPosition(b, t);
    BTL_POKEPARAM_GetValue(TR_AI_GetPoke(b, s), 8);
    return TR_AI_Compare((u8 *)a, c, s, BTL_POKEPARAM_GetValue(TR_AI_GetPoke(b, s), 10), n);
}
