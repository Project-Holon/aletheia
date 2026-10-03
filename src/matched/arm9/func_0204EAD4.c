/*
 * function: func_0204EAD4
 * address:  0x0204EAD4
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020809B4   0x020809B4  arm
 *   func_020806B0   0x020806B0  arm
 *   func_0208068C   0x0208068C  arm
 *   func_0207D4B0   0x0207D4B0  arm
 *   func_0207D518   0x0207D518  arm
 *
 * The mirror of func_0204EB68, and func_0204EA64's other shutdown arm: it
 * *sets* bit 15 of the power-control halfword at 0x04000304 instead of
 * clearing it, runs the complementary SDK calls, and leaves 0x04001000 and
 * 0x0400100c in the "on" state.
 *
 * Three things here are spelling rather than codegen.  The u32 clear is
 * `& ~0x1f00`, which is encodable and becomes `bic`; the u16 mask at the very
 * end is written `& 0xffbf` rather than `& ~0x40` because 0xffbf is not an ARM
 * immediate and therefore costs a pool word, which is what the image has -
 * `~0x40` would have been a `bic #0x40` and four bytes shorter.  And the two
 * last statements each read 0x0400100c afresh, because the first one's store
 * makes the second's read a genuinely new volatile load.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020809B4(void);
extern void func_020806B0(int sub_bg);
extern void func_0208068C(u32 v);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D518(u32 v);

void func_0204EAD4(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = v | 0x8000;
    func_020809B4();
    func_020806B0(4);
    func_0208068C(8);
    *(volatile u32 *)0x04000064 = 0x80330010;
    func_0207D4B0(1, 0, 1);
    func_0207D518(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x400;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0x84 | 0x4000;
    *(volatile u16 *)0x0400100c = *(volatile u16 *)0x0400100c & 0xffbf;
}
