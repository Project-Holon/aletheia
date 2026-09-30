/*
 * function: func_021DD3D4
 * address: 0x021DD3D4
 * packet: pkt_ov119_021DD3D4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Spell the indexed object base at each field read; a cached q local
 * swaps the first-loop counter and pooled-offset registers (10 bytes).
 */
int func_021DD3D4(const char *p, int n, int a, int b)
{
    int j;
    long i;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + n * 12 + 0xfa4 + i * 4) == a &&
            *(int *)(p + n * 12 + 0xfbc + i * 4) == b)
            return -1;
    }
    for (j = 0; j < 3; j++) {
        if (*(int *)(p + n * 12 + 0xfa4 + j * 4) == -1)
            return j;
    }
    return 2;
}
