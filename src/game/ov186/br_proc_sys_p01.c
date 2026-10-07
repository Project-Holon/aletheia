/*
 * file:     br_proc_sys_p01.c
 * unit:     yes
 * function: func_021F90C0, func_021F9244, func_021F92F4
 * address:  0x021F90C0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC3BC 0x021FC3BC thumb ov186
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C3E0 0x0200C3E0 thumb
 *   func_021FB884 0x021FB884 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F99CC 0x021F99CC thumb ov186
 *   func_021FE6C0 0x021FE6C0 thumb ov186
 *   func_021FE7B4 0x021FE7B4 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_021FE7F8 0x021FE7F8 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FED50 0x021FED50 thumb ov186
 *   func_021F98F8 0x021F98F8 thumb ov186
 *   func_021FF408 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 *   func_021FF8D4 0x021FF8D4 thumb ov186
 *   func_021FF4E4 0x021FF4E4 thumb ov186
 *   func_02034A5C 0x02034A5C arm
 *   func_021FEDC4 0x021FEDC4 thumb ov186
 *   func_021FE734 0x021FE734 thumb ov186
 *   func_021F9A6C 0x021F9A6C thumb ov186
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_0200C3EC 0x0200C3EC thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FB92C 0x021FB92C thumb ov186
 *   func_021FC474 0x021FC474 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021FE768 0x021FE768 thumb ov186
 *   func_021FEE00 0x021FEE00 thumb ov186
 *   func_021F9A80 0x021F9A80 thumb ov186
 *   func_021FC4C8 0x021FC4C8 thumb ov186
 *   func_021FF52C 0x021FF52C thumb ov186
 *   func_021F9B98 0x021F9B98 thumb ov186
 */
#include "../../matched/include/Obj00387.h"
#include "../../matched/include/Obj24764.h"
#include "../../matched/include/Obj24765.h"
#include "../../matched/include/Obj24766.h"
#include "../../matched/include/Obj24768.h"
#include "../../matched/include/Obj24769.h"
#include "../../matched/include/Obj24770.h"
#include "../../matched/include/Obj24772.h"
#include "../../matched/include/Obj24773.h"
#include "../../matched/include/Obj24774.h"
#include "../../matched/include/Obj24775.h"
#include "../../matched/include/Obj24776.h"
#include "../../matched/include/Obj24777.h"
#include "../../matched/include/Obj24779.h"
#include "../../matched/include/Obj24780.h"
#include "../../matched/include/Obj24781.h"
#include "../../matched/include/Obj24782.h"
#include "../../matched/include/Obj24783.h"
#include "../../matched/include/Obj24785.h"
#include "../../matched/include/Obj24786.h"
#include "../../matched/include/Obj24787.h"
#include "../../matched/include/Obj24788.h"

struct Obj0203159C;
struct SoundSys;
struct BigObj;
struct Blk34;
struct S020315D4;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct {int x[3];} S;

