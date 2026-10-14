/*
 * function: func_021B8A98
 * address: 0x021B8A98
 * packet: pkt_ov172_021B8A98
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   DRAW_SYSTEM_PushStroke 0x021B6E88 thumb ov172
 */
#include "../include/Obj24086.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
extern u32 COMM_TVT_SYS_GetSprites(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void DRAW_SYSTEM_PushStroke(char *p, void *q);

void func_021B8A98(int a, u32 b, char *list, char *q)
{
    char *p;
    u8 n, i;
    p = (char *)COMM_TVT_SYS_GetSprites(((struct Obj24086 *)q)->f3DC);
    n = (b >> 3) & 0xff;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    for (i = 0; i < n; i++)
        DRAW_SYSTEM_PushStroke(p, list + i * 8);
}
