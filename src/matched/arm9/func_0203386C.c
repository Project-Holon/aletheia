/*
 * function: FLASH_ACCESS_CancelWrite
 * address:  0x0203386C
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 * blocker:  func_02076B98 (label) -- has no witness outside 0203386C..020338B8,
 *           the only branch to it in the image is this function's own call.
 *           Every concrete byte of the body reproduces.
 * symbols:
 *   g_02146998    0x02146998  data
 *   CARD_TryWaitBackupAsync 0x02076B8C  arm
 *   func_02076B98 0x02076B98  arm
 *   CARD_WaitBackupAsync 0x02076B80  arm
 *   func_02075EAC 0x02075EAC  arm
 *   func_02084F10 0x02084F10  arm
 */

typedef unsigned int u32;

extern u32 g_02146998;
extern u32 CARD_TryWaitBackupAsync(void);
extern void func_02076B98(void);
extern void CARD_WaitBackupAsync(void);
extern void func_02075EAC(u32 a);
extern void func_02084F10(u32 a);

void FLASH_ACCESS_CancelWrite(u32 a)
{
    if (CARD_TryWaitBackupAsync() == 0) {
        func_02076B98();
        CARD_WaitBackupAsync();
    }
    if (g_02146998 != 1) {
        return;
    }
    func_02075EAC(a);
    func_02084F10(a);
    g_02146998 = 0;
}
