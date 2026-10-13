/*
 * function: TR_AI_CompareSick
 * address:  0x021888BC
 * packet:   pkt_ov096_021888BC
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);

int TR_AI_CompareSick(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, t1);
    r = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)TR_AI_GetPoke((u8 *)b, s), t2);
    return TR_AI_Compare((u8 *)a, c, r, 1, t3);
}
