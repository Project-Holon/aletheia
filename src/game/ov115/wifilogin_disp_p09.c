/*
 * file:     wifilogin_disp_p09.c
 * unit:     yes
 * function: func_021D4BFC, func_021D4CE4, func_021D4D10
 * address:  0x021D4BFC
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D65D0 0x021D65D0 data a1
 *   func_02034714 0x02034714 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D5984 0x021D5984 thumb ov115
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0202208C 0x0202208C thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_02005D90 0x02005D90 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D4DF4 0x021D4DF4 thumb ov115
 *   func_021D5A88 0x021D5A88 thumb ov115
 *   func_021D5E48 0x021D5E48 thumb ov115
 *   func_020403F4 0x020403F4 arm
 *   func_021D5A9C 0x021D5A9C thumb ov115
 *   func_021D4E04 0x021D4E04 thumb ov115
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj01719.h"
#include "../../matched/include/Obj04465.h"
#include "../../matched/include/Obj22596.h"
#include "../../matched/include/Obj22597.h"
#include "../../matched/include/Obj22598.h"
#include "../../matched/include/Obj06414.h"
#include "../../matched/include/Obj13851.h"

struct Obj0203159C;
struct Big;
struct BigObj;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

extern void func_02034714(const char *,u32,const char *);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u8 *func_021D4D38(u16,u32,int);
extern u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern int func_0203CD98(void);
extern void func_0203CA04(void),func_0203C968(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_021D426C(u8 *,u32);
extern void func_021D497C(u8 *);
extern void func_021D5CCC(u8 *,u32);
extern void func_02005D90(int,int);
extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D4DF4(u8 *p);
extern void func_021D5A88(void *);
extern void func_021D5E48(void *);
extern void func_020403F4(u32 i);
extern void func_021D5A9C(u8 *);
extern void func_021D4E04(u8 *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021D4BFC(void *ctx,int unused,u8 *q);
int func_021D4CE4(int a,int b,int c,u8 *p);
int func_021D4D10(u32 a,int b,int c,u8 *p);
extern char d_021D65D0[];

/*
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 */
int func_021D4BFC(void *ctx,int unused,u8 *q)
{
    u8 *p;
    if(((struct Obj04465 *)q)->fC==0) func_02034714(d_021D65D0,0,d_021D65D0);
    func_0203064C(1,120,0x18000);
    p=func_0203159C(ctx,72,120);
    func_02082BCC(p,0,72);
    ((struct Obj01719 *)p)->fC=120;
    ((struct Obj01719 *)p)->f44=((struct Obj04465 *)q)->f0;
    ((struct Obj01719 *)p)->f34=func_021D4D38(((struct Obj01719 *)p)->fC,((struct Obj04465 *)q)->f4,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f38=func_021D5984(((struct Obj01719 *)p)->fC,232,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f2C=func_02012EBC(((struct Obj04465 *)q)->f0);
    ((struct Obj01719 *)p)->f3C=func_0201283C(((struct Obj04465 *)q)->f0);
    func_0202208C(0,1,1,0,6,1,((struct Obj01719 *)p)->fC);
    *(u8 * *)&((struct Obj01719 *)p)->f40=q;
    if(func_0203CD98()) {
        func_0203CA04();
        func_0203C968();
        func_0200FBB0();
        func_0200FBA0();
    }
    func_021D426C(p,(u32)func_021D497C);
    if(((struct Obj22596 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f4==0) {
        func_021D5CCC(*(u8 * *)&((struct Obj01719 *)p)->f38,35);
        if(((struct Obj22597 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) func_02005D90(1153,65535);
    } else {
        if(((struct Obj22598 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) func_02005D90(1155,65535);
    }
    return 1;
}

int func_021D4CE4(int a,int b,int c,u8 *p) { int r=1; void (*cb)(u8 *); func_021D4DF4(((struct Obj06414 *)p)->f34); func_021D5A88(((struct Obj06414 *)p)->f38); cb=*(void (**)(u8 *))p; if(cb) { cb(p); r=0; } if(((struct Obj06414 *)p)->f30) func_021D5E48(((struct Obj06414 *)p)->f30); return r; }

int func_021D4D10(u32 a,int b,int c,u8 *p) { func_020403F4(7); func_021D5A9C(*(u8 * *)&((struct Obj13851 *)p)->f38); func_021D4E04(*(u8 * *)&((struct Obj13851 *)p)->f34); func_020315D4((struct S020315D4 *)a); func_020306F0(120); return 1; }
