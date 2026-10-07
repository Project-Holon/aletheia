/*
 * file:     unit_021D486C_p01.c
 * unit:     yes
 * function: func_021D4A94, func_021D4AFC, func_021D4B50
 * address:  0x021D4A94
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02075E10  0x02075E10  arm
 *   func_02075E80  0x02075E80  arm
 *   g_021DE66C  0x021DE66C  data
 *   func_0207A78C  0x0207A78C  arm
 *   func_020771B4  0x020771B4  arm
 *   func_021D4B50  0x021D4B50  arm  ov016
 *   FS_NotifyArchiveAsyncEnd     0x02078734  arm
 */
#include "../../matched/include/G_MemArc.h"

typedef unsigned short u16;

extern void func_02075E10(u16 lock_id);
extern void func_02075E80(int id);
extern unsigned long func_0207A78C(void *arc);
extern int func_020771B4(int dma, unsigned long src, void *dst, unsigned long len, void (*cb)(void), void *arg, int async);
extern void func_021D4B50(void);
extern void FS_NotifyArchiveAsyncEnd(void);
int func_021D4A94(int unused, unsigned long cmd);
int func_021D4AFC(void *arc, void *dst, unsigned long pos, unsigned long size);
asm void FATFS_FormatDrive(void);
extern struct MemArc *g_021DE66C;


int func_021D4A94(int unused, unsigned long cmd)
{
	switch (cmd) {
	case 9:
		func_02075E10(*(unsigned short *)(((char *)g_021DE66C) + 0xe4));
		return 0;
	case 10:
		func_02075E80(*(unsigned short *)(((char *)g_021DE66C) + 0xe4));
		return 0;
	case 1:
		return 4;
	default:
		return 0x102;
	}
}


int func_021D4AFC(void *arc, void *dst, unsigned long pos, unsigned long size)
{
	unsigned long base = func_0207A78C(arc);
	func_020771B4(-1, pos + base, dst, size, func_021D4B50, arc, 1);
	return 0x100;
}


asm void FATFS_FormatDrive(void)
{
	ldr ip, =FS_NotifyArchiveAsyncEnd
	mov r1, #0
	bx ip
}
