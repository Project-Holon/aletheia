/*
 * function: BUTTON_MAN_SetRow2
 * address:  0x020519C4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies a 12-byte record into the slot BUTTON_MAN_FindRowData hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SetRow2.c \
 *       --func BUTTON_MAN_SetRow2 --addr 0x020519C4 --cc 1.1p1 --arm
 *
 * symbols:
 *   BUTTON_MAN_FindRowData  0x020518AC  arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern void *BUTTON_MAN_FindRowData(void *obj, int kind);

void BUTTON_MAN_SetRow2(void *p, struct S12 *q)
{
    struct S12 *r = BUTTON_MAN_FindRowData(p, 2);

    if (r != 0)
        *r = *q;
}
