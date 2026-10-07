/*
 * file:     intro_graphic_p02.c
 * unit:     yes
 * function: func_021BDDF8, func_021BDE10, func_021BDE28, func_021BDE30, func_021BDF34, func_021BDF74, func_021BDF90, func_021BDF98, func_021BDFA4, func_021BE03C, func_021BE0D4, func_021BE0EC
 * address:  0x021BDDF8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFEFC 0x021BFEFC data a4
 *   d_021BFEDC 0x021BFEDC data a4
 *   d_021BFE7C 0x021BFE7C data a4
 *   d_021BFE9C 0x021BFE9C data a4
 *   d_021BFEBC 0x021BFEBC data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_021BDB70 0x021BDB70 thumb ov204
 *   d_021BFD68 0x021BFD68 data a4
 *   d_021BFD5C 0x021BFD5C data a4
 *   d_021BFD74 0x021BFD74 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021BFD4C 0x021BFD4C data a4
 *   d_021BFD54 0x021BFD54 data a4
 *   func_02048AD0 0x02048AD0 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 */
#include "../../matched/include/G_DispConfig.h"
#include "../../matched/include/Obj14602.h"
#include "../../matched/include/Obj25335.h"
#include "../../matched/include/Obj25336.h"
#include "../../matched/include/G_021BFD68.h"
#include "../../matched/include/G_021BFD5C.h"
#include "../../matched/include/G_021BFD74.h"
#include "../../matched/include/Obj14603.h"
#include "../../matched/include/Obj25337.h"

struct Cfg;
struct Bank;
struct Light;
struct LightSet;
struct LightSlot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

struct BgTemplate { u32 a,b,c,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; };

typedef struct { u32 x, y, z; } Vec3;

extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(u8 *, u32, u32);
extern u32 func_02043658(void);
extern void func_02041EE4(u32, u32, u32);
extern void func_020419E4(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*setup)(void));
extern u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                          Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B60(struct Light *l, const u32 *in);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_021BDB70(void);
extern void func_02048C4C(u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
/* Original consumes 02048AD0's live r0 through the next veneer call. */
extern void *func_02048AD0(struct Light *);
extern void func_02047964(void *);
extern void func_020479D8(void);
extern void func_02047970(void);
void func_021BDDF8(u8 *p);
void func_021BDE10(u8 *a0);
void func_021BDE28(void *a0);
void func_021BDE30(void *p,u16 heap);
void func_021BDF34(unsigned char *p, int a, int b);
void func_021BDF74(u8 *p);
void func_021BDF90(void *a0);
void func_021BDF98(void *a0);
unsigned func_021BDFA0(char *p);
void func_021BDFA4(char *p, u8 heap);
void func_021BE03C(char *p, u8 heap);
void func_021BE0D4(u8 *p);
void func_021BE0EC(char *p);
void func_021BE100(char *unused);
int func_021BE108(void);
extern struct DispConfig d_021BFD80;
extern const struct BgTemplate d_021BFEFC,d_021BFEDC,d_021BFE7C,d_021BFE9C,d_021BFEBC;
extern struct G_021BFD68 d_021BFD68;
extern struct G_021BFD5C d_021BFD5C;
extern struct G_021BFD74 d_021BFD74;
extern const short d_020A1EB8[];
extern const struct LightSet d_021BFD4C;
extern const struct LightSet d_021BFD54;


/*
 * Addresses are Black-image addresses.
 */
void func_021BDDF8(u8 *p)
{
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}


void func_021BDE10(u8 *a0)
{
    if (func_02043658() & 4) {
        func_02041EE4(2, 1, 1);
    }
}

void func_021BDE28(void *a0) { func_020419E4(); }

void func_021BDE30(void *p,u16 heap)
{
    struct BgTemplate t1,t2,t3,t4,t5;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_021BFD80);
    t1=d_021BFEFC;
    func_0203FCA0(1,&t1,0);
    t2=d_021BFEDC;
    func_0203FCA0(2,&t2,0);
    t3=d_021BFE7C;
    func_0203FCA0(3,&t3,0);
    t4=d_021BFE9C;
    func_0203FCA0(4,&t4,0);
    t5=d_021BFEBC;
    func_0203FCA0(6,&t5,0);
    func_02040588(1,1);
    func_02040588(3,1);
    func_02040588(4,1);
    func_02040588(6,1);
}


void func_021BDF34(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BFD90, a, b);
    ((struct Obj14602 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14602 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021BDF74(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj25335 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021BDF90(void *a0){func_0204A600();}

void func_021BDF98(void *a0){func_0204A648();}

unsigned func_021BDFA0(char *p){return ((struct Obj25336 *)p)->f0;}

/*
 * lever: the fourth 02048A24 argument is the pooled 0x1555 (earlier notes
 * decoded it as 0x155, which also moved the pool order). The heap parameter
 * is u8: with the callees' own prototypes (02046440 s16 heap, 02048A24 u16
 * heap, 02048BC4 u32 heap) a u8 converts to all three with no code, matching
 * the original's unnarrowed full-word stack stores; u16/s16/u32 each add a
 * lsls/asr|lsr pair (156-160 bytes). Twin: ov204_func_021BE03C.c.
 */
void func_021BDFA4(char *p, u8 heap)
{
    u32 far_clip, near_clip;
    func_02046440(0, 4, 0, 2, 0, heap, func_021BDB70);
    *(u32 **)p = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&d_021BFD68), ((Vec3 *)&d_021BFD5C), ((Vec3 *)&d_021BFD74), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    func_02048B6C(*(struct Light **)p, &far_clip);
    func_02048B60(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFD4C, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}

void func_021BE03C(char *p, u8 heap)
{
    u32 far_clip, near_clip;
    func_02046440(0, 2, 0, 2, 0, heap, func_021BDB70);
    *(u32 **)p = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&d_021BFD68), ((Vec3 *)&d_021BFD5C), ((Vec3 *)&d_021BFD74), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    func_02048B6C(*(struct Light **)p, &far_clip);
    func_02048B60(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFD54, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}


void func_021BE0D4(u8 *p)
{
    func_02048C4C(((struct Obj14603 *)p)->f4);
    func_02048AC4((void *)(((struct Obj14603 *)p)->f0));
    func_02046788();
}

void func_021BE0EC(char *p){func_02047964(func_02048AD0(*(struct Light * *)&((struct Obj25337 *)p)->f0));func_020479D8();}

void func_021BE100(char *unused){func_02047970();}

int func_021BE108(void){return 1;}
