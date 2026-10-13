/*
 * function: WIFICLUBACTOR_IsFacingEntrance
 * address:  0x021B9BC4
 * packet:   pkt_ov099_021B9BC4
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
 *   func_021C4A54  0x021C4A54  thumb  ov127
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
extern Pos func_021C4A54(Pos p, int n);
typedef unsigned int   u32;
extern u32 func_021C4864(u8 *p, u16 x, u16 y);

int WIFICLUBACTOR_IsFacingEntrance(Work *w)
{
    Pos b;
    Pos d;
    int n;
    int r;

    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    d = func_021C4A54(b, n);
    r = func_021C4864(w->f588, d.x / 16, d.y / 16);
    if (n == 0 && r == 2)
        return 1;
    return 0;
}
