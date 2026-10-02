/*
 * function: func_021C881C
 * address:  0x021C881C
 * packet:   pkt_ov021_021C881C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021C8608  0x021C8608  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 *func_02012ED0(u32 a);
extern u32 func_021C8608(void);
int func_021C881C(void *task, u32 a)
{
    u32 *p = func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)a)))));
    if (*p == 0)
        *p = func_021C8608();
    return 0;
}
