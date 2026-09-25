/*
 * function: func_0220AFDC
 * address:  0x0220AFDC
 * packet:   pkt_0220AFDC
 * region:   ov196
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */

extern void func_0204B3DC(void *, void *);

void func_0220AFDC(char *p, void *v)
{
    if (*(void **)(p + 0x14) != v)
    {
        unsigned int i;
        for (i = 0; i < 4; i++)
        {
            func_0204B3DC(*(void **)(p + i * 4), v);
        }
        *(void **)(p + 0x14) = v;
    }
}
