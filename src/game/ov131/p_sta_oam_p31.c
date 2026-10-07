/*
 * file:     p_sta_oam_p31.c
 * unit:     yes
 * function: func_021DB508, func_021DB614, func_021DB688, func_021DB6D0, func_021DB700
 * address:  0x021DB508
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_020181FC 0x020181FC thumb
 *   func_02017E64 0x02017E64 thumb
 *   func_021DBE98 0x021DBE98 thumb ov131
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021D618C 0x021D618C thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_02019B44 0x02019B44 thumb
 *   d_021DC2B8 0x021DC2B8 data a1
 *   func_0204B294 0x0204B294 arm
 */
#include "../../matched/include/Obj23171.h"
#include "../../matched/include/Obj00026.h"
#include "../../matched/include/Obj06486.h"
#include "../../matched/include/Obj10523.h"
#include "../../matched/include/Obj00344.h"
#include "../../matched/include/Obj03286.h"

struct Obj;
struct CharBuf;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;

extern void *func_021D6064(u8 *);
extern void func_021D60D4(u8 *,int);
extern u32 func_02017E88(void *,u32,u32);
extern void func_020181FC(void *,u16,u32);
extern void func_02017E64(void *,u32,u32);
extern void func_021DBE98(int *a, int *b);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DBCA4(u8 *p, int v);
extern void func_021DBCF4(u8 *p);
extern void func_021DBA78(u8 *,int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021D618C(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void func_020061E4(u32 a);
extern s8 func_02019B44(u32 a, u32 n);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_021DB508(u8 *p,u8 *q,u32 a,u32 b);
void func_021DB614(void *a,u8 *b,int c);
void func_021DB688(u8 *a,u8 *b,int c);
int func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d);
void func_021DB700(u8 *a,void *b,u8 *p,u8 i);
extern const u8 d_021DC2B8[][2];

/*
 * extent: the final two bytes at 021DB612 are zero alignment padding.
 * semantic: selectors and slot indices preserve every input word. Selector
 *   additions and index*24/address additions are u32 wrap, with pointer
 *   conversion only after address arithmetic; no asserted slot bound.
 *   Six getter results and four selectors are assigned before use.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`apid=a;` before `apid=a+58U;`; `auid=a;` before `auid=a+62U;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021DB508(u8 *p,u8 *q,u32 a,u32 b)
{
    void *m;
    u32 am,app,au,bm,bpp,bu;
    u32 apid,auid,bpid,buid;
    m=func_021D6064(p);
    func_021D60D4(p,1);
    am=func_02017E88(m,a+54U,0);
    apid=a+58U;
    app=func_02017E88(m,apid,0);
    auid=a+62U;
    au=func_02017E88(m,auid,0);
    bm=func_02017E88(m,b+54U,0);
    bpid=b+58U;
    bpp=func_02017E88(m,bpid,0);
    buid=b+62U;
    bu=func_02017E88(m,buid,0);
    func_020181FC(m,bm,a);
    func_020181FC(m,am,b);
    func_02017E64(m,apid,bpp);
    func_02017E64(m,auid,bu);
    func_02017E64(m,bpid,app);
    func_02017E64(m,buid,au);
    func_021D60D4(p,0);
    func_021DBE98(*(void **)((u32)q+a*24U+196U),*(void **)((u32)q+b*24U+196U));
    *(u32 *)((u32)q+a*24U+180U)=1;
    *(u32 *)((u32)q+b*24U+180U)=1;
    func_021D9EE8(p,q);
    ((struct Obj23171 *)q)->f10=1;
}

void func_021DB614(void *a,u8 *b,int c) {
    u8 *p=b+272;
    if(c==1) {
        func_0204B878(((struct Obj06486 *)p)->f8,16);
        func_021DBCA4(((struct Obj06486 *)p)->f14,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,0);
        func_021DBCF4(((struct Obj00026 *)b)->fAC);
        func_021DBCA4(((struct Obj00026 *)b)->fAC,1);
    } else {
        func_021DBCA4(((struct Obj00026 *)b)->fAC,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,1);
        if(b[41]==4) func_021DBA78(p,1); else func_021DBA78(p,0);
        func_021DBCA4(((struct Obj06486 *)p)->f14,1);
    }
}

void func_021DB688(u8 *a,u8 *b,int c) {
    ((struct Obj10523 *)b)->fC=1;
    func_02043B5C(func_02045770(((struct Obj10523 *)b)->f8C),0);
    if(c==1) func_021D618C(a,(unsigned int)(((struct Obj10523 *)b)->f8C),156,0,0,15424);
    func_020061E4(1367);
}

int func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d) {
 switch (func_02019B44(c, d)) {
 case 1: return 0x3d20;
 case -1: return 0x3d40;
 case 0:
 default: return 0x3c40;
 }
}

/*
 * lever: assign p[0] before pos.x to schedule its store before the stack address.
 */
void func_021DB700(u8 *a,void *b,u8 *p,u8 i) {
    ObjPos pos;
    ((struct Obj03286 *)p)->f4=0;
    p[0]=i;
    pos.x=d_021DC2B8[i][0]*8;
    pos.y=d_021DC2B8[i][1]*8;
    pos.priority=10;
    pos.flags=0;
    pos.z=p[0];
    ((struct Obj03286 *)p)->f8=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->fE8,(unsigned int)((struct Obj00344 *)a)->fB0,(unsigned int)((struct Obj00344 *)a)->f118,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->f8,0);
    pos.x=d_021DC2B8[p[0]][0]*8+26;
    pos.y=d_021DC2B8[p[0]][1]*8+9;
    pos.priority=8;
    pos.flags=0;
    pos.z=0;
    ((struct Obj03286 *)p)->fC=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->f130,(unsigned int)((struct Obj00344 *)a)->fA4,(unsigned int)((struct Obj00344 *)a)->f10C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->fC,0);
}
