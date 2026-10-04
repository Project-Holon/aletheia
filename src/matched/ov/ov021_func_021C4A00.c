/*
 * function: func_021C4A00
 * address:  0x021C4A00
 * packet:   pkt_ov021_021C4A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets flag 1 on the field object (tail call).
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 obj;
    u16 id;
} S;

struct BbActSys;
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);

void func_021C4A00(S *s)
{
    func_02050278((struct BbActSys *)s->obj, s->id, 1);
}
