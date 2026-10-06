/*
 * function: func_0204EB68
 * address:  0x0204EB68
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020809A0   0x020809A0  arm
 *   func_0208074C   0x0208074C  arm
 *   func_0208068C   0x0208068C  arm
 *   func_0207D4B0   0x0207D4B0  arm
 *   func_0207D518   0x0207D518  arm
 *
 * The other arm of func_0204EA64's shutdown: it clears bit 15 of the
 * power-control halfword at 0x04000304, runs three SDK calls, writes
 * 0x80320010 to 0x04000064, runs the two channel teardowns and finally sets
 * bit 12 of 0x04001000 in place.
 *
 * Every one of those addresses is a cast constant, not a symbol: the pool
 * words carry no relocations.  The first and the fifth share a single pool
 * word, because 0x04000064 is 0x2A0 below 0x04000304 and the load's reach
 * covers it - that is the "pool base for a far field" sharing
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md),
 * and writing the second address as its own literal costs an extra pool word
 * and four bytes.
 *
 * Both read-modify-writes are one expression each, which is why there is
 * exactly one load and one store per register despite both being volatile.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020809A0(void);
extern void func_0208074C(int sub_obj);
extern void func_0208068C(u32 v);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D518(u32 v);

void func_0204EB68(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = (u16)(v & ~0x8000);
    func_020809A0();
    func_0208074C(8);
    func_0208068C(4);
    *(volatile u32 *)0x04000064 = 0x80320010;
    func_0207D4B0(1, 0, 1);
    func_0207D518(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x1000;
}
