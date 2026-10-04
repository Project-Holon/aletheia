/*
 * function: func_021D434C
 * address:  0x021D434C
 * packet:   pkt_ov117_021D434C
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03253.h"
#include "../include/Obj22635.h"
#include "../include/Obj22636.h"
#include "../include/Obj22637.h"
#include "../include/Obj22638.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void func_0204B9A0(struct Actor *a);

void func_021D434C(void *p)
{
    u32 v = ((struct Obj22635 *)((char *)((struct Obj03253 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22636 *)((char *)((struct Obj03253 *)p)->fC))->fB0 =
            (u32)func_0204B294((void *)((struct Obj03253 *)p)->f9C4,
                          ((struct Obj03253 *)p)->f8A8,
                          ((struct Obj03253 *)p)->f88C,
                          ((struct Obj03253 *)p)->f8BC,
                          &s, 0, ((struct Obj03253 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22637 *)((char *)((struct Obj03253 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22638 *)((char *)((struct Obj03253 *)p)->fC))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}
