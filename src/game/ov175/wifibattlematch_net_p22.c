/*
 * file:     wifibattlematch_net_p22.c
 * unit:     yes
 * function: func_021DBDAC, func_021DBFA4, func_021DBFB4, func_021DC194, func_021DC1A0, func_021DC1E4, func_021DC200, func_021DC240, func_021DC268, func_021DC2A0, func_021DC2C0, func_021DC2D8
 * address:  0x021DBDAC
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
 *   func_021E10CC 0x021E10CC arm ov175
 *   func_021E1540 0x021E1540 arm ov175
 *   func_021E1414 0x021E1414 arm ov175
 *   func_021E1434 0x021E1434 arm ov175
 *   func_021E1454 0x021E1454 arm ov175
 *   func_021E11F0 0x021E11F0 arm ov175
 *   func_021DCE40 0x021DCE40 thumb ov175
 *   func_021DCE08 0x021DCE08 thumb ov175
 *   func_021DCE48 0x021DCE48 thumb ov175
 *   func_021DCE50 0x021DCE50 thumb ov175
 *   func_021DB6A0 0x021DB6A0 thumb ov175
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2F1C 0x021E2F1C data a4
 *   func_021DB6A8 0x021DB6A8 thumb ov175
 *   func_021E1464 0x021E1464 arm ov175
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0201A918  0x0201A918  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */
#include "../../matched/include/Obj00999.h"
#include "../../matched/include/Obj01171.h"
#include "../../matched/include/Obj00629.h"
#include "../../matched/include/Obj24391.h"
#include "../../matched/include/Obj14344.h"
#include "../../matched/include/Obj14345.h"
#include "../../matched/include/Obj14346.h"
#include "../../matched/include/Obj10689.h"

struct Entry;
struct Link;
typedef unsigned long u32_021DBDAC;

typedef struct DWCstAccUserData DWCstAccUserData;

typedef unsigned long u32_021DBFB4;

typedef unsigned long u32_021DC194;

typedef unsigned char u8;

typedef unsigned long u32_021DC1A0;

typedef unsigned long u32_021DC1E4;

typedef unsigned int   u32_021DC200;

typedef unsigned long u32_021DC240;

typedef unsigned long u32_021DC268;

typedef unsigned long u32_021DC2A0;

typedef unsigned short u16;

typedef unsigned long u32_021DC2C0;

typedef unsigned long u32_021DC2D8;

extern int func_021E10CC(int,DWCstAccUserData *,int);
extern int func_021E1540(char *,int,void *,int);
extern void func_021E1414(void);
extern int func_021E1434(void);
extern u32_021DBDAC func_021E1454(void);
extern int func_021E11F0(void);
extern void func_021DCE40(char *,u32_021DBDAC,int);
extern void func_021DCE08(char *,u32_021DBDAC,int);
extern void func_021DCE48(char *,u32_021DBDAC,int);
extern void func_021DCE50(char *,u32_021DBDAC,int);
extern void func_021DB6A0(char *);
extern void func_02034714(const char *expr, u32_021DBDAC line, const char *file);
extern void func_021DB6A8(char *);
extern int func_021E1464(char *,void *,int,int *);
extern struct Entry *func_020399A8(void);
extern u32_021DC1A0 func_0203D1A4(struct Link *p);
extern u32_021DC1A0 func_0203D3F8(u32_021DC1A0 a, u32_021DC1A0 b, u32_021DC1A0 c, u32_021DC1A0 d, u32_021DC1A0 e, u32_021DC1A0 f, u32_021DC1A0 g, u32_021DC1A0 h);
extern int func_0201A918(void);
extern void func_02082D44(char *dst, u32_021DC240 arg, u32_021DC240 src);
extern int func_0203D3A8(struct Entry *a, u32_021DC2C0 b, u32_021DC2C0 c, u32_021DC2C0 d);
int func_021DBDAC(char *p);
void func_021DBFA4(char *ctx);
int func_021DBFB4(char *p);
u32_021DC194 func_021DC194(char *obj);
u32_021DC1A0 func_021DC1A0(char *obj, u32_021DC1A0 data);
u32_021DC1E4 func_021DC1E4(char *obj, char **out);
u32_021DC200 func_021DC200(char *p,unsigned long data);
u32_021DC240 func_021DC240(char *obj, u32_021DC240 arg);
int func_021DC268(char *obj, u32_021DC268 data);
u32_021DC2A0 func_021DC2A0(char *obj, u32_021DC2A0 arg);
int func_021DC2C0(u32_021DC2C0 ignored, void *p);
u32_021DC2D8 func_021DC2D8(char *obj, u32_021DC2D8 *out);
extern const char d_021E2EF8[],d_021E2F1C[];

