/*
 * function: func_021B9E14
 * address:  0x021B9E14
 * packet:   pkt_ov070_021B9E14
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9DE8  0x021B9DE8  thumb  ov070
 *   func_020490F4  0x020490F4  arm
 *   func_02020E60  0x02020E60  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj01041.h"

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect;

typedef unsigned short u16;

extern void func_021B9DE8(char *);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_02020E60(unsigned short, int);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021B9E14(char *p, int id)
{
    void *bg;
    Rect r;
    if (*(int *)&((struct Obj01041 *)p)->f6A0 != 0) {
        func_021B9DE8(p);
    }
    bg = func_020490F4(0x19, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f548 = func_0204AC18(bg, func_02020E60(id, 2), 1, 0, 0, 1, ((struct Obj01041 *)p)->f544);
    ((struct Obj01041 *)p)->f54C = func_0204A6C8(bg, func_02020E60(id, 1), 0, 1, ((struct Obj01041 *)p)->f544);
    func_02049238(bg);
    r.a = 0x84;
    r.b = 0x50;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    *(int *)&((struct Obj01041 *)p)->f6A0 = (int)func_0204B294((void *)((struct Obj01041 *)p)->f69C, ((struct Obj01041 *)p)->f54C, ((struct Obj01041 *)p)->f548, ((struct Obj01041 *)p)->f550, &r, 1, ((struct Obj01041 *)p)->f544);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0, 1);
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj01041 *)p)->f6A0, 1);
}
