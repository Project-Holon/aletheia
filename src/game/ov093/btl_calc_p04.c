/*
 * file:     btl_calc_p04.c
 * unit:     yes
 * function: func_021D70DC, func_021D70E4, func_021D70F0, func_021D70FC, func_021D7108
 * address:  0x021D70DC
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
 *   g_021F3CB0 0x021F3CB0 data a4
 *   func_021D713C 0x021D713C thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Node { struct Node *prev, *next; u8 pad[0x10]; u32 flags; } Node;

extern void func_021D713C(void *, int, int, int);
/* 021D70DC lsls r1,#2; adds r0,r0,r1; str r2,[r0,#0x1c] */ void func_021D70DC(u8 *p, int i, u32 v);
void func_021D70E4(void *a, int id);
void func_021D70F0(void *a, int id);
void func_021D70FC(int a, int b, int c);
void func_021D7108(void *a, int id, int kind, int check);
extern struct { u32 tick; Node *head; } g_021F3CB0;


/* 021D70DC  lsls r1,#2; adds r0,r0,r1; str r2,[r0,#0x1c] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; str r2, [r0, #0x1c]; bx lr.
 */
void func_021D70DC(u8 *p, int i, u32 v) { *(u32 *)(p + i * 4 + 0x1c) = v; }


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
    g_021F3CB0.tick++;
    func_021D713C(a, id, kind, check);
    if (--g_021F3CB0.tick == 0) {
        for (n = g_021F3CB0.head; n != 0; n = n->next) n->flags &= 0xffff0000;
    }
}
