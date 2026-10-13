/*
 * function: DWCi_KB10lEnd
 * address:  0x021BF6B0
 * packet:   pkt_021BF6B0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KB10lEnd 0x021BF6B0 arm
 *   DWCi_TSKlSetParam  0x021D771C  arm
 *   DWCi_CELLlDelete  0x021D4F60  arm
 *
 * Feed the two words at +0x58 and +0x5c of the object behind 0x021DE560 to the library.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void DWCi_CELLlDelete(u8 *p);
extern void DWCi_TSKlSetParam(char *p, unsigned int v);

void DWCi_KB10lEnd(void)
{
    DWCi_CELLlDelete((u8 *)(*(int *)(*(char **)0x021DE560 + 0x58)));
    DWCi_TSKlSetParam((char *)(*(int *)(*(char **)0x021DE560 + 0x5c)), (unsigned int)((void *)0x021C0528));
}