extern void func_0203064C(u32,u32,u32),func_02082BCC(void *,int,unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_021FC3BC(unsigned mode, int setting, unsigned heap);
extern void *func_02012F08(int *);
extern void *func_021FB884(unsigned,unsigned,unsigned);
extern u8 func_0200C3E0(struct Blk34 *p);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021F99CC(unsigned,void *,unsigned,unsigned,unsigned *,u16);
extern int *func_021FE6C0(unsigned);
extern void func_021FE7B4(char *),func_021FE7F4(int *,int),func_021FE7F8(char *,int);
extern int func_021FC224(char *);
extern u32 func_021FC4DC(u8 *p);
extern char *func_021FED50(int,int,char *,unsigned);
extern void func_021F98F8(char *p, int skip, void *sys, int heap);
extern char *func_021FF408(void *owner, void *arg, u32 heap);
extern int func_02034AC4(int),func_0203CD98(void);
extern void func_0203D34C(u32,u32);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void func_02005D90(u32,u16);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern void func_021FE840(int,int,int);
extern int func_021FF8D4(char *);
extern void func_021FF4E4(char *p);
extern void func_02034A5C(int);
extern void func_021FEDC4(char *p, char *ctx);
extern void func_021FE734(char *p);
extern void func_021F9A6C(int *);
extern int func_021FC238(char *p);
extern void func_0200C3EC(struct Blk34 *p, u32 v);
extern void func_021FBDA4(int,unsigned);
extern void func_021FB92C(char *p);
extern void func_021FC474(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021FE768(S *);
extern void func_021FEE00(char *p);
extern void func_021F9A80(char *p);
extern void func_021FC4C8(char *);
extern void func_021FF52C(char *p);
extern int func_021F9B98(int *p);
int func_021F90C0(void *obj,int unused,char *q);
int func_021F9244(int sys,int unused,int unused2,int *p);
int func_021F92F4(int sys,int *state,int unused,int *p);
extern char ov125_id[];
extern const char d_02200254[];

/*
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 */
int func_021F90C0(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    func_0203064C(1,0x5a,0x90000);
    p=func_0203159C(obj,0x1c,0x5a);
    zero=0;
    func_02082BCC(p,0,0x1c);
    *(char * *)&((struct Obj00387 *)p)->f18=q;
    ((struct Obj24765 *)(*(char * *)&((struct Obj24764 *)q)->fC))->fC=zero;
    if(**(int * *)&((struct Obj24766 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC!=2) flag=zero;
    enabled=1;
    ((struct Obj00387 *)p)->f0=func_021FC3BC(flag,1,0x5a);
    mode=func_0200C3E0(func_02012F08(*(int * *)&((struct Obj24769 *)(*(char * *)&((struct Obj24768 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4));
    if(**(int * *)&((struct Obj24770 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) enabled=0;
    ((struct Obj00387 *)p)->f4=func_021FB884(mode,enabled,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),0,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),1,0x5a);
    ((struct Obj00387 *)p)->f8=func_021F99CC(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(((struct Obj24772 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1728),0x5a);
    *(int * *)&((struct Obj00387 *)p)->fC=func_021FE6C0(0x5a);
    func_021FE7B4(*(char * *)&((struct Obj00387 *)p)->fC);
    func_021FE7F4(*(int * *)&((struct Obj00387 *)p)->fC,func_021FC224(*(char * *)&((struct Obj00387 *)p)->f4));
    if(!((struct Obj24773 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4) func_021FE7F8(*(char * *)&((struct Obj00387 *)p)->fC,3);
    *(char * *)&((struct Obj00387 *)p)->f10=func_021FED50(func_021FC4DC((u8 *)(*(int *)&((struct Obj00387 *)p)->f0)),*(int *)&((struct Obj00387 *)p)->fC,*(char * *)&((struct Obj00387 *)p)->f4,0x5a);
    func_021F98F8((char *)(((struct Obj24774 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1748),1,(void *)(((struct Obj24776 *)(*(char * *)&((struct Obj24775 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x5a);
    if(**(int * *)&((struct Obj24777 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        ((struct Obj00387 *)p)->f14=func_021FF408(((struct Obj24780 *)(*(char * *)&((struct Obj24779 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4,(void *)(((struct Obj24782 *)(*(char * *)&((struct Obj24781 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f8),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(func_0203CD98()) func_0203D34C(0,0x5a);
    if(!**(int * *)&((struct Obj24783 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        if(((struct Obj24785 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4!=1) func_02028A58((void *)func_02012A30(((struct Obj24787 *)(*(char * *)&((struct Obj24786 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x40,0);
    } else func_02005D90(0x484,0xffff);
    if(((struct Obj24788 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4==1) {
        func_021FEE9C((char *)(*(int *)&((struct Obj00387 *)p)->f10));func_021FEE4C((char *)(*(int *)&((struct Obj00387 *)p)->f10));
        func_021FE840(*(int *)&((struct Obj00387 *)p)->fC,3,0);
    }
    return 1;
}

int func_021F9244(int sys,int unused,int unused2,int *p)
{
    int *nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) func_02028A58((struct SoundSys *)func_02012A30((const struct BigObj *)nested[1]),0x7f,0);
    if(p[5]) {
        if(func_021FF8D4((char *)p[5])) ((int *)((int *)p[6])[3])[3]=2;
        func_021FF4E4((char *)p[5]); p[5]=0;
    } else func_02034A5C((int)ov125_id);
    func_021FEDC4((char *)p[4],(char *)p[1]);
    func_021FE734((char *)p[3]);
    func_021F9A6C((int *)p[2]);
    nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) {
        int a=(int)func_02012F08((int *)nested[1]);
        int b=func_021FC238((char *)p[1]);
        func_0200C3EC((struct Blk34 *)a,(unsigned char)b);
    }
    func_021FBDA4(p[1],0);
    func_021FBDA4(p[1],1);
    func_021FB92C((char *)p[1]);
    func_021FC474((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    func_020306F0(0x5a);
    return 1;
}

int func_021F92F4(int sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1: func_0204E720(3,16,0,0); *state=2; break;
    case 2: if(!func_0204E804()) *state=3; break;
    case 3:
        func_021FE768((S *)p[3]);
        func_021FEE00((char *)p[4]);
        func_021F9A80((char *)p[2]);
        func_021FC4C8((char *)p[0]);
        if(p[5]) func_021FF52C((char *)p[5]);
        if(func_021F9B98((int *)p[2])) *state=4;
        break;
    case 4: func_0204E720(3,0,16,0); *state=5; break;
    case 5: if(!func_0204E804()) *state=6; break;
    case 6: return 1;
    }
    return 0;
}
