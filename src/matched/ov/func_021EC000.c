/*
 * function: func_021EC000
 * address:  0x021EC000
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Release slot i of the 0x9E74 array when it is non-null.
 */


struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
void func_021EC000(char *p, int i, int v)
{
    int x = *(int *)(p + i * 4 + 0x9E74);
    if (x != 0)
        func_0204B3DC((struct Obj *)x, v);
}
