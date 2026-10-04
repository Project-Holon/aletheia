/*
 * function: func_021D9D44
 * address:  0x021D9D44
 * packet:   pkt_ov129_021D9D44
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s16 x;
    s16 y;
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} L;

struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);

void func_021D9D44(char *p)
{
    L s;
    int h = ((struct Obj00913 *)p)->f25C;
    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 10;
    s.e = 0;
    ((struct Obj00913 *)p)->f1E8 = (int)func_0204B294((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    ((struct Obj00913 *)p)->f204 = (int)func_0204B294((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    s.x = (((struct Obj00913 *)p)->f2F2 + ((struct Obj00913 *)p)->f2F3) / 2;
    s.y = (((struct Obj00913 *)p)->f2F0 + ((struct Obj00913 *)p)->f2F1) / 2;
    func_0204B404((struct Obj *)(((struct Obj00913 *)p)->f1E8), (const struct Vec2 *)(&s), 0);
    func_0204B878((struct Obj *)(((struct Obj00913 *)p)->f1E8), 0);
    s.x = (((struct Obj00913 *)p)->f2F6 + ((struct Obj00913 *)p)->f2F7) / 2;
    s.y = (((struct Obj00913 *)p)->f2F4 + ((struct Obj00913 *)p)->f2F5) / 2;
    func_0204B404((struct Obj *)(((struct Obj00913 *)p)->f204), (const struct Vec2 *)(&s), 0);
    func_0204B878((struct Obj *)(((struct Obj00913 *)p)->f204), 0);
}
