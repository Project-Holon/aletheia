/*
 * function: func_0220558C
 * address: 0x0220558C
 * packet: pkt_ov094_0220558C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int func_02021728(char *p, int i) { return *(int *)(p + i * 0x14); }
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02021728 0x02021728 thumb
 *   func_020215BC 0x020215BC thumb
 */
#include "../include/Obj02440.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
struct PalAnmSlot;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32, u32, u32);
extern void func_0201EFA4(u32, u32, u32, u32, u32, u32);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern int func_021F86E0(void);
extern int func_02021728(char *, int);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
void func_0220558C(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)func_0201EC64(((struct Obj02440 *)s)->f240);
    v = func_020457B0(8, ((struct Obj02440 *)s)->f240);
    w = func_02045EC0(((struct Obj02440 *)s)->f5C, 6);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(9, 10, 0);
    func_0201EFA4(h, 0, b[2], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x8c, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    if (b[0] != b[1])
        func_0201DD78(7, 8, 0);
    func_0201EFA4(h, 0, b[1], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x60, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    func_0201DD78(1, 2, 0);
    extra = func_02045EC0(((struct Obj02440 *)s)->f5C, 7);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x7c, 8, extra, (void *)(((struct Obj02440 *)s)->f224));
    func_02045808(extra);
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(w);
    func_02045808(v);
    func_020215BC((struct PalAnmSlot *)(((struct Obj02440 *)s)->f64), (u16 *)(func_02021728((char *)func_021F86E0(), 1) + 0x40), 1, 0x70, 0x20);
}
