/*
 * function: STAFF_ROLL_PrintNextRow
 * address: 0x021B9C80
 * packet: pkt_ov181_021B9C80
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STAFF_ROLL_PrintRow 0x021B9C58 thumb ov181
 */
#include "../include/Obj14407.h"
extern void STAFF_ROLL_PrintRow(char *p, void *s, unsigned i);
#define IDX(p) (*(unsigned char *)((p) + 0x2BA))
void STAFF_ROLL_PrintNextRow(char *p)
{
    if (IDX(p) < ((struct Obj14407 *)p)->f2B8) {
        STAFF_ROLL_PrintRow(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC));
        STAFF_ROLL_PrintRow(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC) + 1);
        IDX(p)++;
    }
}
