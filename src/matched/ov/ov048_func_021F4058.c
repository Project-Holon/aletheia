/*
 * function: func_021F4058
 * address:  0x021F4058
 * packet:   pkt_ov048_021F4058
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A9810  0x021A9810  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021F3D38  0x021F3D38  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */
#include "../include/Obj00270.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct WordSet;
extern u16 func_021A9810(int a);
struct BigObj;
struct MsgBank;
struct Rec;
struct U16Vec;
extern u8 func_02012984(const struct BigObj *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02013E4C(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021F3D38(int *p, int unused, int b, int *c);
extern u8 d_021F50C0[];

void func_021F4058(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int k;
    void *h;
    u32 r7, r6;

    k = func_021A9810(p[2]);
    if (k == 0xFFFF)
        return;
    if (k == 0x159 && func_02012984((const struct BigObj *)p[2]) == 3)
        return;
    h = func_0201EC64(((struct Obj00270 *)p)->f0);
    r7 = (u32)func_02045B38(0, 2, 0x59, ((struct Obj00270 *)p)->f0);
    r6 = (u32)func_02045EC0((struct MsgBank *)r7, func_02013E4C(k));
    func_0201EE0C(h, 0, (const void *)r6, 0, 1, 0);
    func_02045808((struct U16Vec *)r6);
    func_02045C04((struct Rec *)r7);
    s.a = *(u16 *)(d_021F50C0 + 8);
    s.b = *(int *)(d_021F50C0 + 0x34);
    s.c = *(int *)(d_021F50C0 + 0x50);
    s.d = 2;
    s.e = 0x26;
    s.f = *(int *)(p[7] + 0x20);
    s.g = (int)h;
    func_021F3D38(p, (int)&s, 3, 0);
    func_0201ED04(h);
}
