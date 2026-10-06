/*
 * function: func_021DF370
 * address: 0x021DF370
 * packet: pkt_ov137_021DF370
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate far-field then near-field stores preserve store scheduling.
 * symbols:
 *   func_021E0570 0x021E0570 thumb ov137
 *   func_021E07A4 0x021E07A4 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 */
#include "../include/Obj04539.h"
#include "../include/Obj10622.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E0570(u8 *p);
extern void func_021E07A4(char *p);
extern u8 *func_021E0A44(void *);
int func_021DF370(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Obj04539 *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Obj04539 *)p)->f11C = values[0] << 12;
        ((struct Obj04539 *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Obj04539 *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Obj10622 *)entry)->f1C = values[((struct Obj10622 *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[((struct Obj10622 *)entry)->f10 + 2];
        }
        ((struct Obj04539 *)p)->f1C = values[1];
        func_021E0570(p);
        func_021E07A4((char *)p);
        *(u8 * *)&((struct Obj04539 *)p)->f28 = func_021E0A44(p);
        ((struct Obj04539 *)p)->f0 = 35;
    }
    return 0;
}
