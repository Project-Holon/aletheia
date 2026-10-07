/*
 * file:     unit_021BD8D8_p06.c
 * unit:     yes
 * function: func_021BE53C, func_021BE5B4, func_021BE5B8, func_021BE600, func_021BE6B0, func_021BE6E4, func_021BE6F0, func_021BE788
 * address:  0x021BE53C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_021BE2DC  0x021BE2DC  thumb  ov099
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   func_02156D84 0x02156D84 thumb ov009
 *   func_021563D0 0x021563D0 thumb ov009
 *   func_021BEEBC 0x021BEEBC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02005C4C 0x02005C4C thumb
 *   func_02005D90 0x02005D90 thumb
 *   sub_0204047C  0x0204047C  arm
 *   func_0215683C  0x0215683C  thumb  ov009
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021C1908 0x021C1908 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C2050 0x021C2050 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 */
#include "../../matched/include/Obj03733.h"
#include "../../matched/include/Obj22044.h"
#include "../../matched/include/Obj22045.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj01051.h"
#include "../../matched/include/Obj22046.h"
#include "../../matched/include/Obj22047.h"
#include "../../matched/include/Obj22048.h"

struct Bank;
struct Cfg;
struct Obj;
struct Sub020097BCObj;
struct Entry;
struct Link;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32_021BE53C;

typedef unsigned short u16;

typedef unsigned int u32_021BE5B8;

typedef unsigned long u32_021BE600;

typedef unsigned long u32_021BE6B0;

typedef struct {
    char pad[0x1CC];
    u32_021BE6B0 f1CC;
} S;

typedef unsigned long  u32_021BE6E4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BE6F0;

typedef struct {
    u32_021BE6F0 f0, f4;
    u8 pad8[12];
    u8 f14, f15, f16, f17, f18, f19, f1a;
    u8 bits0:2;
    u8 bits2:2;
    u8 bits4:4;
} State;

extern void func_020434DC(u32_021BE53C mask, u32_021BE53C enable);
extern void func_02043598(u32_021BE53C mask, u32_021BE53C enable);
extern void func_021BE2DC(char *p, int a, int b);
extern void func_02049B40(u32_021BE53C a, u32_021BE53C b, u32_021BE53C c, u32_021BE53C d, u32_021BE53C e, u16 f);
extern void *func_0201F5DC(void *a0, u32_021BE53C a1, u32_021BE53C a2, u32_021BE53C a3);
extern void func_0204A48C(const struct Cfg *cfg, u32_021BE5B8 arg, u32_021BE5B8 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32_021BE5B8 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32_021BE5B8 a1, u32_021BE5B8 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_021C24D4(u8 *p, int v);
extern int func_02156A3C(void);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int func_02156D84(void);
extern void func_021563D0(void);
extern void func_021BEEBC(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u32_021BE600 func_02005C4C(void);
extern void func_02005D90(int, int);
extern void sub_0204047C(int idx, unsigned short val);
extern int func_0215683C(char *a, int b);
extern u8 *func_02012944(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32_021BE6F0 func_02008530(const struct Sub0200852CObj *obj);
extern u32_021BE6F0 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_021C1908(char *, int, int);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern unsigned char func_021C23C0(void *a);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(int unused, void *s);
extern u8 func_021C2050(char *p, int i);
extern void func_021C203C(char *p, int i);
void func_021BE53C(char *p, int v);
void func_021BE5B4(void *a0);
void func_021BE5B8(char *p, void *a1);
int func_021BE600(char *p, int ret);
int func_021BE6B0(S *s, int b);
void func_021BE6E4(char *s);
void func_021BE6F0(char *p, int a, int b);
int func_021BE788(char *p);
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];


void func_021BE53C(char *p, int v)
{
    u32_021BE53C k = 0xF;
    func_020434DC(0xF, 1);
    func_02043598(0xD, 1);
    func_021BE2DC(p + 0x898, v, 0x21);
    func_02049B40(0x17, 5, 0, k << 5, 0x20, 0x21);
    *(void **)(p + 0x1330) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1334) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1338) = func_0201F5DC((void *)1, 0xE, 0, 0x21);
}

/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021BE5B4(void *a0)
{
}


/*
 * note: 2026-10-05 (wD6 lane13): EXACT. func_0204B258 takes two arguments (bank, p); the second is the
 * value stored at p + 0x114. The 0x110/0x114 offsets are plain literals: mwcc derives them from the 0x64
 * count constant by itself.
 */
