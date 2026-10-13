/*
 * function: BUTTON_MAN_SetRow5
 * address:  0x02051A04
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same 12-byte copy as BUTTON_MAN_SetRow2, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SetRow5.c \
 *       --func BUTTON_MAN_SetRow5 --addr 0x02051A04 --cc 1.1p1 --arm
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

void BUTTON_MAN_SetRow5(void *p, struct S12 *q)
{
    struct S12 *r = BUTTON_MAN_FindRowData(p, 5);

    if (r != 0)
        *r = *q;
}
