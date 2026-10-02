/*
 * function: func_0218BB0C
 * address:  0x0218BB0C
 * packet:   pkt_ov021_0218BB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204961C  0x0204961C  arm
 *   func_02049250  0x02049250  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 a, u32 b);
extern u32 func_0204961C(void *obj);
extern u8 *func_02049250(void *h, u32 n, u32 id);
extern void func_02049238(void *h);

void func_0218BB0C(u8 *s, u32 a, u32 n)
{
    void *h;
    u8 *r;

    h = func_020490F4(a, (u16)((*(u16 *)s & 0x7fff) | 0x8000));
    if (func_0204961C(h) <= n)
        n = 0;
    r = func_02049250(h, n, *(u16 *)s);
    *(u8 **)(s + 0x18) = r;
    *(u16 *)(s + 0x1ac) = (u32)r[2] >> 1;
    if (*(u16 *)(s + 0x1ac) > 0x190)
        *(u16 *)(s + 0x1ac) = 0x80;
    func_02049238(h);
}
