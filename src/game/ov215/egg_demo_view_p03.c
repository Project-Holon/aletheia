/*
 * file:     egg_demo_view_p03.c
 * unit:     yes
 * function: func_021F6A48, func_021F6A84, func_021F6A98, func_021F6AB4, func_021F6AB8, func_021F6AE0, func_021F6AEC, func_021F6CAC, func_021F6CC0, func_021F6CCC, func_021F6D0C, func_021F6D1C, func_021F6D58
 * address:  0x021F6A48
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015F50 0x02015F50 thumb
 *   func_0201600C 0x0201600C thumb
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02014BA8 0x02014BA8 thumb
 *   table 0x021F7384 data a4
 *   func_02017270 0x02017270 thumb
 *   func_02015FF0 0x02015FF0 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015F0C 0x02015F0C thumb
 *   func_02015F1C 0x02015F1C thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   func_02015E04 0x02015E04 thumb
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 *   sub_02015BA4 0x02015BA4 thumb
 *   func_02016028 0x02016028 thumb
 *   func_02015EE8 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   func_02015E4C 0x02015E4C thumb
 *   func_02063000 0x02063000 arm
 *   func_020173B4 0x020173B4 thumb
 *   func_02015FAC 0x02015FAC thumb
 *   func_02015FBC 0x02015FBC thumb
 */
#include "../../matched/include/Obj25758.h"
#include "../../matched/include/Obj14710.h"
#include "../../matched/include/Obj25759.h"
#include "../../matched/include/Obj25760.h"
#include "../../matched/include/Obj02262.h"
#include "../../matched/include/Obj10941.h"
#include "../../matched/include/Obj25761.h"
#include "../../matched/include/Obj06707.h"
#include "../../matched/include/Obj14711.h"
#include "../../matched/include/Obj05551.h"
#include "../../matched/include/Obj14712.h"

#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
struct McssFade;
struct Obj;
struct Data;
typedef unsigned char u8;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef struct {int x,y,z;} Vec;

typedef struct {u32 species;float x,y;} Entry;

extern void func_02015EA0(void *);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern int func_0201600C(void *);
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *, unsigned int);
extern void func_02015BF0(void *);
extern void func_02014BA8(u8 *);
extern void *func_02017270(void *,void *,u32,u32,u32,u32);
extern void func_02015FF0(char *,int);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02015C48(void *,u32 *);
extern void func_02015CAC(void *,u32 *);
extern u16 func_02015F0C(void *);
extern s16 func_02015F1C(void *);
extern s16 func_02015F14(void *);
extern void func_02015C78(void *,u32 *);
extern void func_02015E04(void *);
extern void sub_02015BA4(void *,void *);
/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void func_02016028(void *,unsigned);
extern void *func_02015EE8(void *);
extern void func_02064CBC(struct Obj *x);
extern void func_02015E4C(void *);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern int func_020173B4(int a0);
extern u8 func_02015FAC(struct Data *);
extern void func_02015FBC(char *,int);
void func_021F6A48(char *p,int a);
int func_021F6A84(char *p);
void func_021F6A98(char *p);
int func_021F6AA4(char *p);
void func_021F6AB4(void);
void func_021F6AB8(char *p);
void func_021F6AE0(char *p);
void func_021F6AEC(char *p);
void func_021F6CAC(char *p);
void func_021F6CC0(char *p);
void func_021F6CCC(char *p,unsigned flag,int enable);
int func_021F6D0C(char *a);
void func_021F6D1C(char *p);
void func_021F6D58(char *p);
extern const Entry table[];

