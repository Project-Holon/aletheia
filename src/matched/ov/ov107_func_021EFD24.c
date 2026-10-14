/*
 * function: MB_COMM_SYS_FinishReceive
 * address: 0x021EFD24
 * packet: pkt_ov107_021EFD24
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   MB_COMM_SYS_GetMonCount 0x021F11C4 thumb ov107
 *   MB_UTIL_MSG_PrintQueued 0x021F17E0 thumb ov107
 *   MB_UTIL_MSG_SetTimeIconPending 0x021F1B38 thumb ov107
 *   MB_COMM_SYS_RegisterReceivedMons 0x021EFD98 thumb ov107
 *   func_0200C184 0x0200C184 thumb
 *   MB_COMM_SYS_GetMaxSeen 0x021F11E0 thumb ov107
 *   func_0200C18C 0x0200C18C thumb
 *   MB_COMM_SYS_UpdateSaveState 0x021EFC1C thumb ov107
 */
#include "../include/Obj02457.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk34;
extern u8 MB_COMM_SYS_GetMonCount(u8 *p);
extern void MB_UTIL_MSG_PrintQueued(void *,int);
extern void MB_UTIL_MSG_SetTimeIconPending(u8 *p, u32 v);
extern void MB_COMM_SYS_RegisterReceivedMons(void *);
extern u32 func_0200C184(struct Blk34 *p);
extern int MB_COMM_SYS_GetMaxSeen(unsigned char *a);
extern void func_0200C18C(struct Blk34 *p, u32 v);
extern void MB_COMM_SYS_UpdateSaveState(u8 *p, int mode);
void MB_COMM_SYS_FinishReceive(u8 *p) {
 unsigned v=MB_COMM_SYS_GetMonCount(((struct Obj02457 *)p)->fC);
 unsigned old,cur;
 MB_UTIL_MSG_PrintQueued(((struct Obj02457 *)p)->f68,6);MB_UTIL_MSG_SetTimeIconPending(((struct Obj02457 *)p)->f68,1);MB_COMM_SYS_RegisterReceivedMons(p);
 if(p[40]==0) {
 old=(u16)func_0200C184(((struct Obj02457 *)p)->f4C);cur=MB_COMM_SYS_GetMaxSeen(((struct Obj02457 *)p)->fC);
 if(old<cur) {func_0200C18C(((struct Obj02457 *)p)->f4C,cur);MB_COMM_SYS_UpdateSaveState(p,1);}
 else if(v==0) MB_COMM_SYS_UpdateSaveState(p,2);else MB_COMM_SYS_UpdateSaveState(p,0);
 if(((struct Obj02457 *)p)->f38<cur) ((struct Obj02457 *)p)->f38=cur;
 ((struct Obj02457 *)p)->f3C=((struct Obj02457 *)p)->f3C+v;
 }
}
