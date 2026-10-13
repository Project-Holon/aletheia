/*
 * file:     unit_021DC860.c
 * unit:     yes
 * function: func_021DC860, func_021DC900, func_021DC924, func_021DC94C, func_021DC964, func_021DC970, func_021DC9A0, func_021DC9B4, func_021DC9B8, func_021DC9C4, func_021DC9D8
 * address:  0x021DC860
 * region:   ov170
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
 *   func_02007698 0x02007698 thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_020076B4 0x020076B4 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   func_021E1E34  0x021E1E34  thumb  ov170
 *   func_02030EAC  0x02030EAC  arm  arm9
 *   func_021EAB04  0x021EAB04  thumb  ov170
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   func_020433E0  0x020433E0  arm  arm9
 *   PROCSYS_Main  0x02031330  arm  arm9
 */
#include "box2_types.h"
#include "../../matched/include/Obj09220.h"
#include "../../matched/include/Obj18436.h"
#include "../../matched/include/Obj18437.h"
#include "../../matched/include/Obj12145.h"

struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct Node;
struct S02021D50;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef enum { B0=0, B8=8, B16=16 } Bound;

typedef unsigned int   u32;

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *,int,unsigned);
extern unsigned func_02007698(void *);
extern u8 func_020076A4(void *);
extern int func_020078C4(void *save, u32 box);
extern u8 func_020076B4(void *);
extern void *PROCSYS_Create(int a0);
extern unsigned int PROCSYS_Main(void *);
extern int func_021E1E34(char *p, int *state);
extern void func_0200780C(void *save, u32 box);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_020056A0(void *, void *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021EAB04(unsigned char *w);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *c);
int func_021DC860(void *manager, int unused, void **context);
int func_021DC900(int a, int b, int c, int *d);
int func_021DC924(int a, int b, int c, int *d);
void func_021DC94C(char *p);
void func_021DC964(char *p);
void func_021DC970(u32 a, char *p);
void func_021DC9A0(char *p, int v);
void func_021DC9B4(char *p, int v);
void func_021DC9B8(char *p);
void func_021DC9C4(void);
void *func_021DC9D8(void);
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

int func_021DC860(void *manager, int unused, void **context)
{
    u8 *p;
    u16 max;
    u16 i;
    func_0203064C(1,75,0x10000);
    p = func_0203159C(manager,0x30,75);
    func_02082BCC(p,0,0x30);
    *(void ** *)&((BoxTask *)p)->f0 = context;
    p[0x14] = func_02007698(context[1]);
    p[0x15] = func_020076A4((*(void ***)p)[1]);
    p[0x17] = 255;
    ((BoxTask *)p)->f28 = 11;
    if ((u8)p[0x15] != 24) {
        if ((u8)p[0x15] == 8) max = B8;
        else if ((u8)p[0x15] == 16) max = B16;
        for (i=0;i<max;i++) {
            if (func_020078C4((*(void ***)p)[1],i) == 0) break;
        }
        if (i == max) p[0x15] = func_020076B4((*(void ***)p)[1]);
    }
    p[0x20] = 0;
    p[0x1f] = 0;
    p[0x21] = 1;
    ((BoxTask *)p)->f4 = PROCSYS_Create(75);
    return 1;
}

/*
 * Re-derive d[2] from d[1] then test the entry; 0 means accepted.
 */
int func_021DC900(int a, int b, int c, int *d)
{
    d[2] = PROCSYS_Main((void *)d[1]);
    if (func_021E1E34((char *)d, (int *)b) == 0)
        return 1;
    return 0;
}

int func_021DC924(int a, int b, int c, int *d)
{
    func_0200780C((void *)(*(int *)(*d + 4)), ((struct Obj09220 *)d)->f14);
    func_0203133C((struct S020314B8 *)d[1]);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x4b);
    return 1;
}

/*
 * Seat the 0x54 handler word.
 */
void func_021DC94C(char *p)
{
    *(int *)(((struct Obj18436 *)p)->f2C + 0x54) = func_020056A0((void *)func_021DC970, p, 0);
}


/*
 * Tail call func_02030EAC with the word at +0x2c/+0x54.
 */
void func_021DC964(char *p)
{
    func_02030EAC(((struct Obj18437 *)(*(char * *)&((BoxTask *)p)->f2C))->f54);
}


void func_021DC970(u32 a, char *p)
{
    func_021EAB04((unsigned char *)(((struct Obj12145 *)p)->f2C));
    func_020419E4();
    func_0204A648();
    PALANM_TransferPalettes((struct S02021D50 *)(*(u32 *)(((struct Obj12145 *)p)->f2C + 0x6c)));
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3ff8) |= 1;
}



/*
 * Clear the two halfword fields at +0x64/+0x66, store v at +0x58 and zero +0x5c.
 */
void func_021DC9A0(char *p, int v)
{
    ((BoxWork *)p)->f64 = 0;
    ((BoxWork *)p)->f66 = 0;
    ((BoxWork *)p)->f58 = v;
    ((BoxWork *)p)->f5C = 0;
}


/*
 * Store the second argument into the word field at +0x5c of the object.
 */
void func_021DC9B4(char *p, int v)
{
    ((BoxWork *)p)->f5C = v;
}


/*
 * Re-run the reset helper with the stored word.
 */
void func_021DC9B8(char *p)
{
    func_021DC9A0(p, ((BoxWork *)p)->f5C);
}


/*
 * Two calls after setting the first argument.
 */
void func_021DC9C4(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((void *)0x021EF7CC);
}

/*
 * Constant-address getter.
 */
void *func_021DC9D8(void)
{
    return (void *)0x021EF7CC;
}
