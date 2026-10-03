/*
 * function: func_021C6380
 * address:  0x021C6380
 * packet:   pkt_ov111_021C6380
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021C8768     0x021C8768  data  a2
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern const u16 d_021C8768[];

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work;

void func_021C6380(void *a, Work *p, int x, int y, void *s, int idx)
{
    func_0201C7D0(func_02045770(a), x, y, s, p->f31FC, d_021C8768[idx]);
}
