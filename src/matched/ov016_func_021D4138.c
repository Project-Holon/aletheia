/*
 * function: DWC_EnableHotspot
 * address:  0x021D4138
 * packet:   pkt_ov016_021D4138
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MB_CommGetChildUser          0x021F1B64  arm
*/

extern void MB_CommGetChildUser(void);

asm void DWC_EnableHotspot(void)
{
	ldr ip, =MB_CommGetChildUser
	mov r0, #1
	bx ip
}

