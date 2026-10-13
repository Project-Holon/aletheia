/*
 * function: WIFICLUB_SetOwnStatusKindPhase
 * address: 0x021C1908
 * packet: pkt_ov099_021C1908
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 94 bytes code, then two zero alignment bytes before 021C1968.
 * symbols:
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_ChangeNetMode 0x021BDE30 thumb ov099
 *   WIFICLUB_SetStatusActionState 0x021C27D4 thumb ov099
 *   WIFICLUB_SetStatusActionArg 0x021C27DC thumb ov099
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_DrawPlayerInfoWindow 0x021BAEDC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern void WIFICLUB_ChangeNetMode(void *, int, int);
extern void WIFICLUB_SetStatusActionState(void *, u8);
extern void WIFICLUB_SetStatusActionArg(void *, u8);
extern void WIFICLUB_StartBgmFade(char *, int);
extern void WIFICLUB_DrawPlayerInfoWindow(char *);
void WIFICLUB_SetOwnStatusKindPhase(char *p, int kind, int value)
{
    int old;
    int oldvalue;
    if (((struct Obj00008 *)p)->f8 != 0) {
        old = WIFICLUB_GetStatusKind(p, ((struct Obj00008 *)p)->f8);
        oldvalue = WIFICLUB_GetStatusPhase(p, ((struct Obj00008 *)p)->f8);
        if (old != kind || oldvalue != value) {
            WIFICLUB_ChangeNetMode(p, kind, value);
            WIFICLUB_SetStatusActionState(((struct Obj00008 *)p)->f8, kind);
            WIFICLUB_SetStatusActionArg(((struct Obj00008 *)p)->f8, value);
            if (!(value == 5 && kind == 4)) {
                if (kind != 4) WIFICLUB_StartBgmFade(p, 127);
            }
        }
        WIFICLUB_DrawPlayerInfoWindow(p);
    }
}
