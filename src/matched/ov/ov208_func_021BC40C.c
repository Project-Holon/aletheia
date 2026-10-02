/*
 * function: func_021BC40C
 * address: 0x021BC40C
 * packet: pkt_ov208_021BC40C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D064 0x0200D064 thumb
 * tail: two zero alignment bytes at 0x021BC446.
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Cur { void *blk; int f4; int f8; int fc; int f10; int f14; u16 *ids; u16 wrap; u16 pad; u16 *cur; };
extern u32 func_0200CA1C(void *a);
extern u32 func_0200D064(u32 a, u16 id);
void func_021BC40C(struct Ov208Cur *p)
{
    u16 start = *p->cur;
    u32 h = func_0200CA1C(p->blk);
    do {
        if (*p->cur == 0)
            *p->cur = p->wrap - 1;
        else
            *p->cur = *p->cur - 1;
        if (*p->cur == start)
            break;
    } while (func_0200D064(h, p->ids[*p->cur]) == 0);
}
