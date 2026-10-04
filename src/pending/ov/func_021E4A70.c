/*
 * function: func_021E4A70
 * address:  0x021E4A70
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-04): verdict is DIFF since the prototype cleanup (65e037443); it was MATCH (parked) before. Recheck the callee prototypes first.
 *
 * BLOCKER: 73 bytes: the -2 stored at +0xc is materialised in the image as subs r0,r0,#3 from the 1 already in r0 (and spilled to [sp]); mwcc folds the constant to movs r0,#0xfe and does not spill.  Everything else after that point is 2 bytes early.
 *
 * symbols:
 *   func_021E4A70   0x021E4A70  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C83CC   0x021C83CC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(3); the (u8) of func_021D775C(6) and func_021C83CC(b)
 * go into two records #0xe -- the first with a 1 in its +4 word and the 0xfe
 * byte at +0xc, the second with 3 and the same byte re-read from the stack --
 * then a third record #0x13 carries c in its +4 byte.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_021C83CC(int a);
void *func_021C88A4(int a, int k, int b);
void func_021C88C8(int a, void *p);

void func_021E4A70(void *a, int b, int c)
{
    u8 k;
    int v;
    int w;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    v = func_021C83CC(b);
    p = func_021C88A4(b, 0xe, c);
    *(u8 *)(p + 0xf) = 1;
    *(u8 *)(p + 0x10) = k;
    *(u32 *)(p + 4) = 1;
    w = 1 - 3;
    *(u8 *)(p + 0xc) = w;
    *(u32 *)(p + 8) = v;
    *(u8 *)(p + 0xe) = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 0xe, c);
    *(u8 *)(p + 0xf) = 1;
    *(u8 *)(p + 0x10) = k;
    *(u32 *)(p + 4) = 3;
    *(u8 *)(p + 0xc) = w;
    *(u32 *)(p + 8) = v;
    *(u8 *)(p + 0xe) = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 0x13, c);
    *(u8 *)(p + 4) = c;
    func_021C88C8(b, p);
}
