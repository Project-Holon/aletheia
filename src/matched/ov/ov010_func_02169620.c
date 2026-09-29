/*
 * function: func_02169620
 * address:  0x02169620
 * packet:   pkt_ov010_02169620
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020495F4  0x020495F4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020495F4(u32 h, u32 n, u32 dst);

typedef struct S {
    u8 pad0[0x10];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S;

int func_02169620(S *p)
{
    u32 base;
    u32 cur;
    u32 len;
    u32 tot;
    u32 rem;

    base = p->base;
    cur = p->cur;
    len = p->len;
    tot = p->tot;
    if (tot <= len)
        return 0;
    rem = tot - len;
    if (rem > p->n) {
        func_020495F4(p->h, p->n, base + cur);
        p->cur = p->cur + p->n;
        p->len = p->len + p->n;
        return 1;
    }
    func_020495F4(p->h, rem, base + cur);
    p->cur = p->cur + rem;
    return 0;
}
