/*
 * function: func_021B9DEC
 * address: 0x021B9DEC
 * packet: pkt_ov225_021B9DEC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9F8C 0x021B9F8C thumb ov225
 *   func_021B9E80 0x021B9E80 thumb ov225
 *   func_021B9F20 0x021B9F20 thumb ov225
 *   func_021B9BA4 0x021B9BA4 thumb ov225
 *   func_02049238 0x02049238 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B99A0 0x021B99A0 thumb ov225
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01787.h"
struct Rec;struct PrintSys;
extern void func_021B9F8C(char *p);
extern void func_021B9E80(char *,unsigned);
extern void func_021B9F20(void *);
extern void func_021B9BA4(char *p);
extern void func_02049238(void *);
extern void func_02045C04(struct Rec *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern void func_021B99A0(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021B9DEC(char *p)
{
    func_021B9F8C(((struct Obj01787 *)p)->f34);func_021B9E80(p,0xffff);func_021B9F20(p);
    func_021B9BA4(((struct Obj01787 *)p)->f2C);func_02049238(((struct Obj01787 *)p)->f24);func_02049238(((struct Obj01787 *)p)->f28);
    func_02045C04(*(struct Rec * *)&((struct Obj01787 *)p)->f1C);func_02045C04(*(struct Rec * *)&((struct Obj01787 *)p)->f20);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);
    func_0201D83C(((struct Obj01787 *)p)->fC);func_021B99A0(*(char * *)&((struct Obj01787 *)p)->f8);func_020307B0(p);
}
