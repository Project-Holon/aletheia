/*
 * function: DWCi_Http_Resolve
 * address:  0x021798E4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0x1124 of the object.
 *
 * symbols:
 *   CPS_Resolve  0x0215C910  arm
 */

extern unsigned long CPS_Resolve(char *name);

typedef unsigned int   u32;
u32 DWCi_Http_Resolve(const char *p)
{
    return CPS_Resolve((char *)(*(const int *)(p + 0x1124)));
}

