/*
 * function: WIFICLUB_StateShowRuleMatchMessage
 * address:  0x021BD3A8
 * packet:   pkt_ov099_021BD3A8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_0200AE54  0x0200AE54  thumb
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 */
#include "../include/Obj07947.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, unsigned int a, unsigned int b);
struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(char *p);

int WIFICLUB_StateShowRuleMatchMessage(char *p, int v)
{
    int a;
    int b;
    int id;

    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0xA) != 0) {
        a = func_0200AE54((struct Reg *)(((struct Obj07947 *)p)->f1348), 2);
        b = func_0200AE54((struct Reg *)(((struct Obj07947 *)p)->f1348), 3);
        if (a == 3 && b == 3) {
            id = 0x92;
        } else if (a == 4 && b == 4) {
            id = 0x93;
        } else if (a == 6 && b == 6) {
            id = 0x94;
        } else {
            id = 0x91;
        }
        WIFICLUB_ShowStreamedMessage(p, id, 0);
        WIFICLUB_ResetTimeIcon(p);
        ((struct Obj07947 *)p)->f1E0 = 0x78;
        ((struct Obj07947 *)p)->f1CC = 0x69;
    }
    return v;
}
