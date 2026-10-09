/*
 * file:     btl_calc.c
 * unit:     yes
 * function: func_021D6E04, func_021D6E0C, func_021D6E24, func_021D6E40, func_021D6E50, func_021D6E74, func_021D6E88, func_021D6EA0, func_021D6EAC, func_021D6EE8, func_021D6F08, func_021D6F0C, func_021D701C, func_021D7040, func_021D7090, func_021D7098, func_021D70A8, func_021D70AC, func_021D70B4, func_021D70BC, func_021D70C8, func_021D70DC, func_021D70E4, func_021D70F0, func_021D70FC, func_021D7108, func_021D713C, func_021D7240, func_021D7320, func_021D7324, func_021D732C, func_021D7360, func_021D7394, func_021D73D4, func_021D7404, func_021D7438, func_021D7474, func_021D7494, func_021D74BC, func_021D74C8, func_021D74E4, func_021D74F8, func_021D7540, func_021D75A8, func_021D75EC, func_021D7630, func_021D7674, func_021D76BC, func_021D7704, func_021D775C, func_021D778C, func_021D77C4, func_021D77E8, func_021D780C, func_021D7840, func_021D787C, func_021D7894, func_021D78AC, func_021D78E4
 * address:  0x021D6E04
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
 *   func_0202142C 0x0202142C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_020185C4 0x020185C4 thumb
 *   d_021F4470  0x021F4470  data  a4
 *   d_021F3CBC  0x021F3CBC  data  a4
 *   g_021F3CB0  0x021F3CB0  data  a4
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021E03E8  0x021E03E8  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F3ECC 0x021F3ECC data a4
 *   data_021F3AB4  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021F6360 0x021F6360 data a4
 *   d_021F3AB8 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 *   d_021F6368 0x021F6368 data a4
 *   func_020307B0 0x020307B0 arm
 *   data_021F6360  0x021F6360  data  ov093
 *   _ull_mul       0x0209C054  arm
 *   d_021F0448 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/Obj13446.h"
#include "../../matched/include/Obj10052.h"
#include "../../matched/include/Obj18422.h"
#include "../../matched/include/Obj00041.h"
#include "../../matched/include/G_NodeList.h"
#include "../../matched/include/G_Tbl.h"
#include "../../matched/include/G__anon_State.h"
#include "../../matched/include/G_Unk021F6360.h"

struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Node Node;

typedef int (*NodeCallback)(Node *, void *, int, int, u16, u8);

typedef struct {
    int id;
    void (*callback)(Node *, void *, u8, void *);
} Entry;

struct Node {
    Node *prev, *next;
    Entry *table;
    NodeCallback callback;
    int id;
    u32 prio;
    u32 serial : 16;
    u32 count : 8;
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

typedef signed long long s64;

typedef struct { unsigned int v[6]; } Words;

typedef struct { unsigned int f0; void *f4; Words words; } State;

typedef unsigned long long u64;

extern unsigned short func_0202142C(int a0);
extern void func_02017E40(void *, u32, u32);
extern void func_020185C4(void *);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021EF948(int);
extern int func_021E03E8(void *n, u32 *q);
void func_02082BCC(int, int, int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern unsigned int _u32_div_f(unsigned int, unsigned int);
unsigned char func_021D6E04(unsigned char *p);
u8 func_021D6E0C(u8 *p, u32 i);
void func_021D6E24(void **p, int value);
void func_021D6E40(u8 *p, u8 a, u16 b);
int func_021D6E50(u8 *p, u8 *id, u16 *value);
u32 func_021D6E74(u8 *p);
void func_021D6E88(u8 *p);
void func_021D6EA0(void *p);
void func_021D6EAC(void);
void func_021D6EE8(void);
void func_021D6F08(void);
Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 table, u16 count);
void func_021D701C(void);
void func_021D7040(Node *n);
void func_021D7090(Node *p);
int func_021D7098(Node *p);
u16 func_021D70A8(Node *p);
u8 func_021D70AC(Node *p);
u32 func_021D70B4(Node *p, int i);
void func_021D70BC(Node *p);
void func_021D70C8(Node *p);
void func_021D70DC(Node *p, int i, u32 v);
void func_021D70E4(void *a, int id);
void func_021D70F0(void *a, int id);
void func_021D70FC(int a, int b, int c);
void func_021D7108(void *a, int id, int kind, int check);
void func_021D713C(void *a, int id, int kind, int check);
int func_021D7240(void *a, Node *b, int c);
void func_021D7320(Node *p, NodeCallback cb);
void func_021D7324(Node *p);
Node *func_021D732C(int id, int sub);
Node *func_021D7360(Node *n);
void func_021D7394(int kind);
void func_021D73D4(int kind);
void func_021D7404(u32 kind, int id);
int func_021D7438(int kind, int id);
Node *func_021D7474(void);
void func_021D7494(void *p);
void func_021D74BC(int a);
void func_021D74C8(void);
void func_021D74E4(void);
void func_021D74F8(int line);
void func_021D7540(int line);
void func_021D75A8(int key, u32 val);
void func_021D75EC(int key, u32 val);
void func_021D7630(int key, u32 val);
void func_021D7674(int key, u32 val, u32 x, u32 y);
int func_021D76BC(int key, u32 val);
void func_021D7704(int key, s32 m);
int func_021D775C(int key);
int func_021D778C(int key, int *out);
u32 func_021D77C4(struct Tbl *p, int key);
int func_021D77E8(struct Tbl *p, int key);
int func_021D780C(struct Tbl *p, int i, int v);
void func_021D7840(const Words *p, unsigned int heap);
void func_021D787C(const Words *p);
void func_021D7894(void);
u32 func_021D78AC(u32 range);
unsigned short func_021D78E4(unsigned short a, int i);
extern Node d_021F4470[0x84];
extern Node *d_021F3CBC[0x84];
extern struct NodeList g_021F3CB0;
extern struct Tbl g_021F3ECC;
extern char data_021F3AB4[];
extern State d_021F6360;
extern const unsigned char d_021F3AB8[];
extern Words d_021F6368;
extern struct Unk021F6360 data_021F6360;
extern unsigned char d_021F0448[][2];


unsigned char func_021D6E04(unsigned char *p)
{
    return p[0xd0];
}


/*
 * lever: left-associated pointer addition preserves base-plus-index then +0xD1.
 */
