/*
 * function: FIELD_CLOCK_UpdateMinutes
 * address: 0x02169068
 * packet: pkt_ov010_02169068
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKEPARTY_GetSaveData 0x0201AD0C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   FORMCHANGE_RevertShayminIfTimeOfDayChanged 0x0216A2EC thumb ov010
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_SubGatePoints 0x0200C3C0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct BigObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *POKEPARTY_GetSaveData(void *sys);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern int FORMCHANGE_RevertShayminIfTimeOfDayChanged(int,int,int,int *,int);
extern void *BEACON_GetBlock(void *sys);
struct Blk34;
extern void BEACON_SubGatePoints(struct Blk34 *p, u16 v);
void FIELD_CLOCK_UpdateMinutes(int a,int b,int *c) { int t=(int)POKEPARTY_GetSaveData(GAME_DATA_GetSaveControl((struct Big *)a)); FORMCHANGE_RevertShayminIfTimeOfDayChanged(a,t,b,c,GAME_DATA_GetSeason((const struct BigObj *)a)); BEACON_SubGatePoints((struct Blk34 *)((int)BEACON_GetBlock(GAME_DATA_GetSaveControl((struct Big *)a))),b); }
