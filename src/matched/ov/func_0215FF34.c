/*
 * function: EVENT_SHORTCUT_MENU_HasShortcuts
 * address:  0x0215FF34
 * packet:   pkt_0215FF34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three chained arm9 probes; a non-zero result from the last reads as
 * success.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData   0x020120F4  thumb
 *   GAME_DATA_GetSaveControl   0x02012EBC  thumb
 *   func_0200C404   0x0200C404  thumb
 *   func_0200C468   0x0200C468  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C404(void *sys);
extern u16 func_0200C468(const u8 *a);

int EVENT_SHORTCUT_MENU_HasShortcuts(void *sys)
{
    if (func_0200C468(func_0200C404(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(sys)))) != 0)
        return 1;

    return 0;
}