u8 func_021D6E0C(u8 *p, u32 i)
{
    if (i < p[0xd0]) return *(p + i + 0xd1);
    return 0x1f;
}


/*
 * prototype: reads r0 after func_0202142C, so returns the live wrapper result.
 */
void func_021D6E24(void **p, int value)
{
    u32 n;
    n = func_0202142C(value);
    if (n == 0) n = 4;
    func_02017E40(*p, 0x98, n);
}



void func_021D6E40(u8 *p, u8 a, u16 b)
{
    p[0x1F6] = a;
    ((struct Obj13446 *)p)->f1F4 = b;
}


int func_021D6E50(u8 *p, u8 *id, u16 *value)
{
    if (p[0x1f6] != 0x1f) {
        *id = p[0x1f6];
        *value = ((struct Obj10052 *)p)->f1F4;
        return 1;
    }
    return 0;
}



/* 021D6E74  first round: `== 0x1f` gave bne; the image is beq. */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021D6E84; ldrb r0, [r0, r1]; cmp r0, #0x1f; beq loc_021D6E80; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021D6E74(u8 *p)
{
    return (((struct Obj18422 *)p)->f1F6 != 0x1f);
}


/*
 * extent: existing follower ov093_func_021D6EA0 stays separate.
 */
void func_021D6E88(u8 *p)
{
    if (p[0x1f6] != 0x1f) {
        p[0x1f6] = 0x1f;
        ((struct Obj00041 *)p)->f1F4 = 0;
    }
}

void func_021D6EA0(void *p)
{
    func_020185C4(((struct Obj00041 *)p)->f0);
}

void func_021D6EAC(void)
{
    u32 i;
    for (i = 0; i < 0x84; i++) {
        Node *n = &d_021F4470[i];
        func_021D74BC((int)n);
        d_021F3CBC[i] = n;
    }
    g_021F3CB0.head = 0;
    g_021F3CB0.used = 0;
    g_021F3CB0.serial = 0;
    func_021D74C8();
}

void func_021D6EE8(void)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) n->mark = 0;
}



/*
 * empty function: bx lr
 */
