/*
 * function: func_02209C18
 * address:  0x02209C18
 * packet:   pkt_ov094_02209C18
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_02209C18(char *p)
{
    if (*(void **)(p + 4) != 0) {
        func_0204B3B4(*(void **)(p + 4));
        *(void **)(p + 4) = 0;
    }
}
