/*
 * function: func_0200B37C
 * address:  0x0200B37C
 * packet:   pkt_0200B37C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Struct_0200B37C {
    int header;
    int entries[32];
};

void func_0200B37C(struct Struct_0200B37C *p)
{
    int i;
    p->header = -1;
    for (i = 0; i < 32; i++) {
        p->entries[i] = 0;
    }
}
