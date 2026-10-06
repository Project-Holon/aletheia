/*
 * function: func_021F879C,func_021F8994
 * unit: yes
 * address: 0x021F879C
 * packet: pkt_ov132_021F879C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 * symbols:
 *   func_021F8EA8 0x021F8EA8 thumb ov132
 *   func_021FA6CC 0x021FA6CC thumb ov132
 *   func_021F9794 0x021F9794 thumb ov132
 *   func_021FABD8 0x021FABD8 thumb ov132
 *   func_021F9ECC 0x021F9ECC thumb ov132
 *   func_021F9374 0x021F9374 thumb ov132
 *   func_021F94F8 0x021F94F8 thumb ov132
 *   func_021FA064 0x021FA064 thumb ov132
 *   func_021F91CC 0x021F91CC thumb ov132
 *   func_021F9ED4 0x021F9ED4 thumb ov132
 *   func_021F9E4C 0x021F9E4C thumb ov132
 *   func_021F90E0 0x021F90E0 thumb ov132
 *   func_021FAD7C 0x021FAD7C thumb ov132
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F6F64 0x021F6F64 thumb ov112
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F6A58 0x021F6A58 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_0204A648 0x0204A648 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 */
#include "../include/Obj00191.h"
#include "../include/Obj23177.h"
#include "../include/Obj23178.h"
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 d_02FFFC3C,d_021FDE80;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void),func_0200FB24(void);
extern int func_02006238(void);
extern void func_021FCDEC(int,int);
struct Board;
struct Camera;
struct Lights;
extern int func_021FCE00(char *p, int id);
extern u8 func_021FAD7C(char *);
extern void func_021F8EA8(u8 *);
extern void func_021FA6CC(char *p);
extern void func_021F9794(char *p);
extern void func_021FABD8(char *p);
extern int func_021F9ECC(u8 *a0);
extern void func_021F9374(u8 *);
extern void func_021F94F8(char *p);
extern void func_021FA064(char *p);
extern void func_021F91CC(u8 *);
extern void func_021F9ED4(u8 *);
extern void func_021F9E4C(u8 *);
extern void func_021F90E0(u8 *);
extern void func_021F6F64(u8 *);
extern void func_021F7160(u8 *);
extern void func_021F6A58(char *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u8 *);
extern void func_021F75A0(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void),func_0204A648(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
int func_021F879C(u8 *p)
{
    u32 tick;
    tick=d_02FFFC3C;
    ((struct Obj00191 *)p)->f1E8=tick-((struct Obj00191 *)p)->f1EC;
    ((struct Obj00191 *)p)->f1EC=tick;
    switch(((struct Obj00191 *)p)->f1C) {
    case 0:
        func_0202208C(0,1,1,0,6,1,((struct Obj00191 *)p)->f0);
        ((struct Obj00191 *)p)->f1C=1;
        break;
    case 1:
        if(func_020221A4()==1) {
            if(**(u32 * *)&((struct Obj00191 *)p)->f30!=0) {
                ((struct Obj00191 *)p)->f1C=7;
                func_021FCDEC(**(int * *)&((struct Obj00191 *)p)->f30,200);
            } else ((struct Obj00191 *)p)->f1C=4;
        }
        break;
    case 2:
        if(func_02006238()==0) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00191 *)p)->f0);
            ((struct Obj00191 *)p)->f1C=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if((((struct Obj00191 *)p)->f2)++ >=60) ((struct Obj00191 *)p)->f1C=5;
        break;
    case 5:
        if(((struct Obj00191 *)p)->f164==0) {
            ((struct Obj00191 *)p)->fB4=((struct Obj23178 *)(*(u8 * *)&((struct Obj23177 *)(*(u8 * *)&((struct Obj00191 *)p)->f30))->f18))->fC;
            func_021F90E0(p);
            ((struct Obj00191 *)p)->f1C=6;
        }
        break;
    case 6:
        if(func_021FAD7C(*(char * *)&((struct Obj00191 *)p)->fB0)==0) {
            ((struct Obj00191 *)p)->fB4=0;
            if(((struct Obj00191 *)p)->f164==0) ((struct Obj00191 *)p)->f1C=2;
            else ((struct Obj00191 *)p)->f1C=255;
        }
        break;
    case 7:
        if(func_021FCE00(*(void **)*(u8 * *)&((struct Obj00191 *)p)->f30,200)==1)
            ((struct Obj00191 *)p)->f1C=4;
        break;
    }
    func_021F8EA8(p);
    func_021FA6CC((char *)(*(u8 * *)&((struct Obj00191 *)p)->fA4));
    func_021F9794((char *)p);
    if(d_021FDE80==0) func_021FABD8((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB0));
    func_021F6F64(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_021F7160(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F6A58((char *)(*(u8 * *)&((struct Obj00191 *)p)->f54));
    func_021F9ECC(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9374(p);
    func_021F51E8(*(u8 * *)&((struct Obj00191 *)p)->f34);
    func_021F6CB0((char *)(*(u8 * *)&((struct Obj00191 *)p)->f90));
    func_021F94F8((char *)p);
    func_021FA064((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB8));
    func_021F91CC(p);
    func_02047964(); func_020479D8();
    func_021F6E74(*(u8 * *)&((struct Obj00191 *)p)->f90);
    func_021F75A0(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F51F4((void **)(*(u8 * *)&((struct Obj00191 *)p)->f34));
    func_021F718C((char *)(*(u8 * *)&((struct Obj00191 *)p)->f40));
    func_021F6F8C(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_0204F7DC(((struct Obj00191 *)p)->fAC,((struct Obj00191 *)p)->fA8,0);
    func_021F9ED4(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9E4C(p);
    func_02047970(); func_0204A600();
    if(**(u32 * *)&((struct Obj00191 *)p)->f30!=0 && ((struct Obj00191 *)p)->f1C!=0 &&
       ((struct Obj00191 *)p)->f1C!=1 && ((struct Obj00191 *)p)->f1C!=2 &&
       ((struct Obj00191 *)p)->f1C!=3 && func_0200FB24()!=0)
        ((struct Obj00191 *)p)->f1C=2;
    return 0;
}
void func_021F8994(void) { func_0204A648(); }
