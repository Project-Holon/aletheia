/*
 * function: func_0206380C
 * address:  0x0206380C
 * packet:   pkt_0206380C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct Struct0206380C {
    int pad0;
    int pad4;
    int items[];
} Struct0206380C;

int func_0206380C(const Struct0206380C *ptr, int idx)
{
    return ptr->items[idx] != -1;
}

