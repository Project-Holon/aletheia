/*
 * function: func_0218BDD8
 * address:  0x0218BDD8
 * packet:   pkt_ov021_0218BDD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0218BFB4  0x0218BFB4  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data  ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_0218BFB4(u8 *s, u8 *a, u8 *b);
extern char d_021DD9CC[];

void func_0218BDD8(u8 *s, u32 *out)
{
    u32 n;
    u32 i;

    n = *(u16 *)(s + 0x1ac);
    if (n != 0) {
        out[1] = n;
        out[0] = (u32)func_02030734(*(u16 *)s, n << 3, 1, d_021DD9CC, 0x490);
        *(u32 *)(s + 0x1d4) = n;
        *(u32 *)(s + 0x1d8) = (u32)func_02030734(*(u16 *)s, n * 0x18, 1, d_021DD9CC, 0x494);
        for (i = 0; i < *(u32 *)(s + 0x1d4); i++) {
            u8 *a = *(u8 **)(s + 0x1d8);
            u8 *b = *(u8 **)(s + 0x1cc);
            func_0218BFB4(s, a + i * 0x18, b + i * 0x18);
            *(u32 *)(*(u8 **)out + i * 8) = *(u32 *)(a + i * 0x18);
            *(u32 *)(*(u8 **)out + i * 8 + 4) = 0;
        }
    }
}
