/*
 * file:     unit_021BF520_p03.c
 * unit:     yes
 * function: func_021BFA08, func_021BFA70, func_021BFAF0, func_021BFB20
 * address:  0x021BFA08
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWC_Alloc   0x0205A16C  arm
 *   g_021D3B20  0x021D3B20  data
 *   d_021D3B20    0x021D3B20  data  ov114  a4
 *   func_0205A1B0 0x0205A1B0  arm
 *   DWC_Free    0x0205A1B0  arm
 */
#include "../../matched/include/G_Init.h"

typedef struct {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
} Param;

typedef struct Entry_021BFA08 {
    Param param;
    void *data;
    int unk18;
    struct Entry_021BFA08 *next;
} Entry_021BFA08;

typedef struct {
    int count;
    Entry_021BFA08 *head;
} Init;

typedef struct Node {
    unsigned char pad[0x1c];
    struct Node *next;
} Node;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Entry_021BFB20 {
    char pad[0x14];
    void *data;
    int unk18;
    struct Entry_021BFB20 *next;
} Entry_021BFB20;

extern void *DWC_Alloc(int name, unsigned long size);
extern void func_0205A1B0(int, Node *, int);
extern void DWC_Free(int name, void *ptr, int size);
Entry_021BFA08 *func_021BFA08(Param *param);
void func_021BFA70(Node *x);
u8 *func_021BFAF0(u32 key);
void func_021BFB20(void);
extern struct Init g_021D3B20;
extern Node *d_021D3B20[];


Entry_021BFA08 *func_021BFA08(Param *param)
{
    Entry_021BFA08 *entry;

    entry = DWC_Alloc(6, 0x20);
    if (entry == 0) {
        return 0;
    }
    entry->param = *param;
    entry->next = 0;
    entry->data = 0;
    if (g_021D3B20.head == 0) {
        g_021D3B20.head = entry;
        return entry;
    }
    entry->next = g_021D3B20.head;
    g_021D3B20.head = entry;
    return entry;
}


/*
 * Singly linked list removal.  The if/else with a lone `p = q` arm is
 * deliberate: it makes armcc if-convert that assignment to `movne` and
 * branch over the found arm, which is the only shape that reproduces the
 * original loop.  See
 * docs/idioms/a-lone-move-arm-if-converts-to-movne.md
 */
void func_021BFA70(Node *x)
{
    Node *p = d_021D3B20[1];
    Node *q;
    if (p == 0)
        return;
    if (p == x) {
        Node *nx = p->next;
        func_0205A1B0(6, p, 0);
        d_021D3B20[1] = nx;
        return;
    }
    q = p->next;
    if (q == 0)
        return;
    for (;;) {
        if (q != x) {
            p = q;
        } else {
            Node *n = p->next;
            p->next = n->next;
            func_0205A1B0(6, n, 0);
            return;
        }
        q = q->next;
        if (q == 0)
            return;
    }
}


/*
 * Linear search of the 0x021d3b20 list for the node whose +0x18 key matches;
 * NULL when absent.  The compound condition and the named base pointer are
 * what leave the single shared test block at 0x021bfb00 with the entry
 * jumping to it; the base is not folded into the pool word.
 */
u8 *func_021BFAF0(u32 key)
{
    u8 **base = (u8 **)0x021d3b20;
    u8 *p = base[1];

    while (p != 0 && *(u32 *)(p + 0x18) != key)
        p = *(u8 **)(p + 0x1c);
    return p;
}


/*
 * sdk:      DWCi_RemoveAllDWCGHTTPParamEntry (dwc_ghttp.o)
 */
void func_021BFB20(void)
{
    Entry_021BFB20 *cursor;
    Entry_021BFB20 *target;

    cursor = g_021D3B20.head;
    while (cursor != 0) {
        target = cursor;
        cursor = cursor->next;
        if (target->data != 0) {
            DWC_Free(6, target->data, 0);
        }
        DWC_Free(6, target, 0);
    }
    g_021D3B20.head = 0;
}