/*
 * lever: PC-relative slot audit binds error/cancel/timeout lines to 0x11a0,0x11be,0x11ca; fixing source constants removes three pool-byte mismatches.
 * extent: existing matched ov175_func_021DBFA4.c covers the final16 bytes; keep this504-byte lead alone.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives live entry r0 in case 4 despite its unused parameter.
 */
int func_021DBDAC(char *p)
{
    long r;
    switch(((struct Obj00999 *)p)->f12C) {
    case 0:
        r=func_021E10CC(0xb5f,*(DWCstAccUserData * *)&((struct Obj00999 *)p)->f0,0);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1161);func_021DB6A0(p);return 2;}
        ((struct Obj00999 *)p)->f12C=1;break;
    case 1:
        if(((struct Obj00999 *)p)->f198>=0x26)func_02034714(d_021E2EF8,0,d_021E2EF8);
        r=func_021E1540((char *)d_021E2F1C,**(int * *)&((struct Obj00999 *)p)->f1464,((struct Obj00999 *)p)->f190,((struct Obj00999 *)p)->f198);
        if(r!=0) {func_021DCE40(p+0x18,r,0x116e);func_021DB6A0(p);return 2;}
        ((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x117b);((struct Obj00999 *)p)->f12C=6;break;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DCE48(p+0x18,r,0x1186);((struct Obj00999 *)p)->f12C=6;}
        else if(r==1)((struct Obj00999 *)p)->f12C=3;
        break;
    case 3:
        r=func_021E1454();
        if(r==0) {func_021DCE50(p+0x18,r,0x1199);((struct Obj00999 *)p)->f12C=6;}
        else if(r!=1) {func_021DB6A0(p);func_021DCE50(p+0x18,r,0x11a0);return 2;}
        else ((struct Obj00999 *)p)->f12C=4;
        break;
    case 4:
        func_021DB6A0(p);((struct Obj00999 *)p)->f12C=5;
    case 5:return 1;
    case 6:
        r=func_021E11F0();
        if(r==0) {((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=7;}
        else {func_021DCE40(p+0x18,r,0x11be);func_021DB6A0(p);return 2;}
        break;
    case 7:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x11ca);func_021DB6A0(p);return 2;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DB6A0(p);return 2;}
        if(r==1)((struct Obj00999 *)p)->f12C=8;
        break;
    case 8:func_021DB6A0(p);return 2;
    }
    return 0;
}

/*
 * leaf: reset request step then prepare four database fields.
 */
void func_021DBFA4(char *ctx)
{
    ((struct Obj01171 *)ctx)->f12C = 0;
    func_021DB6A8(ctx);
}

/*
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
int func_021DBFB4(char *p)
{
    long r;
    switch(((struct Obj00629 *)p)->f12C) {
    case 0:
        r=func_021E10CC(0xb5f,*(DWCstAccUserData * *)&((struct Obj00629 *)p)->f0,0);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1215);return 2;}
        ((struct Obj00629 *)p)->f12C=1;break;
    case 1:
        r=func_021E1464((char *)d_021E2F1C,((struct Obj00629 *)p)->f190,((struct Obj00629 *)p)->f198,*(int * *)&((struct Obj00629 *)p)->f1464);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1223);return 2;}
        ((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x122f);((struct Obj00629 *)p)->f12C=4;break;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DCE48(p+0x18,r,0x123b);((struct Obj00629 *)p)->f12C=4;}
        else if(r==1)((struct Obj00629 *)p)->f12C=3;
        break;
    case 3:
        r=func_021E1454();
        if(r==0) {func_021DCE50(p+0x18,r,0x124f);((struct Obj00629 *)p)->f12C=4;}
        else if(r!=1) {func_021DB6A0(p);func_021DCE50(p+0x18,r,0x1256);return 2;}
        else {
            if(**(u32_021DBFB4 * *)&((struct Obj00629 *)p)->f1464==0)func_021DCE08(p+0x18,2,0x125c);
            func_021DB6A0(p);return 1;
        }
        break;
    case 4:
        r=func_021E11F0();
        if(r==0) {((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=5;}
        else {func_021DCE40(p+0x18,r,0x126f);func_021DB6A0(p);return 2;}
        break;
    case 5:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x127b);func_021DB6A0(p);return 2;}
        func_021E1414();r=func_021E1434();
        if(r==0||r==4) {func_021DB6A0(p);return 2;}
        if(r==1)((struct Obj00629 *)p)->f12C=6;
        break;
    case 6:func_021DB6A0(p);return 2;
    }
    return 0;
}


/*
 * Two-level dereference: the pointer the object holds at +0x1464, then
 *     the word it points at.  Both loads are register-offset, so the listing
 *     pools one plain literal 0x1464.
 */
