/*
 * function: func_0204EE0C
 * address:  0x0204EE0C
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204EE0C.c \
 *       --func func_0204EE0C --addr 0x0204EE0C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem_0204EE0C {
    u32 field0;
    u8 pad[0x14 - 4];
    u32 field14;
    u8 pad2[0x28 - 0x18];
};

struct Struct_0204EE0C {
    u8 pad[4];
    struct Elem_0204EE0C *items;
    u8 pad2[0xc - 8];
    u16 count;
};

int func_0204EE0C(struct Struct_0204EE0C *p, int *out_index)
{
    int i;
    u16 count = p->count;

    for (i = 0; i < count; i++) {
        struct Elem_0204EE0C *elem = &p->items[i];
        if (elem->field0 == 0 && elem->field14 == 5) {
            *out_index = i;
            return 1;
        }
    }

    *out_index = 0;
    return 0;
}
