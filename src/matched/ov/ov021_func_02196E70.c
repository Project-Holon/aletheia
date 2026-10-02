/*
 * function: func_02196E70
 * address:  0x02196E70
 * packet:   pkt_ov021_02196E70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State step: picks the next handler from the state word and a status query.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196E04  0x02196E04  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196A60(void);
extern void func_02196E04(void);
extern void func_02196804(void);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);

void func_02196E70(u8 *p)
{
    if (*(u32 *)(p + 8) == 0xC) {
        func_02196034(p, func_02196A60, 0x558);
    } else {
        if (func_0200BBA8(func_0200BAC8(*(void **)(*(u8 **)(p + 0x2E4) + 0x4C))) != 0) {
            func_02196034(p, func_02196E04, 0x55D);
        } else {
            func_02196034(p, func_02196804, 0x560);
        }
    }
}
