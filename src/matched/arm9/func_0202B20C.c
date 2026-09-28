/*
 * function: func_0202B20C
 * address:  0x0202B20C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object is idle, marks it started, clears its +4 value and
 * refreshes it through func_0202B2BC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B20C.c \
 *       --func func_0202B20C --addr 0x0202B20C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202B2BC(u8 *p);

void func_0202B20C(u8 *p)
{
    if (*(u32 *)p == 0) {
        *(u32 *)p = 1;
        *(u32 *)(p + 4) = 0;
        func_0202B2BC(p);
    }
}
