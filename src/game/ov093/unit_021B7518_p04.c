/*
 * file:     unit_021B7518_p04.c
 * unit:     yes
 * function: func_021B835C, func_021B83F4, func_021B8434, func_021B84D8, func_021B8548, func_021B8564, func_021B8588, func_021B8590, func_021B85A0, func_021B85A8
 * address:  0x021B835C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4270  0x021D4270  thumb  ov093
 *   func_021B6818  0x021B6818  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021BAB40  0x021BAB40  thumb  ov093
 *   func_021BAB9C  0x021BAB9C  thumb  ov093
 *   func_021CD97C  0x021CD97C  thumb  ov093
 *   func_021CDD94  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
 *   func_021BABDC  0x021BABDC  thumb  ov093
 *   func_021CD914 0x021CD914 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_020083C8 0x020083C8 thumb
 */
#include "../../matched/include/Obj03685.h"
#include "../../matched/include/Obj13269.h"
#include "../../matched/include/Obj05185.h"
#include "../../matched/include/Obj20950.h"
#include "../../matched/include/Obj18120.h"
#include "../../matched/include/Obj18122.h"

struct QA;
struct Scene;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Flags { unsigned char low:2, bit:1, high:5; };

extern int func_021D4270(void);
extern unsigned int func_021B6818(unsigned int *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021BAB40(char *p);
extern int func_021BAB9C(int a);
extern int func_021CD97C(int);
extern void func_021CDD94(char *p, int *o);
extern void func_021E908C(char *p);
extern void func_021BABDC(int, u8 *);
extern void func_021CD914(u8 *p);
extern void *func_021B86B8(void ***);
extern unsigned char func_021B86C0(unsigned char **);
extern unsigned int func_020083C8(void *);
int func_021B835C(u8 *p, int *q);
int func_021B83F4(int a);
int func_021B8434(u8 *p);
int func_021B84D8(u8 *p);
void func_021B8548(unsigned char *p);
int func_021B8564(unsigned char *p);
u32 func_021B8588(void **p);
unsigned int func_021B8590(unsigned char *p);
/* 021B85A0 ldr r0,[r0]; adds r0,#0x80; ldrb r0,[r0] */ u8 func_021B85A0(u8 **p);
int func_021B85A8(unsigned char *p);


int func_021B835C(u8 *p, int *q)
{
    int r, t;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (*q == 0) {
        r = func_021B6818((unsigned int *)(*(int * *)&((struct Obj03685 *)p)->f0));
        t = (int)func_021E8F20(p, (void *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (u32)(p + 0xc8), r, 0x13);
        ((struct Obj03685 *)p)->f4 = t;
        func_021CD95C((struct QA *)(*(int *)(p + p[0x46c] * 4 + 0x10)), t);
        if (p[0x46e]) {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B8434;
            func_021BAB40((char *)(((struct Obj03685 *)p)->f8));
        } else {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B84D8;
        }
        *q = *q + 1;
    } else {
        return 1;
    }
    return 0;
}


int func_021B83F4(int a)
{
    int i, found = 0;
    char *p = (char *)a;
    func_021BAB9C(((struct Obj13269 *)p)->f8);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            func_021CD97C(*(int *)(p + i * 4 + 0x10)) != 0) {
            func_021CDD94((char *)(*(int *)(p + i * 4 + 0x10)), (int *)((int)(p + 0x448)));
            found = 1;
        }
    }
    func_021E908C((char *)(((struct Obj13269 *)p)->f4));
    return found;
}


int func_021B8434(u8 *p)
{
    int r, i;
    if (((B *)p)->a == 0) {
        if (func_021D4270()) {
            ((B *)p)->a = 1;
            func_021B8548(p);
        }
    } else if (((B *)p)->b != 0) {
        return 1;
    }
    r = func_021BAB9C(((struct Obj05185 *)p)->f8);
    if (r) {
        func_021BABDC(((struct Obj05185 *)p)->f8, p + 0x448);
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 && p[i + 0xc4] == 0) {
            p[i + 0xc4] = func_021CD97C(*(int *)(p + i * 4 + 0x10));
        }
    }
    if (func_021B8564(p)) {
        func_021CDD94((char *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (int *)(p + 0x448));
        r = 1;
    }
    func_021E908C((char *)(((struct Obj05185 *)p)->f4));
    return r;
}


int func_021B84D8(u8 *p)
{
    int r, i;
    if (((B *)p)->a == 0) {
        if (func_021D4270()) {
            ((B *)p)->a = 1;
            func_021B8548(p);
        }
    } else if (((B *)p)->b != 0) {
        return 1;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            func_021CD97C(*(int *)(p + i * 4 + 0x10)) != 0) {
            func_021CDD94((char *)(*(int *)(p + i * 4 + 0x10)), (int *)(p + 0x448));
            r = 1;
        }
    }
    func_021E908C((char *)(((struct Obj20950 *)p)->f4));
    return r;
}

void func_021B8548(unsigned char *p) { unsigned int i; for(i=0;i<4;i++) { void *q; q=*(void **)(p+0x10+i*4); if (q) func_021CD914(q); } }

int func_021B8564(unsigned char *p) { unsigned int i; for (i=0;i<4;i++) { if (*(void **)(p+0x10+i*4) != 0 && p[0xc4+i] == 0) return 0; } return 1; }


/*
 * double deref: *(u32*)(*p + 0x4)
 */
u32 func_021B8588(void **p)
{
    return ((struct Obj18120 *)((u8 *)*p))->f4;
}

unsigned int func_021B8590(unsigned char *p) { return ((struct Flags *)(p+0x473))->bit; }


/* 021B85A0  ldr r0,[r0]; adds r0,#0x80; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x80; ldrb r0, [r0]; bx lr.
 */
u8 func_021B85A0(u8 **p) { return ((struct Obj18122 *)(*p))->f80; }

/*
 * note 2026-10-05: the arm9 witness src/matched/arm9/func_020083C8.c exists (EXACT); the only wildcard is that bl, so this lifts to EXACT after the integrator regenerates the manifest/labels.
 */
int func_021B85A8(unsigned char *p) { if (func_021B86B8((void ***)p)==(void *)1 && func_021B8588((void **)p)==0 && func_021B86C0((unsigned char **)p)==0 && func_020083C8(*(void **)(*(unsigned char **)p+0x5c))==0) return 1; return 0; }
