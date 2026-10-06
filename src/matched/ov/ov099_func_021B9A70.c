/*
 * function: func_021B9A70
 * address:  0x021B9A70
 * packet:   pkt_ov099_021B9A70
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C5864  0x021C5864  thumb  ov127
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021BA594  0x021BA594  thumb
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    unsigned short fc;
    unsigned short fe;
    int f10;
    int f14;
    int f18;
} Ent;

typedef unsigned char  u8;
extern int func_021C49A4(u8 *p, unsigned int i);
extern void func_021C57D8(u8 *p, int v);
extern void func_021C5864(u8 *p, int b);
extern void func_021C5814(void *p, Pos pos);
extern void func_021BA594(char *p, int a, int b, int c);

void func_021B9A70(void *o, Ent *e, int n)
{
    Pos s;

    e->f14 = e->f10;
    e->f10 = 0x021BA591;
    e->fe = e->fc;
    e->fc = 5;
    func_021BA594(o, 0, n, func_021C49A4(e->f0, 4));
    func_021C57D8(e->f4, 0);
    func_021C5864(e->f4, n);
    s.x = func_021C49A4(e->f0, 0);
    s.y = func_021C49A4(e->f0, 1);
    func_021C5814(e->f4, s);
}
