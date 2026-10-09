/*
 * file:     cursor_move.c
 * unit:     yes
 * function: func_02025C74, func_02025C88, func_02025C9C, func_02025CB0, func_02025CD0, func_02025D14, func_02025D1C, func_02025D24, func_02025D2C, func_02025DE8, func_02025EA4, func_02025F60, func_02025FA4, func_02025FC8, func_02026010, func_020260E0, func_020260E4, func_020260F0, func_020260F4, func_02026124, func_0202614C, func_0202616C, func_02026178, func_020261C4, func_020261E4, func_02026250, func_0202627C
 * address:  0x02025C74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0209FB18  0x0209FB18  data
 *   sub_02030734  0x02030734  arm
 *   str_020A74A0  0x020A74A0  data
 *   func_02030164  0x02030164  arm
 *   func_02025EA4  0x02025EA4  thumb
 *   func_02025FC8  0x02025FC8  thumb
 *   func_02025F60  0x02025F60  thumb
 *   func_02026010  0x02026010  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203633C  0x0203633C  arm
 *   func_02035C08  0x02035C08  arm
 *   func_020261C4  0x020261C4  thumb
 *   g_0209FB58  0x0209FB58  data
 *   sub_020355D8  0x020355D8  arm
 *   func_02030734   0x02030734  arm
 *   func_02012944   0x02012944  thumb
 *   func_020457B0   0x020457B0  arm
 *   func_02008500   0x02008500  thumb
 *   g_020A74B0      0x020A74B0  data
 *   sub_02045808  0x02045808  arm
 *   sub_020307B0  0x020307B0  arm
 *   g_0209FB5C     0x0209FB5C  data
 *   func_02026490  0x02026490  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* One row of the 16-entry table at d_0209FB18. */
struct CursorRow {
    u16 f0;
    u8 f2;
    u8 f3;
};

/* One selectable slot: neighbour slot per direction, then a four byte tag. */
struct CursorEntry {
    u32 unk0;
    u8 next[4];
    u8 tag[4];
};

typedef void (*CursorCb)(u32 ctx, u8 cur, int prev);

struct CursorVtbl {
    CursorCb slot0;
    CursorCb slot4;
    CursorCb slot8;
    CursorCb slotC;
};

struct Cursor {
    struct CursorEntry *entries;
    u32 state;
    u32 mode;
    u8 field_C;
    u8 cur;
    u8 prev;
    u8 saved;
    u32 bits[2];
    struct CursorVtbl *vt;
    u32 ctx;
};

struct VecItem {
    u32 unk0;
    void *vec1;
    void *vec2;
};

struct VecSet {
    void *owner;
    u8 pad_4[0x38];
    struct VecItem items[6];
};

struct U16Vec;

struct Sub
{
  u32 f00;
  u8 state;
  u8 changed;
  u8 f06;
  u8 f07;
};

struct Comm
{
  u32 f00;
  u8 b0 : 1;
  u8 b1 : 1;
  u8 b2 : 1;
  u8 b3 : 5;
  u8 kind;
  u8 f06;
  u8 f07;
  u32 f08;
  struct Sub sub;
  u32 f14;
  u32 f18;
  u32 f1c;
  void (*f20)(u32, u32);
};

struct Rec
{
  u32 (*start)(struct Sub *, u32);
  u32 (*wait)(struct Sub *, u32, u32);
  void (*run)(struct Sub *, u32, u32);
  u32 (*stop)(struct Sub *, u32, u32);
  u32 (*end)(struct Sub *, u32, u32);
  u32 f14;
  u32 f18;
};

/* the finish arm clears its fields through an enum-typed zero */
typedef enum { Z0 } E;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02030164(void *p);
extern void sub_020355D8(u8 v);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern int func_02035C08(const void *key);
extern u8 *func_02012944(void *a0);
extern struct U16Vec *func_020457B0(u32 a0, u32 a1);
extern void func_02008500(void *a0, void *a1);
extern void sub_02045808(struct U16Vec *vec);
extern u32 sub_020307B0(void *p);
extern void func_02026490(void *obj, u32 value);
extern struct CursorRow d_0209FB18[];
extern const char str_020A74A0[];
extern const u8 g_0209FB58[4];
extern u32 g_020A74B0[];
extern struct Rec g_0209FB5C[];

