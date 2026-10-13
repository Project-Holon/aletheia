/*
 * function: TR_AI_ComparePokeValue
 * address:  0x02189100
 * packet:   pkt_ov096_02189100
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
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern int func_021D59B4(u8 *p, int k);

int TR_AI_ComparePokeValue(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int t3;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    r = func_021D59B4(TR_AI_GetPoke((u8 *)b, TR_AI_GetPosition((u8 *)b, t0)), t1);
    return TR_AI_Compare((u8 *)a, c, r, t2, t3);
}
