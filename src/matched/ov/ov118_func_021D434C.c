/*
 * function: func_021D434C
 * address:  0x021D434C
 * packet:   pkt_ov118_021D434C
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00001.h"
#include "../include/Obj22648.h"
#include "../include/Obj22649.h"
#include "../include/Obj22650.h"
#include "../include/Obj22651.h"

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

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void func_0204B9A0(struct Actor *a);

void func_021D434C(void *p)
{
    u32 v = ((struct Obj22648 *)((char *)((struct Obj00001 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22649 *)((char *)((struct Obj00001 *)p)->fC))->fB0 =
            (u32)func_0204B294((void *)*(u32 *)&((struct Obj00001 *)p)->f9C4,
                          ((struct Obj00001 *)p)->f8A8,
                          ((struct Obj00001 *)p)->f88C,
                          ((struct Obj00001 *)p)->f8BC,
                          &s, 0, ((struct Obj00001 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22650 *)((char *)((struct Obj00001 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22651 *)((char *)((struct Obj00001 *)p)->fC))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}
