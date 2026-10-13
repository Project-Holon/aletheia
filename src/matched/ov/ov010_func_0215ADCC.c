/*
 * function: SCRCMD_WORK_CmdSetSpecialLocation
 * address:  0x0215ADCC
 * packet:   pkt_ov010_0215ADCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  ZONEDATA_SetDirectLocation (0x02014184) has no witness outside the range (sole-ref class fails: no other referrer)
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct BigObj;
struct Rec1C;
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int ZONEDATA_SetDirectLocation();
extern void GAME_DATA_SetSpecialLocation(struct BigObj *p, const struct Rec1C *src);

int SCRCMD_WORK_CmdSetSpecialLocation(int a0, int a1)
{
    int buf[7];
    int v8 = (int)SCRCMD_WORK_GetGameData((void *)a1);
    int c = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int r6 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int r7 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v10 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    ZONEDATA_SetDirectLocation(buf, c, (s16)r6, r7 << 16, v10 << 16, v0 << 16);
    GAME_DATA_SetSpecialLocation((struct BigObj *)v8, (const struct Rec1C *)buf);
    return 0;
}
