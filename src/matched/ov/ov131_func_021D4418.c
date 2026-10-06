/*
 * function: func_021D4418
 * address: 0x021D4418
 * packet: pkt_ov131_021D4418
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x021D44C6.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021D5180 0x021D5180 thumb ov131
 *   func_021D5258 0x021D5258 thumb ov131
 *   func_021D4F24 0x021D4F24 thumb ov131
 *   func_021D91EC 0x021D91EC thumb ov131
 *   func_021D881C 0x021D881C thumb ov131
 *   func_021D9734 0x021D9734 thumb ov131
 *   func_021D7B34 0x021D7B34 thumb ov131
 *   func_021D6608 0x021D6608 thumb ov131
 *   func_021D48E4 0x021D48E4 thumb ov131
 *   func_02012BE0 0x02012BE0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01255.h"
#include "../include/Obj23120.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021D5180(char *);
extern void func_021D5258(char *);
extern void func_021D4F24(char *);
extern void func_021D91EC(void *,void *);
extern void func_021D881C(void *,u8 *);
extern void func_021D9734(u8 *a, u8 *p);
extern void func_021D7B34(int,char *);
extern void func_021D6608(void *,void *);
extern void func_021D48E4(char *);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_020355D8(u8);
extern u32 func_020307B0(void *p);
int func_021D4418(char *p)
{
    u8 i;
    func_02030EAC(((struct Obj01255 *)p)->f4);
    (*(u8 **)(p+8))[15]=((struct Obj01255 *)p)->f18;
    func_021D5180(p);
    func_021D5258(p);
    func_021D4F24(p);
    func_021D91EC(p,((struct Obj01255 *)p)->f94);
    func_021D881C(p,*(u8 * *)&((struct Obj01255 *)p)->f94);
    func_021D9734((u8 *)p,((struct Obj01255 *)p)->f90);
    func_021D7B34((int)p,*(char * *)&((struct Obj01255 *)p)->f8C);
    func_021D6608(p,((struct Obj01255 *)p)->f88);
    func_021D48E4(p);
    if(((struct Obj01255 *)p)->f58<3){
        for(i=0;i<3;i++) func_02012BE0(((struct Obj23120 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8,i+7,*(int *)(p+i*4+0x60));
    }
    if(((struct Obj01255 *)p)->f14==1){
        (*(u8 **)(p+8))[13]=3;
        ((struct Obj01255 *)p)->f14=0;
    }
    func_020355D8(((struct Obj01255 *)p)->f1C);
    if(((struct Obj01255 *)p)->f258) func_020307B0(((struct Obj01255 *)p)->f258);
    return 1;
}
