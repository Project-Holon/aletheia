/*
 * function: func_021ED930
 * address:  0x021ED930
 * packet:   pkt_ov093_021ED930
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_021ED9A4  0x021ED9A4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021B8588(void *p);
extern int func_021B8640(void *p);
extern void func_021ED9A4(void *p, void *s, u8 i);

void func_021ED930(char *s)
{
    u32 i;
    u32 n;

    for (i = 0; i <= 6; i++) {
        *(u8 *)(s + i * 12 + 0x53) = 0;
        *(int *)(s + i * 12 + 0x48) = 0;
    }
    if (func_021B8588(*(void **)(s + 0x134)) != 3) {
        n = func_021B8640(*(void **)(s + 0x134));
    } else {
        n = 5;
    }
    for (i = 0; i <= n; i++) {
        func_021ED9A4(s + 0x48 + i * 12, s, i);
    }
}
