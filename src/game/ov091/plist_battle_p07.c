/*
 * file:     plist_battle_p07.c
 * unit:     yes
 * function: func_021BB1A0, func_021BB200, func_021BB2C0
 * address:  0x021BB1A0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02041300  0x02041300  arm
 *   d_021BEC74     0x021BEC74  data  ov091  a1
 *   d_021BEC75     0x021BEC75  data  ov091  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B09C  0x0204B09C  arm
 *   func_021BAA50  0x021BAA50  thumb  ov091
 *   func_021BAAE4  0x021BAAE4  thumb  ov091
 */
#include "../../matched/include/Obj20878.h"

struct CharBuf;
struct Descriptor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B09C(int a, int b, s16 *c);
extern void func_021BAA50(u8 *a, u8 *s);
extern void func_021BAAE4(u8 *a, u8 *s, int c);
void func_021BB1A0(int unused, u8 *s, int d);
void func_021BB200(u8 *a, u8 *s, int p, int q);
void func_021BB2C0(u8 *a,u8 *s);
extern u8 d_021BEC74[];
extern u8 d_021BEC75[];


void func_021BB1A0(int unused, u8 *s, int d)
{
    int i = s[4];
    int x = d_021BEC74[i * 2];
    u8 y = d_021BEC75[i * 2];
    int z;

    if (i % 2 == 0)
        d = -d;
    z = x + 0x10 + d;
    func_02041300(2, 0, z, y, 0x10, 6, 5);
    func_02041300(1, 0, z, y, 0x10, 6, 5);
}


void func_021BB200(u8 *a, u8 *s, int p, int q)
{
    s16 b[4];
    int i = s[4];
    int x = d_021BEC74[i * 2];
    int y = d_021BEC75[i * 2];

    if (i % 2 == 0)
        q = -q;
    *(int *)s = p;
    *(int *)(s + 0x18) = 0;
    *(int *)(s + 0xc) = func_02017E1C((void *)p, 0x4c, 0);
    *(u16 *)(s + 6) = func_02017E1C((void *)(*(int *)s), 0xa0, 0);
    *(u16 *)(s + 8) = *(u16 *)(s + 6);
    func_0204B3B4((struct Obj *)(*(int *)(s + 0x30)));
    func_0204A8D4(*(int *)(s + 0x2c));
    func_02043B5C(func_02045770((struct Descriptor *)(*(u32 *)(s + 0x20))), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x3c)), 0);
    func_0204B3DC((struct Obj *)(*(int *)(s + 0x40)), 0);
    b[2] = 0;
    b[3] = 0;
    func_0204B09C(*(int *)(s + 0x24), 0, &b[2]);
    func_021BAA50(a, s);
    b[0] = -(x + q) * 8;
    b[1] = -y * 8;
    func_0204B09C(*(int *)(s + 0x24), 0, b);
    func_021BAAE4(a, s, 0);
}

void func_021BB2C0(u8 *a,u8 *s) {func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj20878 *)s)->f20)),0);func_021BAAE4(a,s,0);}
