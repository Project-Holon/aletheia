/*
 * function: func_021865B4
 * address:  0x021865B4
 * packet:   pkt_ov023_021865B4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02027F60  0x02027F60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02027778  0x02027778  thumb
 *   d_02186ABC     0x02186ABC  data
 */
#include "../include/Obj02742.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u8  b;
    u32 c;
    u32 d;
    u8  e[4];
} Arg;

typedef struct {
    u32 a;
    u32 b;
} Ent;

extern Ent d_02186ABC[];
struct MsgBank;
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_02027778(Arg *, u32);

int func_021865B4(char *p)
{
    int i;
    int r;
    char *e;
    Ent *t;
    Arg s;

    ((struct Obj02742 *)p)->f174 = (u32)func_02027F60(0, 2, ((struct Obj02742 *)p)->fC, ((struct Obj02742 *)p)->f168, 0x28);
    for (i = 0; i < 2; i++) {
        t = &d_02186ABC[i];
        *(u32 *)(p + i * 12 + 0x17C) = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02742 *)p)->f14), d_02186ABC[i].a);
        *(u16 *)(p + i * 12 + 0x180) = 0x39E3;
        *(u32 *)(p + i * 12 + 0x184) = t->b;
    }
    s.a = 0x28;
    s.b = 2;
    s.c = (u32)(p + 0x17C);
    s.d = 0;
    s.e[0] = 0x15;
    s.e[1] = 7;
    s.e[2] = 10;
    s.e[3] = 3;
    r = func_02027778(&s, ((struct Obj02742 *)p)->f174);
    ((struct Obj02742 *)p)->f9E70 = 1;
    return r;
}
