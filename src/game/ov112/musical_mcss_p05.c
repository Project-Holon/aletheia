/*
 * file:     musical_mcss_p05.c
 * unit:     yes
 * function: func_021F4C94, func_021F4D40, func_021F4D74, func_021F4DE0, func_021F4E2C, func_021F4E6C, func_021F4E8C, func_021F4EA4, func_021F4EB4, func_021F4EC4, func_021F4ED4, func_021F4EE0, func_021F4EE8, func_021F4EFC, func_021F4F04, func_021F4F10, func_021F4F14, func_021F4F40, func_021F4F54, func_021F4F60, func_021F4F70, func_021F4F74, func_021F4FF4, func_021F5064, func_021F50D0, func_021F50E0, func_021F50F4, func_021F5140, func_021F514C
 * address:  0x021F4C94
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204F428 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   d_021F8300 0x021F8300 data a4
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_0204F1A0 0x0204F1A0 arm
 *   func_021F4AA8 0x021F4AA8 thumb ov112
 *   func_0204F604 0x0204F604 arm
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   func_0204F2CC 0x0204F2CC arm
 *   func_0204F32C 0x0204F32C arm
 *   sub_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   func_0204A1BC 0x0204A1BC arm
 *   d_021F83B4 0x021F83B4 data a1
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj05310.h"
#include "../../matched/include/Obj13826.h"
#include "../../matched/include/Obj02168.h"
#include "../../matched/include/Obj10298.h"
#include "../../matched/include/Obj05311.h"
#include "../../matched/include/Obj05312.h"
#include "../../matched/include/Obj13827.h"
#include "../../matched/include/Obj22523.h"
#include "../../matched/include/Obj01396.h"
#include "../../matched/include/Obj10300.h"
#include "../../matched/include/Obj22528.h"
#include "../../matched/include/Obj22530.h"
#include "../../matched/include/Obj13828.h"
#include "../../matched/include/Obj22532.h"
#include "../../matched/include/Obj22533.h"

struct Board;
struct Vec3;
struct Obj0204F1A0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16_021F4C94;

typedef signed int     s32_021F4C94;

typedef struct { u16 flags, zero; u32 id, index, type; int x,y,z; s16_021F4C94 a,b; void *data; } Entry_021F4C94;

typedef struct { u32 pad; void *board; Entry_021F4C94 *entries; } Object;

typedef short s16_021F4D40;

typedef struct { u16 low:4; u16 bit4:1; u16 rest:11; } Bits_021F4D40;

typedef struct { u16 low:3; u16 bit3:1; u16 bit4:1; u16 rest:11; } Bits_021F4D74;

typedef struct { u16 low:3; u16 bit3:1; u16 rest:12; } Bits_021F4DE0;

typedef signed int     s32_021F4DE0;

typedef signed short s16_021F4E2C;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4E2C;

typedef short s16_021F4E6C;

typedef short s16_021F4E8C;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16_021F4E8C a,b; u8 *data; } Entry_021F4E8C;

typedef short s16_021F4EA4;

typedef short s16_021F4EB4;

typedef short s16_021F4EC4;

typedef short s16_021F4ED4;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4EE8;

typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags_021F4EFC;

typedef struct { int x, y; } Offset;

typedef short s16_021F4F10;

typedef signed char s8;

typedef int s32_021F4F10;

typedef short s16_021F4F54;

typedef int s32_021F4F54;

extern s32_021F4C94 func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *,u32,u32 *);
extern void func_0204F5A8(void *,u32);
extern void func_0204F1A0(struct Obj0204F1A0 *a0, u32 a1);
extern u16 func_021F4AA8(int);
extern void func_0204F604(void *,u32,u16 *);
extern void func_0204F2CC(int p0, int p1, int p2);
extern void func_0204F32C(int p0, int p1, int p2);
extern s32_021F4DE0 sub_02061CA4(void *p, u32 a, u32 b, s32_021F4DE0 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
Entry_021F4C94 *func_021F4C94(Object *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b);
void func_021F4D40(u8 *p,u8 *e);
void func_021F4D74(u8 *p, u8 *e, int type, u16 id);
void func_021F4DE0(char *p, char *e, void *a2);
void func_021F4E2C(void *unused, u8 *s, u8 *d);
void func_021F4E6C(u8 *p,u8 *e,u32 value);
void func_021F4E8C(u32 unused,Entry_021F4E8C *p,const int *q);
void func_021F4EA4(u32 unused,u32 p,u32 q);
void func_021F4EB4(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b);
void func_021F4EC4(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b);
void func_021F4ED4(u32 unused,u32 p,u16 v);
void func_021F4EE0(int unused, u16 *p, u16 *out);
void func_021F4EE8(int unused,Flags_021F4EE8 *s,int flag);
int func_021F4EFC(int unused, Flags_021F4EFC *p);
void func_021F4F04(u8 *p, Offset *out);
u32 func_021F4F10(u8 *p);
u32 *func_021F4F14(int heap);
void func_021F4F40(void **p);
u8 *func_021F4F54(u8 *p, int i);
void func_021F4F60(u8 *p, Offset *out);
int func_021F4F70(int *p);
int func_021F4F74(u16 *p, int mode);
int func_021F4FF4(u16 *p, int mode);
int func_021F5064(u8 *p, int mode);
int func_021F50D0(const unsigned char *p);
int func_021F50E0(const unsigned char *p);
int func_021F50F4(unsigned index);
unsigned char func_021F5140(void *p, int i);
unsigned char func_021F514C(void *p, int i);
extern u32 d_021F8300;
extern char d_021F83B4[];

Entry_021F4C94 *func_021F4C94(Object *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b)
{
    p->entries[index].index = func_0204F428(p->board,p->entries[index].id,4096,4096,(struct Vec3 *)v,31,0,0);
    func_0204F720(p->board,p->entries[index].index,&d_021F8300);
    p->entries[index].flags = (p->entries[index].flags & ~1) | 1;
    p->entries[index].flags |= 2;
    p->entries[index].flags |= 4;
    p->entries[index].flags = p->entries[index].flags & ~8;
    p->entries[index].x = v[0];
    p->entries[index].y = v[1];
    p->entries[index].z = v[2];
    p->entries[index].a = a;
    p->entries[index].b = b;
    p->entries[index].zero = 0;
    return &p->entries[index];
}

void func_021F4D40(u8 *p,u8 *e) { func_0204F5A8(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f8); if (((Bits_021F4D40 *)e)->bit4==1) func_0204F1A0(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f4); ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~1; ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~2; }

void func_021F4D74(u8 *p, u8 *e, int type, u16 id)
{
    ((struct Obj02168 *)e)->fC = func_021F4AA8(type);
    *(u8 * *)&((struct Obj02168 *)e)->f20 = func_021F4F54(*(u8 * *)&((struct Obj10298 *)p)->fC,type);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~8;
    func_0204F604(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f8,&id);
    if (((Bits_021F4D74 *)e)->bit4 == 1) func_0204F1A0(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f4);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~16;
    ((struct Obj02168 *)e)->f4 = id;
    ((struct Obj02168 *)e)->f0 = (((struct Obj02168 *)e)->f0 & ~1) | 1;
    ((struct Obj02168 *)e)->f0 |= 2;
}

/*
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void func_0204F32C(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
void func_021F4DE0(char *p, char *e, void *a2)
{
    u32 first, second;
    if (!((Bits_021F4DE0 *)e)->bit3) {
        func_0204F2CC((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&first));
        func_0204F32C((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&second));
        sub_02061CA4((void *)1,first,(u32)(p+18),((second & 0xffff0000) >> 16) * 8);
        *(u16 *)e |= 8;
    }
}

/*
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
void func_021F4E2C(void *unused, u8 *s, u8 *d)
{
    ((struct Obj05312 *)d)->f10 = ((struct Obj05311 *)s)->f10 + 8192;
    ((struct Obj05312 *)d)->f14 = ((struct Obj05311 *)s)->f14 + 8192;
    ((struct Obj05312 *)d)->f18 = ((struct Obj05311 *)s)->f18 - 2048;
    ((struct Obj05312 *)d)->f1C = ((struct Obj05311 *)s)->f1C;
    ((struct Obj05312 *)d)->f1E = ((struct Obj05311 *)s)->f1E;
    ((struct Obj05312 *)d)->f2 = ((struct Obj05311 *)s)->f2;
    ((Flags_021F4E2C *)d)->flag = ((Flags_021F4E2C *)s)->flag;
}

void func_021F4E6C(u8 *p,u8 *e,u32 value) { func_0204F720(((struct Obj22523 *)p)->f4,((struct Obj13827 *)e)->f8,&value); ((struct Obj13827 *)e)->f0 |=2; }

void func_021F4E8C(u32 unused,Entry_021F4E8C *p,const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }

void func_021F4EA4(u32 unused,u32 p,u32 q) { ((struct Obj10300 *)q)->f0=((struct Obj01396 *)p)->f10; ((struct Obj10300 *)q)->f4=((struct Obj01396 *)p)->f14; ((struct Obj10300 *)q)->f8=((struct Obj01396 *)p)->f18; }

void func_021F4EB4(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b) { u16 flags; ((struct Obj01396 *)p)->f1C=a; flags=((struct Obj01396 *)p)->f0; ((struct Obj01396 *)p)->f1E=b; ((struct Obj01396 *)p)->f0=flags|2; }

void func_021F4EC4(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b) { *a=((struct Obj01396 *)p)->f1C; *b=((struct Obj01396 *)p)->f1E; }

void func_021F4ED4(u32 unused,u32 p,u16 v) { ((struct Obj01396 *)p)->f2=v; ((struct Obj01396 *)p)->f0 |=2; }

/*
 * extent: six-byte body, two zero alignment bytes before separately filed 021F4EE8.
 */
