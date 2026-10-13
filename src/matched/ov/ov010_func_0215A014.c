/*
 * function: func_0215A014
 * address: 0x0215A014
 * packet: pkt_ov010_0215A014
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_SetEventFlag 0x02014314 thumb
 *   d_02170FEC 0x02170FEC data ov010 a4
 */

#include "../include/G_ov010_02170FEC.h"

typedef unsigned short u16;
typedef struct Ent { u16 h0; u16 unused:1; u16 on:1; u16 rest:14; u16 h4, h6, h8; char pad[10]; } Ent;
extern struct G_ov010_02170FEC d_02170FEC[];
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_SetEventFlag(char *, int);
void func_0215A014(void *a, int b) {
 unsigned i;
 Ent *p;
 for(i=0; i<17; i++) {
 p = &((Ent *)d_02170FEC)[i];
 if (b == p->h8 && p->on) {
 ZONEDATA_SetEventFlag((char *)GAME_DATA_GetEventWork(a), p->h0);
 return;
 }
 }
}
