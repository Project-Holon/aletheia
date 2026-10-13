/*
 * function: FIELD_BUILDMODEL_BuildTableIndex
 * address:  0x0218BB78
 * packet:   pkt_ov021_0218BB78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_BUILDMODEL_GetModelDef  0x0218B924  thumb  ov021
 */
#include "../include/Obj00572.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *p, int v, int n);
extern int FIELD_BUILDMODEL_GetModelDef(u8 *p, u32 a1);

void FIELD_BUILDMODEL_BuildTableIndex(u8 *s, int k)
{
    u8 i;
    u8 v;
    int j;

    MI_CpuFill8(s + 0x1c, 0x80, 0x190);
    for (i = 0; i < ((struct Obj00572 *)s)->f1AC; i++)
        s[*((u16 *)FIELD_BUILDMODEL_GetModelDef(s, i)) + 0x1c] = i;
    v = (s + k)[0x1c];
    for (j = 0; j < 0x190; j++) {
        if (s[j + 0x1c] == 0x80)
            s[j + 0x1c] = v;
    }
}
