/*
 * function: func_021F3EE8
 * address:  0x021F3EE8
 * packet:   pkt_ov048_021F3EE8
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `sz = 4; sz = 0x100;` is the original's str/adds #0xfc/str pair into one
 * spill slot (a dead store survives in a stack-homed local); f declared
 * before h1 puts its slot highest.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`sz = 4;` before `sz = 0x100;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_021F44D8  0x021F44D8  thumb  ov048
 *   func_0201EC74  0x0201EC74  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_021F4488  0x021F4488  thumb  ov048
 *   func_021F3D38  0x021F3D38  thumb  ov048
 *   d_021F5124     0x021F5124  data  a4
 *   d_021F50C0     0x021F50C0  data  a4
 */
#include "../include/Obj02413.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h[4];
    u8  b[4];
} Slots;

extern void func_021F44D8(int *p, Slots *q);
extern void *func_0201EC74(int a, int b, int heap);
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct U16Vec;
struct WordSet;
extern u32 func_02013E4C(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern int func_021F4488(unsigned char *p);
extern void func_021F3D38(int *p, int unused, int b, int *c);
extern u32 d_021F5124[];
extern u8 d_021F50C0[];

void func_021F3EE8(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } m;
    Slots s;
    int sz;
    int f;
    void *h1;
    u32 a;
    u32 b;
    int i;
    int c;
    u32 s1;
    u32 s2;
    void *h2;
    u32 s3;
    void *buf;

    func_021F44D8(p, &s);
    sz = 0x100;
    h1 = func_0201EC74(4, sz, ((struct Obj02413 *)p)->f0);
    a = (u32)func_02045B38(0, 2, 0x59, ((struct Obj02413 *)p)->f0);
    b = (u32)func_02045B38(0, 2, 0x26, ((struct Obj02413 *)p)->f0);
    for (i = 0; i < 4; i++) {
        if (s.h[i] == 0x1AB)
            continue;
        c = s.b[i];
        s1 = (u32)func_02045EC0((struct MsgBank *)a, func_02013E4C(s.h[i]));
        s2 = (u32)func_02045EC0((struct MsgBank *)b, d_021F5124[c]);
        h2 = func_0201EC74(2, sz, ((struct Obj02413 *)p)->f0);
        s3 = (u32)func_02045EC0((struct MsgBank *)b, 0xc0);
        buf = func_020457B0(0x40, ((struct Obj02413 *)p)->f0);
        func_0201EE0C(h2, 0, (const void *)s1, 0, 1, 0);
        func_0201EE0C(h2, 1, (const void *)s2, 0, 1, 0);
        func_0201F250(h2, buf, (void *)s3);
        func_02045808((struct U16Vec *)s3);
        func_0201ED04(h2);
        func_0201EE0C(h1, i, (const void *)buf, 0, 1, 0);
        func_02045808((struct U16Vec *)s1);
        func_02045808((struct U16Vec *)s2);
        func_02045808((struct U16Vec *)((u32)buf));
    }
    func_02045C04((struct Rec *)b);
    func_02045C04((struct Rec *)a);
    switch (func_021F4488((unsigned char *)(&s))) {
    case 0:
        break;
    case 1:
        f = 0xc1;
        break;
    case 2:
        f = 0xc2;
        break;
    case 3:
        f = 0xc3;
        break;
    case 4:
        f = 0xc4;
        break;
    }
    m.a = *(u16 *)(d_021F50C0 + 6);
    m.b = *(int *)(d_021F50C0 + 0x30);
    m.c = *(int *)(d_021F50C0 + 0x4c);
    m.d = 2;
    m.e = 0x26;
    m.f = f;
    m.g = (int)h1;
    func_021F3D38(p, (int)&m, 2, 0);
    func_0201ED04(h1);
}
