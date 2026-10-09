/*
 * function: func_0272EE98
 * address:  0x0272EE98
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_0272ED4C 0x0272ED4C arm twl
 */
typedef unsigned int u32;

struct Node {
    struct Node *next;
    u32 key;
    u32 f8;
};

struct Obj {
    char pad0[0x10];
    u32 f10;
    char pad1[0x10];
    u32 f24;
    char pad2[0x28];
    struct Node *free_b;
    struct Node *used_b;
    struct Node *used_c;
};

extern u32 func_0209C2B0(u32, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_0272ED4C(struct Obj *);

struct Node *func_0272EE98(struct Obj *obj, u32 a)
{
    u32 key = func_0209C2B0(a, obj->f24);
    struct Node *res;
    struct Node *tail;
    struct Node **pp = &obj->used_c;

    for (;;) {
        tail = *pp;
        res = tail;
        if (tail->key == key) {
            *pp = tail->next;
            tail->next = obj->used_c;
            obj->used_c = tail;
            break;
        } else if (tail->next == 0) {
            u32 irq = func_02087988();
            struct Node *n = obj->used_b;
            struct Node *link;
            while (n != 0) {
                if (n->key == key) {
                    res = n;
                    tail = 0;
                    break;
                }
                n = n->next;
            }
            if (tail != 0) {
                n = obj->free_b;
                link = (struct Node *)&obj->free_b;
                while (n != 0) {
                    if (n->key == key) {
                        res = n;
                        tail = 0;
                        break;
                    }
                    link = n;
                    n = n->next;
                }
                if (tail != 0) {
                    *pp = 0;
                    link->next = tail;
                    tail->key = key;
                    tail->f8 = key * (obj->f24 * 0x14) + obj->f10;
                }
            }
            func_0208799C(irq);
            if (tail != 0) {
                func_0272ED4C(obj);
            }
            break;
        } else {
            pp = (struct Node **)tail;
        }
    }
    return res;
}


