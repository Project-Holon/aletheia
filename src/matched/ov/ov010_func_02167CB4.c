/*
 * function: func_02167CB4
 * address:  0x02167CB4
 * packet:   pkt_ov010_02167CB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x1C];
} Obj;

extern int func_0200FB24(Obj *o);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);

int func_02167CB4(Obj *o)
{
    u16 h;

    if (func_0200FB24(o) != 0)
        return 1;
    h = o->h12;
    if (h >= 0x2C08)
        return 1;
    if (func_0203D3A8(func_020399A8(), h, 0x46, o->b668) == 1)
        return 1;
    return 0;
}
