/*
 * function: func_021BA6F4
 * address:  0x021BA6F4
 * packet:   pkt_ov070_021BA6F4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */
#include "../include/Obj01515.h"

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect;

typedef struct {
    u8 v[5];
} B5;

typedef struct {
    u8 v[2];
} B2;

struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern int func_021B811C(char *);
extern const B5 d_021BBAA8;
extern const B5 d_021BBA6C;
extern const B2 d_021BBA68;
extern const B2 d_021BBA64;

void func_021BA6F4(char *p)
{
    Rect r;
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
    if (func_021B811C(p) == 0) {
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
