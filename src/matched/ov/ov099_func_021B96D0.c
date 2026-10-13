/*
 * function: WIFICLUBACTOR_Update
 * address:  0x021B96D0
 * packet:   pkt_ov099_021B96D0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C48E8  0x021C48E8  thumb  ov127
 *   WIFICLUBACTOR_UpdateActors  0x021B9C9C  thumb  ov099
 *   WIFICLUBACTOR_ProcessSpawnCommands  0x021B9C4C  thumb  ov099
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 *   func_021C571C  0x021C571C  thumb  ov127
 *   WIFICLUBACTOR_AnimateActors  0x021B9CD0  thumb  ov099
 *   WIFICLUBACTOR_HideCursor  0x021B9F84  thumb  ov099
 *   WIFICLUBACTOR_IsCursorFree  0x021B9BA8  thumb  ov099
 *   WIFICLUBACTOR_UpdatePickRequests  0x021B97CC  thumb  ov099
 *   WIFICLUBACTOR_IsCursorOnExit  0x021B9FDC  thumb  ov099
 *   WIFICLUBACTOR_ShowCursor  0x021B9F48  thumb  ov099
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   WIFICLUBACTOR_GetPickResult  0x021B97F4  thumb  ov099
 *   WIFICLUBACTOR_IsFacingEntrance  0x021B9BC4  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C48E8(u8 *p);
extern void WIFICLUBACTOR_UpdateActors(u8 *p);
extern void WIFICLUBACTOR_ProcessSpawnCommands(char *p);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);
extern void func_021C571C(u8 *p);
extern void WIFICLUBACTOR_AnimateActors(char *p);
extern void WIFICLUBACTOR_HideCursor(char *p);
extern int WIFICLUBACTOR_IsCursorFree(char *p);
extern void WIFICLUBACTOR_UpdatePickRequests(char *p);
extern int WIFICLUBACTOR_IsCursorOnExit(char *p);
extern void WIFICLUBACTOR_ShowCursor(u8 *p);
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern u8 WIFICLUBACTOR_GetPickResult(char *p);
extern int WIFICLUBACTOR_IsFacingEntrance(char *p);

u32 WIFICLUBACTOR_Update(char *p)
{
    if (*(u32 *)0x02FFFC3C & 1) {
        func_021C48E8(*(void **)(p + 0x58C));
        WIFICLUBACTOR_UpdateActors((u8 *)p);
        WIFICLUBACTOR_ProcessSpawnCommands(p);
        func_021C5994(p + 0x594, **(void ***)(p + 0x570));
        func_021C5A60(*(char **)(p + 0x598), p + 0x594);
        func_021C571C(*(void **)(p + 0x590));
        WIFICLUBACTOR_AnimateActors(p);
        WIFICLUBACTOR_HideCursor(p);
    }
    if (WIFICLUBACTOR_IsCursorFree(p) == 1) {
        WIFICLUBACTOR_UpdatePickRequests(p);
        if (WIFICLUBACTOR_IsCursorOnExit(p) == 1) {
            WIFICLUBACTOR_ShowCursor((u8 *)p);
            if (KEY_GetCont() & 0x80)
                return 1;
        }
        if (KEY_GetTrg() & 1) {
            if (WIFICLUBACTOR_GetPickResult(p) != 0)
                return 2;
            if (WIFICLUBACTOR_IsFacingEntrance(p) == 1)
                return 3;
        }
    }
    return 0;
}
