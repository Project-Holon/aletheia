/*
 * file:     pokemontrade_proc_p24.c
 * unit:     yes
 * function: func_021DE3E8, func_021DE518, func_021DE5C4, func_021DE66C
 * address:  0x021DE3E8
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
 *   func_02040588 0x02040588 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE2C4 0x021DE2C4 thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE1B4 0x021DE1B4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE3BC 0x021DE3BC thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_021E1D68 0x021E1D68 thumb ov119
 *   func_021E6440 0x021E6440 thumb ov119
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021DE12C 0x021DE12C thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   d_021E770C 0x021E770C data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 */
#include "../../matched/include/Obj00251.h"
#include "../../matched/include/Obj03775.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22744.h"

struct TaskMenu;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct S S;

typedef struct { char pad[0xfd8]; int obj[2][3]; } State_021DE3E8;

typedef struct { char pad[0xfd8]; void *obj[2][3]; } State_021DE518;

typedef struct { int a,b,c; } Triple;

extern void func_02040588(unsigned char which, unsigned char enable);
extern unsigned func_020221A4(void);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *),func_021B6470(u8 *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int);
extern void func_021DE2C4(char *);
extern void func_021DE3BC(char *p);
extern int func_02035C08(const void *);
extern void func_020355D8(u8);
extern void func_021E68F4(int,int);
extern void func_021DE1B4(State_021DE3E8 *,int);
extern void func_020061E4(u32 a);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern int func_021DE208(char *);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_021E1D68(char *p, void *a);
extern void func_021E6440(int p, int a, int b);
extern void func_021DEBD4(void *);
extern int func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern void func_021DE12C(char *p);
extern void func_021DEA24(char *p);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
void func_021DE3E8(char *p);
void func_021DE518(State_021DE518 *p);
void func_021DE5C4(char *p);
void func_021DE66C(char *p);
extern const char d_021E80C4[];
extern const Triple d_021E770C;

static inline int poll(void) { int v=func_020362DC(); if(v)func_020355D8(0); return v; }

/*
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 */
void func_021DE3E8(char *p)
{
    int idx;
    func_02040588(3,1);
    if(func_020221A4()) {
        func_021B63D0(*(S * *)&((struct Obj00251 *)p)->f9C0);
        if(func_021B6448(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
            func_0202208C((void *)3,0,0,0,6,1,((struct Obj00251 *)p)->f5F4);
            func_021D8E84(p,(int)func_021DE2C4);
            return;
        }
        if(func_021B6470(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==-1) {
            idx=func_02035C08(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                ((struct Obj00251 *)p)->f10A0=idx;
                func_021E68F4((int)p,-1);
                func_021DE1B4((State_021DE3E8 *)p,((struct Obj00251 *)p)->f10A0);
                func_020061E4(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                func_020061E4(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_021DE208(p)) {
                func_020061E4(0x548);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                func_021DE1B4((State_021DE3E8 *)p,((struct Obj00251 *)p)->f10A0);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
            }
        }
    }
}

void func_021DE518(State_021DE518 *p)
{
    char *b=(char *)p;
    u16 idx;
    int col,row;
    void *obj;
    int other;
    if(func_020221A4()) {
        idx=(u16)((struct Obj03775 *)b)->f10A0;
        col=idx%3; row=idx/3;
        other=1-row;
        obj=p->obj[other][col];
        b[0x11f3]=1;
        if(obj && func_02017E1C(obj,169,0)) {
            func_021E1D68((char *)p,obj); func_021E6440((int)p,row,col);
        }
        func_021DEBD4(p);
        func_0202208C((void *)3,1,1,0,6,1,((struct Obj03775 *)b)->f5F4);
        func_021D8980((char *)p); func_021DD09C((char *)p);
        func_021D8E84(p,(int)func_021DE3E8);
    }
}

void func_021DE5C4(char *p)
{
    int v;
    if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
        func_021E12F8(p); func_021E1098(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        switch(v) {
        case 0: func_021D8E84(p,(int)func_021DE12C); return;
        case 1:
            func_0202208C((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
            func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);
            func_021D8E84(p,(int)func_021DE518); return;
        case 2:
            func_021DEBD4(p); func_021D8980(p); func_021DD09C(p);
            func_021D8E84(p,(int)func_021DEA24); return;
        }
    }
}

void func_021DE66C(char *p)
{
    Triple t=d_021E770C;
    func_021E1410(p,(int *)(&t),3);
    func_021B6558((unsigned char *)(((struct Obj22744 *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DE5C4);
}
