/*
 * file:     beacon_view_p06.c
 * unit:     yes
 * function: func_021F0EDC, func_021F0F30, func_021F0F44, func_021F0F74
 * address:  0x021F0EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0ED0  0x021F0ED0  thumb  ov032
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_0204581C  0x0204581C  arm
 *   func_02031194  0x02031194  arm
 *   func_02165CE8  0x02165CE8  thumb  ov010
 *   func_0204A9D0  0x0204A9D0  arm
 *   func_020215BC  0x020215BC  thumb
 *   d_021F3541     0x021F3541  data  ov032  a1
 */
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj00007.h"

struct CharBuf;
struct Obj;
struct TcblNode;
struct U16Vec;
struct PalAnmSlot;
struct S;
struct Sub0204A9D0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F0ED0(char *p, int a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020257D0(struct Obj *o);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02031194(struct TcblNode *n);
extern u8 func_02165CE8(struct S *p);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
void func_021F0EDC(char *p);
void func_021F0F30(char *p, int a, int b);
u8 *func_021F0F44(u8 *p, int a);
void func_021F0F74(char *p, u8 *q, void *r);
extern u8 d_021F3541[];


void func_021F0EDC(char *p)
{
    int z = 0;

    func_021F0EA4(p, 0);
    func_021F0ED0(p, 0);
    func_02043B5C((struct CharBuf *)(((struct Obj00225 *)p)->f1C), 0);
    func_020257D0((struct Obj *)(*(int *)&((struct Obj00225 *)p)->f18));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f24));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f20));
    ((struct Obj00225 *)p)->f1 = 0xff;
    ((struct Obj00225 *)p)->f2 = z;
    ((struct Obj00225 *)p)->f3 = z;
    if (((struct Obj00225 *)p)->f2C != 0) {
        func_02031194((struct TcblNode *)(((struct Obj00225 *)p)->f2C));
        ((struct Obj00225 *)p)->f2C = z;
    }
    if (*(int *)&((struct Obj00225 *)p)->f30 != 0) {
        func_02031194((struct TcblNode *)(*(int *)&((struct Obj00225 *)p)->f30));
        *(int *)&((struct Obj00225 *)p)->f30 = 0;
    }
}

void func_021F0F30(char *p, int a, int b) { func_021F0EDC(p); p[1]=a; p[2]=b; }

u8 *func_021F0F44(u8 *p, int a)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (a == p[i * 0x34 + 0x1b9])
            return p + 0x1b8 + i * 0x34;
    }
    return 0;
}


void func_021F0F74(char *p, u8 *q, void *r)
{
    int x;

    x = func_02165CE8((struct S *)r);
    func_0204A9D0(*(int *)(((struct Obj00007 *)p)->f158 + q[0] * 4), (struct Sub0204A9D0 *)(*(int *)(p + x * 8 + 0x338)));
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC),
                  (const void *)(*(int *)&((struct Obj00007 *)p)->f3BC + ((d_021F3541[x] & 0xf) << 5)), 3,
                  (u16)((q[0] + 9) << 4), 0x20);
}
