/*
 * function: WIFICLUB_StartVoiceChat
 * address:  0x021BC104
 * packet:   pkt_ov099_021BC104
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb  ov009
 *   DWC_RAP_EnableLocalVchat  0x02156330  thumb  ov009
 *   DWC_RAP_StartVchatDefaultHeap  0x021563C0  thumb  ov009
 *   WIFICLUB_StartBgmFade  0x021C24A4  thumb  ov099
 *   WIFICLUB_SetStatusModeFlag  0x021C2864  thumb  ov099
 */
#include "../include/Obj00008.h"
#include "../include/Obj13686.h"

typedef unsigned char u8;

extern void DWC_RAP_SetVchatEnabled(int);
extern int DWC_RAP_EnableLocalVchat(void);
extern void DWC_RAP_StartVchatDefaultHeap(int a);
extern void WIFICLUB_StartBgmFade(void *w, int v);
extern void WIFICLUB_SetStatusModeFlag(void *a, u8 v);

void WIFICLUB_StartVoiceChat(char *p)
{
    char *q = *(char * *)&((struct Obj00008 *)p)->f248;

    if (((struct Obj13686 *)q)->f44 != 0 && ((struct Obj13686 *)q)->f45 != 0) {
        DWC_RAP_SetVchatEnabled(1);
        DWC_RAP_StartVchatDefaultHeap(DWC_RAP_EnableLocalVchat());
        WIFICLUB_StartBgmFade(p, 0x2A);
        WIFICLUB_SetStatusModeFlag(((struct Obj00008 *)p)->f8, 1);
    } else {
        WIFICLUB_SetStatusModeFlag(((struct Obj00008 *)p)->f8, 0);
    }
}
