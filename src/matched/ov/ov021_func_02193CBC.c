/*
 * function: FIELD_WFBC_Clear
 * address:  0x02193CBC
 * packet:   pkt_ov021_02193CBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_WFBC_PEOPLE_Clear  0x02193F6C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_WFBC_BLOCK_ClearGrid  0x02193FE8  thumb  ov021
 *   FIELD_WFBC_BLOCK_ClearRand  0x02194078  thumb  ov021
 */
#include "../include/Obj04214.h"

struct E50;
extern void FIELD_WFBC_PEOPLE_Clear(struct E50 *e);
extern void MI_CpuFill8(void *p, int v, int n);
extern void FIELD_WFBC_BLOCK_ClearGrid(void *p);
typedef unsigned int   u32;
extern void FIELD_WFBC_BLOCK_ClearRand(u32 a);

void FIELD_WFBC_Clear(unsigned char *p)
{
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj04214 *)p)->f4;

    p[0] = 0;
    p[1] = 0;
    ((struct Obj04214 *)p)->f8 = 0;
    if (q != 0) {
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_Clear((struct E50 *)(*(unsigned char * *)&((struct Obj04214 *)p)->f4 + i * 0x50));
    }
    if (((struct Obj04214 *)p)->f14 != 0)
        MI_CpuFill8(((struct Obj04214 *)p)->f14, 0, 0x600);
    FIELD_WFBC_BLOCK_ClearGrid(p + 0x18);
    FIELD_WFBC_BLOCK_ClearRand((u32)(p + 0x11c));
}
