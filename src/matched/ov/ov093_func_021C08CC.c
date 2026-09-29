/*
 * function: func_021C08CC
 * address:  0x021C08CC
 * packet:   pkt_ov093_021C08CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5608  0x021D5608  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D56CC  0x021D56CC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B911C(void *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021D5608(u8 *a, int i, u8 n);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021D56CC(u8 *a, int i);

void func_021C08CC(u8 *p, u8 *a, int b, u8 c)
{
    u32 n;
    if (func_021B911C(*(void **)(p + 4), 5) == 0) {
        n = func_021D5440(a);
        func_021D5608(a, b, c);
        func_021CD4B0(*(void **)(p + 0xc), 4, n, b, c);
        func_021D56CC(a, b);
        func_021CD4B0(*(void **)(p + 0xc), 6, n, b);
    }
}
