/*
 * function: func_021BE094
 * address:  0x021BE094
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
 *   func_021BE4DC  0x021BE4DC  thumb  ov217
 *   func_021BE4E0  0x021BE4E0  thumb  ov217
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 *   func_021BF60C  0x021BF60C  thumb  ov217
 *   func_021BF6A4  0x021BF6A4  thumb  ov217
 *
 * Same two-case entry as func_021BE0D0; mode 0 arms the +5 handle and
 * func_021BF60C().
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
extern u32 func_021BE4DC(void *p);
extern void func_021BE4E0(void *p);
extern void func_021BF5BC(u8 *a0, u32 a1);
extern void func_021BF60C(char *p);
extern u32 func_021BF6A4(u8 *a0);
void func_021BE094(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF5BC((u8 *)a0, 5);
    func_021BF60C((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}
