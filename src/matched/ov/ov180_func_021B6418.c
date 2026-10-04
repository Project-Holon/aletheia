/*
 * function: func_021B6418
 * address: 0x021B6418
 * packet: pkt_ov180_021B6418
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 */
#include "../include/Obj02515.h"
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap); extern void *func_020457B0(unsigned,unsigned);
void func_021B6418(char *p) {
 ((struct Obj02515 *)p)->f9038=func_02045B38(0,2,32,141);
 ((struct Obj02515 *)p)->f9030=func_0201D7EC(23,0,0,0,141);
 ((struct Obj02515 *)p)->f9034=func_0201D7EC(23,3,0,0,141);
 ((struct Obj02515 *)p)->f903C=func_0201EC64(141);
 ((struct Obj02515 *)p)->f9040=func_020457B0(1024,141);
}
