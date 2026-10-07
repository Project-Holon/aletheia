/*
 * file:     btl_rec_sel_graphic_p03.c
 * unit:     yes
 * function: func_021BB360, func_021BB364, func_021BB36C, func_021BB3AC, func_021BB3C8, func_021BB3D0, func_021BB3DC, func_021BB448, func_021BB458
 * address:  0x021BB360
 * region:   ov214
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
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021BB0D4 0x021BB0D4 thumb ov214
 *   dims 0x020A1EB8 data
 *   vec1 0x021BB524 data a4
 *   vec2 0x021BB518 data ov214
 *   vec3 0x021BB530 data ov214
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */
#include "../../matched/include/Obj14703.h"
#include "../../matched/include/Obj25732.h"

struct Cfg;
struct Bank;
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

struct Vec3 { u32 x,y,z; };

extern void func_020419E4(void);
extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021BB0D4(void);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(int);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
void func_021BB360(void *p);
void func_021BB364(void);
void func_021BB36C(unsigned char *p, int a, int b);
void func_021BB3AC(void *p);
void func_021BB3C8(void);
void func_021BB3D0(void);
u32 func_021BB3D8(u32 *p);
void func_021BB3DC(u32 **out,u32 heap);
void func_021BB448(int *p);
void func_021BB458(unsigned int *p);
extern const char dims[];
extern struct Vec3 vec1,vec2,vec3;


void func_021BB360(void *p) { }

void func_021BB364(void) { func_020419E4(); }


void func_021BB36C(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BB54C, a, b);
    ((struct Obj14703 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14703 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

void func_021BB3AC(void *p) { func_0204B1CC(*(struct Bank * *)&((struct Obj25732 *)p)->f0);func_0204A5AC();func_02082BCC(p,0,4); }

void func_021BB3C8(void) { func_0204A600(); }

void func_021BB3D0(void) { func_0204A648(); }

/*
 * follower: 021BB3D8 word getter, within handed extent.
 */
u32 func_021BB3D8(u32 *p) { return *p; }

void func_021BB3DC(u32 **out,u32 heap)
{
    func_02046440(0,1,0,1,0,heap,func_021BB0D4);
    *out=func_02048A24(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,&vec1,&vec2,&vec3,heap);
}


void func_021BB448(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}


void func_021BB458(unsigned int *p)
{
    func_02047964();
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}
