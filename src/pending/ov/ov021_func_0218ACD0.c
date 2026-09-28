/*
 * function: func_0218ACD0
 * address:  0x0218ACD0
 * packet:   pkt_ov021_0218ACD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * For a usable entry id (func_0218AE04), unless ov010 func_021626EC reports
 * kind 1 or func_0218AEAC rejects it, builds its record (func_0218ADC8) and
 * dispatches it (func_0218AD80).
 *
 * Blocker: the call to 0x021626EC is the one wildcard. That address is Thumb
 * code in ov010 (ldrh r2, [r0]; ldr r1, [pc, #0x14]; ...) with no func_
 * label, so no class attests it. It closes once ov010 0x021626EC is labelled.
 *
 * symbols:
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_0218AE04  0x0218AE04  thumb
 *   func_0218AEAC  0x0218AEAC  thumb
 *   func_0218ADC8  0x0218ADC8  thumb
 *   func_0218AD80  0x0218AD80  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0218AE04(u8 *p, void *arg);
extern void *func_021625CC(void *p, u16 id);
extern int func_021626EC(void *obj);
extern int func_0218AEAC(void *obj);
extern void func_0218ADC8(u8 *p, int id, void *arg);
extern int func_0218AD80(u8 *p, void *a, int id, void *arg);

int func_0218ACD0(u8 *p, void *a, void *arg)
{
    u32 id = func_0218AE04(p, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0;
    obj = func_021625CC(*(void **)(p + 0xC), id);
    if (func_021626EC(obj) == 1 || !func_0218AEAC(obj))
        return 0;
    func_0218ADC8(p, id, arg);
    return func_0218AD80(p, a, id, arg);
}
