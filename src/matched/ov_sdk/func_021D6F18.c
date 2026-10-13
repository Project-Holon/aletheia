/*
 * function: DWCi_OBJlFormGx
 * address:  0x021D6F18
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_OBJlFormGx   0x021D6F18  arm
 *   DWCi_QUElPopBack  0x021D54C4  arm
 *
 * Tail-call DWCi_QUElPopBack with an indexed pointer out of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_OBJlFormGx.c \
 *       --func DWCi_OBJlFormGx --addr 0x021D6F18 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void *DWCi_QUElPopBack(void *queue);

void DWCi_OBJlFormGx(unsigned int i)
{
    char *p = *(char **)0x021DE6A8;
    DWCi_QUElPopBack(*(void **)(p + (i << 2) + 0x800));
}
