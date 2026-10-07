/*
 * file:     battle_championship_flow_p01.c
 * unit:     yes
 * function: func_0217AE20, func_0217AE88, func_0217AECC, func_0217AEF4, func_0217AF04, func_0217AF14, func_0217AF2C, func_0217AF44, func_0217AF50, func_0217AF9C, func_0217AFBC, func_0217AFD0, func_0217B00C
 * address:  0x0217AE20
 * region:   ov176
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
 *   func_02034AC4 0x02034AC4 arm
 *   func_0217B014 0x0217B014 thumb ov176
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_02034A5C  0x02034A5C  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   ov177_id       0x000000B1  data
 *   ov67_id        0x00000043  data
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021E5440  0x021E5440  thumb  ov177
 *   func_021E54E0  0x021E54E0  thumb  ov177
 *   func_021E5534  0x021E5534  thumb  ov177
 *   func_021E5980  0x021E5980  thumb  ov177
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E567C  0x021E567C  thumb  ov177
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8628  0x021E8628  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_021E867C  0x021E867C  thumb  ov177
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_0217B0C8 0x0217B0C8 thumb ov176
 *   func_0217B1BC 0x0217B1BC thumb ov176
 */
#include "../../matched/include/Obj10694.h"
#include "../../matched/include/Obj03869.h"
#include "../../matched/include/Obj04561.h"
#include "../../matched/include/Obj14355.h"
#include "../../matched/include/Obj10695.h"
#include "../../matched/include/Obj02888.h"
#include "../../matched/include/Obj24399.h"
#include "../../matched/include/Obj24400.h"

struct Obj0203159C;
struct S020315D4;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct Rec;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {void (*fn)(void *);} CB;

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern int func_02034AC4(signed int);
extern void func_0217B014(void *,int *,char *);
extern int *func_021E8A3C(int a, int b, int c);
extern void func_021E8A78(int);
extern void func_02034A5C(int);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_0217AF14(int *),func_0217AFBC(int *),func_021E8A80(CB *);
extern int func_021E8A90(int **);
extern int *func_021E5440(unsigned swap, int heap);
extern void func_021E54E0(char *p);
extern void func_021E5534(u8 *p);
extern void func_021E5980(int);
extern int func_021E5548(int *p);
extern u32 *func_021E567C(int unused, int mode, int heap);
extern void func_021E5868(void *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *func_021E8568(unsigned,unsigned,unsigned,unsigned,void *,void *,unsigned);
extern void func_021E8628(u32 a);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_021E867C(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AA8(int a);
extern void func_0217B0C8(int *a, int *state, int *p);
extern void func_0217B1BC(int *a, int *state, int *p);
int func_0217AE20(void *a,void *b,void *context);
int func_0217AE88(int a, int b, int c, int *p);
int func_0217AECC(u32 a,u32 b,u32 c,int *p);
void func_0217AEF4(int *p);
void func_0217AF04(int *p);
void func_0217AF14(int *p);
void func_0217AF2C(int *p);
void func_0217AF44(int *p);
void func_0217AF50(char *p);
void func_0217AF9C(int *p);
void func_0217AFBC(int *p);
void func_0217AFD0(void *a,int b,char *p);
void func_0217B00C(void *a);
extern char ov67_id[],ov177_id[];
extern char ov67_id[];

int func_0217AE20(void *a,void *b,void *context)
{
    char *p;
    func_0203064C(1,0x4e,0x30200);
    p=func_0203159C(a,0x34,0x4e);
    func_02082BCC(p,0,0x34);
    ((struct Obj10694 *)p)->f28=context;
    ((struct Obj10694 *)p)->f0=0x4e;
    func_02034AC4((int)ov67_id);
    func_02034AC4((int)ov177_id);
    func_0217AEF4((int *)p);
    func_0217AF2C((int *)p);
    func_0217AF50(p);
    ((struct Obj10694 *)p)->f4=func_021E8A3C((int)p,(int)func_0217B014,0x4e);
    return 1;
}


int func_0217AE88(int a, int b, int c, int *p)
{
    func_021E8A78(((struct Obj03869 *)p)->f4);
    func_0217AF9C(p);
    func_0217AF44(p);
    func_0217AF04(p);
    func_02034A5C((int)ov177_id);
    func_02034A5C((int)ov67_id);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x4e);
    return 1;
}

int func_0217AECC(u32 a,u32 b,u32 c,int *p) {func_0217AF14(p);func_0217AFBC(p);func_021E8A80(*(CB * *)&((struct Obj04561 *)p)->f4);if(func_021E8A90(*(int ** *)&((struct Obj04561 *)p)->f4)) return 1;return 0;}


void func_0217AEF4(int *p)
{
    ((struct Obj14355 *)p)->f24 = (int)func_021E5440(1, ((struct Obj14355 *)p)->f0);
}


void func_0217AF04(int *p)
{
    func_021E54E0((char *)(((struct Obj03869 *)p)->f24));
    ((struct Obj03869 *)p)->f24 = 0;
}


void func_0217AF14(int *p)
{
    if (((struct Obj04561 *)p)->f24) {
        func_021E5534((u8 *)(((struct Obj04561 *)p)->f24));
        func_021E5980(((struct Obj04561 *)p)->f20);
    }
}


/*
 *   func_021E5548 (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_0217AF2C(int *p)
{
    ((struct Obj10695 *)p)->f20 = (int)func_021E567C(func_021E5548((int *)(((struct Obj10695 *)p)->f24)), 1, ((struct Obj10695 *)p)->f0);
}

void func_0217AF44(int *p) {func_021E5868(((struct Obj03869 *)p)->f20);}

/*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 */
void func_0217AF50(char *p)
{
    ((struct Obj02888 *)p)->fC=func_0201D7EC(0x17,0,0,0,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f10=func_02045B38(0,2,4,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f14=(void *)func_0201C440((void *)(((struct Obj02888 *)p)->f0));
    ((struct Obj02888 *)p)->f8=func_021E8568(0,15,14,10,((struct Obj02888 *)p)->f14,((struct Obj02888 *)p)->fC,((struct Obj02888 *)p)->f0);
}


void func_0217AF9C(int *p)
{
    func_021E8628(((struct Obj03869 *)p)->f8);
    func_0201C4C0((struct PrintSys *)(((struct Obj03869 *)p)->f14));
    func_02045C04((struct Rec *)(((struct Obj03869 *)p)->f10));
    func_0201D83C((void *)(((struct Obj03869 *)p)->fC));
}


void func_0217AFBC(int *p)
{
    func_021E867C((char *)(((struct Obj04561 *)p)->f8));
    func_0201C4E4((struct PrintSys *)(((struct Obj04561 *)p)->f14));
}

void func_0217AFD0(void *a,int b,char *p)
{
    switch(((struct Obj24400 *)(*(char * *)&((struct Obj24399 *)p)->f28))->f4){
    case 0: case 1: case 2:
        func_021E8AA0(a,(int)func_0217B0C8); break;
    case 3: case 4: case 5: case 6:
        func_021E8AA0(a,(int)func_0217B1BC); break;
    }
}

void func_0217B00C(void *a)
{
    func_021E8AA8((int)a);
}
