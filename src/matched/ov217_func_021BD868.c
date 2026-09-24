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
 */

typedef unsigned int u32;

extern u32 func_021BE448();
extern u32 func_021BE4DC();
extern u32 func_021BE4E0();
extern u32 func_021C0918();
extern u32 func_021C093C();

void func_021BD868(u32 a0)
{
    switch (func_021BE4DC(a0)) {
    case 0:
        func_021C0918(a0);
        func_021BE4E0(a0);
        break;
    case 1:
        if (func_021C093C(a0) != 0) {
            func_021BE448(a0);
        }
        break;
    }
}
