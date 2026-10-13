/*
 * function: func_021DB164
 * address: 0x021DB164
 * packet: pkt_ov119_021DB164
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB10C 0x021DB10C thumb ov119
 */
#include "../include/Obj10355.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021D8E84(void *,int);
extern void func_021DB10C(char *p);
void func_021DB164(char *p) {
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj10355 *)p)->f720),0x8c,(void *)(((struct Obj10355 *)p)->f738));
 func_021E1024(p);
 ((struct Obj10355 *)p)->f1074=1;
 func_021D8E84(p,(int)func_021DB10C);
}
