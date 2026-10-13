/*
 * function: DWCi_FNTlDelete
 * address:  0x021D5A2C
 * packet:   pkt_021D5A2C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FNTlDelete 0x021D5A2C arm
 *   DWCi_QUElPushBack  0x021D546C  arm
 *   DWCi_OVRlFree  0x021D71C0  arm
 *
 * Release the word at +0x28 then hand the record to the queue at +0x670.
 * Addresses are Black-image addresses.
 */

extern void DWCi_OVRlFree(void *ovram);
extern void DWCi_QUElPushBack(void *queue, void *data);

void DWCi_FNTlDelete(char *a)
{
    DWCi_OVRlFree((void *)(*(int *)(a + 0x28)));
    DWCi_QUElPushBack((void *)(*(int *)(*(char **)0x021DE680 + 0x670)), a);
}
