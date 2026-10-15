/*
 * function: WIFI_BSUBWAY_SaveHistory
 * address: 0x021D6B30
 * packet: pkt_ov116_021D6B30
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BSUBWAY_SAVEDATA_SetHistory 0x0200DF10 thumb
 */
#include "../include/Obj13861.h"
typedef unsigned char  u8;
struct RecSlot;
extern void BSUBWAY_SAVEDATA_SetHistory(struct RecSlot *p, const void *src, u8 a, u8 b);
void WIFI_BSUBWAY_SaveHistory(unsigned char *a,void *b) { BSUBWAY_SAVEDATA_SetHistory(b,a+0x69e,((struct Obj13861 *)a)->f8,((struct Obj13861 *)a)->fA); }
