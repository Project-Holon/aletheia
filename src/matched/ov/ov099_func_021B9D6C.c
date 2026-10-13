/*
 * function: WIFICLUBACTOR_InitLayer
 * address:  0x021B9D6C
 * packet:   pkt_ov099_021B9D6C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C289C     0x021C289C  data  a1
 *   func_021C59F4  0x021C59F4  thumb  ov127
 */
typedef unsigned char u8;

typedef struct {
    u8 b[11];
} Tab;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad14[4];
    void *f18;
    char pad1c[0x598 - 0x1c];
    int f598;
} Obj;

extern Tab d_021C289C;
extern int func_021C59F4(void *a, void *b, Tab *t, int x);

void WIFICLUBACTOR_InitLayer(Obj *o, int x, int unused, int c)
{
    Tab t = d_021C289C;

    t.b[9] += (u8)c;
    o->f598 = func_021C59F4(o->f18, o->f10, &t, x);
}