void func_021D6F08(void)
{
}


Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 table, u16 count)
{
    Node *n = func_021D7474();
    Node *cur;
    Node *prev;
    int f;

    if (n != 0) {
        n->prio = ((7 - pri) << 24) | sub_pri;
        n->id = id;
        n->prev = 0;
        n->next = 0;
        n->table = (Entry *)table;
        n->count = count;
        n->key = key;
        n->b24 = 0;
        n->mark = 0;
        n->b30 = 0;
        n->b26 = 0;
        n->callback = 0;
        n->sub = sub;
        n->busy = 0;
        n->b28 = 0;
        n->serial = g_021F3CB0.serial;
        n->b29 = 1;
        f = 0;
        if (id == 0 || id == 4 || id == 5) f = 1;
        n->kind = f ? sub : 0x1F;
        MI_CpuFill8(n->f1C, 0, sizeof(n->f1C));

        prev = g_021F3CB0.head;
        if (prev == 0) {
            g_021F3CB0.head = n;
        } else if (n->prio > prev->prio) {
            prev->prev = n;
            n->next = g_021F3CB0.head;
            n->prev = 0;
            g_021F3CB0.head = n;
        } else {
            for (cur = prev->next; cur != 0; prev = cur, cur = cur->next) {
                if (n->prio > cur->prio) {
                    n->next = cur;
                    n->prev = cur->prev;
                    cur->prev->next = n;
                    cur->prev = n;
                    break;
                }
            }
            if (cur == 0) {
                prev->next = n;
                n->prev = prev;
            }
        }
        func_021D6F08();
        return n;
    }
    return 0;
}

void func_021D701C(void)
{
    Node *n;
    Node *next;
    for (n = g_021F3CB0.head; n != 0; n = next) {
        next = n->next;
        if (n->id == 6) func_021D7040(n);
    }
}


void func_021D7040(Node *n)
{
    if (n != 0) {
        if (n->b29) {
            if (n->b24) {
                n->busy = 1;
                return;
            }
            if (n == g_021F3CB0.head)
                g_021F3CB0.head = n->next;
            if (n->prev != 0)
                n->prev->next = n->next;
            if (n->next != 0)
                n->next->prev = n->prev;
            func_021D6F08();
            func_021D7494(n);
        }
    }
}



/*
 * store constant 0x6 at #0x10
 */
void func_021D7090(Node *p)
{
    p->id = 6;
}


int func_021D7098(Node *p)
{
    if (p->id == 6) return 1;
    return 0;
}


/*
 * Reads the u16 field at #0x38 of the argument and returns it.
 */
u16 func_021D70A8(Node *p) { return p->key; }


u8 func_021D70AC(Node *p)
{
    return p->kind;
}



/* 021D70B4  lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; ldr r0, [r0, #0x1c]; bx lr.
 */
u32 func_021D70B4(Node *p, int i) { return ((u32 *)p->f1C)[i]; }


void func_021D70BC(Node *p) { p->b26 = 1; }


void func_021D70C8(Node *p)
{
    if (p->b24) p->b28 = 1;
}



/* 021D70DC  lsls r1,#2; adds r0,r0,r1; str r2,[r0,#0x1c] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; str r2, [r0, #0x1c]; bx lr.
 */
void func_021D70DC(Node *p, int i, u32 v) { ((u32 *)p->f1C)[i] = v; }



void func_021D70E4(void *a, int id)
{
    func_021D7108(a, id, 7, 0);
}



void func_021D70F0(void *a, int id)
{
    func_021D7108(a, id, 7, 1);
}



void func_021D70FC(int a, int b, int c)
{
    func_021D7108((void *)a, b, c, 1);
}


void func_021D7108(void *a, int id, int kind, int check)
{
    Node *n;
    g_021F3CB0.serial++;
    func_021D713C(a, id, kind, check);
    if (--g_021F3CB0.serial == 0) {
        for (n = g_021F3CB0.head; n != 0; n = n->next) n->serial = 0;
    }
}

