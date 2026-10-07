/*
 * file:     br_proc_sys_p03.c
 * unit:     yes
 * function: func_021F9754, func_021F9774, func_021F97A0, func_021F97EC
 * address:  0x021F9754
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
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 *   func_021F98F8 0x021F98F8 thumb ov186
 */
#include "../../matched/include/Obj05496.h"
#include "../../matched/include/Obj05497.h"
#include "../../matched/include/Obj24791.h"
#include "../../matched/include/Obj24792.h"
#include "../../matched/include/Obj14449.h"
#include "../../matched/include/Obj24794.h"
#include "../../matched/include/Obj24795.h"
#include "../../matched/include/Obj24796.h"

struct Pair;
struct PrintSys;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern u32 func_021FC4DC(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F98F8(char *p, int skip, void *sys, int heap);
void func_021F9754(int *out,int *source);
void func_021F9770(void);
void func_021F9774(char *p,char *q);
void func_021F979C(void);
void func_021F97A0(int *out,int *source,int *ctx,int type);
void func_021F97EC(char *p,char *q);
extern const char d_02200D00[];

void func_021F9754(int *out,int *source)
{
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[2];
    out[1]=func_021FC4DC((u8 *)source[0]);
}

/*
 * Extent includes empty follower func_021F9770; zeros at 021F976E and 021F9772 are alignment.
 */
void func_021F9770(void)
{
}

void func_021F9774(char *p,char *q) { ((struct Obj05496 *)p)->f8=((struct Obj05497 *)q)->f4;((struct Obj05496 *)p)->f0=((struct Obj05497 *)q)->fC;((struct Obj05496 *)p)->fC=((struct Obj05497 *)q)->f8;((struct Obj05496 *)p)->f4=func_021FC4DC((u8 *)(((struct Obj05497 *)q)->f0));((struct Obj05496 *)p)->f10=((struct Obj05497 *)q)->f14;((struct Obj05496 *)p)->f14=((struct Obj24792 *)(*(char * *)&((struct Obj24791 *)(*(char * *)&((struct Obj05497 *)q)->f18))->fC))->f4; }

/*
 * extent: empty-return follower 0x021F979C; trailing two-byte padding.
 */
void func_021F979C(void) {}

void func_021F97A0(int *out,int *source,int *ctx,int type)
{
    if(type==1) {
        out[0]=ctx[2];
        out[3]=source[1];
        out[1]=source[3];
        out[4]=source[2];
        out[2]=func_021FC4DC((u8 *)source[0]);
        out[5]=(*(int **)((char *)source[6]+0xc))[1];
        out[6]=*(int *)((char *)source[6]+8)+0x1748;
    } else {
        func_02034714(d_02200D00,0,d_02200D00);
    }
}

void func_021F97EC(char *p,char *q) { char *s;if(((struct Obj24794 *)p)->f1C){s=*(char * *)&((struct Obj24795 *)q)->f18;func_021F98F8((char *)(((struct Obj14449 *)s)->f8+0x1748),0,(void *)(((struct Obj24796 *)(*(char * *)&((struct Obj14449 *)s)->fC))->f4),90);} }
