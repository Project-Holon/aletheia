/*
 * unit:     no
 * address:  0x02020DEC
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02020DEC
 *
 * symbols:
 *   func_0200575C  0x0200575C  thumb
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020DEC.c \
 *       --func func_02020DEC --addr 0x02020DEC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void *func_0200575C(u32 x);
extern void  func_020788AC(void *p);
extern void  func_02078C18(void *p, void *q);

void func_02020DEC(void *p, u32 x)
{
    void *q;

    q = func_0200575C(x);
    func_020788AC(p);
    func_02078C18(p, q);
}
