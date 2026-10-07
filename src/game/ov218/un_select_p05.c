/*
 * file:     un_select_p05.c
 * unit:     yes
 * function: func_021B9C74, func_021B9C80, func_021B9C84, func_021B9C88, func_021B9C8C, func_021B9CDC, func_021B9D10, func_021B9D48, func_021B9E28
 * address:  0x021B9C74
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */
#include "../../matched/include/Obj26040.h"
#include "../../matched/include/Obj26041.h"
#include "../../matched/include/Obj26042.h"
#include "../../matched/include/Obj26043.h"
#include "../../matched/include/Obj03959.h"
#include "../../matched/include/Obj02556.h"
#include "../../matched/include/G_Template.h"
#include "../../matched/include/Obj14772.h"

struct S;
struct Tmpl;
struct MsgBank;
struct Rec;
struct U16Vec;
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
void func_021B9C74(u8 *p);
void *func_021B9C80(u8 *p);
void *func_021B9C84(u8 *p);
u32 func_021B9C88(char *p);
void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void func_021B9CDC(u8 *p);
void func_021B9D10(u8 *p,int delta);
void func_021B9D48(char *p);
void func_021B9E28(char *p);
extern struct Template d_021BB060;
extern struct Template template_021BB060;
extern int tbl_021BAC80[];

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
