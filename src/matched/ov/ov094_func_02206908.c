/*
 * function: BTLV_INPUT_IsWazaSelectable
 * address:  0x02206908
 * packet:   pkt_ov094_02206908
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00823.h"
#include "../include/Obj04404.h"

typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf;

int BTLV_INPUT_IsWazaSelectable(char *p, char *q, int i)
{
    int r;

    if (!((Bf *)(p + 0x68))->b4 || ((struct Obj00823 *)p)->f58 != 1)
        return 1 & ((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i];
    r = (((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i] & 2) >> 1;
    if (r == 1)
        *(char *)(p + ((struct Obj00823 *)p)->f27C * 8 + 0x242 + ((struct Obj00823 *)p)->f58) = 0;
    return r;
}