void func_021F4EE0(int unused, u16 *p, u16 *out)
{
    *out = p[1];
}

/*
 * lever: wide int argument into u16 bitfield preserves the redundant
 * halfword narrowing pair; a u16 argument produced 16 bytes, DIFF10.
 * leaf: sole overlay blocker of handed ov133 021B8140; explicit unused r0
 * retained from the caller. Twenty-byte body; following getter omitted.
 */
void func_021F4EE8(int unused,Flags_021F4EE8 *s,int flag)
{
    s->flag=flag;
}

int func_021F4EFC(int unused, Flags_021F4EFC *p)
{
    return p->flag;
}

void func_021F4F04(u8 *p, Offset *out)
{
    func_021F4F60(*(u8 * *)&((struct Obj01396 *)p)->f20, out);
}


u32 func_021F4F10(u8 *p) { return ((struct Obj22528 *)p)->fC; }

u32 *func_021F4F14(int heap)
{
    u32 *p = func_02030734(heap, 8, 0, d_021F83B4, 0x47);
    int r = func_0204A1BC(45, 0x65, 0, heap);
    p[0] = r;
    p[1] = r;
    return p;
}

void func_021F4F40(void **p) { func_020307B0(*p); func_020307B0(p); }


u8 *func_021F4F54(u8 *p, int i) { return *(u8 * *)&((struct Obj22530 *)p)->f4 + i * 0xc; }

