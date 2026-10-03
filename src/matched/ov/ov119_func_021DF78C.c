/*
 * function: func_021DF78C
 * address:  0x021DF78C
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Init the four sub-objects when the object is in the first state.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E6718  0x021E6718  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void func_021E6718(char *p, int i);

void func_021DF78C(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E6718(p, i);
}

