/*
 * function: func_021C4034
 * address:  0x021C4034
 * packet:   pkt_ov093_021C4034
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C40F4  0x021C40F4  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021D6D5C  0x021D6D5C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021D6D7C(u8 *p);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern int func_021C40F4(u8 *p, int i);
extern void func_021C5B74(u8 *p, u8 *a, int c, int k);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021D6D5C(u8 *a, u16 v);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021CD64C(void *w, u8 id, ...);
extern void func_021C5DAC(u8 *p, int a, int b, int c);
extern void func_021C5D88(u8 *p, u8 *a, int b);

int func_021C4034(u8 *p, u8 *a)
{
    int n;
    int r;
    if (func_021D6D7C(a) == 0) {
        n = func_021D7B74(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_021C40F4(p + 0x1ab8, func_021D5440(a));
            if (r != 6) {
                func_021C5B74(p, a, -n, 1);
                func_021C195C(p, a, 1);
                func_021D6D5C(a, n);
                func_021CD4B0(*(void **)(p + 0xc), 0x27, func_021D5440(a), (u16)n);
                func_021CD4B0(*(void **)(p + 0xc), 0x51, r);
                func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x311, func_021D5440(a), 0xffff0000);
                return 1;
            }
        }
        func_021C5DAC(p, 0x7b, 0, 0);
    } else {
        func_021C5D88(p, a, 0x314);
    }
    return 0;
}
