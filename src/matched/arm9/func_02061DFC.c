/*
 * function: NNSi_GfdInitBlockPool
 * address:  0x02061DFC
 * packet:   pkt_02061DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types, ret-var): the function
 *           returns the array pointer it was given; the void version freed r0 too early (2 bytes)
 *
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node02061DFC {
    u32 data0;                 /* 0x0 */
    u32 data1;                 /* 0x4 */
    struct Node02061DFC *prev; /* 0x8 */
    struct Node02061DFC *next; /* 0xc */
};

struct Node02061DFC *NNSi_GfdInitBlockPool(struct Node02061DFC *arr, u32 count)
{
    u32 last = count - 1;
    u32 i = 0;
    u32 *end;

    if (last != 0) {
        struct Node02061DFC *p = arr;
        do {
            struct Node02061DFC *next_node = &arr[i + 1];
            arr[i].next = next_node;
            (&arr[i])[1].prev = p;
            i++;
            p++;
        } while (i < last);
    }

    arr[0].prev = 0;
    end = (u32 *)&arr[count];
    end[-1] = 0;
    return arr;
}
