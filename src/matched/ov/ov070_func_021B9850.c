/*
 * function: func_021B9850
 * address:  0x021B9850
 * packet:   pkt_ov070_021B9850
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Redraw the selected item's detail pane: hide the three detail icons and
 * the 17 list markers, then print the item's name, count or TM/HM number
 * into the three text windows at +0x73C/+0x744/+0x74C and draw its icon.
 * Twin of func_021BA218 (same record getters and window helpers).
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_021B97E8  0x021B97E8  thumb  ov070
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02021350  0x02021350  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_021BAB04  0x021BAB04  thumb  ov070
 *   func_02020FB4  0x02020FB4  thumb
 *   func_021BB724  0x021BB724  thumb  ov070
 *   func_021B9E14  0x021B9E14  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;

struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021B61B8(char *);
extern u16 *func_021B616C(char *o, int k);
extern void func_021B97E8(char *, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_020212B0(u16 id);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B61F4(void *o, int a, u32 b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_02045334(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02021350(u16 id);
extern u8 func_0202130C(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_021BAB04(char *p, int x);
extern void func_02020FB4(void *dst, u32 entry, u32 heap);
extern void func_021BB724(char *);
extern void func_021B9E14(char *p, int id);

void func_021B9850(char *p)
{
    u32 i;
    u32 j;
    u16 *e;
    u16 kind;
    u8 n;

    j = 0;
    for (i = 0; i < 3; i++)
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x6C0), 0);
    for (j = 0; j < 17; j++)
        func_0204B3DC((struct Obj *)*(int *)(p + j * 4 + 0x6CC), 0);
    e = func_021B616C(p, func_021B61B8(p));
    if (e == 0 || *e == 0) {
        func_021B97E8(p, 0);
        return;
    }
    func_021B97E8(p, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f73C)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00002 *)p)->f744)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f74C)), 0);
    kind = func_020212B0(*e);
    if (kind == 0) {
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x86, (void *)(((struct Obj00002 *)p)->f524));
        func_021B61F4(p, 0, *e);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        if (((struct Obj00002 *)p)->f80C != 4) {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, e[1], 3, 0, 1);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BB6E0((int)p, (u32 *)(p + 0x744), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        } else {
            func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f744);
        }
        func_020456F8((struct Descriptor *)(*(u32 *)&((struct Obj00002 *)p)->f734));
    } else {
        n = func_02021350(*e);
        if (n == 0xFF) {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x45, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, func_0202130C(*e) + 1, 2, 2, 1);
        } else {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x47, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, n + 1, 2, 2, 1);
        }
        func_0201EF34((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 1, kind);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021BB6E0((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        func_021BAB04(p, kind);
        func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f744);
    }
    func_02020FB4((void *)(((struct Obj00002 *)p)->f524), *e, ((struct Obj00002 *)p)->f544);
    func_021BB6E0((int)p, (u32 *)(p + 0x74C), ((struct Obj00002 *)p)->f524, 0, 4, 0x3DC0);
    func_021BB724(p + 0x73C);
    func_021BB724(p + 0x744);
    func_021BB724(p + 0x74C);
    func_021B9E14(p, *e);
}
