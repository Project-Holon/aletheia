/*
 * function: func_021BE36C
 * address:  0x021BE36C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE448  0x021BE448  thumb  ov217
 *   func_021BE468  0x021BE468  thumb  ov217
 *
 * Calls func_021BE448() while func_021BE468() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021BE448(void *p);
extern u32 func_021BE468(void *p);
void func_021BE36C(u32 a0)
{
    if (func_021BE468((void *)a0) < *(u32*)(((u8*)a0) + 40)) {
    func_021BE448((void *)a0);
    }
}
