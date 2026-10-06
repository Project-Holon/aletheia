/*
 * function: func_021C385C
 * address:  0x021C385C
 * packet:   pkt_ov021_021C385C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Step counter: every 16 steps rolls for an egg against compatibility (EXACT*: pad).
 *
 * symbols:
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_021C34C4  0x021C34C4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    void *box;
    u16 steps;
} S;

extern int func_0200BCB8(void *e);
extern u32 func_02005728(u32 v);
extern u8 func_021C34C4(void **p);

int func_021C385C(S *p)
{
    u16 old = p->steps;

    p->steps = old + 0x10;
    if (old > 0xFF) {
        p->steps = 0;
        if (func_0200BCB8(p->box) >= 2) {
            u32 r = func_02005728(0x640);
            if (r < func_021C34C4((void **)p))
                return 1;
        }
    }
    return 0;
}
