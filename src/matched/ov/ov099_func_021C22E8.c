/*
 * function: WIFICLUB_DrawSlotStatusIcons
 * address: 0x021C22E8
 * packet: pkt_ov099_021C22E8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_DrawPhaseIcon 0x021BE4BC thumb ov099
 *   WIFICLUB_GetStatusModeFlag 0x021C285C thumb ov099
 *   WIFICLUB_DrawTileBlock 0x021BE3CC thumb ov099
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern int WIFICLUB_GetFriendStatus(int i);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern void WIFICLUB_DrawPhaseIcon(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern int WIFICLUB_GetStatusModeFlag(void *);
extern void WIFICLUB_DrawTileBlock(char *p, int a, u8 b, u8 c, unsigned int d, int e);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void WIFICLUB_DrawSlotStatusIcons(char *p, void *unused, int id, int flag, int x, int y)
{
    int offset;
    void *s;
    int kind;
    int value;
    int icon;
    offset = 0;
    if (flag != 0) offset = 16;
    s = (void *)WIFICLUB_GetFriendStatus(id - 1);
    kind = WIFICLUB_GetStatusKind(p, s);
    value = WIFICLUB_GetStatusPhase(p, s);
    WIFICLUB_DrawPhaseIcon(p + 0x898, 6, (u8)(x + 2), (u8)(y + 2), kind, (int)value, offset);
    if (WIFICLUB_GetStatusModeFlag(s)) icon = 15;
    else icon = 11;
    WIFICLUB_DrawTileBlock(p + 0x898, 6, x + 12, y + 2, (int)(icon + offset), 0);
    func_02041B6C(7);
}
