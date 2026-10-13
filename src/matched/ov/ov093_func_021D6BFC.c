/*
 * function: BTL_POKEPARAM_ReloadFromParam
 * address: 0x021D6BFC
 * packet: pkt_ov093_021D6BFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_ReloadFromMon 0x021D4EFC thumb ov093
 *   BTL_POKEPARAM_LoadMoves 0x021D4F84 thumb ov093
 *   BTL_POKEPARAM_SyncMovesFromMon 0x021D50B4 thumb ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S; struct Work;
extern void BTL_POKEPARAM_ReloadFromMon(struct S *,void *,u32,u32);
extern int BTL_POKEPARAM_LoadMoves(u8 *,void *,int);
extern void BTL_POKEPARAM_SyncMovesFromMon(struct Work *);
struct Flags { u8 pad[0x1b]; u8 low:5; u8 active:1; u8 high:2; };
void BTL_POKEPARAM_ReloadFromParam(u8 *p) { if(!((struct Flags *)p)->active) { BTL_POKEPARAM_ReloadFromMon((struct S *)p,((struct Obj00041 *)p)->f0,1,0); BTL_POKEPARAM_SyncMovesFromMon((struct Work *)p); } else { BTL_POKEPARAM_LoadMoves(p,((struct Obj00041 *)p)->f0,0); } }
