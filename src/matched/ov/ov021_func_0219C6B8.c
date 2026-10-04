/*
 * function: func_0219C6B8
 * address:  0x0219C6B8
 * packet:   pkt_ov021_0219C6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): func_0205082C (0x0205082C) and func_020507F0 (0x020507F0) are
 * unlabelled arm9 leaves (Ilias's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (func_020500A0 is the arm9 label at 0x020500A0):
 *     void func_020507F0(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void func_0205082C(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; func_020500A0(e); }
 * func_0219C9D0 (function pointer word) is filed as pkt_ov021_0219C9D0.
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_02050340  0x02050340  arm
 *   func_0219D3E4  0x0219D3E4  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0219C9D0  0x0219C9D0  thumb  ov021
 *   d_021D75D0     0x021D75D0  data  a4
 */
#include "../include/Obj07474.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

extern u16 d_021D75D0[][2];
extern u32 func_0216D520(void *p);
extern u32 func_02050340(u32, u32, Desc *, u32, u32);
extern u32 *func_0219D3E4(u32);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u16 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_0219C9D0(u32 a, u32 b, u8 *p);

u32 func_0219C6B8(u32 a, V3 *b, int c, u32 d, u16 e)
{
    u8 *m = (u8 *)func_0216D520((void *)a);
    Desc s;
    u32 r;
    u32 *q;
    u16 *t = d_021D75D0[c];
    u32 h;
    s.slot = e;
    s.v12 = d_021D75D0[c][0];
    s.v14 = t[1];
    s.pos = *b;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.f1c = (void (*)(void))func_0219C9D0;
    s.f20 = (u32)m;
    r = func_02050340(((struct Obj07474 *)m)->f4, ((struct Obj07474 *)m)->f8, &s, 1, 0);
    q = func_0219D3E4(d);
    if (q[0] != 0) {
        func_02050804((void *)(((struct Obj07474 *)m)->f4), r, q[0], (u16)q[1]);
        h = ((struct Obj07474 *)m)->f4;
        func_0205082C((void *)h, r, 0);
        func_020507F0((void *)h, r, 1);
    }
    return r;
}
