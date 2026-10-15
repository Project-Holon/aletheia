/*
 * function: func_021B9A68
 * address: 0x021B9A68
 * packet: pkt_ov205_021B9A68
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021B9A92 follow; no follower.
 * symbols:
 *   RTC_GetDate 0x02088864 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   MISC_SAVEDATA_SnapshotParty 0x0200EA3C thumb
 */
#include "../include/Obj14630.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec; struct BigObj; struct Date; extern void RTC_GetDate(void *); extern void *GAME_DATA_GetMyParty(const struct BigObj *);extern void *GAME_DATA_GetSaveBlock42(void **);extern void MISC_SAVEDATA_SnapshotParty(struct Rec *,void *,struct Date *,u32);
void func_021B9A68(char *p) { u32 date[4];void *party,*rec;RTC_GetDate(date);party=GAME_DATA_GetMyParty(*(struct BigObj * *)&((struct Obj14630 *)p)->f4);rec=GAME_DATA_GetSaveBlock42(*(void ** *)&((struct Obj14630 *)p)->f4);MISC_SAVEDATA_SnapshotParty(rec,party,(struct Date *)date,4); }
