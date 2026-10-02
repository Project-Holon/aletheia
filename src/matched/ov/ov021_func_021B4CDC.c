/*
 * function: func_021B4CDC
 * address:  0x021B4CDC
 * packet:   pkt_ov021_021B4CDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * func_0215466C, filed as ov001_func_02154694.c). Old note: it sat inside ov001 pool_02154690
 * (ldr r3,[pc]; bx r3; .word func_0215466C+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that func_020124AC loads (not an OVERLAY_ID_CONSUMER).
 *
 * symbols:
 *   func_0215A5F4    0x0215A5F4  thumb  ov010
 *   func_0215A5DC    0x0215A5DC  thumb  ov010
 *   func_0215897C    0x0215897C  thumb  ov010
 *   func_0201210C    0x0201210C  thumb
 *   func_020124AC    0x020124AC  thumb
 *   abs_id_01        0x00000001  data
 *   func_02154694  0x02154694  thumb  ov001
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 abs_id_01[];
extern u32 func_02154694(void *a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(u32 a, u32 b);
extern void *func_0201210C(void *p);
extern u32 func_020124AC(u32 a, u32 b, u32 (*fn)(void *, u32), u32 c);

int func_021B4CDC(u32 a, u32 b)
{
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    func_0215897C(r5, func_020124AC(r4, (u32)abs_id_01, func_02154694, func_0201210C((void *)r4)));
    return 1;
}
