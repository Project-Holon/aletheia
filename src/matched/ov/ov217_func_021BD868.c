/*
 * function: func_021BD868
 * address:  0x021BD868
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE448 0x021BE448 thumb ov217
 *   func_021BE4DC 0x021BE4DC thumb ov217
 *   func_021BE4E0 0x021BE4E0 thumb ov217
 *   func_021C0918 0x021C0918 thumb ov217
 *   func_021C093C 0x021C093C thumb ov217
 */

typedef unsigned int u32;

#pragma thumb on
typedef unsigned char  u8;
extern void func_021BE448(void *p);
extern u32 func_021BE4DC(void *p);
extern void func_021BE4E0(void *p);
extern void func_021C0918(u8 *a0);
extern int func_021C093C(u8 *a0);

void func_021BD868(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
        func_021C0918((u8 *)a0);
        func_021BE4E0((void *)a0);
        break;
    case 1:
        if (func_021C093C((u8 *)a0) != 0) {
            func_021BE448((void *)a0);
        }
        break;
    }
}
