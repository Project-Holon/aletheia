/*
 * function: INTRUDE_COMM_UpdateRequest
 * address:  0x0217546C
 * packet:   pkt_ov011_0217546C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_GetActiveRequestTarget  0x021754B4  thumb ov011
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb ov011
 *   INTRUDE_COMM_ClearRequestOpen  0x0217545C  thumb ov011
 */
#include "../include/Obj00566.h"

typedef unsigned char u8;

int INTRUDE_COMM_GetActiveRequestTarget(u8 *p, int *out);
int GAMESYSTEM_IsEventActive(char *p);
void INTRUDE_COMM_InitRequest(u8 *p, int a);
void INTRUDE_COMM_ClearRequestOpen(u8 *p);

void INTRUDE_COMM_UpdateRequest(u8 *p)
{
    u8 buf[4];
    u8 *q;
    int i;

    if (INTRUDE_COMM_GetActiveRequestTarget(p, (int *)buf) == 1 && GAMESYSTEM_IsEventActive((char *)((struct Obj00566 *)p)->f0) == 1) {
        q = p + 0x945;
        i = p[0x154];
        if (q[i] == 0) {
            q[i] = p[0x158];
        }
        INTRUDE_COMM_InitRequest(p, 4);
        INTRUDE_COMM_ClearRequestOpen(p);
    }
}
