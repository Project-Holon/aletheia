/*
 * function: func_021F022C
 * address: 0x021F022C
 * packet: pkt_ov031_021F022C
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj06132.h"
struct Bank;
struct PrintSys;
struct Rec;
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0204B1CC(struct Bank *bank);
void func_021F022C(char *p)
{
    func_02045C04(((struct Obj06132 *)p)->f48);
    func_0201D83C(((struct Obj06132 *)p)->f44);
    func_0201C6EC(((struct Obj06132 *)p)->f40);
    func_0201C4C0(((struct Obj06132 *)p)->f40);
    func_0204B1CC(((struct Obj06132 *)p)->f14);
}
