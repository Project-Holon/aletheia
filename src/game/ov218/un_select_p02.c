/*
 * file:     un_select_p02.c
 * unit:     yes
 * function: func_021B9C74, func_021B9C80, func_021B9C84, func_021B9C88, func_021B9C8C, func_021B9CDC, func_021B9D10, func_021B9D48, func_021B9E28, func_021B9E48, func_021B9F98, func_021B9FD4, func_021B9FD8, func_021BA0B0, func_021BA138, func_021BA1A0, func_021BA1C0, func_021BA208, func_021BA21C
 * address:  0x021B9C74
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021BA4FC 0x021BA4FC thumb ov218
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_021B9AE4 0x021B9AE4 thumb ov218
 *   func_021BA75C 0x021BA75C thumb ov218
 *   func_021BA6E8 0x021BA6E8 thumb ov218
 *   func_021B8AB8 0x021B8AB8 thumb ov067
 *   func_021BA680 0x021BA680 thumb ov218
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021BA6BC 0x021BA6BC thumb ov218
 *   func_021BA554 0x021BA554 thumb ov218
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_021B796C 0x021B796C thumb ov067
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BA780 0x021BA780 thumb ov218
 *   func_0207D534 0x0207D534 arm
 *   func_021BA848 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   func_021B6100 0x021B6100 thumb ov067
 *   func_021B96CC 0x021B96CC thumb ov218
 *   func_021B9964 0x021B9964 thumb ov218
 *   func_021BA960 0x021BA960 thumb ov218
 *   func_021B9820 0x021B9820 thumb ov218
 *   func_02027F60 0x02027F60 thumb
 *   func_021BA290 0x021BA290 thumb ov218
 *   func_021BA328 0x021BA328 thumb ov218
 *   func_021BA61C 0x021BA61C thumb ov218
 *   func_0207D63C 0x0207D63C arm
 *   func_02005624 0x02005624 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_020362DC 0x020362DC arm
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9890 0x021B9890 thumb ov218
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00 0x021B9C00 thumb ov218
 *   func_021B9898 0x021B9898 thumb ov218
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_021B991C 0x021B991C thumb ov218
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9914 0x021B9914 thumb ov218
 */
#include "../../matched/include/Obj26040.h"
#include "../../matched/include/Obj26041.h"
#include "../../matched/include/Obj26042.h"
#include "../../matched/include/Obj26043.h"
#include "../../matched/include/Obj03959.h"
#include "../../matched/include/Obj02556.h"
#include "../../matched/include/G_Template.h"
#include "../../matched/include/Obj14772.h"
#include "../../matched/include/Obj00243.h"
#include "../../matched/include/Obj02931.h"
#include "../../matched/include/Obj04644.h"
#include "../../matched/include/Obj26046.h"
#include "../../matched/include/Obj26047.h"
#include "../../matched/include/Obj26048.h"

struct S;
struct Tmpl;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Obj0203159C;
struct R;
struct TaskMenu;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct Template Template;

