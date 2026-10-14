/*
 * function: POKETRADE_2D_BuildMarkingTablesFrom
 * address: 0x021E3E00
 * packet: pkt_ov119_021E3E00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_BuildPartyMarkingTable 0x021E3DBC thumb ov119
 *   POKETRADE_2D_BuildBoxMarkingTable 0x021E3D88 thumb ov119
 */
#include "../include/Obj10378.h"
extern void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out);
extern void POKETRADE_2D_BuildBoxMarkingTable(char *p, int box, unsigned char *out);
int POKETRADE_2D_BuildMarkingTablesFrom(char *p, int i)
{
    while (i < ((struct Obj10378 *)p)->f630 + 1) {
        if (i == ((struct Obj10378 *)p)->f630) {
            POKETRADE_2D_BuildPartyMarkingTable(p, ((struct Obj10378 *)p)->f838, (unsigned char *)(p + 0x2E0));
            return 1;
        }
        POKETRADE_2D_BuildBoxMarkingTable(p, i, (unsigned char *)(p + 0x10 + i * 30));
        break;
    }
    return 0;
}
