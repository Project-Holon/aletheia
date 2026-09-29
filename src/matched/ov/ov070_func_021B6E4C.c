/*
 * function: func_021B6E4C
 * address:  0x021B6E4C
 * packet:   pkt_ov070_021B6E4C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 *   func_021B7D20  0x021B7D20  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32  func_02028754(void *obj, u32 n);
extern void func_02045CAC(u32 a0, u32 a1, u32 a2);
extern void func_0201F02C(u32 a0, u32 a1, u32 a2);
extern void func_0201F250(u32 a0, u32 a1, u32 a2);
extern void func_021B6100(void *obj, void *fn);
extern void func_021B6AD8(void);
extern void func_021B7D20(void *obj, int x);

u32 func_021B6E4C(u8 *p)
{
    if (*(u32 *)(p + 0x848) == 0) {
        if (func_02028754(*(void **)(p + 0xC), 3)) {
            *(u32 *)(p + 0x844) = 0xE;
            func_021B6100(p, 0);
            func_021B7D20(p, 1);
            return 1;
        }
        func_02045CAC(*(u32 *)(p + 0x51C), 0x3A, *(u32 *)(p + 0x524));
        func_0201F02C(*(u32 *)(p + 0x520), 0, *(u32 *)(p + 8));
        func_0201F250(*(u32 *)(p + 0x520), *(u32 *)(p + 0x528), *(u32 *)(p + 0x524));
        func_021B6100(p, (void *)func_021B6AD8);
        return 0;
    }
    return 0;
}
