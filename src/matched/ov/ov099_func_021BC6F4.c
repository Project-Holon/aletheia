/*
 * function: WIFICLUB_StateSyncAsGuest
 * address:  0x021BC6F4
 * packet:   pkt_ov099_021BC6F4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *
 * Levers: the word index 0x73 of the first arm is an enum-typed local set
 * before the call (it keeps r6 = 0x73 live across it); the stores are written
 * out per arm.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef enum { K73 = 0x73 } Idx;

extern u32 GFL_NET_IsParentAid(void);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, unsigned int a, unsigned int b);

int WIFICLUB_StateSyncAsGuest(char *p, int v)
{
    u32 *a = (u32 *)p;
    Idx k;

    if (GFL_NET_IsParentAid() != 0) {
        k = K73;
        WIFICLUB_ShowStreamedMessage(p, 0x73, 0);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
        a[k] = 0x49;
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x72, 0);
        a[0x78] = 0x78;
        a[0x73] = 0x8f;
    }
    return v;
}
