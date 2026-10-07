/*
 * file:     unit_021E0284_p01.c
 * unit:     yes
 * function: func_021E0284, func_021E02C0, func_021E02DC, func_021E0354, func_021E0394
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
 */
struct Node;
struct QQ;
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
void func_021E0284(int a, void *b, int c, int *d, u8 e);
void func_021E02C0(int a, int b, int c, int *d);
int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
int func_021E0354(int sub, int key, u8 *found);
void func_021E0394(u8 *a, int b);
extern const struct Handler data_021F3030[0x102];
extern struct NodeList data_021F3CB0;


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
