/*
 * file:     pokemontrade_proc_p11.c
 * unit:     yes
 * function: func_021DAF68, func_021DAFB8, func_021DB030, func_021DB0A0, func_021DB10C, func_021DB164, func_021DB198, func_021DB1BC, func_021DB278, func_021DB290, func_021DB2E8, func_021DB304, func_021DB41C, func_021DB45C
 * address:  0x021DAF68
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D9C00 0x021D9C00 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_02039C68 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021E131C 0x021E131C thumb ov119
 *   d_021E758C 0x021E758C data a4
 *   func_0207D658 0x0207D658 arm
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021E4AA4 0x021E4AA4 thumb ov119
 *   func_021DB4B4 0x021DB4B4 thumb ov119
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   func_020435F4 0x020435F4 arm
 *   func_021E5D84 0x021E5D84 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021E71E0 0x021E71E0 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021E707C 0x021E707C thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E8044 0x021E8044 data a1
 *   func_021E6FD4 0x021E6FD4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021E0EF4 0x021E0EF4 thumb ov119
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021E5C64 0x021E5C64 thumb ov119
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22732.h"
#include "../../matched/include/Obj10355.h"
#include "../../matched/include/Obj01055.h"

struct Entry;
struct MsgBank;
struct Link;
struct TaskMenu;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct { int a,b; } Pair;

typedef struct { u8 a,b,c,d; } Rect;

extern int func_021E12AC(char *p);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D9C00(char *p);
extern void func_021D8E84(void *,int),func_021DAF68(void *),func_021D9434(void *);
extern void func_02039C68(struct Link *,unsigned,unsigned);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021E6700(void *);
extern void func_021DBE70(char *p);
extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern unsigned int func_020173EC(void);
extern u32 func_020307B0(void *p);
extern void func_021D9468(void *,int,void *);
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern int func_021E4DBC(char *);
extern int func_021D8AF4(int,char *);
extern int func_021D8B0C(int,int);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021E4AA4(int,int);
extern int func_021DB4B4(int);
extern void func_021DB7AC(char *,int,int);
extern void func_020435F4(unsigned);
extern void func_021E5D84(char *p);
extern void func_021DF7AC(void *,int);
extern void func_021E71E0(void *,int);
extern void func_021DBB6C(char *p);
extern void func_021E7058(void *);
extern int func_021E707C(void *);
extern int func_021E12AC(char *),func_02035C08(const void *);
extern void func_021E6FD4(char *,int,int);
extern void func_020061E4(u32 a);
extern void func_021E0EF4(char *p, int flag, int x, int y, int w, int h);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *);
extern void func_021E5C64(char *p);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern int func_021DD2F4(char *p);
void func_021DAF68(void *p);
void func_021DAFB8(char *p);
void func_021DB030(char *p);
int func_021DB0A0(char *p);
void func_021DB10C(char *p);
void func_021DB164(char *p);
void func_021DB198(void *p);
int func_021DB1BC(char *p,int kind);
void func_021DB278(void *p);
void func_021DB290(void *p);
void func_021DB2E8(void *p);
void func_021DB304(char *p);
void func_021DB41C(char *p);
void func_021DB45C(char *p);
extern const Pair d_021E758C;
extern Rect d_021E8044[];

void func_021DAF68(void *p) {
 unsigned id=(unsigned)func_020399A8();
 u8 b;
 if(func_021E12AC(p)) {
  if(func_021D8A24(p)) {
   b=2;
   if(func_0203D3A8((void *)id,0xc0f,1,(u32)(&b))) func_021D8E84(p,(int)func_021D9C00);
  } else { func_021D8E84(p,(int)func_021D9C00); }
 }
}

void func_021DAFB8(char *p) {
 u8 b;
 if(func_021D8A24(p)) {
  b=4;
  if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&b))) {
   func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),136,(void *)(*(int *)&((struct Obj00001 *)p)->f738));func_021E1024(p);func_021E1030(p);
   func_02039C68((struct Link *)func_020399A8(),26,8);func_021D8E84(p,(int)func_021DAF68);
  }
 } else {((struct Obj22732 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8=3;func_021D8E84(p,(int)func_021D9434);}
}

/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 */
void func_021DB030(char *p) {
 int v;
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
  v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));func_021E12F8(p);*(int *)&((struct Obj00001 *)p)->f64C=0;
  switch(v) {
  case 0:func_021D8E84(p,(int)func_021DAFB8);return;
  case 1:func_021E1098(p);func_021D8E84(p,(int)func_021DBE70);
   ((struct Obj00001 *)p)->f1080=-1;func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);func_021E6700(p);return;
  }
 }
}

