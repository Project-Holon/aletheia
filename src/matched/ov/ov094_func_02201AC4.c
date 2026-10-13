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
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 */
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;
typedef struct Res { void *owner; void *h; Ent e[7]; } Res;
extern void func_02201CA4(Res *r, int i);
struct Bank;
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02201AC4(Res *r)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (r->e[i].h8 != 0)
            func_02201CA4(r, i);
    }
    CLACT_DeleteUnit(r->h);
    func_020307B0(r);
}
