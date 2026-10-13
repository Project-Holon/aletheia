/*
 * function: PALANM_GetDefaultWork
 * address:  0x02021728
 * packet:   pkt_02021728
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
int PALANM_GetDefaultWork(char *p, int i)
{
    return *(int *)(p + i * 0x14);
}
