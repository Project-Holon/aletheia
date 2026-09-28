/*
 * unit:     yes
 * address:  0x0201042C
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201042C, func_02010444
 *
 * Two mirror-image four-word functions: set and clear one flag halfword of
 * entry 0xC3 in a table reached through the pointer variable at 0x0214617C's
 * neighbour, 0x021461E0.  0x021461E0 is a plain literal pool word (the same
 * address is loaded by nine other functions in this file's neighbourhood, at
 * 0x020103D4, 0x02010420 and so on), so it needed no relocation resolution,
 * the same situation documented in src/matched/sub_0200F800.c for 0x0214617C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201042C.c \
 *       --addr 0x0201042C --thumb
 */

typedef unsigned short u16;

struct Entry {
    u16 flag;
    u16 pad;
};

void func_0201042C(void)
{
    struct Entry *arr = *(struct Entry **)0x021461E0;
    if (arr != 0) {
        arr[0xC3].flag = 1;
    }
}

void func_02010444(void)
{
    struct Entry *arr = *(struct Entry **)0x021461E0;
    if (arr != 0) {
        arr[0xC3].flag = 0;
    }
}