extern void func_0201F7A8(void *,u32);
extern void func_021BA4FC(char *ctx);
extern u32 func_021B9398(char *p, int index);
extern unsigned func_021B9394(char *p);
extern void func_021B9AE4(u8 *p, u32 a, u32 b, void *c, u32 d);
extern int func_021BA75C(char *p, int v);
extern void func_021BA6E8(u32 p, int sel, u32 y);
extern int func_021B8AB8(u8 *);
extern void func_021BA680(char *p, int v);
extern int func_021B93A4(char *);
extern int func_021B93B0(char *);
extern void func_021BA6BC(char *p, int y);
extern void func_021BA554(const char *p, int delta);
extern struct S *func_021B7754(struct Tmpl *tmpl, u32 heap);
extern void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *);
extern void func_021B796C(struct S *);
extern int func_02034AC4(int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_021BA780(int);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern char *func_021BA848(unsigned swap, unsigned heap);
extern void *func_021B6100(u32,void *,u8,u16,void *);
extern void func_021B96CC(u8 *p, u16 heap);
extern void *func_021B9964(u16);
extern u32 func_021BA960(char *p);
extern void *func_021B9820(int,int);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021BA290(char *),func_021B9D48(char *),func_021BA328(char *),func_021BA61C(char *);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void func_0203D34C(u32,u32);
extern u32 func_020362DC(void);
extern int func_021B7AB0(struct S *p);
extern void func_021B9280(u8 *p, int a, u32 b);
extern void func_020061E4(u32);
extern void func_021B61F8(unsigned char *,int);
extern void func_021B9890(void *);
extern int func_021B6448(unsigned char *);
extern unsigned func_021B61FC(const unsigned char *p);
extern void func_021B6200(u8 *a);
extern int func_021B9924(void);
extern void func_021B9B78(char *p, u32 id);
extern int func_021B9C00(char *p);
extern struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
extern int func_0204E804(void);
extern int func_02024004(int a);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_021B991C(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
extern void func_021B9944(void);
extern void func_021B9914(struct TaskMenu *p);
void func_021B9C74(u8 *p);
void *func_021B9C80(u8 *p);
void *func_021B9C84(u8 *p);
u32 func_021B9C88(char *p);
void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void func_021B9CDC(u8 *p);
void func_021B9D10(u8 *p,int delta);
void func_021B9D48(char *p);
void func_021B9E28(char *p);
char *func_021B9E48(void *owner,char *input);
void func_021B9F98(u8 *p, int mode);
int func_021B9FD4(void);
int func_021B9FD8(unsigned char *task,char *p);
int func_021BA0AC(void);
u32 func_021BA0B0(u8 *a, u8 *b);
int func_021BA138(unsigned char *task, char *ctx);
int func_021BA1A0(void);
int func_021BA1C0(unsigned char *task, char *ctx);
int func_021BA208(void *unused, char *p);
int func_021BA21C(unsigned char *task, char *ctx);
void func_021BA238(void);
extern struct Template d_021BB060;
extern struct Template template_021BB060;
extern int tbl_021BAC80[];
extern char ov067_id[];
extern char d_021BAB20[];



void func_021B9C74(u8 *p)
{
    func_0201F7A8(((struct Obj26040 *)p)->f24,1);
}



void *func_021B9C80(u8 *p)
{
    return ((struct Obj26041 *)p)->fC;
}



void *func_021B9C84(u8 *p)
{
    return ((struct Obj26042 *)p)->f10;
}




/*
 * Unlabelled leaf in ov218, printed as a .word run right before the next
 * function at 0x021B9C8C; four-byte word getter.  Blocker target of
 * func_021BA0B0 (pkt_021BA0B0), whose ov218 hint then covers it.
 */
u32 func_021B9C88(char *p)
{
    return ((struct Obj26043 *)p)->f8;
}



void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    func_021BA4FC((char *)p);
    func_021B9398((char *)(*(u8 **)(p + 0x2C)), a);
    t = func_021B9394((char *)(*(u8 **)(p + 0x2C)));
    func_021B9AE4(*(u8 **)(p + 0x28), b, t, func_021B9C80(*(u8 **)(p + 0x28)), a);
    if (func_021BA75C((char *)p, a)) {
        func_021BA6E8((u32)p, d, (u32)(c + 0x14));
    }
}



void func_021B9CDC(u8 *p)
{
    int selected;
    s16 y;
    y=func_021B8AB8(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=func_021B93A4(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)func_021B93B0(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}



void func_021B9D10(u8 *p,int delta)
{
    int selected;
    s16 y;
    func_021BA554((const char *)p,(int)(0u-(u32)delta));
    y=func_021B8AB8(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=func_021B93A4(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)func_021B93B0(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}



void func_021B9D48(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=**(u8 * *)&((struct Obj02556 *)p)->f20;
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    ((struct Obj02556 *)p)->f2C=func_021B7754((struct Tmpl *)(&template_021BB060),((struct Obj02556 *)p)->f0);
    archive=func_020490F4(193,((struct Obj02556 *)p)->f0);
    func_021B7A10(((struct Obj02556 *)p)->f2C,(u32)archive,3,0,0);
    func_021B7A10(((struct Obj02556 *)p)->f2C,(u32)archive,4,0,1);
    func_021B7A4C(((struct Obj02556 *)p)->f2C,archive,1,2,3);
    func_02049238(archive);
    bank=func_02045B38(0,2,229,((struct Obj02556 *)p)->f0);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(*(u32 *)(p+0x34+offset)==1)disabled=0;
        func_021B79E4(((struct Obj02556 *)p)->f2C,disabled,i);
        if(disabled==0)
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,238);
    }
    func_02045C04(bank);
}



void func_021B9E28(char *p){int i;for(i=0;i<130;i++)func_02045808(*(struct U16Vec **)(((struct Obj14772 *)p)->f28+i*4+0x2c));func_021B796C(*(struct S * *)&((struct Obj14772 *)p)->f2C);}



char *func_021B9E48(void *owner,char *input)
{
    char *p;
    int i,value;
    u32 a,b;
    func_02034AC4((int)ov067_id);
    func_0203064C(1,122,0x30000);
    p=func_0203159C(owner,0x330,122);
    func_02082BCC(p,0,0x330);
    ((struct Obj00243 *)p)->f0=122;
    *(char * *)&((struct Obj00243 *)p)->f20=input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))*(u32 *)(p+0x34+i*4)=1;
        else *(u32 *)(p+0x34+i*4)=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=func_021BA780(value);
        else value=65535;
        *(int *)(p+0x2dc+i*4)=value;
    }
    func_0207D534((u16 *)0x0400006c,-16);
    func_0207D534((u16 *)0x0400106c,-16);
    ((struct Obj00243 *)p)->f4=func_021BA848(0,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f24=func_021B6100(((struct Obj00243 *)p)->f0,d_021BAB20,3,0,p);
    func_021B96CC((u8 *)p,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f28=func_021B9964(((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f8=func_021B9820(func_021BA960(((struct Obj00243 *)p)->f4),((struct Obj00243 *)p)->f0);
    a=(u32)func_021B9C80(((struct Obj00243 *)p)->f28);
    b=(u32)func_021B9C84(((struct Obj00243 *)p)->f28);
    ((struct Obj00243 *)p)->f18=func_02027F60(1,11,a,b,((struct Obj00243 *)p)->f0);
    func_021BA290(p);
    func_021B9D48(p);
    func_021BA328(p);
    func_021BA61C(p);
    func_0207D63C((u32 *)0x04001050,4,8,6,10);
    ((struct Obj00243 *)p)->f23C=func_02005624((u32)func_021BA238,(u32)p,0);
    func_0203D34C(1,((struct Obj00243 *)p)->f0);
    return p;
}



void func_021B9F98(u8 *p, int mode)
{
    switch (mode) {
    case 0: {
        int idx = *(int *)(p + 0x30);
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0x83 - idx;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = tbl_021BAC80[idx];
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 1;
        break;
    }
    case 1:
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = 0;
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 0;
        break;
    }
}



int func_021B9FD4(void) { return 1; }



int func_021B9FD8(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct Obj02931 *)p)->f32C=0;
    if(func_020362DC()&0x200)active=1;
    else if(func_020362DC()&0x100)active=1;
    if(active) ((struct Obj02931 *)p)->f32C=1;
    if((u32)func_021B7AB0(((struct Obj02931 *)p)->f2C)<4){
        selected=func_021B93A4(*(char * *)&((struct Obj02931 *)p)->f2C);
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            ((struct Obj02931 *)p)->f30=selected;
            func_021B9280(((struct Obj02931 *)p)->f2C,(unsigned short)func_021B93B0(*(char * *)&((struct Obj02931 *)p)->f2C),3);
            func_020061E4(1356);
            func_021B61F8(task,**(unsigned char * *)&((struct Obj02931 *)p)->f20==131-selected ? 2 : 1);
            return 1;
        }
    }
    func_021B9890(((struct Obj02931 *)p)->f8);
    switch(func_021B6448(*(unsigned char * *)&((struct Obj02931 *)p)->f8)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        func_021B9F98((u8 *)p,1);
        func_021B61F8(task,65534);
        return 1;
    }
    return 0;
}



int func_021BA0AC(void) { return 1; }



u32 func_021BA0B0(u8 *a, u8 *b)
{
    switch (func_021B61FC(a)) {
    case 0:
        func_021B9924();
    tail:
        func_021B6200(a);
        break;
    case 1:
        if (func_0204E804() == 1) break;
        if (func_02024004(1) == 0) break;
        func_0201F048((struct WordSet *)(*(u32 *)(*(u8 **)(b + 0x28) + 0x14)), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78((char *)(*(u8 **)(b + 0x28)), 0xEA);
        goto tail;
    case 2:
        if (func_021B9C00((char *)(*(u8 **)(b + 0x28))) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = (u32)func_021B9898((void *)(*(u32 *)(b + 0x18)), (struct MsgBank *)func_021B9C88((char *)(*(u8 **)(b + 0x28))), *(u16 *)b);
        return 1;
    }
    return 0;
}



int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (func_020279E8(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (func_02027A04(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((u8 *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}



int func_021BA1A0(void){if(func_0204E804()==1 || func_02024004(1)==0)return 0;return 1;}



int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (func_021B61FC(task)) {
    case 0:
        func_021B9924();
advance:
        func_021B6200(task);
        break;
    case 1:
        if (func_0204E804() == 1)
            break;
        if (func_02024004(1) == 0)
            break;
        func_021B9B78(((struct Obj26046 *)ctx)->f28, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}




int func_021BA208(void *unused, char *p)
{
    return func_021B9C00((char *)(((struct Obj26047 *)p)->f28)) != 0;
}



int func_021BA21C(unsigned char *task, char *ctx)
{
    func_021B9944();
    func_021B9C74(((struct Obj26048 *)ctx)->f28);
    func_021B61F8(task, 0);
    return 1;
}



void func_021BA238(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}