u32_021DC194 func_021DC194(char *obj)
{
    return *(u32_021DC194 *)(((struct Obj24391 *)obj)->f1464);
}


/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */
u32_021DC1A0 func_021DC1A0(char *obj, u32_021DC1A0 data)
{
    u32_021DC1A0 busy = func_0203D1A4((struct Link *)((u32_021DC1A0)func_020399A8()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return func_0203D3F8((u32_021DC1A0)func_020399A8(), (u8)flag, 0x2401, func_0201A918() + 0xd4, data, 1, 1, 1);
}


/*
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */
u32_021DC1E4 func_021DC1E4(char *obj, char **out)
{
    u32_021DC1E4 v = ((struct Obj14344 *)obj)->f13C;
    if (v != 0) {
        ((struct Obj14344 *)obj)->f13C = 0;
        *out = obj + 0x218;
    }
    return v;
}

u32_021DC200 func_021DC200(char *p,unsigned long data)
{
    unsigned long busy=func_0203D1A4((struct Link *)((unsigned long)func_020399A8()));
    int flag=1;
    if(busy!=0) flag=0;
    return func_0203D3F8((unsigned long)func_020399A8(),(unsigned char)flag,0x2403,func_0201A918(),data,1,1,1);
}


/*
 * Takes and clears the +0x144 block; when there was one, calls
 *     0x0201A918(0) and hands its result to 0x02082D44 together with the
 *     object's +0x218 port block and the caller's second argument.  Returns
 *     the block it took.
 */
u32_021DC240 func_021DC240(char *obj, u32_021DC240 arg)
{
    u32_021DC240 v = ((struct Obj14345 *)obj)->f144;

    if (v != 0) {
        ((struct Obj14345 *)obj)->f144 = 0;
        func_02082D44(obj + 0x218, arg, func_0201A918());
    }
    return v;
}


/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x0201A918
 * The call at +0x14 targets 0x0201A918, which has no label in the ARM9
 * listings and no branch to it from outside this function, so it fails
 * both the `label` and `sole-ref/code` classes.  Bytes are exact.
 */


/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2404, 4, data, 1, 1, 1); flag is 1 unless 0x0203D1A4 reports the link busy.
 */
int func_021DC268(char *obj, u32_021DC268 data)
{
    u32_021DC268 busy = func_0203D1A4((struct Link *)((u32_021DC268)func_020399A8()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return func_0203D3F8((u32_021DC268)func_020399A8(), (u8)flag, 0x2404, 4, data, 1, 1, 1);
}


u32_021DC2A0 func_021DC2A0(char *obj, u32_021DC2A0 arg)
{
    u32_021DC2A0 v = ((struct Obj14346 *)obj)->f148;

    if (v != 0) {
        ((struct Obj14346 *)obj)->f148 = 0;
        func_02082D44(obj + 0x218, arg, 4);
    }
    return v;
}


/*
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */
int func_021DC2C0(u32_021DC2C0 ignored, void *p)
{
    return func_0203D3A8(func_020399A8(), 0x2405, 4, (u32_021DC2C0)p);
}


/*
 * Take-and-clear: returns the word at +0x14c; when it is set, clears it and hands back the word at +0x150 through out.
 */
u32_021DC2D8 func_021DC2D8(char *obj, u32_021DC2D8 *out)
{
    u32_021DC2D8 v = ((struct Obj10689 *)obj)->f14C;
    if (v != 0) {
        ((struct Obj10689 *)obj)->f14C = 0;
        *out = ((struct Obj10689 *)obj)->f150;
    }
    return v;
}
