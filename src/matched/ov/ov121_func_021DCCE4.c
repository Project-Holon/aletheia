/*
 * function: func_021DCCE4
 * address: 0x021DCCE4
 * packet: pkt_ov121_021DCCE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 * symbols:
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA038 0x021DA038 thumb ov121
 *   func_021DA148 0x021DA148 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_0200A0C8 0x0200A0C8 thumb
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj00253.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 v[7];u16 a,b,c,d;} Desc;
extern void *func_021D9CA4(int a, unsigned char b, void *c, void *d, u16 heap);
typedef unsigned char  u8;
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021D9E50(u8 *p);
extern void *func_021DA038(const u8 *p, u16 heap);
extern void func_021DA148(u8 *p);
extern int func_021DA178(char *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021DA8B8(u32 *p);
extern void func_021DC08C(void *task, u32 *state, char *p);
extern int func_021DE014(char *p);
extern u32 func_0200A0C8(u8 *p);
extern void func_0200A2B8(void *a0, int a1);
extern int func_0200A2D8(void *a0, int a1);
extern void func_02082BCC(void *,int,int);
void func_021DCCE4(void *arg,u32 *state,char *p)
{
    Desc d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!((struct Obj00253 *)p)->f0) *state=5;
        else if (func_0200A0C8(((struct Obj00253 *)p)->fC)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,93,1);
        *state=3;
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) {
            func_02082BCC(&d,0,36);
            d.v[0]=*(u32 *)&((struct Obj00253 *)p)->f1C;
            d.v[1]=*(u32 *)&((struct Obj00253 *)p)->f10;
            d.v[2]=*(u32 *)&((struct Obj00253 *)p)->f14;
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            ((struct Obj00253 *)p)->fAC0=func_021DA038((const u8 *)(&d),((struct Obj00253 *)p)->f24);
            *state=4;
        }
        break;
    case 4:
        result=func_021DA178(((struct Obj00253 *)p)->fAC0);
        ((struct Obj00253 *)p)->fBAC=0x7fff;
        if (result!=-1) {
            func_021DA148(((struct Obj00253 *)p)->fAC0);
            ((struct Obj00253 *)p)->fAC0=0;
            if (!result) *state=5;
            else {
                if (((struct Obj00253 *)p)->fABC) {
                    func_021D9E04(((struct Obj00253 *)p)->fABC);
                    ((struct Obj00253 *)p)->fABC=0;
                }
                func_021DA8B0(arg,(u32)func_021DC08C);
            }
        }
        break;
    case 5:
        if (((struct Obj00253 *)p)->fAD4) *state=6;
        else *state=10;
        break;
    case 6:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,115,2);
        *state=7;
        break;
    case 7:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) *state=8;
        break;
    case 8:
        ready=1;
        if (((struct Obj00253 *)p)->fAAC && !func_021DE014(((struct Obj00253 *)p)->fAAC)) ready=0;
        if (ready) {
            func_0200A2B8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20));
            *state=9;
        }
        break;
    case 9:
        if (func_0200A2D8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20))==2) *state=10;
        break;
    case 10:
        if (((struct Obj00253 *)p)->fABC) {
            func_021D9E04(((struct Obj00253 *)p)->fABC);
            ((struct Obj00253 *)p)->fABC=0;
        }
        func_021DA8B8(arg);
        break;
    }
    if (((struct Obj00253 *)p)->fABC) func_021D9E50(((struct Obj00253 *)p)->fABC);
}