void func_021D713C(void *a, int id, int kind, int check)
{
    Node *n;
    Node *next;
    Entry *entry;
    const Entry *table;
    u32 i;
    int count;
    int tmp;
    u32 tmp1;
    for (n = g_021F3CB0.head; n != 0; ) {
        next = n->next;
        if (n->b24 && !n->b28) goto advance;
        if (n->mark || n->b30) goto advance;
        tmp = (kind != 7) && (n->id != kind);
        if (tmp) goto advance;
        if (n->serial != 0 && n->serial >= g_021F3CB0.serial) goto advance;
        if (!n->b29) goto advance;
        if (id == 0x73 && !n->b26) goto advance;
        count = n->count;
        table = n->table;
        i = 0;
        for (; i < count; i++) {
            entry = (Entry *)&table[i];
            if (id != entry->id) continue;
            if (check && func_021D7240(a, n, id)) break;
            n->b24 = 1;
            tmp1 = n->sub;
            entry->callback(n, a, tmp1, n->f1C);
            if (n->b28) n->b28 = 0;
            else n->b24 = 0;
            if (n->busy) {
                if (next != 0 && !next->b29) next = n->next;
                func_021D7040(n);
            }
            break;
        }
advance:
        if (next == 0) break;
        if (next->b29) n = next;
        else n = n->next;
    }
}

int func_021D7240(void *a, Node *b, int c)
{
    void *q = 0;
    Node *n;
    if (b->kind != 0x1f) q = func_021C7CF4(a, b->kind);
    if (b->id == 4 && q != 0 && func_021D62C4(q, 0x10)) return 1;
    if (b->id == 5) {
        if (func_021EF948(7)) return 1;
        if (q != 0 && func_021D62C4(q, 0x13)) return 1;
        if (q != 0 && func_021D5BB0(q, 9)) return 1;
    }
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->callback == 0) continue;
        if (n->id == 4) {
            q = func_021C7CF4(a, n->kind);
            if (q != 0 && func_021D62C4(q, 0x10)) continue;
        }
        if (n->b30) continue;
        if (n->callback(n, a, b->id, c, b->key, b->sub)) return 1;
    }
    return 0;
}


/*
 * Stores the second argument (a u32) into the field at #0xc.
 */
void func_021D7320(Node *p, NodeCallback cb) { p->callback = cb; }



void func_021D7324(Node *p)
{
    p->callback = 0;
}



Node *func_021D732C(int id, int sub)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->id == id && n->sub == sub && !n->busy) return n;
    }
    return 0;
}



Node *func_021D7360(Node *n)
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
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->id == 0 && n->kind == kind && func_021E03E8(n, (u32 *)n->f1C) != 0) n->mark = 1;
    }
}


void func_021D73D4(int kind)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->id == 0 && n->kind == kind) n->mark = 0;
    }
}

void func_021D7404(u32 kind, int id)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->kind == kind && n->id == id) n->b30 = 1;
    }
}

int func_021D7438(int kind, int id) { Node *n; int found=0; for(n=g_021F3CB0.head; n; n=n->next) { if(n->kind==kind && n->id==id) { n->b30=0; found=1; } } return found; }

Node *func_021D7474(void)
{
    u32 i;
    if (g_021F3CB0.used == 0x84) return 0;
    i = g_021F3CB0.used++;
    return g_021F3CB0.pool[i];
}


void func_021D7494(void *p) { if (g_021F3CB0.used) { func_021D74BC((int)p); g_021F3CB0.pool[--g_021F3CB0.used] = p; } }



void func_021D74BC(int a)
{
    func_02082BCC(a, 0, 0x3c);
}


void func_021D74C8(void) { struct Tbl *p = &g_021F3ECC; unsigned int i; p->count = 0; for (i = 0; i < 0x60; i++) p->keys[i] = 0; }



/* 021D74E4  call through a global pointer when it is set */
/*
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021D74F4; ldr r0, [r0]; cmp r0, #0; beq loc_021D74F2; bl func_021D74C8; pop {r3, pc}.
 */
void func_021D74E4(void)
{
    if (g_021F3ECC.count != 0)
        func_021D74C8();
}



void func_021D74F8(int line)
{
    struct Tbl *p = &g_021F3ECC;
    while (p->count < 0x60) {
        if (p->keys[p->count] == 0) break;
        p->count++;
    }
    if (p->count < 0x5F) {
        p->keys[p->count++] = 1;
    } else {
        func_02034714(data_021F3AB4, 0, data_021F3AB4);
    }
}