int func_021DB0A0(char *p)
{
    int t=(int)func_021D8D4C(*(void ** *)&((struct Obj00001 *)p)->f828,((struct Obj00001 *)p)->fF88,((struct Obj00001 *)p)->fF84,p);
    if(func_021D8A24(p)) {
        unsigned id=(unsigned)func_020399A8();
        if(func_0203D3A8((void *)id,(u16)0xc01,(u16)func_020173EC(),t)==0) {
            func_020307B0((void *)t);
            return 0;
        }
    }
    func_021D9468(p,0,(void *)t);
    func_020307B0((void *)t);
    return 1;
}

void func_021DB10C(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E758C;
        func_021E131C(p,(int *)(&t),2,0x20,0xc);
        ((struct Obj00001 *)p)->f1080=-1;
        func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);
        func_021D8E84(p,(int)func_021DB030);
    }
}

void func_021DB164(char *p) {
 func_02045CAC((struct MsgBank *)(((struct Obj10355 *)p)->f720),0x8c,(void *)(((struct Obj10355 *)p)->f738));
 func_021E1024(p);
 ((struct Obj10355 *)p)->f1074=1;
 func_021D8E84(p,(int)func_021DB10C);
}

void func_021DB198(void *p) {
 func_0207D658((u32)((void *)0x04001050),27,-8);
 func_021D8E84(p,(int)func_021DB164);
}

int func_021DB1BC(char *p,int kind)
{
    int index=func_021E4DBC(p);
    int outer;
    for(outer=0;outer<((struct Obj00001 *)p)->f634;outer++) {
        int inner;
        index++;
        if(index>=((struct Obj00001 *)p)->f634) index=0;
        for(inner=0;inner<5;inner++) {
            int a=func_021D8AF4(index,p);
            int b=func_021D8B0C(index,inner);
            int obj=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),a,b,p);
            if(obj && func_021E4AA4(func_02017E88((void *)obj,0xab,0),kind) && !func_02017E88((void *)obj,0x4c,0)) {
                ((struct Obj00001 *)p)->f1080+=1;
                ((struct Obj00001 *)p)->f107C=func_021DB4B4(index)-0x20;
                ((struct Obj00001 *)p)->f1084=1;
                func_021DB7AC(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}

void func_021DB278(void *p) {
 func_020435F4(30);
 func_021D8E84(p,(int)func_021DBE70);
}

/*
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 */
void func_021DB290(void *p)
{
    func_020435F4(0x1a);
    func_021E5D84(p);
    func_021E1098(p);
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_021DF7AC(p,1);
    func_021E71E0(p,0);
    func_021DBB6C(p);
    func_021E6700(p);
    func_021E7058(p);
    func_021D8E84(p,(int)func_021DB278);
}

void func_021DB2E8(void *p) {
 if(func_021E707C(p)==0) func_021D8E84(p,(int)func_021DB290);
}

/*
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 */
void func_021DB304(char *p)
{
    int index;
    func_020435F4(31);
    if(func_021E12AC(p)) {
        index=func_02035C08(d_021E8044);
        if(index!=-1) {
            ((struct Obj00001 *)p)->f800=(u32)index+1u;
            func_021E6FD4(p,d_021E8044[index].c,d_021E8044[index].a);
            if(func_021DB1BC(p,index)) {
                func_020061E4(0x548);
                *(volatile u32 *)0x04001000 &= 0xffff1fff;
                func_021D8E84(p,(int)func_021DB2E8);
                return;
            }
            func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x34,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
            func_021E0EF4(p,1,1,1,0x1d,4);
            func_020061E4(0x557);
        }
        func_021B63D0(((struct Obj00001 *)p)->f9C0);
        if(func_021B6448(*(u8 * *)&((struct Obj00001 *)p)->f9C0)==1) {
            func_020435F4(0x1a);
            *(int *)&((struct Obj00001 *)p)->f800=0;
            func_021E5D84(p);
            func_021E1098(p);
            *(volatile u32 *)0x04001000 &= 0xffff1fff;
            func_021DF7AC(p,1);
            func_021E71E0(p,0);
            func_021DBB6C(p);
            func_021E6700(p);
            func_021E7058(p);
            func_021D8E84(p,(int)func_021DB290);
        }
    }
}

void func_021DB41C(char *p)
{
    func_021E5C64(p);
    func_02045CAC((struct MsgBank *)(((struct Obj01055 *)p)->f720),0x33,(void *)(*(int *)&((struct Obj01055 *)p)->f738));
    func_021E0EF4(p,1,1,1,0x1d,4);
    func_021D8E84(p,(int)func_021DB304);
}

void func_021DB45C(char *p)
{
    func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,0);
    func_021DF7AC(p,0);
    func_0207D658((u32)((void *)0x04001050),10,-8);
    func_021E71E0(p,1);
    if(func_021DD2F4(p))
        func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    func_021D8E84(p,(int)func_021DB41C);
}
