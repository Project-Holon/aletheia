/*
 * function: func_021DC4F0
 * address: 0x021DC4F0
 * packet: pkt_ov121_021DC4F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9D4C 0x021D9D4C thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021DA038 0x021DA038 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021DA148 0x021DA148 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021DC030 0x021DC030 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 *   func_021DC734 0x021DC734 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   data_021DF86E 0x021DF86E data a1
 */
#include "../include/Obj00169.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v[7]; u16 a,b,c,d; } Desc;
typedef struct { short x,y; } Vec;
typedef struct { u8 x,y,pad[6]; } Coord;
extern const Coord data_021DF86E[];
extern void *func_021D9CA4(int,int,void *,void *,int);
extern void *func_021D9D4C(int,int,void *,void *,int);
struct Obj;
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern void *func_021DA038(const void *,u16);
extern int func_021DA178(char *p);
extern void func_021DA148(u8 *p);
extern void func_021D9E04(u8 *);
extern void func_021D9E50(u8 *);
extern unsigned func_021D9FF8(u8 *p);
extern int func_021DC030(u32 p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021DC08C(void *task, u32 *state, char *p);
extern void func_021DC734(void *task, u32 *state, char *p);
extern void func_02082BCC(void *,int,u32);
extern void func_0204B404(void *,const Vec *,u32);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021DC4F0(void *task,u32 *state,u8 *p)
{
    Desc d;
    Vec v;
    int result;
    switch (*state) {
    case 0:
        if (!((struct Obj00169 *)p)->fABC) {
            ((struct Obj00169 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
            func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,116,0);
        *state=1;
        break;
    case 1:
        func_02082BCC(&d,0,36);
        d.v[0]=*(u32 *)&((struct Obj00169 *)p)->f1C; d.v[1]=*(u32 *)&((struct Obj00169 *)p)->f10; d.v[2]=*(u32 *)&((struct Obj00169 *)p)->f14;
        d.v[3]=117;d.v[4]=118;d.v[5]=119;d.v[6]=3;
        d.a=0;d.b=15;d.c=13;d.d=1;
        ((struct Obj00169 *)p)->fAC0=func_021DA038(&d,((struct Obj00169 *)p)->f24);
        *state=2;
        break;
    case 2:
        result=func_021DA178(((struct Obj00169 *)p)->fAC0);
        ((struct Obj00169 *)p)->fBAC=0x7fff;
        if (result==-1) break;
        if (result==0) {
            ((struct Obj00169 *)p)->fAE0=1;
            v.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
            v.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
            func_0204B404(((struct Obj00169 *)p)->fAF0,&v,0);
            func_0204B3DC(((struct Obj00169 *)p)->fAF0,1);
            ((struct Obj00169 *)p)->fADE=((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4;
            if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
            if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
            if (!((struct Obj00169 *)p)->fABC) {
                ((struct Obj00169 *)p)->fABC=func_021D9D4C(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
                func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
            }
            func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,122,0);
            *state=6;
        } else if (result==1) {
            if (func_021DC030((u32)((void *)((u32)p+40+220*(((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4))))) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,120,1);
        *state=4;
        break;
    case 4:
        if (func_021D9FF8(((struct Obj00169 *)p)->fABC)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 6:
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 7:
        func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;
        func_021DA8B0(task,(u32)func_021DC734);
        break;
    }
    if (*(u8 * *)&((struct Obj00169 *)p)->fABC) func_021D9E50(*(u8 * *)&((struct Obj00169 *)p)->fABC);
}
