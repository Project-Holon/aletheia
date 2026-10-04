/*
 * function: func_021F0378
 * address:  0x021F0378
 * packet:   pkt_ov031_021F0378
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both copy pointers are u16 element offsets (+0x2A0), not byte offsets:
 * `(u16 *)(out + 0xC) + 0x2A0` keeps the +0xC add apart, so the 0x540 byte
 * offset is built as `lsls rN, r7, #6` off the register holding 0x15
 * instead of folding with 0xC into a pooled 0x54C.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_020307B0(void *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049238(void *h);

void func_021F0378(u32 *p)
{
    void *h;
    u32 r;
    u16 *pal;
    void *res;
    u8 *out;
    int i;

    h = func_020490F4(0x53, 0x15);
    r = func_0203FA08(5, 0x80, 1);
    p[1] = r;
    func_02049658(h, 0x1C, 5, r, 0x80, 0, 0x15);
    pal = (u16 *)func_0204162C(5);
    res = func_02049EF4(h, 0x1D, 0, (void **)&out, 0x15);
    func_02082D44((u16 *)(out + 0xC) + 0x2A0, pal + 0x2A0, 0xC0);
    func_020307B0(res);
    for (i = 0; i < 0x60; i++)
        pal[0x2A0 + i] = (pal[0x2A0 + i] & 0xFFF) + r + 0xD000;
    func_02049B68(h, 0x1B, 4, 0x1A0, 0x20, 0x15);
    func_02049238(h);
}
