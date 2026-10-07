/*
 * file:     unit_021E0098.c
 * unit:     yes
 * function: func_021E0098, func_021E02F0, func_021E03F8
 * address:  0x021E0098
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E0090  0x021E0090  arm  ov175
 *   func_021E0504   0x021E0504  arm  ov175
 *   func_021E054C   0x021E054C  arm  ov175
 *   func_021E04FC  0x021E04FC  arm  ov175
 */
#define BS32(x) ((u32)((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                       (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000)))
#define BS16(x) ((u16)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Node {
    char _0[0x24];
    unsigned short h24;
    unsigned short h26;
    unsigned short h28;
    char _2a[0x38 - 0x2a];
    int w38;
    int w3c;
    int w40;
} Node;

typedef struct Obj {
    int f0;
    int f4;
    unsigned short h8;
    char _a[0x120 - 0xa];
    int f120;
    Node *f124;
} Obj;

typedef short s16;

extern int func_021E0090(void *a0);
extern u8 *func_021E0504(u8 *dst, unsigned int v);
extern u8 *func_021E054C(u8 *dst, u32 v);
extern char *func_021E04FC(char *dst, int value);
int func_021E0098(u8 *p, int f, u32 v);
int func_021E02F0(Obj *o, int a, int b);
int func_021E03F8(char *p, int a1, int a2);


int func_021E0098(u8 *p, int f, u32 v)
{
    u8 *q = *(u8 **)(p + 0x124);

    func_021E0090(p);
    if (f != 0)
        *(u32 *)(q + 0x1c) |= 1;
    *(u32 *)(q + 0x18) = BS32(v);
    *(u32 *)(q + 0x1c) = BS32(*(u32 *)(q + 0x1c));
    *(u16 *)(q + 0x20) = BS16(*(u16 *)(q + 0x20));
    *(u16 *)(q + 0x22) = BS16(*(u16 *)(q + 0x22));
    *(u16 *)(q + 0x2a) = 0;
    *(u16 *)(q + 0x24) = BS16(*(u16 *)(q + 0x24));
    *(u16 *)(q + 0x26) = BS16(*(u16 *)(q + 0x26));
    *(u16 *)(q + 0x28) = BS16(*(u16 *)(q + 0x28));
    *(u32 *)(q + 0x2c) = BS32(*(u32 *)(q + 0x2c));
    *(u32 *)(q + 0x30) = BS32(*(u32 *)(q + 0x30));
    *(u32 *)(q + 0x34) = BS32(*(u32 *)(q + 0x34));
    *(u32 *)(q + 0x38) = BS32(*(u32 *)(q + 0x38));
    *(u32 *)(q + 0x3c) = BS32(*(u32 *)(q + 0x3c));
    *(u32 *)(q + 0x40) = BS32(*(u32 *)(q + 0x40));
    return 0;
}


int func_021E02F0(Obj *o, int a, int b)
{
    int f0 = o->f0;
    Node *n = o->f124;

    if (f0 == 2) {
        n->h24++;
        n->w38 += 8;
    } else if (f0 == 3) {
        n->h26++;
        n->w3c += 8;
        o->h8++;
        func_021E0504((u8 *)((char *)o->f124 + o->f4), (short)o->h8);
    } else if (f0 == 4) {
        n->h28++;
        n->w40 += 8;
        o->h8++;
        func_021E0504((u8 *)((char *)o->f124 + o->f4), (short)o->h8);
    }
    func_021E0504((u8 *)((char *)o->f124 + o->f120), (short)a);
    o->f120 += 2;
    func_021E0504((u8 *)((char *)o->f124 + o->f120), (short)0);
    o->f120 += 2;
    func_021E054C((u8 *)((char *)o->f124 + o->f120), (int)b);
    o->f120 += 4;
    return 0;
}


int func_021E03F8(char *p, int a1, int a2)
{
    char *q = *(char **)(p + 0x124);
    int v = *(int *)p;

    if (v == 2) {
        *(u16 *)(q + 0x24) += 1;
        *(int *)(q + 0x38) += 5;
    } else if (v == 3) {
        *(u16 *)(q + 0x26) += 1;
        *(int *)(q + 0x3c) += 5;
        *(u16 *)(p + 8) += 1;
        func_021E0504((u8 *)(*(char **)(p + 0x124) + *(int *)(p + 4)), *(s16 *)(p + 8));
    } else if (v == 4) {
        *(u16 *)(q + 0x28) += 1;
        *(int *)(q + 0x40) += 5;
        *(u16 *)(p + 8) += 1;
        func_021E0504((u8 *)(*(char **)(p + 0x124) + *(int *)(p + 4)), *(s16 *)(p + 8));
    }
    func_021E0504((u8 *)(*(char **)(p + 0x124) + *(int *)(p + 0x120)), (s16)a1);
    *(int *)(p + 0x120) += 2;
    func_021E0504((u8 *)(*(char **)(p + 0x124) + *(int *)(p + 0x120)), 2);
    *(int *)(p + 0x120) += 2;
    func_021E04FC(*(char **)(p + 0x124) + *(int *)(p + 0x120), a2);
    *(int *)(p + 0x120) += 1;
    return 0;
}
