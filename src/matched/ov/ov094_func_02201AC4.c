/*
 * function: func_02201AC4
 * address:  0x02201AC4
 * packet:   pkt_ov094_02201AC4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02201CA4  0x02201CA4  thumb  ov094
 */
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;
typedef struct Res { void *owner; void *h; Ent e[7]; } Res;
extern void func_02201CA4(Res *r, int i);
extern void func_0204B1CC(void *);
extern void func_020307B0(void *);

void func_02201AC4(Res *r)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (r->e[i].h8 != 0)
            func_02201CA4(r, i);
    }
    func_0204B1CC(r->h);
    func_020307B0(r);
}
