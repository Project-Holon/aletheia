/*
 * function: MOVE_POKEMON_MilkDrinkEventMain
 * address: 0x0215EEF8
 * packet: pkt_ov010_0215EEF8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   SCRIPT_WORK_SetParams 0x02159058 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct C { u8 pad00[8]; void *f8; u16 fc; };
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
int MOVE_POKEMON_MilkDrinkEventMain(void *p, void *unused, struct C *ctx)
{
    int h;
    int t;
    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(ctx->f8));
    h = ctx->fc;
    t = SCRIPT_SYS_ChangeScriptEvent((int)p, 0x271c, 0, 0);
    SCRIPT_WORK_SetParams(t, h, 0, 0, 0);
    return 0;
}
