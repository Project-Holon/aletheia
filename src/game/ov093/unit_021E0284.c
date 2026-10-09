/*
 * file:     unit_021E0284.c
 * unit:     yes
 * function: func_021E0284, func_021E02C0, func_021E02DC, func_021E0354, func_021E0394, func_021E03D8, func_021E03E8, func_021E03F8, func_021E0434, func_021E045C, func_021E0468, func_021E050C
 * address:  0x021E0284
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   data_021F3030  0x021F3030  data
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F261C     0x021F261C  data   ov093  a4
 *   d_021F2414     0x021F2414  data   ov093  a4
 */
#include "../../matched/include/Obj13503.h"

struct Node;
struct QQ;
struct QG;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Handler { u16 key; int (*fn)(u32 *out); };

struct Node {
    struct Node *prev;
    struct Node *next;
    u32 f8;
    u32 fC;
    int id;
    u32 prio;
    u32 serial : 16;
    u32 f16 : 8;
    u32 b24 : 1;
    u32 mark : 1;
    u32 b26 : 1;
    u32 busy : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 b30 : 1;
    u32 b31 : 1;
    u8 f1C[0x1C];
    u16 key;
    u8 sub;
    u8 kind;
};

struct NodeList { u32 serial; struct Node *head; u32 used; struct Node *pool[0x84]; };

extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
extern u32 func_021C7EC4(u8 *p);
extern u8 func_021D5440(u8 *p);
extern struct Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern struct Node *func_021D732C(int id, int sub);
extern u16 func_021D70A8(struct QQ *p);
extern struct Node *func_021D7360(struct Node *n);
extern u32 func_021D70B4(u8 *p, int i);
extern void func_021D7040(struct Node *n);
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_0201C1C8(void *p);
extern int func_021D5814(void *q, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 func_021D78AC(u32 range);
extern int func_021E8CF0(int a);
extern void func_021C88C8(void *a, void *b);
void func_021E0284(int a, void *b, int c, int *d, u8 e);
void func_021E02C0(int a, int b, int c, int *d);
int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
int func_021E0354(int sub, int key, u8 *found);
void func_021E0394(u8 *a, int b);
void func_021E03D8(u8 *a, int b);
int func_021E03E8(void *n, u32 *q);
void func_021E03F8(int a, int b);
void func_021E0434(u8 *p);
int *func_021E045C(int *p);
void func_021E0468(void *a, void *b, int c);
int *func_021E050C(int *p);
extern const struct Handler data_021F3030[0x102];
extern struct NodeList data_021F3CB0;
extern int d_021F261C[];
extern int d_021F2414[];






void func_021E0284(int a, void *b, int c, int *d, u8 e)
{
    if (c == func_021D775C(3) && e == func_021D775C(22)) {
        if (*d == 1 || func_021C7EC4(b))
            func_021D7704(49, 6 << 10);
    }
}






void func_021E02C0(int a, int b, int c, int *d)
{
    if (c == func_021D775C(3) && *d == 1)
        *d = 2;
}





int func_021E02DC(u8 *a, u16 key, u32 sub_pri)
{
    u32 i;
    u8 sub;
    u8 found;
    u32 out;
    int r;
    for (i = 0; i < 0x102; i++) {
        if (key == data_021F3030[i].key) {
            sub = func_021D5440(a);
            found = 0;
            if (func_021E0354(sub, key, &found) != 0) {
                r = data_021F3030[i].fn(&out);
                if (r != 0) {
                    func_021D6F0C(0, key, 0, sub_pri, sub, r, out);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}





int func_021E0354(int sub, int key, u8 *found)
{
    struct Node *n;
    u32 i = 0;
    for (n = func_021D732C(0, sub); n != 0; n = func_021D7360(n)) {
        if (key == func_021D70A8((struct QQ *)n)) {
            *found = 1;
            return 0;
        }
        if (++i > 8) return 0;
    }
    return 1;
}






void func_021E0394(u8 *a, int b)
{
    void *n;
    void *next;

    n = func_021D732C(0, func_021D5440(a));
    while (n != 0) {
        next = func_021D7360(n);
        if (b == func_021D70A8(n) && func_021D70B4(n, 6) == 0) {
            func_021D7040(n);
        }
        n = next;
    }
}






/* 021E03D8  pass-through: second callee takes the first one's result */
void func_021E03D8(u8 *a, int b)
{
    func_021E03F8(func_021D5440(a), b);
}






int func_021E03E8(void *n, u32 *q)
{
    if (q[6] != 0) return 1;
    return 0;
}




void func_021E03F8(int a, int b)
{
    void *n = func_021D732C(0, a);

    while (n != 0) {
        if (b == func_021D70A8(n)) {
            func_021D7040(n);
            n = func_021D732C(0, a);
        } else {
            n = func_021D7360(n);
        }
    }
}



void func_021E0434(u8 *p)
{
    int n = func_021D5440(p);
    void *a;

    while ((a = func_021D732C(0, n)) != 0)
        func_021D7040(a);
}


int *func_021E045C(int *p)
{
    *p = 1;
    return d_021F261C;
}


void func_021E0468(void *a, void *b, int c)
{
    u8 buf[4];
    void *q;
    u32 n;
    u16 i;
    u16 cnt;
    u32 v;
    char *p;

    if (c == func_021D775C(3)) {
        q = func_021C7CF4(b, c);
        n = func_021D5448(q);
        i = 0;
        cnt = 0;
        for (; i < n; i++) {
            v = func_021D54C0(q, (u8)i);
            if (v != func_021D70A8(a)) {
                v = func_0201C1C8((void *)v);
                if (func_021D5814(q, v) == 0) {
                    buf[cnt++] = v;
                }
            }
        }
        if (cnt != 0) {
            p = func_021C88A4(b, 0x14, c);
            ((struct Obj13503 *)p)->f4 = func_021E8CF0(buf[(u16)func_021D78AC(cnt)]);
            ((struct Obj13503 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}


/*
 * extent: 021E05C2 alignment padding.
 */
int *func_021E050C(int *p)
{
    *p = 1;
    return d_021F2414;
}