void func_021F6A48(char *p,int a)
{
    func_021F6CAC(p);
    *(int *)(p + 4) = a;
    func_021F6AEC(p);
    func_021F6CCC(p,0,0);
    func_02015EA0(*(void **)(p + 0x34));
    func_02015F50(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}

/*
 * trailing: existing followers 021F6A98/6AA4 unit and 021F6AB4 shard.
 */
int func_021F6A84(char *p){if(func_0201600C(((struct Obj25758 *)p)->f34)==0)return 1;return 0;}

void func_021F6A98(char *p){((struct Obj14710 *)p)->fC=6;((struct Obj14710 *)p)->f18=0;}

int func_021F6AA4(char *p){if(((struct Obj25759 *)p)->fC>=9)return 1;return 0;}

/*
 * evidence: sole callback blocker of 021F6720; parent SDK/ownership audit.
 * extent: bx lr at 021F6AB4, zero padding at 6AB6; 6AB8 begins next function.
 */
void func_021F6AB4(void)
{
}

void func_021F6AB8(char *p)
{
    *(void **)(p + 0x30) = func_02014B08(1, (void *)(*(unsigned short *)p));
    func_02016020(*(void **)(p + 0x30), 3 << 16);
    func_02015BF0(*(void **)(p + 0x30));
    *(unsigned int *)(p + 0x3c) = 0;
    *(unsigned char *)(p + 0x40) = 0;
}

void func_021F6AE0(char *p){func_02014BA8(*(u8 * *)&((struct Obj25760 *)p)->f30);}

/*
 * lever: FX float rounding macro; translation z shares the constructor's -50<<16 literal.
 */
void func_021F6AEC(char *p)
{
    Vec trans,scale,delta;
    u32 species;
    u8 i=0;
    float angle,y,x;
    ((struct Obj02262 *)p)->f34=func_02017270(((struct Obj02262 *)p)->f30,((struct Obj02262 *)p)->f4,0,0,0xfff42000,0xffce0000);
    func_02015FF0(*(char * *)&((struct Obj02262 *)p)->f34,1);
    species=func_02017E1C(((struct Obj02262 *)p)->f4,171,0);
    if(species!=650){
        for(;i<4;i++){
            if(species==table[i].species){
                trans.x=FIX(table[i].x);
                trans.y=FIX(table[i].y);
                trans.z=0xffce0000;
                func_02015C48(((struct Obj02262 *)p)->f34,(u32 *)&trans);
                break;
            }
        }
    }
    scale.x=65536;scale.y=65536;scale.z=4096;
    func_02015CAC(((struct Obj02262 *)p)->f34,(u32 *)&scale);
    angle=(float)func_02015F0C(((struct Obj02262 *)p)->f34);
    y=(float)func_02015F1C(((struct Obj02262 *)p)->f34);
    x=(float)func_02015F14(((struct Obj02262 *)p)->f34);
    if(angle>96.0f)angle=96.0f;
    y=(96.0f-angle)/2.0f+y;
    x=0.0f-x;
    delta.x=FIX(x);delta.y=FIX(y);delta.z=0;
    func_02015C78(((struct Obj02262 *)p)->f34,(u32 *)&delta);
    func_02015E04(((struct Obj02262 *)p)->f34);
}

/*
 * trailing: existing follower 021F6CC0 in its own matched shard.
 */
void func_021F6CAC(char *p){func_02015EA0(((struct Obj10941 *)p)->f34);sub_02015BA4(((struct Obj10941 *)p)->f30,((struct Obj10941 *)p)->f34);}

/*
 * leaf: sole overlay blocker of 021F67E0; tail-call pool ends at 021F6CCC.
 */
void func_021F6CC0(char *p){func_02015EA0(((struct Obj25761 *)p)->f34);}

void func_021F6CCC(char *p,unsigned flag,int enable)
{
    void *obj;
    func_02016028(((struct Obj06707 *)p)->f34,flag);
    obj=func_02015EE8(((struct Obj06707 *)p)->f34);
    func_02064CBC(obj);
    func_02015E4C(((struct Obj06707 *)p)->f34);
    if(enable) {
        func_02063000((int)obj,1,(int)p,(int)func_021F6D0C);
        ((struct Obj06707 *)p)->f38=0;
    } else func_020173B4((int)(((struct Obj06707 *)p)->f34));
}


/*
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
int func_021F6D0C(char *a)
{
    func_02015E04((void *)(((struct Obj14711 *)a)->f34));
    ((struct Obj14711 *)a)->f38 = 1;
    return 1;
}

void func_021F6D1C(char *p){u8 n;if(((struct Obj05551 *)p)->f3C){n=func_02015FAC(*(struct Data * *)&((struct Obj05551 *)p)->f34);if(n>((struct Obj05551 *)p)->f40)n--;else n++;func_02015FBC(*(char * *)&((struct Obj05551 *)p)->f34,n);if(n==((struct Obj05551 *)p)->f40)((struct Obj05551 *)p)->f3C=0;}}

void func_021F6D58(char *p){func_02015E04(((struct Obj14712 *)p)->f34);func_02015F50(*(struct McssFade * *)&((struct Obj14712 *)p)->f34,0,16,0,32767);}
