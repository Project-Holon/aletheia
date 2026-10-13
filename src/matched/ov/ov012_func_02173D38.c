/*
 * function: UNION_COMMAND_SendAppEntry
 * address:  0x02173D38
 * packet:   pkt_ov012_02173D38
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 */
#include "../include/Obj12448.h"
#include "../include/Obj19262.h"

typedef unsigned char u8;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int MYSTATUS_GetSize(void);
extern u8 *GAME_DATA_GetMyStatus(void *p);
typedef unsigned int   u32;
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 UNION_COMMAND_SendAppEntry(u8 *p)
{
    p[0x282B] = 0;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140A, MYSTATUS_GetSize(),
                  (u32)GAME_DATA_GetMyStatus((void *)(((struct Obj19262 *)(*(u8 * *)&((struct Obj12448 *)p)->f0))->f8)), 1, 0, 0);
}
