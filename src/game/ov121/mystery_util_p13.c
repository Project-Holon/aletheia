/*
 * file:     mystery_util_p13.c
 * unit:     yes
 * function: func_021DBCC8, func_021DBDB8, func_021DBDBC
 * address:  0x021DBCC8
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200A254  0x0200A254  thumb
 *   func_0200A348  0x0200A348  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_021DBEE4  0x021DBEE4  thumb  ov121
 *   func_021DBDF4  0x021DBDF4  thumb  ov121
 *   func_021DD980  0x021DD980  thumb  ov121
 *   func_021DC02C  0x021DC02C  thumb  ov121
 *   func_021DD24C  0x021DD24C  thumb  ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 */
#include "../../matched/include/Obj22900.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Item { unsigned char raw[0xDC]; } Item;

typedef struct Obj {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x10];
    void *ctx;
    u16 f24;
    unsigned char pad26[2];
    Item items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[4];
    void *desc;
    unsigned char padAB4[0xAD4 - 0xAB4];
    int dirty;
} Obj;

typedef unsigned char u8;

extern void func_0200A254(void *, u32, u32);
extern u32 func_0200A348(struct Obj *list);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DBEE4(u32 p);
extern void func_021DBDF4(Item *it, void *data, Obj *o, u16 f);
extern void func_021DD980(char *p);
extern char *func_021DC02C(void *);
extern void *func_021DD24C(void *,void *,void *,u16);
extern int func_021DBF04(int *);
void func_021DBCC8(Obj *o, u32 a, u32 b);
int func_021DBDB8(char *p);
u32 func_021DBDBC(u32 p);


/*
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   func_021DBC08 (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 */
void func_021DBCC8(Obj *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A254(o->list, a, b);
    for (i = 0; i < func_0200A348(o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348(o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4(&o->items[i], buf, o, o->f24);
        }
    }
    func_021DD980(o->slots[a]);
    func_021DD980(o->slots[b]);
    o->slots[a] = func_021DD24C(func_021DC02C(&o->items[a]), o->desc, o->ctx, o->f24);
    o->slots[b] = func_021DD24C(func_021DC02C(&o->items[b]), o->desc, o->ctx, o->f24);
    o->dirty = 1;
}


int func_021DBDB8(char *p) { return 3; }

/*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: func_0200A348 returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 */
u32 func_021DBDBC(u32 p) { u32 i; u32 count=0; for (i=0;i<func_0200A348(((struct Obj22900 *)p)->fC);i++) { if (func_021DBF04((int *)(p+40+i*220))) count++; } return count; }
