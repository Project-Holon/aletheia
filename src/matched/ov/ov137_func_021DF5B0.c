/*
 * function: func_021DF5B0
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
 *   func_021E0130 0x021E0130 thumb ov137
 *   func_02039C68 0x02039C68 arm
 *   func_0203516C 0x0203516C arm
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
extern void func_021E0130(u8 *,int);
extern void func_02039C68(struct Link *,u32,u32);
extern void func_0203516C(u32);
int func_021DF5B0(u8 *p) { struct Link *link; link=(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(); func_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj23762 *)(*(u8 * *)&((struct Obj23761 *)(*(u8 * *)&((struct Obj14226 *)p)->fD8))->f14))->f10,90); func_021E0130(p,11); func_02039C68(link,205,40); ((struct Obj14226 *)p)->f0=43; func_0203516C(8); return 0; }
