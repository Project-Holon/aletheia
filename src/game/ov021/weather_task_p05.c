/*
 * file:     weather_task_p05.c
 * unit:     yes
 * function: func_021A277C, func_021A27B8, func_021A27F8, func_021A282C, func_021A284C, func_021A2860, func_021A28A0
 * address:  0x021A277C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021A2978  0x021A2978  thumb  ov021
 *   func_021A29A8  0x021A29A8  thumb  ov021
 *   func_021A29F4  0x021A29F4  thumb  ov021
 *   func_021A2994  0x021A2994  thumb  ov021
 *   func_021A2A18  0x021A2A18  thumb  ov021
 *   func_021A2A68  0x021A2A68  thumb  ov021
 */
#include "../../matched/include/Obj12084.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct Node021A277C {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A277C *prev;
    struct Node021A277C *next;
} Node021A277C;

typedef struct {
    u8 pad[0x774];
    Node021A277C *head;
    int count;
} Obj021A277C;

typedef struct Node021A27B8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27B8 *prev;
    struct Node021A27B8 *next;
} Node021A27B8;

typedef struct {
    u8 pad[0x774];
    Node021A27B8 *head;
    int count;
} Obj021A27B8;

typedef struct Node021A27F8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27F8 *prev;
    struct Node021A27F8 *next;
} Node021A27F8;

typedef struct {
    u8 pad[0x48];
    void (*cb)(Node021A27F8 *n);
} Ops021A27F8;

typedef struct {
    u8 pad[0x20];
    Ops021A27F8 *ops;
    u8 pad24[0x750];
    Node021A27F8 *head;
} Obj021A27F8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad0[4];
    unsigned short count;
} Hdr;

typedef struct {
    char pad0[0x18];
    int *arr;
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[4];
} Obj;

typedef struct {
    u8 pad[4];
    u16 count;
} Info021A28A0;

typedef struct {
    u8 pad[0x18];
    u32 *items;
    u8 pad1C[4];
    Info021A28A0 *info;
    u8 pad24[4];
    u8 slots[1];
} Obj021A28A0;

void func_0204B3DC(struct Obj *h, unsigned int v);
extern void func_021A2978(u8 *p, u16 *q, u32 c, u32 a3);
extern u32 func_021A29A8(u32, u32, u32);
extern u32 func_021A2994(u32);
extern void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3);
void func_021A2A18(void *a, int i, int v, void *p, int x);
void func_021A2A68(u8 *p, int i, int x);
void func_021A277C(Obj021A277C *p, Node021A277C *n);
void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n);
void func_021A27F8(Obj021A27F8 *p);
int func_021A282C(u32 a, u32 b, u32 c, u32 d);
int func_021A284C(u32 a, u32 b, u32 c, u32 d);
void func_021A2860(Obj *o, int x);
void func_021A28A0(Obj021A28A0 *p);


void func_021A277C(Obj021A277C *p, Node021A277C *n)
{
    Node021A277C *tail;

    p->count++;
    if (p->head == 0) {
        p->head = n;
        n->next = n;
        p->head->prev = n;
        return;
    }
    tail = p->head->prev;
    n->prev = tail;
    n->next = tail->next;
    tail->next->prev = n;
    tail->next = n;
    func_0204B3DC((struct Obj *)n->handle, 1);
}


void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n)
{
    p->count--;
    if (p->head == n) {
        if (n->next == n)
            p->head = 0;
        else
            p->head = n->next;
    }
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = 0;
    n->prev = 0;
    func_0204B3DC((struct Obj *)n->handle, 0);
}


void func_021A27F8(Obj021A27F8 *p)
{
    Node021A27F8 *cur = p->head;
    Node021A27F8 *nx;

    if (cur != 0 && p->ops->cb != 0) {
        nx = cur->next;
        do {
            p->ops->cb(cur);
            cur = nx;
            nx = nx->next;
        } while (cur != p->head && p->head != 0);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A282C(u32 a, u32 b, u32 c, u32 d)
{
func_021A2978((u8 *)(a + 40), (u16 *)(((struct Obj12084 *)((u8 *)(a)))->f20), b, d);
return func_021A29A8((a + 40), ((struct Obj12084 *)((u8 *)(a)))->f20, b);
}


int func_021A284C(u32 a, u32 b, u32 c, u32 d)
{
func_021A29F4((u16 *)(a + 40), b, c, d);
return func_021A2994((a + 40));
}


void func_021A2860(Obj *o, int x)
{
    int i;

    for (i = 0; i < o->hdr->count; i++) {
        func_021A2A18(o->sub, i, o->arr[i], (char *)o->hdr + 0xe + i * 12, x);
    }
}


void func_021A28A0(Obj021A28A0 *p)
{
    int i;

    for (i = 0; i < p->info->count; i++)
        func_021A2A68(p->slots, i, p->items[i]);
}
