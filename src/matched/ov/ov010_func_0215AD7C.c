/*
 * function: SCRCMD_WORK_CmdSetSpecialLocationHere
 * address:  0x0215AD7C
 * packet:   pkt_ov010_0215AD7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  byte-correct (80/80, MATCH*). The bl at +003C to 0x02014184 is
 * unresolved: 0x02014184 is an unlabelled Thumb leaf in the ARM9 image (a
 * 64-byte run that disasm.py prints as ARM junk, no func_ label) with one
 * caller image-wide, so label / sole-ref/code refuse it. evidence class:
 * label / sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 */

typedef struct {
    int w[7];
} V28;

typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Rec1C;
struct Rec44;
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int GAME_DATA_GetMyPlayerWork(void);
extern int *GAME_DATA_GetPlayerPosition(void);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 GAME_DATA_GetPlayerDirectionType(const struct Rec44 *p);
extern void ZONEDATA_SetDirectLocation(V28 *, int, short, int, int, int);
extern void GAME_DATA_SetSpecialLocation(struct BigObj *p, const struct Rec1C *src);

int SCRCMD_WORK_CmdSetSpecialLocationHere(int a, int b)
{
    V28 v;
    int t = (int)SCRCMD_WORK_GetGameData((void *)b);
    int r5 = GAME_DATA_GetMyPlayerWork();
    int *r4 = GAME_DATA_GetPlayerPosition();
    int r7 = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)r5);

    ZONEDATA_SetDirectLocation(&v, r7, GAME_DATA_GetPlayerDirectionType((const struct Rec44 *)r5), r4[0], r4[1], r4[2]);
    GAME_DATA_SetSpecialLocation((struct BigObj *)t, (const struct Rec1C *)(&v));
    return 0;
}
