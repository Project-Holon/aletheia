/*
 * function: func_0218ACA8
 * address:  0x0218ACA8
 * packet:   pkt_ov021_0218ACA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010F18  0x02010F18  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   func_021F532C  0x021F532C  thumb  ov083
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc;

extern u8 abs_id_83[];
extern u8 func_02010F18(void);
extern struct Desc *func_020124AC(void *a0, const void *a1, void (*fn)(void *, u32), u32 a3);
extern void func_021F532C(void *a, u32 b);

struct Desc *func_0218ACA8(void *a)
{
    if (func_02010F18() == 0x30) {
        return 0;
    }
    return func_020124AC(a, abs_id_83, func_021F532C, 0);
}
