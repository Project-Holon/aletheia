/*
 * function: func_021BFF60
 * address:  0x021BFF60
 * packet:   pkt_ov093_021BFF60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The k clamp is written with gotos: the original branches n == 0 straight to
 * the shared `k = 0x1f`, and the if/else and `||` spellings reorder that.
 *
 * symbols:
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021C000C  0x021C000C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021C0780  0x021C0780  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D69AC(u8 *a, int i);
extern int func_021B9934(u8 *p, int i);
extern int func_021D62C4(int p, int i);
extern void func_021C5620(u8 *p, int a, int k, void *out);
extern void func_021C6110(u8 *p, int a, int r);
extern int func_021C000C(u8 *p, int k);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021C5D88(u8 *p, int a, int b);
extern void func_021C0780(u8 *p, u8 *a, int i, u8 v);
extern int func_021D5B68(u8 *p);
extern u8 func_021D5440(u8 *p);

void func_021BFF60(u8 *p, u8 *a, int z)
{
    u8 k;
    int n;
    int w;
    n = func_021D69AC(a, 4);
    if (n == 0) goto bad;
    k = n - 1;
    if (k < 0x18) goto ok;
bad:
    k = 0x1f;
ok:
    if (k != 0x1f) {
        w = func_021B9934(*(u8 **)(p + 8), k);
        if (func_021D62C4(w, 0x21) != 0) {
            func_021C5620(p, w, 0x21, 0);
            func_021C6110(p, w, 3);
            if (func_021C000C(p + 0x1ab8, k) != 0) {
                func_021CD4B0(*(void **)(p + 0xc), 0x31, k, 0);
                func_021C5D88(p, w, 0x465);
            }
        }
        func_021C0780(p, a, 4, 0);
        k = 0;
        if (z == 0 && func_021D5B68(a) == 0) {
            func_021CD4B0(*(void **)(p + 0xc), 0x31, func_021D5440(a), k);
        }
    }
}
