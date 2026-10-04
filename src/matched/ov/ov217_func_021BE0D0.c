/*
 * function: func_021BE0D0
 * address:  0x021BE0D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE448  0x021BE448  thumb  ov217
 *   func_021BE4DC  0x021BE4DC  thumb  ov217
 *   func_021BE4E0  0x021BE4E0  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BF658  0x021BF658  thumb  ov217
 *   func_021BF6A4  0x021BF6A4  thumb  ov217
 *
 * Sub-state entry for mode 0 and mode 1, picked by func_021BE4DC().
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
extern void func_021BEAF8(u8 *p);
extern void func_021BF658(char *p);
extern u32 func_021BF6A4(u8 *a0);
void func_021BE0D0(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF658((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BEAF8((u8 *)a0);
    func_021BE448((void *)a0);
    }
    break;
    }
}
