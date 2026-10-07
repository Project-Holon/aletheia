/*
 * file:     box2_main_p04.c
 * unit:     yes
 * function: func_021DD8D0, func_021DD8F8, func_021DD908, func_021DD930, func_021DDAE8, func_021DDC00
 * address:  0x021DD8D0
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
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_020092AC 0x020092AC thumb
 *   func_021EC7B8 0x021EC7B8 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EF4A4 0x021EF4A4 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021DD684 0x021DD684 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_021DD694 0x021DD694 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 */
#include "../../matched/include/Obj10646.h"
#include "../../matched/include/Obj23832.h"
#include "../../matched/include/Obj23834.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj18452.h"
#include "../../matched/include/Obj06551.h"
#include "../../matched/include/Obj23835.h"
#include "../../matched/include/Obj23836.h"
#include "../../matched/include/Obj23837.h"
#include "../../matched/include/Obj23838.h"
#include "../../matched/include/Obj23839.h"

#define SYS(p) (*(unsigned **)(p))
#define RESULT(p) (*(unsigned char *)(*(char **)((p) + 0x2C) + 0xA173))
struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Node;
struct Blk37;
struct WinMgr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short f4;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

typedef struct {
    Entry e[7];
    int count;
} Move;

extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void *func_0200CA1C(void *);
extern u32 func_0200CA38(struct Blk37 *);
extern u32 func_020307B0(void *p);
extern u32 func_021DD25C(void ***,u16,int,u32,u32);
extern u32 func_020092AC(const u8 *bits, int n);
extern void func_021EC7B8(char *p, int i, unsigned j, int flag);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern int func_021EF4A4(struct WinMgr *mgr);
extern void func_021EC000(char *p, int i, int v);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED75C(char **p, int i);
extern void func_021ED7C4(char *p, int i);
extern int func_021DD684(unsigned char *p, unsigned i);
extern int func_020078C4(void *save, u32 box);
extern int func_021DD694(void ***p, unsigned skip);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern unsigned func_0202136C(unsigned short v);
void func_021DD8D0(char *p);
void func_021DD8F8(char *p);
int func_021DD908(char *p, u32 a);
int func_021DD930(unsigned char *p);
int func_021DDAE8(unsigned char *p);
int func_021DDC00(unsigned char *p, unsigned a, unsigned b);

void func_021DD8D0(char *p) { *(u16 * *)&((struct Obj23832 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f180=func_0201AF80(76,0);((struct Obj23834 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f17C=func_0200CA38(func_0200CA1C(**(void ** *)&((struct Obj10646 *)p)->f0)); }


/*
 * Tail call func_020307B0 with the word at +0x2c/+0x180.
 */
void func_021DD8F8(char *p)
{
    func_020307B0(((struct Obj18452 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f180);
}

int func_021DD908(char *p, u32 a) { u16 n;n=func_021DD25C((void ***)p,a,((struct Obj06551 *)p)->f14,5,0);return func_020092AC(*(u8 * *)&((struct Obj23835 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f20,n); }


int func_021DD930(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23836 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            func_021EC7B8(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, e->slot, 1);
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            if (e->slot < 0x1E) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
            } else if (e->slot < 0x24) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
                if (p[0x1A] == 2 && func_021EF4A4(*(struct WinMgr * *)&((struct Obj23837 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    func_021EC548(0x24, &t[1], &t[0], p[0x1A]);
                    if (p[0x1A] == 2 && func_021EF4A4(*(struct WinMgr * *)&((struct Obj23838 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                        t[0] += 0xC0;
                } else {
                    func_021EC548(e->id, &t[1], &t[0], p[0x1A]);
                }
                func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
            }
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
            if (e->used == 2)
                func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
        }
        func_021ED75C((char **)p, p[0x16]);
        func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, 0);
    }
    func_021ED75C((char **)p, p[0x16]);
    func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}


/*
 * Twin of src/matched/ov170_func_021DD930.c.
 */
int func_021DDAE8(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23839 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
            if (e->slot >= 0x1E)
                t[0] += 0x90;
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        }
        func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, 0);
        break;
    }
    func_021ED75C((char **)p, p[0x16]);
    func_021ED7C4(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}


int func_021DDC00(unsigned char *p, unsigned a, unsigned b)
{
    unsigned m;
    if (b >= 0x24) {
        int n = func_021DD684(p, b - 0x24);
        if (n == p[0x14] || func_020078C4((void *)SYS(p)[1], n) == 0x1E) {
            RESULT(p) = 1;
            return 0;
        }
        if (a >= 0x1E) {
            if (func_021DD694((void ***)p, a - 0x1E) == 0) {
                RESULT(p) = 3;
                return 0;
            }
            if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
                RESULT(p) = 2;
                return 0;
            }
        }
        m = 0;
    } else {
        m = func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0);
    }
    if (SYS(p)[9] == 4) {
        if (SYS(p)[5] == 1) {
            RESULT(p) = 5;
            return 0;
        }
        if (a < 0x1E && b >= 0x1E && b < 0x24 && func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
        if (a >= 0x1E && a < 0x24 && b < 0x1E && m != 0 && func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
    }
    if (a >= 0x1E) {
        if (func_021DD694((void ***)p, a - 0x1E) == 0) {
            if (m == 0) {
                if ((b < 0x1E || b >= 0x24) && SYS(p)[9] != 4) {
                    RESULT(p) = 3;
                    return 0;
                }
            } else if (func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0 && b < 0x1E && SYS(p)[9] != 4) {
                RESULT(p) = 3;
                return 0;
            }
        }
        if (b < 0x1E && func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
    } else if (b >= 0x1E && m != 0) {
        if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], b - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
        if (func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0 && func_021DD694((void ***)p, b - 0x1E) == 0 && SYS(p)[9] != 4) {
            RESULT(p) = 3;
            return 0;
        }
    }
    RESULT(p) = 0;
    return 1;
}
