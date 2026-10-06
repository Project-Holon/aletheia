/*
 * function: func_0219C52C
 * address:  0x0219C52C
 * packet:   pkt_ov021_0219C52C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02050330  0x02050330  arm
 *   func_02050080  0x02050080  arm
 *   func_02050304  0x02050304  arm
 *   func_0204F214  0x0204F214  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 func_02050330(u8 *p, int i);
extern u32 func_02050080(u32 *p);
extern int func_02050304(int a0, int a1);
extern void func_0204F214(u8 *a0, int i);

void func_0219C52C(u32 a, u32 b)
{
    u32 x = func_02050330((u8 *)a, b);
    u32 y = func_02050080((u32 *)a);
    func_02050304(a, b);
    func_0204F214((u8 *)y, x);
}
