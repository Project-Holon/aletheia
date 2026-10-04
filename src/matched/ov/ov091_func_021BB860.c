/*
 * function: func_021BB860
 * address:  0x021BB860
 * packet:   pkt_ov091_021BB860
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BBA28  0x021BBA28  thumb  ov091
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_021BB910  0x021BB910  thumb  ov091
 */
#include "../include/Obj06213.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef signed int     s32;
struct MsgBank;
struct Rec;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BBA28(int a, int b);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02028470(void *a, u32 b);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern int func_021BB910(int k);

void func_021BB860(u8 *a, u32 *s, u32 x, u32 y)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06213 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)func_020457B0(0x100, ((struct Obj06213 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        func_02045808((struct U16Vec *)t);
        t = n;
    }
    func_021BBA28((int)a, (int)s);
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    s[8] = y;
    s[4] = t;
    func_02028470(s + 6, 6);
    s[3] = (u32)func_0201CD10(s[1], 0, 0, s[4], ((struct Obj06213 *)a)->f138, func_02012FFC(), s[2], 0,
                         ((struct Obj06213 *)a)->f0, 0xf, (u32)func_021BB910);
}
