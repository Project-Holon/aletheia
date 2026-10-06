/*
 * function: func_021BB0F8
 * address:  0x021BB0F8
 * packet:   pkt_ov070_021BB0F8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BB580(char *p, int v);
extern void func_021BB3F4(int, int);

void func_021BB0F8(int p)
{
    Desc s;
    int h;
    int r;

    h = ((struct Obj00002 *)p)->f544;
    s.a = h;
    s.b = 2;
    s.c = p + 0x780;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = (int)func_020457B0(0x64, h);
    ((struct Obj00002 *)p)->f780 = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x84, (void *)r);
    ((struct Obj00002 *)p)->f784 = 0x39E0;
    ((struct Obj00002 *)p)->f788 = 0;
    r = (int)func_020457B0(0x64, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f78C = r;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x85, (void *)r);
    ((struct Obj00002 *)p)->f790 = 0x39E0;
    ((struct Obj00002 *)p)->f794 = 0;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f780));
    func_02045808((struct U16Vec *)(((struct Obj00002 *)p)->f78C));
    func_021BB580((char *)p, 0);
    func_021BB3F4(p, 0);
}