u32 func_02025C74(u32 x);
u32 func_02025C88(u32 x);
u32 func_02025C9C(u32 x);
u32 func_02025CB0(u32 v);
struct Cursor *func_02025CD0(struct CursorEntry *entries, struct CursorVtbl *vt, u32 ctx, u32 state, u8 start, u16 heapId);
u32 func_02025D14(void *a0);
void func_02025D1C(struct Cursor *obj);
void func_02025D24(struct Cursor *obj);
int func_02025D2C(struct Cursor *obj);
int func_02025DE8(struct Cursor *obj);
int func_02025EA4(struct Cursor *obj, int *out);
u32 func_02025F60(const struct CursorEntry *entries, u32 idx, u32 type);
int func_02025FA4(struct Cursor *obj);
int func_02025FC8(struct Cursor *obj);
int func_02026010(struct Cursor *obj, u32 dir, int sel);
u8 func_020260E0(struct Cursor *obj);
void func_020260E4(struct Cursor *obj, u8 sel);
u32 func_020260F0(struct Cursor *obj);
void func_020260F4(struct Cursor *obj, u32 state);
void func_02026124(struct Cursor *obj, u32 idx);
void func_0202614C(struct Cursor *obj, u32 idx);
struct CursorEntry *func_0202616C(struct Cursor *obj, u32 idx);
int func_02026178(const struct CursorEntry *entry, u32 type);
int func_020261C4(const u32 *bitmap, u32 bit);
struct VecSet *func_020261E4(u32 a0, void *a1);
void func_02026250(struct VecSet *obj);
void func_0202627C(struct Comm *p);


/*
 * Halfword accessor over the 0x10-entry table of 4-byte records at
 * 0x0209FB18 (u16, u8, u8; func_02025C9C reads the u8 at +2, func_02025C88
 * the one at +3); out of range returns 0xB.  Seeded from ov019 0x0217AE76
 * and ov021 0x021CFCD6.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02025C74(u32 x)
{
    if (x >= 0x10u)
        return 0xB;
    return d_0209FB18[x].f0;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module: byte accessor over a 0x10-entry
 * table of 4-byte records.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02025C88(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return d_0209FB18[x].f3;
}


/*
 * Two more leaves over the 0x10-entry table of 4-byte records at 0x0209FB18
 * (see func_02025C74 and func_02025C88): the byte at +2 of entry x (2 when
 * out of range), and the index of the first entry whose byte at +3 equals v
 * (0 when none does).  Seeded from ov111 0x021C6216 and ov116 0x021D6AAC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02025C9C(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return d_0209FB18[x].f2;
}


u32 func_02025CB0(u32 v)
{
    u32 i;

    for (i = 0; i < 0x10; i++) {
        if (v == d_0209FB18[i].f3)
            return i;
    }
    return 0;
}


struct Cursor *func_02025CD0(struct CursorEntry *entries, struct CursorVtbl *vt, u32 ctx, u32 state, u8 start, u16 heapId)
{
    struct Cursor *p = (struct Cursor *)sub_02030734(heapId, 0x20, 0, str_020A74A0, 0x6a);

    p->entries = entries;
    p->vt = vt;
    p->ctx = ctx;
    p->field_C = 0;
    p->state = state;
    p->mode = 0;
    p->cur = start;
    p->prev = 0xff;
    p->saved = 0xff;
    p->bits[0] = -1;
    p->bits[1] = -1;

    return p;
}


/*
 * Unlabelled Thumb leaf: a bare tail call to func_02030164 with no arguments.
 * `ldr r3,[pc,#0]; bx r3` (the pool word names 0x02030164).  Disasm.py did
 * not label it because it has no prologue; the live bytes decode as Thumb.
 */
