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
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021E1030  0x021E1030  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   func_02039C68  0x02039C68  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 */
#include "../include/Obj00001.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern void func_021E1024(void *p);
struct Entry;
extern void func_021E1030(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct MsgBank;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

void func_021DADAC(void *p)
{
    u8 b = 3;

    if (func_021D8A24(p) == 0) {
        MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x61,
                      (void *)(*(int *)&((struct Obj00001 *)p)->f738));
        func_021E1024(p);
        func_021D8E84(p, 0x021DAEF1);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b)) == 0)
        return;
    func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, 0x021DAD85);
}
