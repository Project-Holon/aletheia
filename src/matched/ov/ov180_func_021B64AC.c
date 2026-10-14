/*
 * function: HALL_OF_FAME_StartBgm
 * address: 0x021B64AC
 * packet: pkt_ov180_021B64AC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHallOfFameWaveArcIds 0x021B8018 data a4
 *   GFL_USE_LoadWaveArcSet 0x02005A98 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
#include "../include/Obj02515.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Sub02005A98Hdr;
extern const u32 gHallOfFameWaveArcIds[];
extern struct Sub02005A98Hdr *GFL_USE_LoadWaveArcSet(const u32 *,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u32);
void HALL_OF_FAME_StartBgm(char *p) {*(struct Sub02005A98Hdr * *)&((struct Obj02515 *)p)->fC=GFL_USE_LoadWaveArcSet(gHallOfFameWaveArcIds,1);GFL_USE_CancelChangeAndPlayBgm(1015,65535);}
