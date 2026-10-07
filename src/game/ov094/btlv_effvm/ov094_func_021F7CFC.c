/*
 * function: func_021F7CFC
 * address:  0x021F7CFC
 * packet:   pkt_ov094_021F7CFC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F9844  0x021F9844  thumb  ov094
 *   func_021F94F8  0x021F94F8  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0, b1, b2, b3;
    int f4;
    int f8;
    u16 fc;
} Arg;

typedef struct {
    char pad[0x188];
    void *h188;
    char pad2[0x1e8 - 0x18c];
    int f1e8;
} Work;

extern Work *d_0220AF20;

extern void func_021F9844(Arg *a);
extern void func_021F94F8(void *h, int a, u32 b, u16 c, Arg *d);

void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e)
{
    Arg l;

    func_021F9844(&l);
    l.b3 = c;
    l.f8 = e;
    l.f4 = d;
    l.fc = b;
    func_021F94F8(d_0220AF20->h188, 0, a, 0x23a, &l);
    d_0220AF20->f1e8 = 1;
}