void func_021BE5B8(char *p, void *a1)
{
    func_0204A48C((const struct Cfg *)d_021C3740, (u32_021BE5B8)d_021C3AA0, 0x21);
    *(void **)(p + 0x110) = func_0204B100(0x64, 0, 0x21);
    *(void **)(p + 0x114) = func_0204B034(d_021C375C, 2, 0x21);
    func_0204B258(*(void **)(p + 0x110), *(void **)(p + 0x114));
}

int func_021BE600(char *p, int ret)
{
    if (((struct Obj22044 *)(*(char * *)&((struct Obj03733 *)p)->f248))->fC) {
        func_021C24D4((u8 *)p, 4);
        func_02009B80(((struct Obj03733 *)p)->f4, func_02156A3C());
        if ((unsigned)(((struct Obj03733 *)p)->f135C - 3) <= 1 && !func_02156D84()) {
            func_021563D0();
            func_021BEEBC(p);
            ((struct Obj03733 *)p)->f242 = ((struct Obj22045 *)(*(char * *)&((struct Obj03733 *)p)->f248))->f47;
            func_021C18C8(p, 4, 3);
            func_02039C68((struct Link *)func_020399A8(), 0x18, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0xac;
        } else {
            func_02039C68((struct Link *)func_020399A8(), 0x12, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0x93;
        }
    } else {
        ((struct Obj03733 *)p)->f1CC = 9;
        func_021C24D4((u8 *)p, 1);
    }
    if (func_02005C4C() != 0x424) func_02005D90(0x424, 0xffff);
    return ret;
}


int func_021BE6B0(S *s, int b)
{
    sub_0204047C(0, 3);
    sub_0204047C(1, 1);
    sub_0204047C(3, 1);
    sub_0204047C(2, 0);
    s->f1CC = 6;

    return b;
}


/*
 * Hands the pointer at +0x08 to the ov009 routine with selector 0x20.
 */
void func_021BE6E4(char *s)
{
    func_0215683C(((struct Obj00008 *)s)->f8, 0x20);
}

/*
 * extent: two zero padding bytes at 0x021BE786.
 * lever: a named u8 local narrows the accessor result before bitfield masking.
 */
void func_021BE6F0(char *p, int a, int b)
{
    void *q;
    u8 t;
    q = func_02012944(((struct Obj01051 *)p)->fC4);
    (*(State * *)&((struct Obj01051 *)p)->f8)->f15 = 0x15;
    (*(State * *)&((struct Obj01051 *)p)->f8)->f16 = 2;
    t = (int)func_02008550(q);
    (*(State * *)&((struct Obj01051 *)p)->f8)->bits2 = t;
    (*(State * *)&((struct Obj01051 *)p)->f8)->f14 = func_02008554(q);
    func_021C1908(p, a, b);
    (*(State * *)&((struct Obj01051 *)p)->f8)->f19 = func_0200856C(q);
    (*(State * *)&((struct Obj01051 *)p)->f8)->f1a = func_02008570(q);
    func_021C27E8(((struct Obj01051 *)p)->f8, ((struct Obj22046 *)(*(char * *)&((struct Obj01051 *)p)->f248))->f46);
    func_021C2864(((struct Obj01051 *)p)->f8, ((struct Obj22047 *)(*(char * *)&((struct Obj01051 *)p)->f248))->f46);
    (*(State * *)&((struct Obj01051 *)p)->f8)->f4 = func_02008530(q);
    (*(State * *)&((struct Obj01051 *)p)->f8)->f0 = func_0200853C(q);
    func_021BE6E4(p);
}

int func_021BE788(char *p)
{
    int count = 0;
    int i;
    unsigned value;
    for (i = 0; i < 32; i++) {
        *(u8 *)(p + i + 0x10) = 0;
        if (((struct Obj22048 *)p)->f132A > i && func_021C23C0((void *)i)) {
            value = func_021BDD48((int)p, (void *)func_021C23B8(i));
            if (value != 0 && value < 6) {
                *(u8 *)(p + count + 0x10) = i + 1;
                count++;
            } else if (func_021C2050(p, i + 1)) {
                func_021C203C(p, i + 1);
            }
        }
    }
    return count;
}
