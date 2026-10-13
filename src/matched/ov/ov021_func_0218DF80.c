/*
 * function: FIELD_G3D_MAPPER_CountFittingSlots
 * address:  0x0218DF80
 * packet:   pkt_ov021_0218DF80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts how many leading entries fit the width budget.
 *
 * symbols:
 *   FIELD_G3D_MAP_GetTotalBytes  0x02169538  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04990.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void FIELD_G3D_MAP_GetTotalBytes(unsigned char *a, int *out);

void FIELD_G3D_MAPPER_CountFittingSlots(u8 *a)
{
    int n;
    int i;
    int sum = 0;
    int w;

    ((struct Obj04990 *)a)->f4C = 0;
    n = ((struct Obj04990 *)a)->f42 - (((struct Obj04990 *)a)->f2E - ((struct Obj04990 *)a)->f40);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            u8 *cnt = a + 0x4C;
            int idx = (*(u8 **)(a + 0x44))[i];
            if (idx == 0xFF) break;
            FIELD_G3D_MAP_GetTotalBytes((unsigned char *)(*(int *)(*(u8 * *)&((struct Obj04990 *)a)->f24 + idx * 0x28)), &w);
            sum += w;
            if (((struct Obj04990 *)a)->f48 < sum) break;
            *cnt = *cnt + 1;
        }
    }
}
