/*
 * function: func_021F0674
 * address: 0x021F0674
 * packet: pkt_ov033_021F0674
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
#include "../include/Obj06142.h"
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *);
void func_021F0674(int a, unsigned char *p)
{
    PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj06142 *)p)->fBC);
    if (((struct Obj06142 *)p)->fB0 != 0) {
        if (p[0xac] >= 4)
            p[0xac] = 0;
        p[0xac]++;
    }
}
