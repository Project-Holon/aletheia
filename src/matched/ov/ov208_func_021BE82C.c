/*
 * function: ov208_func_021BE82C
 * address:  0x021BE82C
 * packet:   pkt_ov208_021BE82C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE9C8        0x021BE9C8  thumb
 *   ov208_func_021BE920  0x021BE920  thumb
 */

typedef unsigned int u32;

struct Ov208Icon {
    u32 pad0[3];
    int fc;
};

extern void func_021BE9C8(void);
extern void ov208_func_021BE920(struct Ov208Icon *p);

void ov208_func_021BE82C(struct Ov208Icon *p, int kind)
{
    p->fc = kind;
    func_021BE9C8();
    ov208_func_021BE920(p);
}
