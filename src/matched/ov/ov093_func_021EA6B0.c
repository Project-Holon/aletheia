/*
 * function: func_021EA6B0
 * address:  0x021EA6B0
 * packet:   pkt_ov093_021EA6B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202A298  0x0202A298  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021EA730  0x021EA730  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0202A298(u16 key, u16 want, u32 heap);
extern void func_0202A310(u16 key, u16 want, void *dest, u32 heap);
extern void func_021EA730(char *p, int a, int b, int c);

int func_021EA6B0(char *p, u16 a, u16 b)
{
    if (func_0202A298(a, b, *(u16 *)(p + 0x184)) != 0) {
        func_0202A310(a, b, *(void **)(p + 0xac), *(u16 *)(p + 0x184));
        func_021EA730(p, *(int *)(p + 0xac), 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}
