/*
 * function: EVENT_FIELD_MENU_OnFinish
 * address:  0x0215FEF4
 * packet:   pkt_ov010_0215FEF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);

int EVENT_FIELD_MENU_OnFinish(u32 *a0, u32 *a1)
{
    void *h = GAMESYSTEM_GetGameData((const struct Ctx *)a1[2]);

    switch (a0[9]) {
    case 4:
        GAME_DATA_SetSubscreenType(h, 6);
        break;
    case 0:
        GAME_DATA_SetSubscreenType(h, 1);
        break;
    case 1:
    case 2:
    case 3:
        GAME_DATA_SetSubscreenType(h, (u8)a1[6]);
        break;
    default:
        break;
    }
    return 1;
}
