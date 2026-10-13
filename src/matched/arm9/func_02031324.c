/*
 * function: PROCSYS_Create
 * address:  0x02031324
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_CreateInternal  0x02031354  arm
 */

extern void *PROCSYS_CreateInternal(int a0);

void *PROCSYS_Create(int a0)
{
    return PROCSYS_CreateInternal(a0);
}
