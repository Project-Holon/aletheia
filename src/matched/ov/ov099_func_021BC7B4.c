/*
 * function: WIFICLUB_StateStartScene
 * address:  0x021BC7B4
 * packet:   pkt_ov099_021BC7B4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both 0x4c and 0x4d spell the shared call/store/result tail in full.
 * Cross-jumping retains 0x4c's bare branch over 0x4d's initial call;
 * a goto directly to that shared tail threads the stub away (152 vs156).
 *
 * symbols:
 *   WIFICLUB_CopyZeroToDeviceAddr  0x021C282C  thumb  ov099
 *   WIFICLUB_StartVoiceChat  0x021BC104  thumb  ov099
 *   WIFICLUB_ShowMessage  0x021BAADC  thumb  ov099
 *   WIFICLUB_SetOwnStatusAndPublish  0x021C18C8  thumb  ov099
 *   WIFICLUB_StartBgmFade  0x021C24A4  thumb  ov099
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 */
#include "../include/Obj04414.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int WIFICLUB_CopyZeroToDeviceAddr(u8 *p);
extern void WIFICLUB_StartVoiceChat(char *p);
extern void WIFICLUB_ShowMessage(char *p, int a, int b);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int a, int b);
extern void WIFICLUB_StartBgmFade(char *p, int v);
extern void WIFICLUB_ClearTalkWindow(char *p);

int WIFICLUB_StateStartScene(char *p, int v)
{
    int r4;
    int sel;

    WIFICLUB_CopyZeroToDeviceAddr(*(u8 * *)&((struct Obj04414 *)p)->f8);
    ((struct Obj04414 *)p)->f1351 = 0;
    sel = ((struct Obj04414 *)p)->f132C;
    switch (sel) {
    case 0x4b:
        r4 = 4;
        break;
    case 0x4c:
        r4 = 5;
        break;
    case 0x4d:
        r4 = 6;
        break;
    }
    switch (sel) {
    case 0x4b:
        WIFICLUB_StartVoiceChat(p);
        WIFICLUB_ShowMessage(p, 0x7b, 0);
        WIFICLUB_SetOwnStatusAndPublish(p, 4, 4);
        WIFICLUB_StartBgmFade(p, 0);
        ((struct Obj04414 *)p)->f1355 = 0;
        ((struct Obj04414 *)p)->f1CC = 0x10;
        break;
    case 0x4c:
        WIFICLUB_ClearTalkWindow(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    case 0x4d:
        WIFICLUB_StartVoiceChat(p);
        WIFICLUB_ClearTalkWindow(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    }
    WIFICLUB_SetOwnStatusAndPublish(p, 4, r4);
    return v;
}
