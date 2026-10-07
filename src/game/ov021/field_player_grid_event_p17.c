/*
 * file:     field_player_grid_event_p17.c
 * unit:     yes
 * function: func_021C0988, func_021C09A8, func_021C09B0, func_021C0A10, func_021C0A48, func_021C0A70, func_021C0AA0
 * address:  0x021C0988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021DA098  0x021DA098  data  ov021  a4
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_021C0B3C  0x021C0B3C  thumb  ov021
 *   func_021C0AC0  0x021C0AC0  thumb  ov021
 */
#include "../../matched/include/Obj20159.h"
#include "../../matched/include/Obj00707.h"

struct Mtx33;
struct Blk;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0218C860(int);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_0207C9D0(u8 *dst, u8 *src, int *v);
extern u8 *func_0218C7F0(u8 *owner, u32 x, struct Blk *src);
extern void func_020061E4(u32 a);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern int func_0218C8FC(unsigned char *p, int i);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021C0AC0(u32 a, int *st, u8 *p);
void func_021C0B3C(u8 *p, u32 a);
void func_021C0988(u8 *p);
void func_021C09A8(u8 *p, int *st, int v);
void func_021C09B0(u8 *p);
void func_021C0A10(u8 *p);
void func_021C0A48(u8 *p);
int func_021C0A70(u8 *p);
void *func_021C0AA0(void *p, int a1);
extern u8 d_021DA098[];


/*
 * Releases each of the p[0x14] handles (EXACT*: unlabelled follower at 0x021C09A8).
 */
void func_021C0988(u8 *p)
{
    int i;

    for (i = 0; i < p[0x14]; i++)
        func_0218C860(((int *)(p + 0x1C))[i]);
}


/*
 * Unlabelled leaf: stores the next state and clears the halfword counter at +0x16.
 */
void func_021C09A8(u8 *p, int *st, int v)
{
    *st = v;
    ((struct Obj20159 *)p)->f16 = 0;
}


void func_021C09B0(u8 *p)
{
    struct { int out[3]; int scale[3]; int mat[9]; } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mat);
        func_0207C9D0(p + 8, d_021DA098 + i * 12, s.out);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(((struct Obj00707 *)p)->f18), 0x62, (struct Blk *)s.out);
        p[0x15] = p[0x15] + 1;
        func_020061E4(0x568);
    }
}


/*
 * Resets each of the p[0x15] handles, then the optional one at +0x34.
 */
void func_021C0A10(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 0);
    if (((struct Obj00707 *)p)->f34 != 0)
        func_0218C69C((unsigned char *)(*(int *)&((struct Obj00707 *)p)->f18), ((struct Obj00707 *)p)->f34, 0, 0);
}


/*
 * Sets mode 3 on each of the p[0x15] handles.
 */
void func_021C0A48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 3);
}


/*
 * Returns 1 when every one of the p[0x15] handles reports done.
 */
int func_021C0A70(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++) {
        if (func_0218C8FC((unsigned char *)(((int *)(p + 0x1C))[i]), 0) != 1)
            return 0;
    }
    return 1;
}


/*
 * Spawns a 0x3C-byte task (callback func_021C0AC0) and initialises it.
 */
void *func_021C0AA0(void *p, int a1)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0AC0, 0x3C);
    u8 *w = func_020124E8(t);

    func_021C0B3C(w, (u32)p);
    return t;
}
