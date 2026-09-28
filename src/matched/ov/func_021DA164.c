/*
 * function: func_021DA164
 * address:  0x021DA164
 * packet:   pkt_021DA164
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021DA164(void *p)
{
    unsigned char *b = (unsigned char *)p;
    int i;

    for (i = 0; i < *(int *)(b + 0x23c); i++)
    {
        if (i >= *(int *)(b + 0x248) && i < *(int *)(b + 0x24c))
            *(int *)(b + i * 0x1c + 8) = 1;
        else
            *(int *)(b + i * 0x1c + 8) = 0;
    }
}
