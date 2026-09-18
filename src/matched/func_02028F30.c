/*
 * function: func_02028F30
 * address:  0x02028F30
 * packet:   pkt_02028F30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02028F48.c is now a manifest entry (matched class)
 *
 * Node kind 2 setter: guarded by func_02028FD0, then the kind tag and
 * this kind's payload members are written.
 *
 * symbols:
 *   func_02028FD0  0x02028FD0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028F30.c \
 *       --func func_02028F30 --addr 0x02028F30 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02028FD0(u8 *p, u32 kind);

void func_02028F30(u8 *p, u32 a)
{
    if (func_02028FD0(p, 2) != 0) {
        *(u32 *)(p + 0x1c) = (u32)2;
        *(u16 *)(p + 0x1a) = (u16)a;
    }
}
