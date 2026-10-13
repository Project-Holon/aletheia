/*
 * function: EVENT_MAPCHANGE_StartSeasonEffect
 * address: 0x0218601C
 * packet: pkt_ov020_0218601C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   func_02008B14 0x02008B14 thumb
 *   FORMCHANGE_RevertShayminAtNight 0x0216A358 thumb ov010
 */
typedef unsigned char  u8;
struct Big;
struct BigObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0201AD0C(void *sys);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern char *func_02008B14(int);
typedef unsigned int   u32;
extern int FORMCHANGE_RevertShayminAtNight(int a, int b, u32 *p, int c);
void EVENT_MAPCHANGE_StartSeasonEffect(int p) { int a; int b; int c; a=(int)GAME_DATA_GetSaveControl((struct Big *)p); b=(int)func_0201AD0C((void *)a); c=GAME_DATA_GetSeason((const struct BigObj *)p); FORMCHANGE_RevertShayminAtNight(p,b,(u32 *)(func_02008B14(a)+0x14),c); }
