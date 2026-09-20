/*
 * function: func_02036640
 * address:  0x02036640
 * packet:   pkt_02036640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct Struct_02036640 {
    char pad[4];
    int f4;
    char pad8[4];
    short fc;
    short fe;
} Struct_02036640;

int func_02036640(const Struct_02036640 *p)
{
    int fc = p->fc;
    int fe = p->fe;
    int x;
    if (fc > fe) {
        x = p->f4 + p->fe;
    } else {
        x = p->fe;
    }
    return p->f4 - (x - fc);
}
