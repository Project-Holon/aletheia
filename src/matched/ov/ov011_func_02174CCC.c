/*
 * function: INTRUDE_COMM_UpdatePageRequests
 * address:  0x02174CCC
 * packet:   pkt_ov011_02174CCC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is GAME_DATA_GetSecondUnionInfo's argument (the r0 at that call is never re-set).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   INTRUDE_COMM_SendUnionInfo  0x02174734  thumb ov011
 *   INTRUDE_COMM_BuildSymbolPage  0x02174D5C  thumb ov011
 *   INTRUDE_COMM_SendSymbolPage  0x021748CC  thumb ov011
 *   INTRUDE_COMM_SendAreaNotice  0x02174954  thumb ov011
 */
#include "../include/Obj04951.h"

typedef unsigned int   u32;
u32 func_02026478(void *obj);
unsigned char *GAME_DATA_GetSecondUnionInfo(void *p);
typedef unsigned char  u8;
int INTRUDE_COMM_SendUnionInfo(char *p, int b, void *c);
void INTRUDE_COMM_BuildSymbolPage(int *p, const u8 *q);
int INTRUDE_COMM_SendSymbolPage(char *p, int a);
u32 INTRUDE_COMM_SendAreaNotice(u32 p);

void INTRUDE_COMM_UpdatePageRequests(unsigned char *p)
{
    unsigned char i;
    unsigned char *e;
    unsigned char *q;
    int h;

    h = func_02026478((void *)(((struct Obj04951 *)p)->f4));
    if (p[0x908] != 0) {
        if (INTRUDE_COMM_SendUnionInfo((char *)p, p[0x908], (void *)GAME_DATA_GetSecondUnionInfo((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    e = p + 0x8D4;
    for (i = 0; i < 3; i++) {
        q = p + i * 4;
        if (q[0x8D5] == 1) {
            INTRUDE_COMM_BuildSymbolPage((int *)p, e + i * 4);
            if (INTRUDE_COMM_SendSymbolPage((char *)p, i) == 1) {
                q[0x8D5] = 0;
            }
        }
    }
    if (p[0x8E1] == 1) {
        if (INTRUDE_COMM_SendAreaNotice((u32)(p + 0x8E0)) == 1) {
            p[0x8E1] = 0;
        }
    }
}
