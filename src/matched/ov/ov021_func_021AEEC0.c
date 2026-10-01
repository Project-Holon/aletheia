/*
 * function: func_021AEEC0
 * address:  0x021AEEC0
 * packet:   pkt_ov021_021AEEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_02011330(u32 a);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u16 func_02005F38(void);

int func_021AEEC0(u32 a, u32 b)
{
    func_02011330(a);
    *func_02159AE8(a, b) = func_02005F38();
    return 0;
}
