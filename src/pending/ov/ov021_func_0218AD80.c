/*
 * function: func_0218AD80
 * address:  0x0218AD80
 * packet:   pkt_ov021_0218AD80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Looks up entry id through func_021625CC, optionally resolves its argument,
 * then dispatches to ov020 func_02185410 for kind 6 or func_02185360
 * otherwise.
 *
 * Blocker: the call to 0x021626A8 is the one wildcard. In ov010 that address
 * is an unlabelled Thumb veneer (ldr r3, [pc, #0]; bx r3; .word 0x02162B69)
 * with no func_ label, so no class attests it. It closes once ov010
 * 0x021626A8 is labelled.
 *
 * symbols:
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626A8  0x021626A8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185410  0x02185410  thumb  ov020
 *   func_02185360  0x02185360  thumb  ov020
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_021625CC(void *p, u16 id);
extern void *func_021626A8(void *obj, void *arg);
extern u8 func_021626E8(void *obj);
extern void func_02185410(void *p, void *a, void *obj, void *d);
extern void func_02185360(void *p, void *a, void *obj, void *d);

void func_0218AD80(u8 *p, void *a, int id, void *arg)
{
    void *obj = func_021625CC(*(void **)(p + 0xC), id);
    void *d;

    if (arg != 0)
        d = func_021626A8(obj, arg);
    else
        d = 0;
    if (func_021626E8(obj) == 6)
        func_02185410(*(void **)(p + 4), a, obj, d);
    else
        func_02185360(*(void **)(p + 4), a, obj, d);
}
