/*
 * file:     zukan_info_p09.c
 * unit:     yes
 * function: func_021BBAB0, func_021BBBD8
 * address:  0x021BBAB0
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC0E4 0x021BC0E4 thumb ov206
 *   func_021BC0B0 0x021BC0B0 thumb ov206
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021BBC04 0x021BBC04 thumb ov206
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 */
struct Obj;
struct Actor;
struct Node;
typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};

typedef struct S_021BBAB0 {
    u16 id;
    char pad2[0x1a];
    int f1c;
    char pad20[4];
    u32 f24;
    char pad28[0x174 - 0x28];
    u32 a174[2];
    u32 f17c;
    u32 f180;
    u32 f184;
    u32 a188[2];
    char pad190[0x1b4 - 0x190];
    u32 f1b4;
    char pad1b8[0x1d8 - 0x1b8];
    u32 f1d8;
    u32 f1dc;
} S_021BBAB0;

typedef signed int     s32;

typedef struct S_021BBBD8 {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S_021BBBD8;

extern u32 func_021BC0E4(u32 a, u32 b);
extern int func_021BC0B0(int v);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pt, u16 f, u16 g);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021BBC04(S_021BBAB0 *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
void func_021BBAB0(S_021BBAB0 *p, u32 a, u32 b, u32 idx);
void func_021BBBD8(S_021BBBD8 *p, int i);

void func_021BBAB0(S_021BBAB0 *p, u32 a, u32 b, u32 idx)
{
    u32 flag;
    u32 w;
    u32 v;
    Bool flag2;
    struct Point pt;

    flag = 0;
    if (p->f1c != 0)
        flag = 1;
    flag2 = p->f1c == 0 ? B_FALSE : B_TRUE;
    v = func_021BC0E4(a, b);
    if (v == 0xFFFF) {
        w = p->f1d8;
        p->a174[idx] = func_0204A6C8((void *)w, func_021BC0B0(a), 1, flag, p->id);
    } else {
        p->a174[idx] = func_0204A6C8((void *)p->f1dc, v, 1, flag, p->id);
    }
    pt.x = 0x78;
    pt.y = p->f1b4 + 0x58;
    pt.f4 = 0;
    pt.f6 = 1;
    pt.f7 = 0;
    if (a <= 0x1ED && v != 0xFFFF)
        p->a188[idx] = (u32)func_0204B294((void *)p->f24, p->a174[idx], p->f17c, p->f180, &pt, flag2, p->id);
    else
        p->a188[idx] = (u32)func_0204B294((void *)p->f24, p->a174[idx], p->f17c, p->f184, &pt, flag2, p->id);
    func_0204B800((void *)p->a188[idx], 1);
    func_0204B688((void *)p->a188[idx], 1);
    func_021BBC04(p);
}

void func_021BBBD8(S_021BBBD8 *p, int i)
{
    if (p->b[i] != 0) {
        func_0204B3B4(p->b[i]);
        func_0204A8D4((u32)p->a[i]);
        p->b[i] = 0;
    }
}
