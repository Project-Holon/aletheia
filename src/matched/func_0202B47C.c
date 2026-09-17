/*
 * function: func_0202B47C
 * address:  0x0202B47C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object is idle, marks it active and resolves its current
 * record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B47C.c \
 *       --func func_0202B47C --addr 0x0202B47C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0202B49C(u8 *p, u32 id);

void func_0202B47C(u8 *p)
{
    if (*(u32 *)(p + 0xc) == 0) {
        *(u32 *)(p + 0xc) = 1;
        func_0202B49C(p, *(u16 *)(p + 0x10));
    }
}