void func_021D7540(int line)
{
    struct Tbl *p = &g_021F3ECC;
    u16 i;
    if (p->count != 0) {
        i = p->count;
        while (i < 0x60 && p->keys[i] != 0) {
            p->keys[i++] = 0;
        }
        p->count--;
        p->keys[p->count] = 0;
        if (p->count != 0) {
            while (p->count != 0) {
                p->count--;
                if (p->keys[p->count] == 1) {
                    p->count++;
                    return;
                }
            }
        }
    }
}



void func_021D75A8(int key, u32 val)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = 0;
    g_021F3ECC.a[i] = 0;
    g_021F3ECC.c[i] = 0;
}



void func_021D75EC(int key, u32 val)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = 0;
    g_021F3ECC.a[i] = 0;
    g_021F3ECC.c[i] = 4;
}



void func_021D7630(int key, u32 val)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = 0;
    g_021F3ECC.a[i] = 0;
    g_021F3ECC.c[i] = 1;
}



void func_021D7674(int key, u32 val, u32 x, u32 y)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = x;
    g_021F3ECC.a[i] = y;
    g_021F3ECC.c[i] = 3;
}


int func_021D76BC(int key, u32 val)
{
    struct Tbl *t = &g_021F3ECC;
    int i = func_021D77E8(t, key);

    if (i >= 0 && t->c[i] <= 1) {
        t->keys[i] = key;
        t->vals[i] = val;
        if (t->c[i] == 1)
            t->c[i] = 2;
        return 1;
    }
    return 0;
}


void func_021D7704(int key, s32 m)
{
    struct Tbl *t = &g_021F3ECC;
    int i = func_021D77E8(t, key);

    if (i >= 0 && t->c[i] == 3) {
        s32 v = t->vals[i];
        s64 prod = (s64)v * (s64)m;
        t->vals[i] = func_021D780C(t, i, (s32)((prod + 0x800) >> 12));
    }
}



int func_021D775C(int key)
{
    struct Tbl *p = &g_021F3ECC;
    u32 i;

    i = p->count;
    if (i < 0x60) {
        for (;;) {
            if (p->keys[i] == key)
                return p->vals[i];
            if (p->keys[i] == 0)
                break;
            if (++i >= 0x60)
                break;
        }
    }
    return 0;
}


int func_021D778C(int key, int *out) { struct Tbl *p = &g_021F3ECC; unsigned int i; for(i=p->count; i<0x60; i++) { if(key==p->keys[i]) { *out=p->vals[i]; return 1; } if(p->keys[i]==0) break; } return 0; }



u32 func_021D77C4(struct Tbl *p, int key)
{
    u32 i;
    for (i = p->count; i < 0x60; i++) {
        if (p->keys[i] == 0) break;
        if (key == p->keys[i]) break;
    }
    if (i >= 0x60) i = 0;
    return i;
}


int func_021D77E8(struct Tbl *p, int key) { unsigned int i; for (i=p->count; i<0x60 && p->keys[i]!=0; i++) { if(key==p->keys[i]) return i; } return -1; }


int func_021D780C(struct Tbl *p, int i, int v) { int hi = p->a[i]; if (hi || p->b[i]) { if ((int)p->b[i] > v) v = p->b[i]; if (hi < v) v=hi; } return v; }


void func_021D7840(const Words *p, unsigned int heap) { d_021F6360.f4=func_02030734(heap,0x460,1,(const char *)d_021F3AB8,0x50); d_021F6360.words=*p; }


void func_021D787C(const Words *p) { d_021F6368 = *p; }


void func_021D7894(void) { if (d_021F6360.f4) { func_020307B0(d_021F6360.f4); d_021F6360.f4 = 0; } }



u32 func_021D78AC(u32 range)
{
    struct Unk021F6360 *p = &data_021F6360;
    u32 v;

    p->seed = p->mul * p->seed + p->add;
    if (range == 0) {
        v = (u32)(p->seed >> 32);
    } else {
        v = (u32)(((p->seed >> 32) * range) >> 32);
    }
    return v;
}


unsigned short func_021D78E4(unsigned short a, int i) { return _u32_div_f((unsigned short)(a*d_021F0448[i][0]), d_021F0448[i][1]); }
