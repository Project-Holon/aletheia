/*
 * file:     wifibattlematch_net_p10.c
 * unit:     yes
 * function: func_021D6788, func_021D679C, func_021D67BC, func_021D6854, func_021D6954, func_021D6964
 * address:  0x021D6788
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
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *   func_020173EC 0x020173EC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B9A64 0x021B9A64 thumb ov114
 *   func_021B9A94 0x021B9A94 thumb ov114
 *   func_021B9A1C 0x021B9A1C thumb ov114
 *   func_021B9A8C 0x021B9A8C thumb ov114
 *   func_020362DC                0x020362DC  arm
 *   func_021E8738                0x021E8738  thumb  ov177
 *   func_021E8844                0x021E8844  thumb  ov177
 *   func_021D6550                0x021D6550  thumb
 *   func_021D65DC                0x021D65DC  thumb
 *   func_021D65C8                0x021D65C8  thumb
 *   func_021DA434                0x021DA434  thumb
 *   func_021E7E0C                0x021E7E0C  thumb  ov177
 *   func_021DA36C                0x021DA36C  thumb
 *   func_0200FB24                0x0200FB24  thumb
 *   func_0203CD98                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021D6BF4 0x021D6BF4 thumb ov175
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_0201A920 0x0201A920 thumb
 *   func_021DD008 0x021DD008 thumb ov175
 */
#include "../../matched/include/Obj01562.h"
#include "../../matched/include/Obj00171.h"
#include "../../matched/include/Obj24232.h"

struct GfFont;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct Big;
struct Party;
struct Rec160;
typedef unsigned long u32_021D6788;

typedef unsigned long u32_021D679C;

typedef unsigned int u32_021D67BC;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned long u32_021D6854;

typedef unsigned long u32_021D6954;

typedef unsigned int u32_021D6964;

typedef signed int     s32;

extern void func_021E8AA0(u32_021D6788 sys, void *fn);
extern void func_021E8A80(u32_021D679C h);
extern int func_021E8A90(u32_021D679C h);
extern u32_021D67BC func_020173EC(void);
extern u32_021D67BC func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32_021D67BC idx);
extern u8 *func_021B9A64(int a, int b, int c);
extern void func_021B9A94(int p, int a, u32_021D67BC b, int n);
extern int func_021B9A1C(void *a, int b, int c, char *d, u16 e);
extern void func_021B9A8C(void *);
extern u32_021D6854 func_020362DC(void);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *p);
extern void func_021D6550(u32_021D6854 *obj, int kind);
extern int func_021D65DC(char *obj);
extern void func_021D65C8(char *obj);
extern int func_021DA434(u32_021D6854 h);
extern void func_021E7E0C(void **p, int on);
extern void func_021DA36C(u32_021D6854 h);
extern u32_021D6854 func_0200FB24(void);
extern int func_0203CD98(void);
extern void DWC_CloseAllConnectionsHard(void);
extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32_021D6964,u32_021D6964,u32_021D6964);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021D6964 size, u32_021D6964 heap);
extern void func_02082BCC(void *,int,u32_021D6964);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *sys);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32_021D6964 index);
extern int *func_021E5440(unsigned,int);
extern int func_021E5548(int *);
extern u32_021D6964 *func_021E567C(int unused, int mode, int heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32_021D6964 heapId);
extern u32_021D6964 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32_021D6964 resident, u32_021D6964 arcId, u32_021D6964 fileId, u32_021D6964 heapId);
extern struct WordSet *func_0201EC74(u32_021D6964 n, u32_021D6964 size, unsigned short heap);
extern char *func_021D9DC8(u32_021D6964 a, void *save, u32_021D6964 b, u16 heap);
extern u32_021D6964 func_021E8568(int,int,int,int,u32_021D6964,u32_021D6964,int);
extern int *func_021E8A3C(int,int,int);
extern void func_021D6BF4(u32_021D6964,void *,char *);
extern void **func_021E7D20(void *,void *,unsigned);
extern struct Party *func_0201A920(u32_021D6964 heap);
extern void func_021DD008(char *,int);
void func_021D6788(char *obj, void *fn);
u32_021D679C func_021D679C(char *obj);
int func_021D67BC(char *p, u16 heapId);
int func_021D6854(char *obj, int trigger, int go);
void func_021D6954(char *obj);
int func_021D6964(void *sys,int unused,u32_021D6964 *ctx);
extern const char ov067_id[],ov114_id[];


