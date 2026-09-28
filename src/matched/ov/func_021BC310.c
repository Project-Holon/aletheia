/*
 * function: func_021BC310
 * address:  0x021BC310
 * packet:   pkt_021BC310
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Calls the virtual function at +0x10 of the object at +0 when it is set.
 */


typedef void (*Vfn)(char *self, char *a, int b, int c, int d);

void func_021BC310(char *p, int v)
{
    Vfn fn = *(Vfn *)(*(char **)p + 0x10);

    if (fn != 0)
        fn(p, p + 8, *(int *)(p + 0xc), *(int *)(p + 0x10), v);
}

