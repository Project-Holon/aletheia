/*
 * function: SCRCMD_PROC_FLD_InitShop
 * address:  0x021B3258
 * packet:   pkt_ov021_021B3258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_InitShop 0x021B3258 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   SCRCMD_PROC_FLD_AllocShopResources 0x021B3B14 thumb ov021
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_CountFlags 0x0200C258 thumb
 *   SCRCMD_PROC_FLD_BuildItemListByBadges 0x021B38E0 thumb ov021
 *   SCRCMD_PROC_FLD_BuildItemListFixed 0x021B39C4 thumb ov021
 *   SCRCMD_PROC_FLD_BuildItemListFromRange 0x021B3A64 thumb ov021
 *   SCRCMD_PROC_FLD_LoadShopMessages 0x021B331C thumb ov021
 *   SCRCMD_PROC_FLD_InitShopGraphics 0x021B3BD8 thumb ov021
 *   SCRCMD_PROC_FLD_InitShopWindows 0x021B3FA0 thumb ov021
 *   SCRCMD_PROC_FLD_InitShopCells 0x021B3F00 thumb ov021
 *   SCRCMD_PROC_FLD_PrintMoneyWindow 0x021B40D4 thumb ov021
 *   SCRCMD_PROC_FLD_CreateItemListMenu 0x021B43EC thumb ov021
 */

typedef unsigned char u8;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int SCRCMD_PROC_FLD_AllocShopResources(char *p, int a);
extern void *GAME_DATA_GetMiscSave(int *p);
extern int BEACON_CountFlags(void);
extern void SCRCMD_PROC_FLD_BuildItemListByBadges(char *p, int a, int b, int c);
extern void SCRCMD_PROC_FLD_BuildItemListFixed(u8 *, int);
extern void SCRCMD_PROC_FLD_BuildItemListFromRange(char *p, int i);
extern void SCRCMD_PROC_FLD_LoadShopMessages(u8 *, int);
extern void SCRCMD_PROC_FLD_InitShopGraphics(char *p);
extern void SCRCMD_PROC_FLD_InitShopWindows(char *w);
extern void SCRCMD_PROC_FLD_InitShopCells(u8 *);
extern void SCRCMD_PROC_FLD_PrintMoneyWindow(char *w);
extern void SCRCMD_PROC_FLD_CreateItemListMenu(char *w);

void SCRCMD_PROC_FLD_InitShop(int ctx, u8 *a, int b, int c)
{
    void *t = GAMESYSTEM_GetGameData((void *)ctx);
    int r;

    GAME_DATA_GetMyStatus(t);
    a[354] = 0;
    b = SCRCMD_PROC_FLD_AllocShopResources((char *)a, b);
    r = b;
    switch (r) {
    case 255:
        GAME_DATA_GetMiscSave(t);
        SCRCMD_PROC_FLD_BuildItemListByBadges((char *)a, r, c, BEACON_CountFlags());
        break;
    case 254:
        SCRCMD_PROC_FLD_BuildItemListFixed(a, 0);
        a[355] = 1;
        break;
    case 253:
        a[355] = 1;
        a[354] = 1;
        SCRCMD_PROC_FLD_BuildItemListFixed(a, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        SCRCMD_PROC_FLD_BuildItemListFromRange((char *)a, r);
        break;
    default:
        SCRCMD_PROC_FLD_BuildItemListByBadges((char *)a, r, c, 0);
        break;
    }
    SCRCMD_PROC_FLD_LoadShopMessages(a, a[355]);
    SCRCMD_PROC_FLD_InitShopGraphics((char *)a);
    SCRCMD_PROC_FLD_InitShopWindows((char *)a);
    SCRCMD_PROC_FLD_InitShopCells(a);
    SCRCMD_PROC_FLD_PrintMoneyWindow((char *)a);
    SCRCMD_PROC_FLD_CreateItemListMenu((char *)a);
}
