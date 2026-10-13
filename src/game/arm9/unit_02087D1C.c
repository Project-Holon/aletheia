/*
 * file:     unit_02087D1C.c
 * function: OSi_GetOwnerInfoExBuffer
 * address:  0x02087D1C
 * packet:   pkt_02087D1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Return the address of the object at 0x020A5CE8.  Unlabelled ARM leaf in
 * the ARM9 listing; matched so overlay callers get a `matched` witness.
 *
 * symbols:
 *   g_020A5CE8  0x020A5CE8  data  a4
 */

extern char g_020A5CE8[];

char *OSi_GetOwnerInfoExBuffer(void)
{
    return g_020A5CE8;
}
