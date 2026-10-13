/*
 * function: CALENDER_CreateTask
 * address: 0x02164B38
 * packet: pkt_ov010_02164B38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   CALENDER_OverlaySequenceEvent 0x02164A2C thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 */
#include "../include/Obj07302.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct SeqWork2;
extern struct Desc *func_020122C0(void *,void *,void *,u32);
struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int CALENDER_OverlaySequenceEvent(void *,u32 *,struct SeqWork2 *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
void *CALENDER_CreateTask(void *a, void *b, u8 c){void *t=func_020122C0(a,0,(void *)CALENDER_OverlaySequenceEvent,0x1c);u8 *p=func_020124E8(t);void *v=GAMESYSTEM_GetGameData(a);((struct Obj07302 *)p)->f4=v;((struct Obj07302 *)p)->f8=GAME_DATA_GetSaveControl(v);((struct Obj07302 *)p)->f0=a; p[0x18]=c;return t;}
