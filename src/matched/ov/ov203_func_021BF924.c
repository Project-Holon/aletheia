/*
 * function: func_021BF924
 * address: 0x021BF924
 * packet: pkt_ov203_021BF924
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BE9E8 0x021BE9E8 thumb ov203
 *   func_0203115C 0x0203115C arm
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 */
#include "../include/Obj02250.h"
typedef unsigned int   u32;
struct S02031140;
struct Tcbl;
extern void func_021BE9E8(int);
extern void func_0203115C(struct Tcbl *p);
extern void func_02005DE4(void *);
extern void func_02005DF8(u32 a);
extern void func_02049238(void *);
extern void func_0201D83C(void *);
extern void func_02031140(struct S02031140 *p);
extern int func_02005E9C(void);
void func_021BF924(char *p)
{
    if(((struct Obj02250 *)p)->f2C) func_021BE9E8(((struct Obj02250 *)p)->f2C);
    func_0203115C(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        func_02005E9C();func_02005DE4(0);func_02005DF8(60);
    }
    func_02049238(((struct Obj02250 *)p)->f28);func_0201D83C(((struct Obj02250 *)p)->f24);func_02031140(((struct Obj02250 *)p)->f20);
}
