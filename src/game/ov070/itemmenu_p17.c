/*
 * file:     itemmenu_p17.c
 * unit:     yes
 * function: func_021BA6F4, func_021BA8C0, func_021BA96C
 * address:  0x021BA6F4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B811C  0x021B811C  thumb  ov070
 *   d_021BBAA8     0x021BBAA8  data  ov070  a1
 *   d_021BBA6C     0x021BBA6C  data  a1
 *   d_021BBA68     0x021BBA68  data  a1
 *   d_021BBA64     0x021BBA64  data  ov070  a1
 *   d_021BBA74     0x021BBA74  data  a1
 *   d_021BBBCC     0x021BBBCC  data  a2
 *   d_021BBA81     0x021BBA81  data  a1
 *   func_0204B878  0x0204B878  arm
 */
#include "../../matched/include/Obj01515.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021BA6F4;

typedef struct {
    u8 v[5];
} B5;

typedef struct {
    u8 v[2];
} B2;

typedef struct {
    short x, y;
    unsigned short z;
    unsigned char d, e;
} Rect_021BA8C0;

typedef struct {
    unsigned char pad0[0x544];
    unsigned short heap;
    unsigned char pad546[0x590 - 0x546];
    int res[3];
    unsigned char pad59C[0x69C - 0x59C];
    int owner;
    unsigned char pad6A0[0x6AC - 0x6A0];
    int obj[5];
} W;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *, unsigned int);
extern int func_021B811C(u8 *p);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BA6F4(char *p);
void func_021BA8C0(W *p);
void func_021BA96C(int p, unsigned sel);
extern const B5 d_021BBAA8;
extern const B5 d_021BBA6C;
extern const B2 d_021BBA68;
extern const B2 d_021BBA64;
extern unsigned char d_021BBA74[];
extern short d_021BBBCC[][2];
extern unsigned char d_021BBA81[];


void func_021BA6F4(char *p)
{
    Rect_021BA6F4 r;
    B5 t1;
    B5 t2;
    B2 t3;
    B2 t4;
    u8 i;

    r.d = 0xa;
    r.e = 1;
    t1 = d_021BBAA8;
    t2 = d_021BBA6C;
    for (i = 0; i < 5; i++) {
        r.a = t2.v[i];
        r.b = 0xa8;
        r.c = t1.v[i];
        if (i == 2) {
            r.b += 4;
        }
        *(int *)(p + i * 4 + 0x710) = (int)func_0204B294((void *)((struct Obj01515 *)p)->f69C, ((struct Obj01515 *)p)->f564, ((struct Obj01515 *)p)->f55C, ((struct Obj01515 *)p)->f570, &r, 0, ((struct Obj01515 *)p)->f544);
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x710), 1);
    }
    func_0204B92C((struct Obj *)((struct Obj01515 *)p)->f710, 1);
    func_0204B92C((struct Obj *)((struct Obj01515 *)p)->f714, 1);
    if (func_021B811C((u8 *)p) == 0) {
        func_0204B3DC((struct Obj *)((struct Obj01515 *)p)->f718, 0);
    }
    if (((struct Obj01515 *)p)->f10 == 2) {
        func_0204B3DC((struct Obj *)((struct Obj01515 *)p)->f71C, 0);
    }
    t3 = d_021BBA68;
    t4 = d_021BBA64;
    for (i = 0; i < 2; i++) {
        r.a = 0xe8;
        r.b = t4.v[i];
        r.c = t3.v[i];
        r.e = 0;
        *(int *)(p + (u8)(i + 5) * 4 + 0x710) = (int)func_0204B294((void *)((struct Obj01515 *)p)->f69C, ((struct Obj01515 *)p)->f564, ((struct Obj01515 *)p)->f55C, ((struct Obj01515 *)p)->f570, &r, 0, ((struct Obj01515 *)p)->f544);
        func_0204B92C((struct Obj *)*(int *)(p + (u8)(i + 5) * 4 + 0x710), 1);
        func_0204B3DC((struct Obj *)*(int *)(p + (u8)(i + 5) * 4 + 0x710), 0);
    }
}


/*
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 */
void func_021BA8C0(W *p)
{
    unsigned i;
    Rect_021BA8C0 r;
    for (i = 0; i < 5; i++) {
        r.d = d_021BBA74[i];
        r.e = 1;
        r.x = d_021BBBCC[i][0] - 0x10;
        r.y = d_021BBBCC[i][1];
        r.z = d_021BBA81[i * 2 + 1];
        p->obj[i] = (int)func_0204B294((void *)p->owner, p->res[1], p->res[0], p->res[2], &r, 0, p->heap);
        func_0204B92C((struct Obj *)p->obj[i], 1);
    }
}


void func_021BA96C(int p, unsigned sel)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == sel) {
            func_0204B878((struct Obj *)(*(unsigned *)(p + i * 4 + 0x6AC)), d_021BBA81[i * 2]);
        } else {
            func_0204B878((struct Obj *)(*(unsigned *)(p + i * 4 + 0x6AC)), d_021BBA81[i * 2 + 1]);
        }
    }
}
