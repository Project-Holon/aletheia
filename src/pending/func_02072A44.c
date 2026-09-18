/*
 * function: func_02072A44
 * address:  0x2072A44
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x0214DECC is named by one pool word, its own (literal class)
 * symbols:
 *   g_0214DECC       0x214DECC  data
 *
 * Registers a slot: probes func_0207292C with the slot's bit mask, and on
 *  * success stores the index at +0 and clears +8 of a 0x14-byte entry.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct P { u32 a; u32 b; u32 c; u32 d; u32 e; };
extern char g_0214DECC[];
extern int func_0207292C(u32);

struct P *func_02072A44(int x)
{
    struct P *p;

    if (func_0207292C(1 << x) == 0) return 0;
    p = (struct P *)(g_0214DECC + x * 0x14);
    p->a = x;
    p->c = 0;
    return p;
}
