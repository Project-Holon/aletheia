/*
 * function: FLDMMDL_G3DOBJ_InitResTable
 * address:  0x0219D4AC
 * packet:   pkt_ov021_0219D4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates n*4 bytes (n = *(u16 *)(obj+8)), stores the pointer at obj+0xc,
 * then writes 0xFFFF into the high halfword of each 4-byte entry.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDD80     0x021DDD80  data ov021 a4
 */
#include "../include/Obj04226.h"

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
extern unsigned char d_021DDD80[];

void FLDMMDL_G3DOBJ_InitResTable(int *obj, int a)
{
    int i;
    *(int *)&((struct Obj04226 *)obj)->fC =
        (int)(unsigned short *)func_02030734(a, ((struct Obj04226 *)obj)->f8 * 4,
                                             1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)((struct Obj04226 *)obj)->f8; i++) {
        unsigned short *p = *(unsigned short * *)&((struct Obj04226 *)obj)->fC;
        p[i * 2 + 1] = 0xFFFF;
    }
}
