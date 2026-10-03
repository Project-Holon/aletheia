/*
 * function: func_0220266C
 * address:  0x0220266C
 * packet:   pkt_ov094_0220266C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * note: the two zero arguments of func_0204E720 sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 *
 * symbols:
 *   func_02202248  0x02202248  thumb  ov094
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_02204A3C  0x02204A3C  thumb  ov094
 *   func_02204A70  0x02204A70  thumb  ov094
 *   d_0220AEB0  0x0220AEB0  data  a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
typedef struct Obj {
    void *h0;
    char pad[0x68 - 4];
    Bits f68;
    char pad2[0x240 - 0x6c];
    u16 heap;
} Obj;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_0207D55C(u32);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_02202248(Obj *);
extern void *func_02030DA8(void *, void (*)(void *, Obj **), void *, u32);
extern void func_0220684C(Obj *, void *, void (*)(void *));
extern void func_02204A3C(void *, Obj **);
extern void func_02204A70(void *);
extern const char d_0220AEB0[];

void func_0220266C(Obj *p)
{
    Obj **q;
    q = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (func_0207D55C(0x0400106c) <= 0)
        func_0204E720(2, 0x10, 0, 0);
    else
        func_0204E720(8, 0x10, 0, 0);
    func_02202248(p);
    p->f68.mode = 2;
    *q = p;
    func_0220684C(p, func_02030DA8(p->h0, func_02204A3C, q, 0), func_02204A70);
}
