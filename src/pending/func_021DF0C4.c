/*
 * function: func_021DF0C4
 * address:  0x021DF0C4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH (parked)
 *
 * BLOCKER: the image opens with push {r3,r4,r5,r6,r7,lr}; sub sp,#8; str r0,[sp] -- an 8-byte frame holding one spilled word.  mwcc here spills a into the pushed r3 slot with no frame, so every instruction after +0x02 is 2 bytes early.  Function is 4 bytes short at 120 of 124 and otherwise byte-identical.  Probes: void* a, int a -- same.  See docs/notes/pkt_021B75A8.c.txt.
 *
 * symbols:
 *   func_021DF0C4   0x021DF0C4  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021E899C   0x021E899C  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Three func_021D775C gates (4, 0x1d == 7, and the (u8) of 3 not 0x1f), then
 * record #0xc carries the key, the constant 7, func_021E899C(c) and a flag,
 * plus the two-string tail seeded with func_021D70A8(a).  The first argument
 * is spilled to the stack because all six saved registers are taken.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C88A4(int a, int k, int b);
int func_021E899C(int a);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);
int func_021D70A8(void *a);
void func_021C88C8(int a, void *p);

void func_021DF0C4(void *a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x1d) != 7)
        return;
    k = (u8)func_021D775C(3);
    if (k == 0x1f)
        return;
    p = func_021C88A4(b, 0xc, c);
    *(u8 *)(p + 0xf) = k;
    *(u32 *)(p + 4) = 7;
    *(u32 *)(p + 8) = func_021E899C(c);
    *(u8 *)(p + 0xd) = 1;
    func_021C8838(p + 0x14, 2, 0x14a);
    func_021C8860(p + 0x14, k);
    func_021C8860(p + 0x14, func_021D70A8(a));
    func_021C88C8(b, p);
}
