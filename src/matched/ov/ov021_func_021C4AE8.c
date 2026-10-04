/*
 * function: func_021C4AE8
 * address:  0x021C4AE8
 * packet:   pkt_ov021_021C4AE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S;

struct BbActSys;
extern void func_02050468(struct BbActSys *o, u32 first, u32 count);

void func_021C4AE8(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}
