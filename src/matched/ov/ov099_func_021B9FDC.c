/*
 * function: WIFICLUBACTOR_IsCursorOnExit
 * address:  0x021B9FDC
 * packet:   pkt_ov099_021B9FDC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */
typedef unsigned short u16;
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
typedef unsigned char  u8;
extern int func_021C49A4(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern u32 func_021C4864(u8 *p, u16 x, u16 y);

int WIFICLUBACTOR_IsCursorOnExit(Work *w)
{
    Pos b;
    int n;

    if (w->f570 == 0)
        return 0;
    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    if (func_021C4864(w->f588, b.x / 16, b.y / 16) == 15 && n == 1)
        return 1;
    return 0;
}
