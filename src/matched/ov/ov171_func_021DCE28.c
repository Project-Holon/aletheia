/*
 * function: func_021DCE28
 * address: 0x021DCE28
 * packet: pkt_ov171_021DCE28
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj14285.h"
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021DCE28(char *p)
{
    unsigned short i, j;
    char *row;
    char *cell;
    for(i=0;i<15;i++) {
        row=p+i*0xbc;
        for(j=0;j<6;j++) {
            cell=row+j*0x1c;
            STRBUF_Delete(((struct Obj14285 *)cell)->fC);
            STRBUF_Delete(((struct Obj14285 *)cell)->f10);
        }
    }
}
