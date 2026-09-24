/*
 * function: func_021C51A0
 * address:  0x021C51A0
 * packet:   pkt_021C51A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5078 0x021C5078  thumb  ov208

 * Releases the two handles held at +0 and +4.
 */


extern void func_021C5078(int, int);
extern void func_020307B0(int);

void func_021C51A0(char *p, int a)
{
    if (*(int *)p != 0)
        func_021C5078(a, *(int *)p);
    *(int *)p = 0;
    if (*(int *)(p + 4) != 0)
        func_020307B0(*(int *)(p + 4));
    *(int *)(p + 4) = 0;
}

