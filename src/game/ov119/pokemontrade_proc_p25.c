/*
 * file:     pokemontrade_proc_p25.c
 * unit:     yes
 * function: func_021DE6AC, func_021DE70C, func_021DE754, func_021DE820, func_021DE8C0, func_021DE918, func_021DE950, func_021DE988, func_021DE9E8
 * address:  0x021DE6AC
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
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_020173EC 0x020173EC thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE66C 0x021DE66C thumb ov119
 *   func_021D8F20  0x021D8F20  thumb  ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_02082D44 0x02082D44 arm
 *   func_021D8F60 0x021D8F60 thumb ov119
 *   func_021DDAD4 0x021DDAD4 thumb ov119
 *   func_020221A4 0x020221A4 thumb
 *   func_021DC720 0x021DC720 thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   func_0204B100 0x0204B100 arm
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   func_0203D34C 0x0203D34C arm
 *   func_021DACE4 0x021DACE4 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_02039C68  0x02039C68  arm
 *   func_021DDF74  0x021DDF74  thumb  ov119
 *   func_02045CAC  0x02045CAC  arm
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021E1030  0x021E1030  thumb  ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   d_021E76DC     0x021E76DC  data  a4
 *   func_021E131C  0x021E131C  thumb  ov119
 */
#include "../../matched/include/Obj10361.h"
#include "../../matched/include/Obj00251.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj00252.h"
#include "../../matched/include/Obj10362.h"

struct Entry;
struct Bank;
struct Link;
struct MsgBank;
struct TaskMenu;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u8 pad[0x11fb]; u8 state:4; u8 other:4; } Flags;

typedef unsigned int   u32;

typedef struct { char pad[0xfa4]; int entry[2][3]; char gap[0x1c]; void *mon[2][3]; int value[2][3]; } State;

typedef struct {
    int a;
    int b;
} Pair;

extern int func_021D8A24(void *);
extern struct Entry *func_020399A8(void);
extern u32 func_020173EC(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D8E84(void *,int);
extern void func_021DE66C(char *p);
extern int func_021D8F20(void *p, int idx);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern void func_020061E4(u32 a);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D9468(void *,int,void *);
extern void func_02082D44(void *,const void *,int);
extern void func_021D8F60(void *,int,int);
extern void func_021DDAD4(char *p);
extern unsigned int func_020221A4(void);
extern void func_021DC720(char *p);
extern void func_021E57E8(int);
extern void func_021E5680(char *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021E10D8(char *p);
extern void func_021E58A0(int p);
extern void func_021E467C(char *p);
extern void func_021E3E80(char *p);
extern void func_021E3FE4(char *p);
extern void func_021E3F74(char *p);
extern void func_021E3208(void *,int);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_021E3C20(char *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021DACE4(char *p);
extern int func_021E12AC(char *p);
extern int func_021DD140(char *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021DDF74(char *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *p);
extern void func_021E1030(char *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern int func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern void func_021DEA24(char *p);
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
void func_021DE6AC(char *p);
void func_021DE70C(void *p);
int func_021DE754(char *p,int idx);
void func_021DE820(char *p);
void func_021DE8C0(char *p);
void func_021DE918(void *p);
void func_021DE950(char *p);
void func_021DE988(char *p);
void func_021DE9E8(void *p);
extern const Pair d_021E76DC;

void func_021DE6AC(char *p)
{
    unsigned id;
    if(((Flags *)p)->state==1) return;
    if(func_021D8A24(p)!=0) {
        id=(unsigned)func_020399A8();
        if(!func_0203D3A8((void *)id,(u16)0xc01,(u16)func_020173EC(),(u32)(((struct Obj10361 *)p)->f106C))) return;
    }
    p[0x11fb]=((u8)p[0x11fb]&~15)|1;
    func_021D8E84(p,(int)func_021DE66C);
}


void func_021DE70C(void *p)
{
    u8 v;
    if (func_021D8A24(p) != 0) {
        v = func_021D8F20(p, 0);
        if (func_0203D3A8((struct Entry *)((u32)func_020399A8()), (u16)0xC16, (u16)func_020173EC(), (u32)(&v)) == 0) {
            return;
        }
    }
    func_021D8E84(p, (int)func_021DE6AC);
}

/*
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 */
int func_021DE754(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    State *s=(State *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->entry[1-row][col];
    if(entry==-1) goto fail;
    mon=s->mon[1-row][col];
    value=s->value[1-row][col];
    if(mon==0 || func_02017E1C(mon,169,0)==0) goto fail;
    ((struct Obj00251 *)p)->f10A0=idx;
    func_020061E4(0x54c);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
    if(row!=0) {
        func_021D8E84(p,(int)func_021DDAD4);
    } else {
        func_021D9468(p,row,mon);
        func_02082D44(mon,((struct Obj00251 *)p)->f106C,func_020173EC());
        func_021D8F60(p,0,value);
        func_021D8E84(p,(int)func_021DE70C);
    }
    return 1;
fail:
    return 0;
}

/*
 * volatile: 0x021DE89A reads 0x04001000 before the store at 0x021DE89E.
 */
void func_021DE820(char *p)
{
    if(func_020221A4()) {
        func_021DC720(p); func_021E57E8(0); func_021E5680(p);
        ((struct Obj00252 *)p)->f9C4=func_0204B100(0x154,0,((struct Obj00252 *)p)->f5F4);
        func_021E10D8(p); func_021E58A0((int)p); func_021E467C(p);
        func_021E3E80(p); func_021E3FE4(p); func_021E3F74(p);
        func_021E3208(p,0); func_02043534(31); func_020435F4(30);
        func_021E3C20(p); func_0203D34C(0,((struct Obj00252 *)p)->f5F4);
        *(volatile unsigned *)0x04001000 &= 0xffff1fff;
        func_021D8E84(p,(int)func_021DACE4);
    }
}

void func_021DE8C0(char *p)
{
    func_020399A8();
    if(func_021E12AC(p) && func_021DD140(p) && ((struct Obj00001 *)p)->fF2C>=120) {
        func_0202208C(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
        func_021D8E84(p,(int)func_021DE820);
    }
}


void func_021DE918(void *p)
{
    u8 cmd;
    cmd = 0xC;
    if (func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0xC00, 1, (u32)(&cmd)) != 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x1C, 8);
        func_021D8E84(p, (int)func_021DDF74);
    }
}


void func_021DE950(char *p)
{
    func_02045CAC(((struct Obj10362 *)p)->f720, 0x88, ((struct Obj10362 *)p)->f738);
    func_021E1024(p);
    func_021E1030(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DE918);
}

void func_021DE988(char *p)
{
    int v;
    if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
        func_021E12F8(p);
        func_021E1098(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        if(v==0) {
            func_021D8E84(p,(int)func_021DE950);
            return;
        }
        func_021E1098(p);
        func_021D8980(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}


void func_021DE9E8(void *p)
{
    Pair t;
    if (func_021E12AC(p) != 0) {
        t = d_021E76DC;
        func_021E131C(p, (int *)&t, 2, 0x20, 12);
        func_021D8E84(p, (int)func_021DE988);
    }
}
