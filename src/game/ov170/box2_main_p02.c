/*
 * file:     box2_main_p02.c
 * unit:     yes
 * function: func_021DD3DC, func_021DD414, func_021DD42C, func_021DD464, func_021DD4B8, func_021DD530
 * address:  0x021DD3DC
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
 *   func_021DD314  0x021DD314  thumb  ov170
 *   func_021EDAB0  0x021EDAB0  thumb  ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021DD684 0x021DD684 thumb ov170
 *   func_021EDB34 0x021EDB34 thumb ov170
 *   func_0200752C 0x0200752C thumb
 *   func_02007664 0x02007664 thumb
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017988 0x02017988 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02007610 0x02007610 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD330 0x021DD330 thumb
 *   func_021DD39C 0x021DD39C thumb
 *   func_021DD810 0x021DD810 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj09221.h"
#include "../../matched/include/Obj12149.h"
#include "../../matched/include/Obj18446.h"
#include "../../matched/include/Obj18447.h"
#include "../../matched/include/Obj23829.h"

struct Sub020075B0Entry;
struct Party;
struct Sub02007454Entry;
struct Blk37;
typedef unsigned int u32;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
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
    unsigned a;
    unsigned b;
} Move;

extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *p);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_021DD314(char **p, int a, unsigned b);
extern void func_021EDAB0(char *, int);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern unsigned int func_0201AA18(void *);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD684(unsigned char *,unsigned);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_02007664(void *,unsigned,unsigned);
extern void func_021EDB34(char *p, int a);
extern void func_021DD8A8(unsigned char *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern u32 func_02017988(void *p, u32 a);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_02007610(void *save, unsigned b1, unsigned a, unsigned b2, unsigned c);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD330(unsigned char *p, unsigned short *q, unsigned short *t);
extern void func_021DD39C(unsigned char *p, unsigned short *q);
extern void func_021DD810(unsigned char *p, unsigned b, unsigned a, unsigned box);
void func_021DD3DC(char *p, unsigned char *a);
void func_021DD414(char **p, char *q);
void func_021DD42C(int *p, unsigned char *a);
void func_021DD464(unsigned char *p,unsigned a,unsigned b,unsigned c);
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b);
void func_021DD530(unsigned char *p);

/*
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
void func_021DD3DC(char *p, unsigned char *a)
{
    int x = (int)func_020185F4(func_0201AB28(*(void **)(*(int *)&((struct Obj00000 *)p)->f0 + 8),
                                        ((struct Obj09221 *)a)->f4 - 0x1e));
    func_020075B0((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 4)), ((struct Obj00000 *)p)->f14,
                  ((struct Obj09221 *)a)->f2, (const struct Sub020075B0Entry *)x);
    func_021DD314((char **)p, ((struct Obj00000 *)p)->f14, ((struct Obj09221 *)a)->f4);
    func_021EDAB0(p, ((struct Obj00000 *)p)->f14);
}


/*
 * Forward two biased halfword coordinates.
 */
void func_021DD414(char **p, char *q)
{
    func_0201AB8C((struct Party *)(((struct Obj18446 *)(*p))->f8), ((struct Obj12149 *)q)->f4 - 0x1e,
                  ((struct Obj12149 *)q)->f2 - 0x1e, 0x4c);
}

/*
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
void func_021DD42C(int *p, unsigned char *a)
{
    unsigned i = ((struct Obj18447 *)a)->f4 - 0x1e;
    while (i < func_0201AA18(*(void **)(*p + 8)) - 1) {
        func_0201AB8C((struct Party *)(*(int *)(*p + 8)), i, i + 1, 0x4c);
        i++;
    }
}

void func_021DD464(unsigned char *p,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = (void *)func_021DD2D0((void ***)p,a,b);
    box = func_021DD684(p,c);
    func_0200752C((*(void ***)p)[1],box,m);
    func_02007664((*(void ***)p)[1],a,b);
    func_021EDAB0((char *)p,a);
    func_021EDB34((char *)p,a);
    func_021EDAB0((char *)p,box);
    func_021EDB34((char *)p,box);
}

/*
 * lever: declaring m before box selects r7 for m and r6 for box.
 */
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=func_021DD684(p,b);
    m=func_0201AB28((*(void ***)p)[2],a-30);
    if(func_02017E1C(m,5,0)==492){
        func_02017988(m,0);
        func_021DD8A8(p,a);
        func_0200CFA0(func_0200CA1C((*(void ***)p)[0]),m);
    }
    func_0200752C((*(void ***)p)[1],box,func_020185F4(m));
    func_021DD314((char **)p,p[0x14],a);
    func_021EDAB0((char *)p,box);
    func_021EDB34((char *)p,box);
}


void func_021DD530(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23829 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            func_021DD464(p, p[0x17], m->a, m->b - 0x24);
        else
            func_021DD4B8(p, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            func_02007610(((void **)((struct Obj00000 *)p)->f0)[1], p[0x17], m->a, p[0x14], m->b);
            func_021EDAB0((char *)p, p[0x14]);
            func_021EDB34((char *)p, p[0x14]);
            if (p[0x14] != p[0x17]) {
                func_021EDAB0((char *)p, p[0x17]);
                func_021EDB34((char *)p, p[0x17]);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            func_021DD330(p, (short unsigned int *)(&m->e[0]), (short unsigned int *)(&m->e[1]));
            func_021DD810(p, m->b, m->a, p[0x17]);
        } else {
            func_021DD39C(p, (short unsigned int *)(&m->e[0]));
            func_021DD810(p, m->b, m->a, p[0x17]);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (func_021DD25C((void ***)p, m->b, p[0x14], 0xA9, 0)) {
            func_021DD330(p, (short unsigned int *)(&m->e[1]), (short unsigned int *)(&m->e[0]));
            func_021DD810(p, m->b, m->a, p[0x14]);
        } else {
            func_021DD3DC((char *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
            func_021DD810(p, m->b, m->a, p[0x14]);
        }
        return;
    }
    if (m->b - 0x1E < n)
        func_021DD414((char **)p, (char *)m);
    else
        func_021DD42C((int *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
}
