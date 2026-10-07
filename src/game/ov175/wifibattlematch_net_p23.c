/*
 * file:     wifibattlematch_net_p23.c
 * unit:     yes
 * function: func_021DC2F4, func_021DC338, func_021DC5AC, func_021DC5C8, func_021DC5F8, func_021DC610, func_021DC66C, func_021DC680, func_021DC6A4, func_021DC6D0, func_021DC6FC, func_021DC738
 * address:  0x021DC2F4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   d_021E2FA4 0x021E2FA4 data a1
 *   func_021C5928 0x021C5928 arm ov114
 *   func_021C5C04 0x021C5C04 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5B80 0x021C5B80 arm ov114
 *   func_021C5AB8 0x021C5AB8 arm ov114
 *   func_021C5E14 0x021C5E14 arm ov114
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0200FA84 0x0200FA84 thumb
 *   func_0200B1A8 0x0200B1A8 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E4B80 0x021E4B80 data a4
 *   d_021E2FA8 0x021E2FA8 data a4
 *   d_021E2FB0 0x021E2FB0 data a4
 *   d_021E2FC4 0x021E2FC4 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 *   func_021B9774   0x021B9774  thumb  ov114
 *   func_021B9838   0x021B9838  thumb  ov114
 *   func_021DAE18   0x021DAE18  thumb  ov175
 *   g_021E2EF8   0x021E2EF8  data
 *   func_02082D44 0x02082D44 arm
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_02034714 0x02034714 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 */
#include "../../matched/include/Obj14347.h"
#include "../../matched/include/Obj00841.h"
#include "../../matched/include/Obj03320.h"
#include "../../matched/include/Obj10690.h"
#include "../../matched/include/Obj10691.h"
#include "../../matched/include/Obj10692.h"
#include "../../matched/include/Obj06575.h"

struct Reg2;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned long u32_021DC338;

typedef unsigned int u32_021DC5AC;

typedef unsigned int u32_021DC5C8;

typedef unsigned int u32_021DC5F8;

typedef unsigned int u32_021DC610;

typedef unsigned int u32_021DC680;

typedef unsigned int u32_021DC6A4;

typedef unsigned int u32_021DC6D0;

typedef unsigned int u32_021DC6FC;

typedef unsigned int   u32_021DC738;

extern void func_02082BCC(void *,int,int);
extern int func_0208D7E0(char *,const char *,...);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int func_021C5C04(char *,char *,char *);
extern int func_021C5C38(void *,unsigned int,unsigned int);
extern int func_021C5CFC(void *,char *,unsigned int);
extern int func_021C5B80(void);
extern void func_021C5AB8(void);
extern int func_021C5E14(u32_021DC338 *,u32_021DC338 *);
extern void func_0203C9AC(int,u32_021DC338,u32_021DC338,u32_021DC338);
extern void func_0200FA84(void);
extern unsigned int func_0200B1A8(struct Reg2 *);
extern u32_021DC338 _u32_div_f(u32_021DC338,u32_021DC338);
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);
extern void func_021DAE18(char *obj);
extern void func_02034714(const char *expr, u32_021DC610 line, const char *file);
extern void func_02082D44(const void *,void *,int);
extern int func_021C5DB4(void);
extern u8 *func_02012944(void *p);
extern u32_021DC738 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int a, int b, int c);
void func_021DC2F4(char *p,unsigned a);
int func_021DC338(u8 *p);
int func_021DC5AC(const u32_021DC5AC *p,u32_021DC5AC bytes);
void func_021DC5C8(void *p, int unused, int kind);
u32_021DC5F8 func_021DC5F8(char *p, int a, int kind);
int func_021DC610(unsigned int a);
void func_021DC66C(const char *p,void *out);
void func_021DC680(u8 *p,int state);
void func_021DC6A4(u8 *p,int state);
void func_021DC6D0(u8 *p,int state);
void func_021DC6FC(void *p,u32_021DC6FC kind);
void func_021DC738(char *p,unsigned heap);
extern const char d_021E2FA4[];
extern u8 d_021E4B80[];
extern char d_021E2FA8[],d_021E2FB0[],d_021E2FC4[],d_021E2EF8[];
extern u32_021DC610 g_021E2EF8[];