void func_021F4F60(u8 *p, Offset *out)
{
    out->x = ((struct Obj13828 *)p)->f4;
    out->y = ((struct Obj13828 *)p)->f5;
}

/*
 * follower: func_021F4F74 filed separately.
 */
int func_021F4F70(int *p) { return *p; }

int func_021F4F74(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 4) return 1; break;
    case 4: if (p[3] & 8) return 1; break;
    case 5: if (p[3] & 16) return 1; break;
    case 6: if (p[3] & 32) return 1; break;
    case 7: case 8: if (p[3] & 64) return 1; break;
    case 9: return 0;
    }
    return 0;
}

int func_021F4FF4(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 12) return 1; break;
    case 4: if (p[3] & 16) return 1; break;
    case 5: if (p[3] & 32) return 1; break;
    case 6: case 7: if (p[3] & 64) return 1; break;
    case 8: return 0;
    }
    return 0;
}

int func_021F5064(u8 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[8] == 0) return 1; break;
    case 2: if (p[8] == 1) return 1; break;
    case 3: if ((u8)(p[8] + 254) <= 1) return 1; break;
    case 4: if (p[8] == 4) return 1; break;
    case 5: if (p[8] == 5) return 1; break;
    case 6: case 7: if (p[8] == 6) return 1; break;
    case 8: return 0;
    }
    return 0;
}


int func_021F50D0(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22532 *)p)->f6 & 0x80)
        return 1;
    return 0;
}


int func_021F50E0(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22533 *)p)->f6 & 0x200)
        return 1;
    return 0;
}

/*
 * leaf: Sole unresolved ov112 mapper for concrete-correct ov133 func_021B8444; root reserved ownership.
 */
int func_021F50F4(unsigned index)
{
    switch (index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 9;
    }
}


unsigned char func_021F5140(void *p, int i)
{
    return *(unsigned char *)(func_021F4F54(p, i) + 9);
}


unsigned char func_021F514C(void *p, int i)
{
    return *(unsigned char *)(func_021F4F54(p, i) + 10);
}
