/*
 * function: func_02067EB0
 * address:  0x02067EB0
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

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
