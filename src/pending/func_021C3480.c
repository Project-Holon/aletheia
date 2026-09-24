/*
 * function: func_021C3480
 * address:  0x021C3480
 * packet:   pkt_021C3480
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)

 * BLOCKED.  Unverifiable: func_020065D8 resolves only through the `matched` class and layout/matched/ov093 holds func_021B911C in two shards, which aborts every manifest load.
 */


extern int func_02006650(int);
extern void func_020065D8(int);

void func_021C3480(int unused, char *p)
{
    int v;

    if (*(int *)(p + 0x68) != 0) {
        v = func_02006650(*(int *)(p + 0x68));
        if (v != 0)
            func_020065D8(v);
        *(int *)(p + 0x68) = 0;
    }
    *(unsigned short *)(p + 0x74) = 0;
}

