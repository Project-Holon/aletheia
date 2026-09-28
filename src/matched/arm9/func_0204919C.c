/*
 * function: func_0204919C
 * address:  0x0204919C
 * packet:   pkt_0204919C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 *
 * Walk the reader past its own header.  A halfword count at +0x4c is read
 * first, then skipped by, then a six-byte record is read into a stack buffer
 * whose first word is added to that count and whose third halfword lands in
 * the object at +0x4e; the running total then skips the following four-byte
 * field, which is read into the second half of the same buffer and added to
 * the total for the final offset at +0x48.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204919C.c \
 *       --func func_0204919C --addr 0x0204919C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02078B44(void *p, u32 off, u32 mode);
extern void func_02078B70(void *p, void *dst, u32 n);

void func_0204919C(u8 *p)
{
    u8 buf[12];
    u32 off;

    *(u16 *)(p + 0x4c) = 0;
    func_02078B44(p, 0xc, 0);
    func_02078B70(p, p + 0x4c, 2);
    func_02078B44(p, *(u16 *)(p + 0x4c) + 4, 0);
    func_02078B70(p, buf, 6);
    *(u16 *)(p + 0x4e) = *(u16 *)(buf + 4);
    off = *(u16 *)(p + 0x4c) + *(u32 *)buf;
    func_02078B44(p, off + 4, 0);
    func_02078B70(p, buf + 8, 4);
    *(u32 *)(p + 0x48) = off + *(u32 *)(buf + 8);
}