void func_021DC2F4(char *p,unsigned a)
{
    ((struct Obj14347 *)p)->f12C=0;
    ((struct Obj14347 *)p)->f1458=0;
    func_02082BCC(p+0x144c,0,10);
    func_02082BCC(p+0x1390,0,0xb0);
    func_0208D7E0(p+0x144c,d_021E2FA4,a);
}

/*
 * lever: case-local repeated error call+break reproduces merged error block and long-branch layout; tail goto displaced it.
 * extent: unlabelled28-byte zero-word test021DC5AC filed separately.
 */
int func_021DC338(u8 *p)
{
    u32_021DC338 count,percent;
    switch(((struct Obj00841 *)p)->f12C) {
    case 0:
        if(func_021C5928((void (*)(int,  int,  int))func_021DC6FC,d_021E2FA8,d_021E2FB0)==0)return 3;
        ((struct Obj00841 *)p)->f1458=1;
        func_021DC680(p,1);break;
    case 1:
        if(func_021C5C04(d_021E2FC4,(char *)(p+0x144c),d_021E2EF8)==0){func_021DC6A4(p,8);break;}
        ((struct Obj00841 *)p)->f12C=2;break;
    case 2:
        if(func_021C5C38(p+0x1390,0,1)==0){func_021DC6A4(p,8);break;}
        func_021DC680(p,3);break;
    case 3:
        count=0xb0;
        if(func_021DC5AC((const unsigned int *)(p+0x1390),0xb0)==0) {
            count+=0xb0;
            if(func_021C5CFC(p+0x1390,(char *)(p+0x1230),count)==0){func_021DC6A4(p,8);break;}
            d_021E4B80[0]=0;*(u32_021DC338 *)(d_021E4B80+4)=0;
            ((struct Obj00841 *)p)->f12C=4;
        } else {
            if(func_021C5B80()==0) {((struct Obj00841 *)p)->f1458=0;return 2;}
            func_021DC680(p,7);
        }
        break;
    case 4:
        func_021C5AB8();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {func_0203C9AC(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(d_021E4B80[0]==0) {
            if(func_021C5E14((u32_021DC338 *)(p+0x1444),(u32_021DC338 *)(p+0x1448))==1) {
                percent=_u32_div_f(((struct Obj00841 *)p)->f1444*100,((struct Obj00841 *)p)->f1448);
                if(((struct Obj00841 *)p)->f1440!=percent)((struct Obj00841 *)p)->f1440=percent;
            }
        } else {
            if(*(u32_021DC338 *)(d_021E4B80+4)!=0) {
                if(*(u32_021DC338 *)(d_021E4B80+4)==8)func_0200FA84();
                else func_021DC6A4(p,8);
            } else {
                if(func_021C5B80()==0) {((struct Obj00841 *)p)->f1458=0;return 3;}
                func_021DC680(p,5);
            }
        }
        break;
    case 5:((struct Obj00841 *)p)->f12C=6;break;
    case 6:
        if(func_0200B1A8((struct Reg2 *)(p+0x1230))!=0) {((struct Obj00841 *)p)->f1458=0;return 1;}
        ((struct Obj00841 *)p)->f1458=0;return 2;
    case 7:((struct Obj00841 *)p)->f1458=0;return 2;
    case 8:((struct Obj00841 *)p)->f1458=0;return 3;
    case 100:
        func_021C5AB8();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {func_0203C9AC(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(*(u32_021DC338 *)(d_021E4B80+4)!=0) {
            if(*(u32_021DC338 *)(d_021E4B80+4)==8)func_0200FA84();
            else func_021DC6A4(p,8);
        }
        if(d_021E4B80[0]!=0) {
            d_021E4B80[0]=0;
            if(*(u32_021DC338 *)(d_021E4B80+4)==0)((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;
        }
        break;
    case 200:
        func_021C5AB8();
        if(d_021E4B80[1]!=0) {d_021E4B80[1]=0;((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;}
        break;
    case 300:
        func_021C5AB8();
        if(d_021E4B80[0]!=0) {d_021E4B80[0]=0;func_021DC6A4(p,((struct Obj00841 *)p)->f130);}
        break;
    }
    return 0;
}

/*
 * lever: unlabelled zero-word test blocking matched caller021DC338.
 */
int func_021DC5AC(const u32_021DC5AC *p,u32_021DC5AC bytes)
{
    u32_021DC5AC i;
    for(i=0;i<(bytes>>2);i++)if(p[i]!=0)return 0;
    return 1;
}


/*
 * note:     the listing extent (72 B) runs into the neighbour's `mov r8,r8`
 *           pad and pool word; all 48 compiled bytes match.
 *
 * Kind 3 or 6 teardown of the +0x121c sub-object: its handle is unregistered
 * from both pools, the slot cleared, and the object recomputed.
 */
void func_021DC5C8(void *p, int unused, int kind)
{
    if (kind != 3 && kind != 6)
        return;
    if (((struct Obj03320 *)p)->f121C != 0) {
        func_021B9774((u8 *)(((struct Obj03320 *)p)->f121C));
        func_021B9838((u8 *)(((struct Obj03320 *)p)->f121C));
        ((struct Obj03320 *)p)->f121C = 0;
    }
    func_021DAE18(p);
}

u32_021DC5F8 func_021DC5F8(char *p, int a, int kind)
{
    if (kind == 3 || kind == 6) return *(u32_021DC5F8 *)(p + 0x1458);
    return 0;
}


/*
 * note:     the listing extent (148 B) covers the following leaf and pool
 *           words as well; every compiled byte of this 92-byte body matches.
 *
 * Thumb jump table over 0..9: the startup mode reports 0x34..0x3b from its own
 * single-return blocks, mode 0 runs the 0x02034714 job with the 0x021E2EF8
 * record on both the first and third argument and reports 0, and mode 9 shares
 * the default's 0x3c block (stacked `case 9: default:` labels, which is what
 * keeps the table at ten entries and the block count at nine).
 */
int func_021DC610(unsigned int a)
{
    switch (a) {
    case 0:
        func_02034714((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    case 1:
        return 0x34;
    case 2:
        return 0x35;
    case 3:
        return 0x36;
    case 4:
        return 0x37;
    case 5:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3a;
    case 8:
        return 0x3b;
    case 9:
    default:
        return 0x3c;
    }
}

void func_021DC66C(const char *p,void *out)
{
    func_02082D44(p+0x1230,out,0x160);
}

/*
 * lever: unlabelled asynchronous state setter blocking matched caller021DC338.
 */
void func_021DC680(u8 *p,int state)
{
    d_021E4B80[0]=0;
    *(u32_021DC680 *)(d_021E4B80+4)=0;
    ((struct Obj10690 *)p)->f130=state;
    ((struct Obj10690 *)p)->f12C=100;
    ((struct Obj10690 *)p)->f1A0=0;
}

void func_021DC6A4(u8 *p,int state) { d_021E4B80[0]=0; *(u32_021DC6A4 *)(d_021E4B80+4)=0; ((struct Obj10691 *)p)->f130=state; ((struct Obj10691 *)p)->f12C=200; if(func_021C5B80()==0) ((struct Obj10691 *)p)->f130=state; }

void func_021DC6D0(u8 *p,int state) { d_021E4B80[0]=0; *(u32_021DC6D0 *)(d_021E4B80+4)=0; ((struct Obj10692 *)p)->f130=state; ((struct Obj10692 *)p)->f12C=300; if(func_021C5DB4()==0) ((struct Obj10692 *)p)->f130=state; }

void func_021DC6FC(void *p,u32_021DC6FC kind) { switch(kind) { case 0:case 1:case 2:case 3:case 4:case 5:case 7: break; case 6:case 8: func_0200FA84(); break; } d_021E4B80[0]=1; *(u32_021DC6FC *)(d_021E4B80+4)=kind; d_021E4B80[1]=1; }

void func_021DC738(char *p,unsigned heap)
{
    if(*(int *)&((struct Obj06575 *)p)->f121C!=0) func_02034714(d_021E2EF8,0,d_021E2EF8);
    ((struct Obj06575 *)p)->f12C=0;
    ((struct Obj06575 *)p)->f121C=func_021B9800(heap,func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj06575 *)p)->f8)),((struct Obj06575 *)p)->f10);
}
