/*
 * function: WIFI_BSUBWAY_StartUploadPlayer
 * address: 0x021D7060
 * packet: pkt_ov116_021D7060
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes after the epilogue.
 * symbols:
 *   DPW_BT_UploadPlayerAsync 0x021C9530 arm ov114
 *   WIFI_BSUBWAY_AsyncReset 0x021D70E4 thumb ov116
 *   BSUBWAY_SAVEDATA_GetTrainersTagA 0x0200DE94 thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagB 0x0200DEA0 thumb
 *   BSUBWAY_SCOREDATA_GetRecordScoreTier  0x0200DCFC  thumb  arm9
 */
#include "../include/Obj10339.h"
typedef unsigned char u8;
struct Blk1AC;
struct RecSlot;
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct RecSlot *p);
extern u8 BSUBWAY_SCOREDATA_GetRecordScoreTier(struct Blk1AC *p);
typedef unsigned int   u32;
extern void DPW_BT_UploadPlayerAsync(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v);
extern void WIFI_BSUBWAY_AsyncReset(u8 *);
void WIFI_BSUBWAY_StartUploadPlayer(u8 *p, u8 *q) {
    int a, b, c;
    a = BSUBWAY_SAVEDATA_GetTrainersTagA(((struct Obj10339 *)p)->f160);
    b = BSUBWAY_SAVEDATA_GetTrainersTagB(((struct Obj10339 *)p)->f160);
    c = BSUBWAY_SCOREDATA_GetRecordScoreTier(((struct Obj10339 *)p)->f164);
    DPW_BT_UploadPlayerAsync((u8)a,(u8)b,(u8)c,p+0x70,p+0x16e,(int)0x80);
    WIFI_BSUBWAY_AsyncReset(q);
}
