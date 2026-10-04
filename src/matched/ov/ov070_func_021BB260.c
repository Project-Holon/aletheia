/*
 * function: func_021BB260
 * address:  0x021BB260
 * packet:   pkt_ov070_021BB260
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: each window address bound to its own pointer local (win before the
 * first statement, win2 at the top of the if block, before the
 * func_021B619C call). With the addresses spelled inline the compiler CSEs
 * the stack-argument zero into r7 and spills val; with the locals val keeps
 * r7 and every zero is rematerialised. The same lever closed
 * ov070_func_021BAB04 (MATCH, arm9 leaf blocker).
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_021BB724(u32 *);
extern int func_021B619C(int a, int b, unsigned int id);

void func_021BB260(u8 *p, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)(p + 0x754);

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win)), 5);
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, val, 3, 0, 1);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, win, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
    func_021BB724(win);
    if (((struct Obj00002 *)p)->f7EC == 2) {
        win2 = (u32 *)(p + 0x76C);
        v = func_021B619C(((struct Obj00002 *)p)->f84C, ((struct Obj00002 *)p)->f7F4, ((struct Obj00002 *)p)->f544);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win2)), 5);
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x54, (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), 0, v, 7, 0, 1);
        func_0201F250((struct WordSet *)(*(int *)&((struct Obj00002 *)p)->f520), (void *)(*(int *)&((struct Obj00002 *)p)->f528), (void *)(*(int *)&((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, win2, *(u32 *)&((struct Obj00002 *)p)->f528, 0, 0, 0x3DC5);
        func_021BB724(win2);
    }
}
