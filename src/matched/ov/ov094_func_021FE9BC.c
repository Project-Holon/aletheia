/*
 * function: func_021FE9BC
 * address:  0x021FE9BC
 * packet:   pkt_ov094_021FE9BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_ApplyLoadHandlers  0x02051394  arm
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef unsigned short u16;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    void *obj;              /* 0x04 */
} Ctx;

typedef unsigned int   u32;
extern void PARTICLE_ApplyLoadHandlers(u32 *p);
extern void func_021F89BC(void *h);

void func_021FE9BC(void *h, Ctx *c)
{
    u16 line = *(volatile u16 *)0x04000006;

    if (line >= 0xc0 && line <= 0xc8) {
        PARTICLE_ApplyLoadHandlers(c->obj);
        *c->reg &= ~0x10000u;
        func_021F89BC(h);
    }
}
