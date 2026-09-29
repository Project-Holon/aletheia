/*
 * function: func_021C7684
 * address:  0x021C7684
 * packet:   pkt_ov021_021C7684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7730  0x021C7730  thumb  ov021
 *   _fflt          0x0209BDBC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

extern u16 func_02188C84(u32 a);
extern void *func_021C6C70(u32 h, int size, void *fn);
extern Fx *func_021C6CCC(void *o);
extern void func_021C7730(void);

void *func_021C7684(u32 a, u32 b, int c, int d)
{
    void *o;
    Fx *p;

    o = func_021C6C70(func_02188C84(a), 0x14, (void *)func_021C7730);
    p = func_021C6CCC(o);
    p->st = 0;
    p->w4 = a;
    p->h8 = 0;
    p->ha = c;
    p->fc = (float)d;
    p->w10 = b;
    return o;
}
