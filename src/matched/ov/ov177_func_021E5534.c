/*
 * function: func_021E5534
 * address:  0x021E5534
 * packet:   pkt_ov177_021E5534
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5668  0x021E5668  thumb  ov177
 *   func_021E5600  0x021E5600  thumb  ov177
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021E5668(void *p);
extern void func_021E5600(void *p);

void func_021E5534(u8 *p)
{
    func_021E5668(p + 4);
    func_021E5600(p);
}
