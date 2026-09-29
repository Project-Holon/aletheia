/*
 * function: func_021D61F4
 * address:  0x021D61F4
 * packet:   pkt_ov016_021D61F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GXlSetWndPlane (libdwcutil.TWL.HYB.a(graphics.o))
 *
 * symbols:

 */

typedef unsigned short u16;
typedef volatile u16 vu16;

#define LO(a) \
    do { \
        int v = (*(vu16 *)(a) & ~0x3f) | plane; \
        if (effect) \
            v |= 0x20; \
        *(vu16 *)(a) = v; \
    } while (0)

#define HI(a) \
    do { \
        int v = (*(vu16 *)(a) & ~0x3f00) | (plane << 8); \
        if (effect) \
            v |= 0x2000; \
        *(vu16 *)(a) = v; \
    } while (0)

void func_021D61F4(int lcd, int wnd, int plane, int effect)
{
    switch (wnd) {
    case 0:
        if (lcd == 1)
            LO(0x04001048);
        else
            LO(0x04000048);
        break;
    case 1:
        if (lcd == 1)
            HI(0x04001048);
        else
            HI(0x04000048);
        break;
    case 2:
        if (lcd == 1)
            HI(0x0400104a);
        else
            HI(0x0400004a);
        break;
    case 3:
        if (lcd == 1)
            LO(0x0400104a);
        else
            LO(0x0400004a);
        break;
    }
}
