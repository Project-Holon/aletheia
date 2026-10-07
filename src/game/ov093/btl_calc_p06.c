/*
 * file:     btl_calc_p06.c
 * unit:     yes
 * function: func_021D732C, func_021D7360, func_021D7394
 * address:  0x021D732C
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
 *   data_021F3CB0  0x021F3CB0  data
 *   func_021E03E8  0x021E03E8  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

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

extern int func_021E03E8(void *n, u32 *q);
struct Node *func_021D732C(int id, int sub);
struct Node *func_021D7360(struct Node *n);
void func_021D7394(int kind);
extern struct NodeList data_021F3CB0;


struct Node *func_021D732C(int id, int sub)
{
    struct Node *n;
    for (n = data_021F3CB0.head; n != 0; n = n->next) {
        if (n->id == id && n->sub == sub && !n->busy) return n;
    }
    return 0;
}


struct Node *func_021D7360(struct Node *n)
{
    int id;
    u8 sub;
    if (n != 0) {
        id = n->id;
        sub = n->sub;
        for (n = n->next; n != 0; n = n->next) {
            if (n->id == id && n->sub == sub && !n->busy) return n;
        }
    }
    return 0;
}


void func_021D7394(int kind)
{
    struct Node *n;
    for (n = data_021F3CB0.head; n != 0; n = n->next) {
        if (n->id == 0 && n->kind == kind && func_021E03E8(n, (u32 *)n->f1C) != 0) n->mark = 1;
    }
}
