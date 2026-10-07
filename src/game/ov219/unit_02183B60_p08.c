/*
 * file:     unit_02183B60_p08.c
 * unit:     yes
 * function: func_02185580, func_0218562C, func_021856CC, func_02185728, func_02185794, func_02185824
 * address:  0x02185580
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204767C 0x0204767C arm
 *   d_02185E18 0x02185E18 data a2
 *   func_02048AC4 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_02185F00 0x02185F00 data a4
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B80 0x02048B80 arm
 *   func_02048B94 0x02048B94 arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02185AC8 0x02185AC8 thumb ov219
 *   d_020A1C78 0x020A1C78 data
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   d_02185DD4    0x02185DD4 data ov219
 */
#include "../../matched/include/Obj04645.h"
#include "../../matched/include/Obj04646.h"
#include "../../matched/include/Obj10975.h"
#include "../../matched/include/G_02185E0C.h"
#include "../../matched/include/G_Vec3.h"
#include "../../matched/include/Obj10976.h"

struct Rec;
struct Tagged;
struct Light;
struct LightSet;
struct LightSlot;
typedef unsigned short u16;

typedef struct {u16 index,member;} Entry;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {unsigned x,y,z;} Vec3_02185728;

typedef struct {Vec3_02185728 vec;short x,y;} Config;

typedef struct {u32 x,y,z;} Vec3_02185794;

typedef struct {char pad[0x30]; short a, b;} Cfg;

extern void *func_02046DB8(unsigned,unsigned),*func_02047400(void *,unsigned,void *),*func_0204767C(unsigned,unsigned *,int);
extern int func_02046FF8(int *);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(void *);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *);
extern void func_02046EFC(struct Tagged *p);
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,Vec3_02185728 *,Vec3_02185728 *,Vec3_02185728 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_02048AFC(void *, Vec3_02185794 *);
extern void func_02048B44(void *, Vec3_02185794 *);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern int func_02185AC8(char *);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
void func_02185580(char *p, void *arc);
void func_0218562C(char *p);
void func_021856CC(u8 *p);
void func_02185728(char *p);
void func_02185794(char *p);
void func_02185824(char *p);
extern const Entry d_02185E18[];
extern struct G_02185E0C d_02185E0C;
extern struct Vec3_02185728 d_02185DF4;
extern Vec3_02185728 d_02185F00;
extern Config d_020A1EB8;
extern Cfg d_020A1C78;
extern char d_02185DD4[];

void func_02185580(char *p, void *arc)
{
    unsigned i;
    char *row;
    ((struct Obj04645 *)p)->fC374=func_02046DB8(197,0);
    func_02046FF8(*(int * *)&((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC38C=func_02047400(((struct Obj04645 *)p)->fC374,0,((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC3A4=func_0204767C(*(unsigned *)&((struct Obj04645 *)p)->fC38C,0,0);
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        ((struct Obj04646 *)row)->fC378=func_02046DB8(197,d_02185E18[i].member);
        func_02046FF8(*(int * *)&((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC390=func_02047400(((struct Obj04646 *)row)->fC378,0,((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC3A8=func_0204767C(*(unsigned *)&((struct Obj04646 *)row)->fC390,0,0);
    }
    func_02185728(p);
    func_02185824(p);
}

void func_0218562C(char *p)
{
    u32 i;
    char *row;
    func_02048AC4(*(void **)(p+0xC36C));
    func_02048C4C(*(void **)(p+0xC370));
    func_02047738(*(void **)(p+0xC3A4));
    func_02047504(*(void **)(p+0xC38C));
    func_020470D0(*(u32 **)(p+0xC374));
    func_02046EFC(*(void **)(p+0xC374));
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        func_02047738(*(void **)(row+0xC3A8));
        func_02047504(*(void **)(row+0xC390));
        func_020470D0(*(u32 **)(row+0xC378));
        func_02046EFC(*(void **)(row+0xC378));
    }
    *(u32 *)(p+0xC3A4)=0;
}


void func_021856CC(u8 *p)
{
    int k = 0xC2DC;

    *(int *)(p + k) = 0;
    *(int *)(p + k + 4) = 0;
    *(int *)(p + k + 8) = 0;
    *(int *)(p + k + 0xC) = 0x1000;
    *(int *)(p + k + 0x10) = 0x1000;
    *(int *)(p + k + 0x14) = 0x1000;
    *(int *)(p + k + 0x18) = 0x1A40;
    *(int *)(p + k + 0x1C) = 0x7C00;
    *(int *)(p + k + 0x20) = 0;
    *(int *)(p + k + 0x24) = 0x1000;
    *(int *)(p + k + 0x28) = 0x1000;
    *(int *)(p + k + 0x2C) = 0x1000;
}

void func_02185728(char *p)
{
    Vec3_02185728 vec;
    u16 heap;
    heap=((struct Obj10975 *)p)->f0;
    vec=d_02185F00;
    ((struct Obj10975 *)p)->fC36C=func_02048A24(0,d_020A1EB8.x,d_020A1EB8.y,5461,0,4096,4194304,0,((Vec3_02185728 *)&d_02185E0C),&vec,((Vec3_02185728 *)&d_02185DF4),heap);
    func_02048AD0(((struct Obj10975 *)p)->fC36C);
}


/*
 * note 2026-10-05 (wD6 lane16): EXACT. The flag block is an if/else-if chain with h == 0 first; tail merging of the duplicate stores gives the bne/b pairs.
 */
void func_02185794(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    func_02048AFC(*(void **)(p + 0xC36C), ((Vec3_02185794 *)&d_02185E0C));
    func_02048B44(*(void **)(p + 0xC36C), ((Vec3_02185794 *)&d_02185DF4));
    func_02048B80(*(void **)(p + 0xC36C), d_020A1C78.a);
    func_02048B94(*(void **)(p + 0xC36C), d_020A1C78.b);
    func_02048B60(*(void **)(p + 0xC36C), &a);
    func_02048B6C(*(void **)(p + 0xC36C), &b);
    if (*(u16 *)(p + 0xC31C) == 0)
        *(u16 *)(p + 0xC30C) = 1;
    else if (*(u32 *)(p + 0xC33C) == 0)
        *(u16 *)(p + 0xC30C) = 0;
    else if (*(u32 *)(p + 0xC33C) == 0xdc)
        *(u16 *)(p + 0xC30C) = 0;
    else
        *(u16 *)(p + 0xC30C) = 1;
    while (func_02185AC8(p) != 1)
        ;
}


void func_02185824(char *p)
{
    ((struct Obj10976 *)p)->fC370 = func_02048BC4((const struct LightSet *)d_02185DD4, (unsigned short)((struct Obj10976 *)p)->f0);
    func_02048C58(((struct Obj10976 *)p)->fC370);
}
