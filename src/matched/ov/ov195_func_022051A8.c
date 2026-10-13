/*
 * function: func_022051A8
 * address: 0x022051A8
 * packet: pkt_ov195_022051A8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
#include "../include/Obj04594.h"
typedef unsigned int   u32;
struct S02021D50;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
void func_022051A8(int task, char *p)
{
    switch (((struct Obj04594 *)p)->f88) {
    case 1:
        func_02040588(1, 1);
        ((struct Obj04594 *)p)->f8C = 1;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    case 2:
        func_02040588(1, 0);
        ((struct Obj04594 *)p)->f8C = 0;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    }
    if (((struct Obj04594 *)p)->fA8)
        PALANM_TransferPalettes(((struct Obj04594 *)p)->fA8);
}
