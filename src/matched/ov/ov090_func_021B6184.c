/*
 * function: func_021B6184
 * address:  0x021B6184
 * packet:   pkt_ov090_021B6184
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u8 b;
} Msg;

struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021B6184(u8 *p, u8 b, u16 a)
{
    Msg m;
    u32 h;

    h = (u32)func_020399A8();
    m.b = b;
    m.a = a;
    if (p[0x62] != 2)
        return 0;
    return func_0203D3F8(h, 0xff, 0x2d00, 4, (u32)(&m), 1, 0, 0);
}
