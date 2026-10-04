/*
 * function: func_02206728
 * address:  0x02206728
 * packet:   pkt_ov094_02206728
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_021F88F4  0x021F88F4  thumb  ov094
 */
#include "../include/Obj05249.h"
#include "../include/Obj21799.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F88F4(void);
typedef signed short   s16;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201DE00(u8 *a, u8 *b, u8 *c);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02204C98(int a, int b, int *outn, int *outq);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201ED04(struct WordSet *p);

void func_02206728(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (func_021F88F4() == 0)
        return;
    h = (int)func_0201EC64(((struct Obj05249 *)s)->f240);
    v = func_020457B0(6, ((struct Obj05249 *)s)->f240);
    w = func_02045EC0(((struct Obj05249 *)s)->f5C, 8);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 2, 0);
    func_0201EFA4((struct WordSet *)h, 0, ((struct Obj21799 *)b)->fC4, 2, 0, 1);
    func_0201F250((struct WordSet *)h, v, w);
    func_02204C98((int)v, ((struct Obj05249 *)s)->f224, &v18, &v14);
    func_0201C7A4((void *)(((struct Obj05249 *)s)->f234), 12 - v18 / 2, 0, v, (void *)(((struct Obj05249 *)s)->f224));
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(w);
    func_02045808(v);
}
