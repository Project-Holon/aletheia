/*
 * function: func_022135CC
 * address: 0x022135CC
 * packet: pkt_ov199_022135CC
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 */
extern int func_0201AA18(void *);
void func_022135CC(unsigned char *p, unsigned char *a, unsigned char *b)
{
    int i, index, j, count;
    int side, flags;
    i = 0;
    flags = p[0x21];
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            count = func_0201AA18(*(void **)(p + 0x24 + index * 4));
            for (j = 0; j < count; j++) {
                if (p[0xc8 + index * 6 + j] != 2)
                    (*a)++;
            }
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            count = func_0201AA18(*(void **)(p + 0x24 + index * 4));
            for (j = 0; j < count; j++) {
                if (p[0xc8 + index * 6 + j] != 2)
                    (*b)++;
            }
        }
    }
}
