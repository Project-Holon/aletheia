/*
 * function: BACKUP_SYSTEM_CheckFlashAsync
 * address:  0x020334B0
 * packet:   pkt_020334B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FLASH_ACCESS_PollWrite  0x020337B8  arm
 *
 * Tail-call accessor, the sibling of BACKUP_SYSTEM_WriteFlash: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r1 plus that word
 * as the third argument of FLASH_ACCESS_PollWrite.  The loaded word lands in r2
 * (not r3 like BACKUP_SYSTEM_WriteFlashAsync), which is what fixes the arity at three.
 * Unlabelled in the listing (it saves no lr), so it is invisible to
 * `sole-ref/code` until this entry exists; it is the witness that
 * unblocks the thumb caller SAVE_OUTSIDE_WriteAsync.
 */

extern void FLASH_ACCESS_PollWrite(int, int, int);
void BACKUP_SYSTEM_CheckFlashAsync(int a0, int a1){ FLASH_ACCESS_PollWrite((int)a0, (int)a1, (int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520))); }
