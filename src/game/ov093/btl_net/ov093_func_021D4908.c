/*
 * function: func_021D4908
 * address:  0x021D4908
 * packet:   pkt_ov093_021D4908
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_021D4A0C  0x021D4A0C  thumb ov093
 *   func_021D4A64  0x021D4A64  thumb ov093
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
};

extern struct S *d_021F3B88;
extern void *func_021D4A0C(void *a, u32 heap);
extern void func_021D4A64(void *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021D4908(void *a)
{
    void *o;
    u32 r;

    o = func_021D4A0C(a, (u16)((d_021F3B88->f04 & 0x7fff) | 0x8000));
    r = func_0203D3F8(d_021F3B88->f00, 0xff, 0x106, 0x6c, (u32)o, 0, 1, 0);
    func_021D4A64(o);
    return r;
}
