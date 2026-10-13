/*
 * function: GPOWER_EVENT_CreateFlashEvent
 * address: 0x021F5340
 * packet: pkt_ov083_021F5340
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GPOWER_EVENT_FlashMain 0x021F542C thumb ov083
 */
#include "../include/Obj13226.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GPOWER_EVENT_FlashMain(int a0, int *p);
void *GPOWER_EVENT_CreateFlashEvent(void *p) { void *task; u8 *w; task=func_020122C0(p,0,(void *)GPOWER_EVENT_FlashMain,12); w=func_020124E8(task); ((struct Obj13226 *)w)->f8=GAMESYSTEM_GetGameData(p); ((struct Obj13226 *)w)->f4=p; return task; }
