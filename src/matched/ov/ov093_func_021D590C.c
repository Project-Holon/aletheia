/*
 * function: func_021D590C
 * address:  0x021D590C
 * packet:   pkt_ov093_021D590C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017D70  0x02017D70  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_02017D30(void *h);
extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern u32 func_02017D70(void *h, u32 v);

void func_021D590C(void **p, u16 *out)
{
    u8 v = func_02017D30(*p);
    out[1] = func_02017E1C(*p, 0xa1, 0);
    out[2] = func_02017E1C(*p, 0xa2, 0);
    out[3] = func_02017E1C(*p, 0xa3, 0);
    out[4] = func_02017E1C(*p, 0xa5, 0);
    out[5] = func_02017E1C(*p, 0xa6, 0);
    out[6] = func_02017E1C(*p, 0xa4, 0);
    func_02017D70(*p, v);
}
