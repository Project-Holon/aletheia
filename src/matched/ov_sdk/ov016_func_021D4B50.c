/*
 * function: FATFS_FormatDrive
 * address:  0x021D4B50
 * packet:   pkt_ov016_021D4B50
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_NotifyArchiveAsyncEnd     0x02078734  arm
*/

extern void FS_NotifyArchiveAsyncEnd(void);

asm void FATFS_FormatDrive(void)
{
	ldr ip, =FS_NotifyArchiveAsyncEnd
	mov r1, #0
	bx ip
}

