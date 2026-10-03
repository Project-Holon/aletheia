/*
 * function: func_021D8E24
 * address:  0x021D8E24
 * packet:   pkt_ov131_021D8E24
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9440  0x021D9440  thumb ov131
 *   func_021D9428  0x021D9428  thumb ov131
 *   func_02035C08  0x02035C08  arm
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

extern s16 func_021D9440(u8 *p, u32 target);
extern u32 func_021D9428(u8 *p, u32 target);
extern void func_02035C08(const void *p);

void func_021D8E24(void *unused, u8 *p)
{
    Rect r[11];
    u8 i;
    int v;

    for (i = 0; i < 10; i++) {
        v = func_021D9440(p, i);
        r[i].w = 8;
        r[i].h = 0x90;
        if (v < 0)
            r[i].x = 0;
        else if (v > 0xa8)
            r[i].x = 0xa8;
        else
            r[i].x = v;
        if (v + 0x18 < 0)
            r[i].y = 0;
        else if (v + 0x18 > 0xa8)
            r[i].y = 0xa8;
        else
            r[i].y = v + 0x18;
        if (r[i].x == 0 && r[i].y == 0)
            r[i].x = 0xfd;
        if (func_021D9428(p, i) == 0xffff)
            r[i].x = 0xfd;
    }
    r[10].x = 0xff;
    func_02035C08(r);
}
