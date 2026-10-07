/*
 * file:     pokemontrade_3d_p03.c
 * unit:     yes
 * function: func_021E198C, func_021E1A44, func_021E1AA8, func_021E1B14, func_021E1CA8, func_021E1CC8, func_021E1CE8
 * address:  0x021E198C
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
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   d_021E7934 0x021E7934 data a4
 *   d_021E7914 0x021E7914 data a4
 *   d_021E794C 0x021E794C data a4
 *   func_02017E1C 0x02017E1C thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 *   func_0204B84C 0x0204B84C arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021E0DA0 0x021E0DA0 thumb ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021E3F70  0x021E3F70  thumb  ov119
 *   func_021E5BE4  0x021E5BE4  thumb  ov119
 *   func_021E5EF8  0x021E5EF8  thumb  ov119
 *   func_021E625C  0x021E625C  thumb  ov119
 *   func_020456F8  0x020456F8  arm
 */
#include "../../matched/include/Obj00001.h"

struct MsgBank;
struct WordSet;
struct Descriptor;
struct Rec;
struct Cfg;
typedef signed short s16;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct {int a,b;} Pair;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern unsigned int func_02017E1C(void *,unsigned int,unsigned int);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u8 func_02018598(void *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201DD78(u32,u32,u32);
extern int func_021D8ADC(char *p);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E1778(int,int,int,int,char *);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
extern void func_0204B84C(void *,u32);
extern void func_021E0E4C(char *p);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern void func_021E0DA0(char *p);
extern void func_021E36D8(void *p, int a);
extern void func_021E3F70(void *p);
extern void func_021E5BE4(int a);
extern void func_021E5EF8(void *p);
extern void func_021E625C(void *p);
extern void func_020456F8(struct Descriptor *d);
void func_021E198C(int a,int b,int x,int y,char *p);
void func_021E1A44(int a,int b,int x,int y,char *p);
void func_021E1AA8(int a,int b,int x,int y,char *p);
void func_021E1B14(char *p,int i,void *mon);
void func_021E1CA8(char *p);
void func_021E1CC8(char *p);
void func_021E1CE8(void *p, int a1);
extern const Pair d_021E7934,d_021E7914,d_021E794C;

void func_021E198C(int a,int b,int x,int y,char *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=func_02017E1C((void *)a,54+i,0);
        if(v) {
            func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),45,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
            func_0201EF34((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v);
            func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
            func_0201C7A4(func_02045770((struct Descriptor *)b),x,y+16*i,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
        }
    }
}

void func_021E1A44(int a,int b,int x,int y,char *p)
{
    int s;
    s=(int)func_02045B38(0,2,24,((struct Obj00001 *)p)->f5F4);
    func_02045CAC((struct MsgBank *)s,func_02018598((void *)a),(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
    func_02045C04((struct Rec *)s);
}

void func_021E1AA8(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),42,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    v=func_02017E1C((void *)a,10,0);
    func_0201EF8C((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
}

/*
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 */
void func_021E1B14(char *p,int i,void *mon)
{
    Pair a=d_021E7934;
    Pair b=d_021E7914;
    Pair c=d_021E794C;
    u32 flag;
    const char *old;
    u32 index;
    char *tmp;
    flag=func_02017E1C(mon,76,0);
    func_02049B40(23,5,0,448,32,((struct Obj00001 *)p)->f5F4);
    old=p;
    old=old+0x5bc;
    index=i*4;
    if(*(const int *)(old+index))func_020452E8((struct Descriptor *)(*(const int *)(old+index)));
    *(int *)(p+0x5bc+index)=(int)func_020450F0(3,(u8)(*(int *)((char *)&a+index)),1,14,20,14,0);
    func_0201DD78(15,2,0);
    {
        void *window=func_02045770((struct Descriptor *)*(int *)(p+0x5bc+index));
        func_021E1430(mon,window,16,0,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *items=p+0x5bc;
        void *window=func_02045770((struct Descriptor *)*(int *)(items+index));
        func_021E1670(mon,window,80,0,p,0,func_021D8ADC(p));
        func_0201DD78(15,2,0);
        func_021E15F8(mon,func_02045770((struct Descriptor *)*(int *)(items+index)),16,19,p);
        func_021E1778((int)mon,*(int *)(items+index),16,128,p);
        i++;
        func_021E0E68(p+0x8c4+i*20,mon,((struct Obj00001 *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((struct Obj00001 *)p)->f5F4,*(int *)((char *)&c+index));
        func_0204B84C(*(void **)(p+i*20+0x8d4),1);
    } else {
        tmp=p+0x8c4;
        func_021E0E4C(tmp+(i+1)*20);
    }
    func_02045334((struct Descriptor *)*(const int *)(old+index));
    func_02045374((struct Cfg *)(*(const int *)(old+index)));
    func_02041B6C(3);
}

void func_021E1CA8(char *p)
{
    char *q = p + 0x8C4;
    int i;
    for (i = 0; i < 3; i++) {
        func_021E0E4C(q + i * 0x14);
    }
}

void func_021E1CC8(char *p)
{
    char *q;
    int i = 0;
    q = p + 0x900;
    for (; i < 4; i++) {
        func_021E0DA0(q + i * 0x14);
    }
}


void func_021E1CE8(void *p, int a1)
{
    unsigned int v;

    func_021E5EF8((char *)p + 0x964);
    func_021E5EF8((char *)p + 0x978);
    func_021E625C(p);
    if (a1 != 0) {
        v = *(volatile unsigned int *)0x04001000;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    func_021E1CA8(p);
    func_021E1CC8(p);
    func_021E5EF8((char *)p + 0x950);
    func_021E5BE4((int)p);
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    func_020456F8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    func_020452E8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    *(int *)&((struct Obj00001 *)p)->f6B4 = 0;
    func_021E3F70(p);
}
