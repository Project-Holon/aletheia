/*
 * function: func_021BC2F0
 * address:  0x021BC2F0
 * packet:   pkt_021BC2F0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Virtual call through the field at +0 of the object at +0, passing the object and three of its fields plus the two arguments.
 */


void func_021BC2F0(char *p, int a, int b)
{
    void (*fn)(char *, char *, int, int, int, int);

    fn = *(void (**)(char *, char *, int, int, int, int))(*(int *)p + 0xc);
    if (fn != 0)
        fn(p, p + 8, *(int *)(p + 0xc), *(int *)(p + 0x10), a, b);
}

