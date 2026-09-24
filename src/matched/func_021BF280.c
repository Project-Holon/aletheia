/*
 * function: func_021BF280
 * address:  0x021BF280
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF084  0x021BF084  thumb  ov099
 *   func_021BF24C  0x021BF24C  thumb  ov099
 *   func_021BF1CC  0x021BF1CC  thumb  ov099
 *
 * Three-step update of the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BF084(void);
extern void func_021BF24C(void *a, void *b);
extern void func_021BF1CC(void *a);

void func_021BF280(void *a, void *b)
{
    func_021BF084();
    func_021BF24C(a, b);
    func_021BF1CC(a);
}
