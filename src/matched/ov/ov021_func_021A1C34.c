/*
 * function: func_021A1C34
 * address:  0x021A1C34
 * packet:   pkt_ov021_021A1C34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A1D78  0x021A1D78  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 pad0;
    u32 pad4;
    u16 result;
    u16 busy;
    u16 cur;
    u16 next;
    u32 flag;
    u16 queued;
} Obj021A1C34;

int func_021A1D78(u16 a, u16 b);

int func_021A1C34(Obj021A1C34 *p, u16 x)
{
    if (p->busy != 0) {
        p->queued = x;
        return 0;
    }
    if (p->cur == x && x != 0)
        return 0;
    p->next = x;
    p->flag = 1;
    p->result = func_021A1D78(p->cur, p->next);
    p->busy = 1;
    return 1;
}
