/*
 * function: func_021DF0C4
 * address:  0x021DF0C4
 * packet:   pkt_ov093_021DF0C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wave B2 lane 01): DIFF, only the frame. The image has push {r3-r7,lr}; sub sp,#8 (two stack words, [sp] = a, [sp+4] never touched) and mwcc here emits push {r3-r7,lr} with the spill in the r3 slot and no sub, so everything after +0x02 is 2 bytes early. Tried: unused scalar and array locals (dead code is dropped before layout), shared p+0x14 pointer, early/late a spill spellings. Open: what creates the second frame word.
 * symbols:
 *   func_021DF0C4  0x021DF0C4  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
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