/*
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
void func_021D6788(char *obj, void *fn)
{
    func_021E8AA0(((struct Obj01562 *)obj)->f38, fn);
    ((struct Obj01562 *)obj)->f3C = 0xFFFF;
}


u32_021D679C func_021D679C(char *obj)
{
    func_021E8A80(((struct Obj01562 *)obj)->f38);
    if (func_021E8A90(((struct Obj01562 *)obj)->f38) != 0)
        return ((struct Obj01562 *)obj)->f3C;
    return 0xFFFF;
}


/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * The second call, at +0x0C, targets 0x021E8A90.  That address carries no
 * func_/sub_ label in ANY listing -- ov093 has a bare `bx lr` there and
 * ov177 has plain .word data -- so no class can attest it: four call
 * sites image-wide (ov175 x2, ov176 x3) are not enough without a traced
 * entry point.  Bytes are exact; only the relocation is unwitnessed.
 */

/*
 * lever: `int i` declared before the list pointer gives i r4 and list r5
 * (declaration-order-decides-which-register-a-local-gets.md); the earlier
 * DIFF was that r4/r5 swap alone.
 * leaf: +008A func_021B9A8C resolves as matched through
 *   src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *   unlabelled ov114 tail-call stub to 0x020307B0.
 */
int func_021D67BC(char *p, u16 heapId)
{
    int i;
    u32_021D67BC size;
    void *list=p+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32_021D67BC ret;
    size=func_020173EC();
    buf=func_021B9A64(size,func_0201AA18(list),(u16)heap);
    for(i=0;i<(int)func_0201AA18(list);i++) {
        void *entry=func_0201AB28(list,i);
        func_021B9A94((int)buf,(int)entry,func_020173EC(),i);
    }
    size=func_020173EC();
    ret=func_021B9A1C(buf,size,func_0201AA18(list),p+0x54,heap);
    func_021B9A8C(buf);
    return ret;
}


int func_021D6854(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00171 *)obj)->fE4) {
    case 0:
        if (trigger != 0 && (func_020362DC() & 2))
            ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        else return 0;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x23, 1);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00171 *)obj)->f24)))
            break;
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 3:
        func_021D6550((u32_021D6854 *)obj, 0);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 4:
        r = func_021D65DC(obj);
        if (r == -1)
            break;
        func_021D65C8(obj);
        switch (r) {
        case 0:
            ((struct Obj00171 *)obj)->fE4 = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x21, 0);
            ((struct Obj00171 *)obj)->fE4 = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x2b, 2);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00171 *)obj)->f30);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        func_021E7E0C((void **)(((struct Obj00171 *)obj)->f20), 0);
        func_021DA36C(((struct Obj00171 *)obj)->f30);
        if (!func_0200FB24() && func_0203CD98())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00171 *)obj)->fE4 = 0;
        return 3;
    }
    return 1;
}


/*
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path func_021D65C8, which is why nothing is saved.
 */
void func_021D6954(char *obj)
{
    ((struct Obj24232 *)obj)->fE4 = 0;
    func_021D65C8(obj);
}

/*
 * func_0203159C's r0 is read after the call, requiring a returning declaration.
 */
int func_021D6964(void *sys,int unused,u32_021D6964 *ctx)
{
    u32_021D6964 *p;
    func_02034AC4((int)ov067_id); func_02034AC4((int)ov114_id);
    func_0203064C(1,87,0x30000);
    p=func_0203159C(sys,0x270,87); func_02082BCC(p,0,0x270);
    p[0x104/4]=(u32_021D6964)ctx;
    p[0x108/4]=(u32_021D6964)func_0200B1D4(func_0200B358(func_02012EBC((struct Big *)(*(u32_021D6964 *)ctx[2]))),0);
    p[0]=(u32_021D6964)func_021E5440(1,87);
    p[1]=(u32_021D6964)func_021E567C(func_021E5548((int *)p[0]),0,87);
    p[2]=(u32_021D6964)func_0201D7EC(0x17,0,0,0,87);
    p[3]=(u32_021D6964)func_0201D7EC(0x17,3,0,0,87);
    p[4]=func_0201C440((void *)87); p[5]=(u32_021D6964)func_02045B38(0,2,0xd2,87);
    p[6]=(u32_021D6964)func_0201EC74(8,0x40,87);
    p[0x34/4]=(u32_021D6964)func_021D9DC8(((u32_021D6964 *)p[0x104/4])[0xf],(void *)(*(u32_021D6964 *)ctx[2]),ctx[7],87);
    p[0x2c/4]=func_021E8568(0,15,14,10,p[4],p[2],87);
    p[0x38/4]=(u32_021D6964)func_021E8A3C((int)p,(int)func_021D6BF4,87);
    p[0x3c/4]=(u32_021D6964)func_021E8A3C((int)p,0,87);
    p[0x28/4]=(u32_021D6964)func_021E7D20((void *)func_021E5548((int *)p[0]),(void *)p[1],87);
    func_021E7E0C((void **)p[0x28/4],0);
    p[0xfc/4]=(u32_021D6964)func_0201A920(87); func_021DD008((char *)p[0x34/4],1);
    return 1;
}
