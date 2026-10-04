/*
 * function: func_021EED6C
 * address:  0x021EED6C
 * packet:   pkt_ov093_021EED6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_021BA020  0x021BA020  thumb  ov093
 *   func_0201F0F8  0x0201F0F8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D d_021F6398;
extern unsigned short func_021BA020(char *p, int i);
struct WordSet;
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);

void func_021EED6C(u32 a, u32 b, int c)
{
    func_0201F0F8((struct WordSet *)a, b, (u8)func_021BA020((void *)d_021F6398.f0, c));
}
