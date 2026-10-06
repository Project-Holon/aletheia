/*
 * function: func_021FE8AC
 * address:  0x021FE8AC
 * packet:   pkt_ov094_021FE8AC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 */
typedef struct {
    unsigned int *reg;      /* 0x00 */
    char pad04[0x20];
    int k24;                /* 0x24 */
} Ctx;

typedef unsigned int   u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_021FE8AC(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->k24 == 0)
        *(volatile unsigned int *)0x04000000 &= ~0xE000u;
    *c->reg &= ~0x100u;
}
