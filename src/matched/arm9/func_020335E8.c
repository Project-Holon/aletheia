/*
 * function: FLASH_ACCESS_Read
 * address:  0x020335E8
 * packet:   pkt_02033534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * EXACT* rather than EXACT: the follower at 0x020336A4 (20 bytes, an
 * unlabelled leaf holding a two-instruction store and `bx lr` between the
 * pool words) saves no lr, so disasm.py gives no label and the inferred
 * extent runs 188 -> 208.  Every concrete byte of the 188 is identical.
 * Report the follower rather than editing layout/function_starts.txt.
 * symbols:
 *   str_020A78A0            0x020A78A0  data
 *   str_020A78B0            0x020A78B0  data
 *   func_02034714           0x02034714  arm
 *   OS_GetLockID           0x02084EB8  arm
 *   func_02075E9C           0x02075E9C  arm
 *   CARDi_RequestStreamCommand 0x02076AC0  arm
 *   CARD_WaitBackupAsync           0x02076B80  arm
 *   func_02075EAC           0x02075EAC  arm
 *   OS_ReleaseLockID           0x02084F10  arm
 *
 * The result of CARDi_RequestStreamCommand lands in r6 only after the
 * intervening call to the void CARD_WaitBackupAsync: mwcc keeps r0 live across a
 * void-returning call and defers the move.  Same body as FLASH_ACCESS_Identify with
 * a two-function stream instead of CARD_IdentifyBackup.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLASH_ACCESS_Read.c \
 *       --func FLASH_ACCESS_Read --addr 0x020335E8 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 str_020A78A0[];
extern const u8 str_020A78B0[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int  OS_GetLockID(u32 a);
extern void func_02075E9C(u16 a);
extern int  CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void *callback,
                                       void *arg, int is_async, int req_type,
                                       int req_retry, int req_mode);
extern int  CARD_WaitBackupAsync(void);
extern void func_02075EAC(u16 a);
extern void OS_ReleaseLockID(u16 a);

int FLASH_ACCESS_Read(u32 a0, u32 a1, u32 a2, void (*a3)(void))
{
    int id = OS_GetLockID(a0);
    int r;

    if (id == -3) {
        func_02034714((const char *)str_020A78A0, 0xa4, (const char *)str_020A78B0);
    }
    func_02075E9C((u16)id);
    r = CARDi_RequestStreamCommand(a0, a1, a2, 0, 0, 1, 6, 1, 0);
    r = CARD_WaitBackupAsync();
    func_02075EAC((u16)id);
    OS_ReleaseLockID((u16)id);
    if (r == 0 && a3 != 0) {
        a3();
    }
    return r;
}