u32 func_02025D14(void *a0)
{
    return func_02030164(a0);
}


void func_02025D1C(struct Cursor *obj)
{
    obj->field_C = 1;
}


void func_02025D24(struct Cursor *obj)
{
    obj->mode = 1;
}


/*
 * field_sound_system.c.  The primary-pad poll: with no pending selection, read the four direction bits of the button word and hand the matching entry to func_02026010; B answers the current slot and A answers -2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025D2C.c \
 *       --func func_02025D2C --addr 0x02025D2C --cc 1.1p1 --thumb
 */
int func_02025D2C(struct Cursor *obj)
{
    int dir;
    int res;
    u32 sel;

    if (func_02025EA4(obj, &res) == 1) {
        return res;
    }
    if (obj->state == 0 && obj->field_C == 1) {
        return func_02025FC8(obj);
    }

    if (func_020362DC() & 0x40) {
        sel = func_02025F60(obj->entries, obj->cur, 0);
        dir = 0;
    } else if (func_020362DC() & 0x80) {
        sel = func_02025F60(obj->entries, obj->cur, 1);
        dir = 1;
    } else if (func_020362DC() & 0x20) {
        sel = func_02025F60(obj->entries, obj->cur, 2);
        dir = 2;
    } else if (func_020362DC() & 0x10) {
        sel = func_02025F60(obj->entries, obj->cur, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return func_02026010(obj, dir, sel);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        return obj->cur;
    }
    if (func_020362DC() & 2) {
        dir = 0;
        func_020355D8(0);
        return dir - 2;
    }
    return -1;
}


/*
 * field_sound_system.c.  The secondary-pad twin of func_02025D2C: identical shape, but the four direction bits come from func_0203633C while the two action bits still come from func_020362DC.
 *
 * func_02026010 takes three arguments; the third is the slot value
 * func_02025F60 returned, which reads at the call site as a leftover r2 but
 * is a real argument -- without it the `adds r2, r0, #0` after the call is
 * dead-code eliminated and the function comes out two bytes short.
 */
int func_02025DE8(struct Cursor *obj)
{
    u32 sel;
    u32 dir;
    int res;

    if (func_02025EA4(obj, &res) == 1) {
        return res;
    }
    if (obj->state == 0 && obj->field_C == 1) {
        return func_02025FC8(obj);
    }

    if (func_0203633C() & 0x40) {
        sel = func_02025F60(obj->entries, obj->cur, 0);
        dir = 0;
    } else if (func_0203633C() & 0x80) {
        sel = func_02025F60(obj->entries, obj->cur, 1);
        dir = 1;
    } else if (func_0203633C() & 0x20) {
        sel = func_02025F60(obj->entries, obj->cur, 2);
        dir = 2;
    } else if (func_0203633C() & 0x10) {
        sel = func_02025F60(obj->entries, obj->cur, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return func_02026010(obj, dir, sel);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        return obj->cur;
    }
    if (func_020362DC() & 2) {
        dir = 0;
        func_020355D8(0);
        return dir - 2;
    }
    return -1;
}


/*
 * Scan the entry table hanging off the object for a live record: each
 * entry's tag word is copied into the low half of a 8-byte stack scratch
 * whose high half is preloaded from the four-byte template g_0209FB58, then
 * handed to func_02035C08.  A hit that also passes the bitmap test commits
 * the entry: the previous slot id is shifted to prev, the new index becomes
 * cur, an in-flight request (state == 1 with field_C == 1) is cancelled
 * through the vtable slot 4 before the normal slot C notification, and the
 * caller's out word receives the index.
 */
/*
 * field_sound_system.c.  Scan the entry table hanging off the object for a
 * live record: each 12-byte entry's tag word (bytes 8..11) is copied into
 * the low half of a 8-byte stack scratch whose high half is preloaded from
 * the four-byte template g_0209FB58, then handed to func_02035C08.  A hit
 * that also passes the bitmap test at +0x10 commits the entry: the previous
 * slot id is shifted to +0xe, the new index becomes +0xd, an in-flight
 * request (field_4 == 1 with field_C == 1) is cancelled through the record's
 * vtable slot +4 before the normal slot +0xc notification, and the caller's
 * out word receives the index.
 *
 * occurrence of the address anywhere in the image (arm9 and overlays), so the
 * only witness for the ABS32 site lies inside this function's own extent.
 * No evidence class applies -- `literal` needs the word at a different
 * address, `label` and `matched` need code -- so the function caps at MATCH
 * regardless of how the C is spelled.  Unstick it by decompiling any other
 * reader of 0x0209FB58, which would supply a second pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02025EA4.c \
 *       --func func_02025EA4 --addr 0x02025EA4 --cc 1.1p1 --thumb
 */
int func_02025EA4(struct Cursor *obj, int *out)
{
    u8 key[8];
    u16 i;
    int res;
    u32 *bitmap;
    struct CursorEntry *e;

    key[4] = g_0209FB58[0];
    key[5] = g_0209FB58[1];
    key[6] = g_0209FB58[2];
    key[7] = g_0209FB58[3];
    res = 0;
    i = res;
    bitmap = obj->bits;
    *out = res - 1;

    while (1) {
        e = (struct CursorEntry *)((u8 *)obj->entries + i * 12);
        if (e->tag[0] == 0xff) {
            break;
        }
        key[0] = ((volatile struct CursorEntry *)e)->tag[0];
        key[1] = e->tag[1];
        key[2] = e->tag[2];
        key[3] = e->tag[3];
        if (func_02035C08(key) != -1) {
            res = 1;
            if (func_020261C4(bitmap, i) == 1) {
                obj->prev = obj->cur;
                obj->cur = (u8)i;
                if (obj->state == 1 && obj->field_C == 1) {
                    obj->state = 0;
                    obj->vt->slot4(obj->ctx, obj->cur, obj->prev);
                }
                obj->vt->slotC(obj->ctx, obj->cur, obj->prev);
                obj->prev = 0xff;
                obj->saved = 0xff;
                *out = i;
                func_020355D8(1);
                break;
            }
        }
        i = i + 1;
    }
    return res;
}


u32 func_02025F60(const struct CursorEntry *entries, u32 idx, u32 type)
{
    switch (type) {
    case 0:
        idx = entries[idx].next[0];
        break;
    case 1:
        idx = entries[idx].next[1];
        break;
    case 2:
        idx = entries[idx].next[2];
        break;
    case 3:
        idx = entries[idx].next[3];
        break;
    }

    return idx;
}


int func_02025FA4(struct Cursor *obj)
{
    int one = 1;

    sub_020355D8(0);
    obj->state = one;
    obj->prev = 0xff;
    obj->saved = 0xff;
    obj->vt->slot0(obj->ctx, obj->cur, obj->prev);

    return one - 5;
}


/*
 * Poll the pending-interrupt word and answer with the slot a matching mask
 * selects: mode 1 (a0[8] == 1) tests 0xf3, the other path tests 0xf1 and
 * then bit 1; a hit runs func_02025FA4 and returns its value, a miss in the
 * bit-1 case answers -2 and a miss anywhere else answers -1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025FC8.c \
 *       --func func_02025FC8 --addr 0x02025FC8 --cc 1.1p1 --thumb
 */
int func_02025FC8(struct Cursor *obj)
{
    if (obj->mode == 1) {
        if (func_020362DC() & 0xf3) {
            return func_02025FA4(obj);
        }
    } else if (func_020362DC() & 0xf1) {
        return func_02025FA4(obj);
    } else if (func_020362DC() & 2) {
        func_02025FA4(obj);
        return -2;
    }
    return -1;
}


/*
 * field_sound_system.c.  Moves the cursor from the current entry to the
 * one func_02025F60 names for `dir`, skipping entries whose bit is clear
 * in the object's 32-bit-word skip bitmap, then notifies the owner.
 */
int func_02026010(struct Cursor *obj, u32 dir, int sel)
{
    int direct;
    u32 n;

    func_020355D8(0);

    if (sel & 0x80) {
        if (obj->saved != 0xff) {
            sel = obj->saved;
        } else {
            sel ^= 0x80;
        }
    }

    direct = 1;
loop:
    if ((obj->bits[(u32)sel >> 5] & (1 << (sel % 32))) == 0) {
        direct = 0;
        n = (u8)(func_02025F60(obj->entries, sel, dir) & 0x7f);
        if (n == (u32)sel || n == obj->cur) {
            sel = obj->cur;
        } else {
            sel = n;
            goto loop;
        }
    }

    if (obj->cur != sel) {
        if (func_02026178(&obj->entries[sel], dir) == 1 && direct) {
            obj->saved = obj->cur;
        } else {
            obj->saved = 0xff;
        }

        {
            u8 prev = obj->cur;
            struct CursorVtbl *vt = obj->vt;
            u32 ctx = obj->ctx;

            obj->cur = (u8)sel;
            obj->prev = prev;
            vt->slot8(ctx, obj->cur, obj->prev);
        }
        return -3;
    }

    if (dir == 0) {
        return -8;
    }
    if (dir == 1) {
        return -7;
    }
    if (dir == 2) {
        return -6;
    }
    if (dir == 3) {
        return -5;
    }
    return -1;
}


/*
 * field_sound_system.c accessors following src/matched/func_02026010.c:
 * read the current cursor entry, set it (clearing the two trailing
 * cached indices to 0xff), and read field_4.  All leaves; calls nothing.
 */
u8 func_020260E0(struct Cursor *obj)
{
    return obj->cur;
}


void func_020260E4(struct Cursor *obj, u8 sel)
{
    obj->cur = sel;
    obj->prev = 0xff;
    obj->saved = 0xff;
}


u32 func_020260F0(struct Cursor *obj)
{
    return obj->state;
}


void func_020260F4(struct Cursor *obj, u32 state)
{
    obj->state = state;
    if (state == 1) {
        obj->prev = 0xff;
        obj->saved = 0xff;
        obj->vt->slot0(obj->ctx, obj->cur, -1);
    } else {
        obj->vt->slot4(obj->ctx, obj->cur, -1);
    }
}


/*
 * field_sound_system.c leaves after src/matched/sub_020260F4.c, on the
 * same object as src/matched/unit_020260E0.c: clear a bit in the flag
 * words at +0x10, set it, and address an entry of the 12-byte table.
 * The clear spells ~m as m ^ 0xFFFFFFFF (the compiler derives -1 from the
 * live 0x1f with subs #0x20); the set is an xor guarded by the test.
 * Seeded from ov170 (0x021DF6AE, 0x021EA0FE, 0x021EA892) and ov069/ov136.
 */
void func_02026124(struct Cursor *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if (obj->bits[w] & (1 << b)) {
        obj->bits[w] &= (1 << b) ^ 0xFFFFFFFF;
    }
}


void func_0202614C(struct Cursor *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if ((obj->bits[w] & (1 << b)) == 0) {
        obj->bits[w] ^= (1 << b);
    }
}


struct CursorEntry *func_0202616C(struct Cursor *obj, u32 idx)
{
    return &obj->entries[idx];
}


int func_02026178(const struct CursorEntry *entry, u32 type)
{
    switch (type) {
    case 0:
        if (entry->next[1] & 0x80) {
            return 1;
        }
        break;
    case 1:
        if (entry->next[0] & 0x80) {
            return 1;
        }
        break;
    case 2:
        if (entry->next[3] & 0x80) {
            return 1;
        }
        break;
    case 3:
        if (entry->next[2] & 0x80) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_020261C4(const u32 *bitmap, u32 bit)
{
    u32 mask = 1 << (bit & 0x1f);
    int res = 1;

    if ((bitmap[bit >> 5] & mask) == 0) {
        res = 0;
    }
    return res;
}


/*
 * Allocate the 0x88-byte sprite for a1 (tag 0xe0), keep a1 as its first word,
 * then attach six sub-buffers: each starts at +0x3c with a 0xc stride, gets
 * two 8-byte allocations out of the a0 heap and registers both with the
 * resource handle func_02012944 returned for a1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020261E4.c \
 *       --func func_020261E4 --addr 0x020261E4 --cc 1.1p1 --thumb
 */
struct VecSet *func_020261E4(u32 a0, void *a1)
{
    int i;
    struct VecSet *p;
    struct VecItem *base;
    struct VecItem *e;
    u8 *q;

    p = (struct VecSet *)sub_02030734(a0, 0x88, 1, (const char *)g_020A74B0, 0xe0);
    p->owner = a1;
    q = func_02012944(a1);
    base = p->items;
    for (i = 0; i < 6; i++) {
        e = base + i;
        e->vec1 = func_020457B0(8, a0);
        e->vec2 = func_020457B0(8, a0);
        func_02008500(q, e->vec1);
        func_02008500(q, e->vec2);
    }
    return p;
}


void func_02026250(struct VecSet *obj)
{
    struct VecItem *items = obj->items;
    int i;

    for (i = 0; i < 6; i++) {
        sub_02045808(items[i].vec1);
        sub_02045808(items[i].vec2);
    }
    sub_020307B0(obj);
}

/*
 * game_comm.c: the per-frame request state machine.  The request kind
 * (+5) selects a 0x1C-byte record of callbacks in the table at 0x0209FB5C
 * (func_02026388 and func_020263B0 read its words at +0x14 and +0x18); the
 * state byte of the 8-byte sub-object at +0xC is the dense switch.
 *
 * Closed 2026-09-24 (wave 21, lane E) after the DIFF 10 recorded in
 * docs/notes/pkt_0202627C.c.txt.  The lever is the finish arm's zero typed
 * as an enum (`E z = Z0` assigned first, then cb, a, b read in that order):
 * with -enum int an enum value is not constant-propagated the way a u32
 * zero is, so the zero keeps its own web (r2, shared with the bics mask)
 * and the callback takes r5 as in the image.  A u32 zero in the same
 * position is 13 out; see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202627C.c \
 *       --func func_0202627C --addr 0x0202627C --cc 1.1p1 --thumb
 */
void func_0202627C(struct Comm *p)
{
  struct Sub *sub;
  struct Rec *rec;
  if ((p == 0) || (p->kind == 0))
    return;
  sub = &p->sub;
  rec = &g_0209FB5C[p->kind];
  if (sub->changed == 1)
  {
    sub->f00 = 0;
    sub->changed = 0;
  }
  switch (sub->state)
  {
    case 0:
      if (rec->start != 0)
      p->f18 = rec->start(sub, p->f14);
      p->f06 = p->kind;
      p->f08 = 0;
      func_02026490(sub, 1);
      break;

    case 1:
      if ((rec->wait == 0) || (rec->wait(sub, p->f14, p->f18) == 1))
      func_02026490(sub, 2);
      break;

    case 2:
      if (p->b0 == 1)
    {
      p->b0 = 0;
      func_02026490(&p->sub, 3);
      break;
    }
      rec->run(sub, p->f14, p->f18);
      break;

    case 3:
      if (rec->stop != 0)
    {
      if (rec->stop(sub, p->f14, p->f18) == 1)
        func_02026490(sub, 4);
    }
    else
    {
      func_02026490(sub, 4);
    }
      break;

    case 4:
      if ((rec->end != 0) && (rec->end(sub, p->f14, p->f18) != 1))
      break;
      func_02026490(sub, 5);

    case 5:
    {
      void (*cb)(u32, u32);
      u32 a;
      u32 b;
      E z;
      z = Z0;
      cb = p->f20;
      a = p->f1c;
      b = p->b1;
      p->f18 = z;
      p->kind = z;
      p->f20 = 0;
      p->f1c = z;
      p->b1 = 0;
      if (cb != 0)
        cb(a, b);
      break;
    }

  }

}
