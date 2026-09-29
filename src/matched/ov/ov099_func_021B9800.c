/*
 * function: func_021B9800
 * address:  0x021B9800
 * packet:   pkt_ov099_021B9800
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work;

extern Pos func_021C4AC4(void *v);
extern int func_021C4864(void *o, u16 x, u16 y);

void func_021B9800(Work *w)
{
    Pos b = func_021C4AC4(*w->f570);

    func_021C4864(w->f588, b.x / 16, b.y / 16);
}
