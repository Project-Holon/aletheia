/*
 * file:     btlv_effvm_p103.c
 * unit:     yes
 * function: func_022064CC, func_02206578
 * address:  0x022064CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_0220663C  0x0220663C  thumb  ov094
 *   func_02206710  0x02206710  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data   ov094
 */
#include "../../matched/include/Obj00823.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef short s16;

typedef struct Point { s16 x, y; } Point;

typedef struct { void *h; int x; } Slot;

typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W;

typedef unsigned short u16;

typedef struct {
    unsigned int lo : 31;
    unsigned int top : 1;
} Top;

typedef struct {
    char *s;
    int f4;
    int f8;
    int fc;
} Ctx;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned int func_0203630C(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_0220684C(char *p, int a, int b);
extern void func_0220663C(void);
extern void func_02206710(void *h);
void func_022064CC(W *p, u8 (* __restrict tab)[4], s8 (*rows)[12]);
int func_02206578(char *s, int a, int b);
extern char d_0220AEB0[];


/*
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 */
void func_022064CC(W *p, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    Point pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            func_0204B3DC(p->slots[i].h, *p->f274);
            func_0204B404(p->slots[i].h, (const struct Vec2 *)(&pos), 1);
        } else {
            func_0204B3DC(p->slots[i].h, 0);
        }
    }
}


int func_02206578(char *s, int a, int b)
{
    Ctx *c;
    int flag;

    if (b < 0)
        return a;
    if ((func_0203630C() & 0x200) && a < 4 && (((struct Obj00823 *)s)->f58 == 2 || ((struct Obj00823 *)s)->f58 == 5))
        ((struct Obj00823 *)s)->f70 = a | 0x8000;
    else
        ((struct Obj00823 *)s)->f70 = a;
    c = func_02030734((u16)((((struct Obj00823 *)s)->f240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & b) == 0)
        flag = 1;
    ((Top *)(s + 0x68))->top = flag;
    c->s = s;
    c->f4 = 0;
    c->f8 = (u16)b;
    if (((struct Obj00823 *)s)->f220 == 1 && c->f8 == 0)
        c->fc = 1;
    else
        c->fc = 0;
    func_0220684C(s, (int)func_02030DA8(((struct Obj00823 *)s)->f0, (void *)func_0220663C, c, 0), (int)((void *)func_02206710));
    return -1;
}
