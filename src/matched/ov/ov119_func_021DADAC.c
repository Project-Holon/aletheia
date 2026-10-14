/*
 * function: func_021DADAC
 * address:  0x021DADAC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_SAVE_OpenMessageWindowTop  0x021E1024  thumb  ov119
 *   POKETRADE_SAVE_ShowTimeIcon  0x021E1030  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 */
#include "../include/Obj00001.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern int POKETRADE_PROC_IsNetSession(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int v);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
struct Entry;
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct MsgBank;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

void func_021DADAC(void *p)
{
    u8 b = 3;

    if (POKETRADE_PROC_IsNetSession(p) == 0) {
        MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x61,
                      (void *)(*(int *)&((struct Obj00001 *)p)->f738));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p, 0x021DAEF1);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b)) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, 0x021DAD85);
}
