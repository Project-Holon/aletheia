/*
 * file:     unit_02067EB0.c
 * unit:     yes
 * function: func_02067EB0, func_02067F78, func_02067F9C
 * address:  0x02067EB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020698F8    0x020698F8  arm
 *   func_02069C00    0x02069C00  arm
 *   func_02067EB0  0x02067EB0  arm
 */
struct Struct02067EB0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Entry02067EB0 {
    u16 key;
    u16 val;
};

struct Struct02067EB0 {
    u16 base;               /* 0x0 */
    u16 pad_02;
    u16 type;               /* 0x4 */
    u16 pad_06;
    u8 pad_08[4];
    union {
        u16 offset;         /* 0xc */
        u16 arr1[1];        /* 0xc */
        u16 count;          /* 0xc */
    };
    u16 pad_0e;
    struct Entry02067EB0 entries[]; /* 0xe */
};

struct Rec {
    u16  lo;    /* 0x00 */
    u16  hi;    /* 0x02 */
    u8   pad_04[4];
    struct Rec *next;   /* 0x08 */
};

struct Obj {
    u8          pad_00[0x10];
    struct Rec *chain;  /* 0x10 */
};

extern void func_020698F8(u32 a, void *b);
extern u32 func_02067EB0(struct Struct02067EB0 *tbl, u32 val);
void func_02067F78(void *a, u32 b);
extern u8 func_02069C00[];


u32 func_02067EB0(struct Struct02067EB0 *tbl, u32 val)
{
    u32 ret = 0xFFFF;
    u16 type = tbl->type;

    switch (type) {
    case 0:
        {
            u32 diff = val - tbl->base;
            ret = (u16)(tbl->offset + diff);
        }
        break;
    case 1:
        ret = *(u16 *)((u8 *)tbl + 0xc + (val - tbl->base) * 2);
        break;
    case 2:
        {
            struct Entry02067EB0 *low = (struct Entry02067EB0 *)((u8 *)tbl + 0xe);
            struct Entry02067EB0 *high = low + (tbl->count - 1);

            while (low <= high) {
                struct Entry02067EB0 *mid = low + (high - low) / 2;

                if (mid->key < val) {
                    low = mid + 1;
                } else if (val < mid->key) {
                    high = mid - 1;
                } else {
                    ret = mid->val;
                    break;
                }
            }
        }
        break;
    }

    return ret;
}


/*
 * Blocking class: label.  Every concrete byte is right; both relocation sites are
 * unresolved and both for the same reason: the `bl func_020698F8` at 0x02067F88 is
 * the only branch to 0x020698F8 in the image, and the pool word that stores
 * 0x02069C00 as a value (+0x20) is the only reference to that address anywhere, so
 * neither `label` nor `literal` has a witness outside this file's 32 bytes.
 */
void func_02067F78(void *a, u32 b)
{
    func_020698F8(b, a);
    ((u32 *)a)[1] = (u32)func_02069C00;
}


/*
 * Range lookup over a singly linked list of key records: walk the chain hung
 * off (*a0)->f10 and hand the first record whose [lo, hi] halfword pair
 * contains `key` to func_02067EB0, which returns the mapped word.  No record
 * holds the key: return the pooled 0xFFFF sentinel.  The record's link is at
 * +0x04 (used by the twin at 0x02067FE4) while the chain head here is the
 * +0x10 field of the object the caller's pointer points at.
 *
 * The half-open test is ONE conjunction (`key >= lo && key <= hi`): the
 * original's `ldrhls`/`cmpls` pair is the second comparison issued
 * conditionally on the first, which is a `&&`, not two nested guards.
 */
u32 func_02067F9C(struct Obj **a0, u32 key)
{
    struct Rec *r = (*a0)->chain;

    while (r != 0) {
        if (r->lo <= key && key <= r->hi) {
            return func_02067EB0((struct Struct02067EB0 *)r, key);
        }
        r = r->next;
    }

    return 0xffff;
}
