/*
 * function: GURU2_MAIN_StateSaveResult
 * address: 0x021DF5B0
 * packet: pkt_ov137_021DF5B0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02008DF0 0x02008DF0 thumb
 *   GURU2_MAIN_PrintMessage 0x021E0130 thumb ov137
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   UI_SetSoftResetInhibitGlobal 0x0203516C arm
 */
#include "../include/Obj14226.h"
#include "../include/Obj23761.h"
#include "../include/Obj23762.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link; struct Sub02008C20Obj;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern void GURU2_MAIN_PrintMessage(u8 *,int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern void UI_SetSoftResetInhibitGlobal(u32);
int GURU2_MAIN_StateSaveResult(u8 *p) { struct Link *link; link=(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(); func_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj23762 *)(*(u8 * *)&((struct Obj23761 *)(*(u8 * *)&((struct Obj14226 *)p)->fD8))->f14))->f10,90); GURU2_MAIN_PrintMessage(p,11); GFL_NET_HANDLE_SetTimingSyncRange(link,205,40); ((struct Obj14226 *)p)->f0=43; UI_SetSoftResetInhibitGlobal(8); return 0; }
