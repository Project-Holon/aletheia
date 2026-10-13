/*
 * function: SCRCMD_WORK_CreateCommon
 * address:  0x0215A514
 * packet:   pkt_ov010_0215A514
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   sScrcmdWorkFileName     0x021728E0  data  ov010  a4
 */

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern int sScrcmdWorkFileName;

void *SCRCMD_WORK_CreateCommon(int a, int heap)
{
    int *p = (int *)func_02030734(heap, 0x110, 1, (const char *)&sScrcmdWorkFileName, 0x78);

    p[0] = a;
    p[1] = (int)SCRIPT_WORK_GetGameSystem((void *)a);
    p[2] = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p[1]);
    p[3] = GAME_DATA_GetOccupyInfo((const struct BigObj *)p[2]);
    *((char *)p + 0x104) = 7;
    return p;
}
