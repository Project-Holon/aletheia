/*
 * file:     btlv_effvm_p89.c
 * unit:     yes
 * function: func_0220266C, func_022026FC
 * address:  0x0220266C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

typedef signed int     s32;

struct W { unsigned char pad[0x68]; unsigned int pad15 : 15; unsigned int f : 2; };

extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_02202248(char *p);
extern void *func_02030DA8(void *, void (*)(void *, Obj **), void *, u32);
extern void func_0220684C(char *p, int a, int b);
extern void func_02204A3C(void *a, char **s);
extern void func_02204A70(void *);
void func_0220266C(Obj *p);
int func_022026FC(struct W *p);
extern const char d_0220AEB0[];


/*
 * note: the two zero arguments of func_0204E720 sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 */
void func_0220266C(Obj *p)
{
    Obj **q;
    q = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (func_0207D55C((volatile u16 *)0x0400106c) <= 0)
        func_0204E720(2, 0x10, 0, 0);
    else
        func_0204E720(8, 0x10, 0, 0);
    func_02202248((char *)p);
    p->f68.mode = 2;
    *q = p;
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, (void (*)(void *, Obj **))func_02204A3C, q, 0), (int)func_02204A70);
}


/*
 * notes:    tests a 2-bit field at bits 15..16 of the word at +0x68, returns 1 if nonzero. Witness for calls in ov098 func_021B6578 (2026-10-05, lane W-B).
 */
int func_022026FC(struct W *p)
{
    if (p->f) return 1;
    return 0;
}
