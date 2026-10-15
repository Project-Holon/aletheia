/*
 * file:     flash_access.c
 * unit:     yes
 * function: FLASH_ACCESS_Identify, FLASH_ACCESS_Write, FLASH_ACCESS_Read, FLASH_ACCESS_OnWriteDone, FLASH_ACCESS_StartWrite, FLASH_ACCESS_PollWrite, FLASH_ACCESS_CancelWrite, FLASH_ACCESS_EndAccess, FLASH_ACCESS_GetBusyFlag
 * address:  0x02033534
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from backup_system.c at 0x02033534 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   flash_access_File   0x020A78A0  data
 *   flash_access_LockIdAssert   0x020A78B0  data
 *   OS_GetLockID  0x02084EB8  arm
 *   func_02075E9C  0x02075E9C  arm
 *   func_02076B2C  0x02076B2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   OS_ReleaseLockID  0x02084F10  arm
 *   CARDi_RequestStreamCommand 0x02076AC0  arm
 *   CARD_WaitBackupAsync           0x02076B80  arm
 *   _WriteDone  0x020A789C  data
 *   _AccessBusy     0x02146998  data
 *   func_02075DD8  0x02075DD8  arm
 *   CARD_TryWaitBackupAsync 0x02076B8C  arm
 *   func_02076B98 0x02076B98  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef void (*FlashErrorFunc)(u32 no_response);

extern void func_02034714(const char *file, u32 line, const char *expr);
extern int  OS_GetLockID(u32 lock_arg);
extern void func_02075E9C(u16 lock_id);
extern int  func_02076B2C(int type);
extern void func_02075EAC(u16 lock_id);
extern void OS_ReleaseLockID(u16 lock_id);
extern int  CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void *callback,
                                       void *arg, int is_async, int req_type,
                                       int req_retry, int req_mode);
extern int  CARD_WaitBackupAsync(void);
extern u32  func_02075DD8(void);
extern u32  CARD_TryWaitBackupAsync(void);
extern void func_02076B98(void);
int FLASH_ACCESS_Identify(u32 unused_arg);
u32 FLASH_ACCESS_Write(u32 flash_addr, u32 ram_src, u32 size, u32 on_error);
int FLASH_ACCESS_Read(u32 flash_addr, u32 ram_dst, u32 size, void (*on_error)(void));
void FLASH_ACCESS_OnWriteDone(void);
u16 FLASH_ACCESS_StartWrite(u32 flash_addr, u32 ram_src, u32 size, void *on_error);
int FLASH_ACCESS_PollWrite(u16 lock_id, u32 *success, u32 on_error);
void FLASH_ACCESS_CancelWrite(u16 lock_id);
void FLASH_ACCESS_EndAccess(u16 lock_id, u32 no_response, FlashErrorFunc on_error);
void *FLASH_ACCESS_GetBusyFlag(void);
extern const u8 flash_access_File[];
extern const u8 flash_access_LockIdAssert[];
extern u32 _WriteDone;
extern u32 _AccessBusy;

#define FLASH_PROBE_LEN 4


/*
 * FLASH_ACCESS_Identify: take a lock id, lock the backup device, ask the card
 * layer to identify the backup type, unlock and release the id.  Returns
 * whether identification succeeded (the type word is zeroed on failure).
 * The unused argument is only the leftover first register of the lock-id
 * call; the SDK function takes none.
 */
int FLASH_ACCESS_Identify(u32 unused_arg)
{
    int lock_id = OS_GetLockID(unused_arg);
    u32 type;

    if (lock_id == -3) {
        func_02034714((const char *)flash_access_File, 0x38, (const char *)flash_access_LockIdAssert);
    }
    func_02075E9C((u16)lock_id);
    type = 0x00ff1302;
    if (func_02076B2C(type) == 0) {
        type = 0;
    }
    func_02075EAC((u16)lock_id);
    OS_ReleaseLockID((u16)lock_id);
    return type != 0;
}


/*
 * FLASH_ACCESS_Write: blocking write.  Starts the asynchronous write and
 * spins until the poll function reports completion.  The retry loop is a
 * `while (call(...) == 0) ;` with an uninitialised `success`: zeroing it first
 * costs a `mov r4, #0` + `str r4, [sp]` and 8 bytes of frame the original
 * does not have.
 */
u32 FLASH_ACCESS_Write(u32 flash_addr, u32 ram_src, u32 size, u32 on_error)
{
    u32 success;
    u16 lock_id = FLASH_ACCESS_StartWrite(flash_addr, ram_src, size, (void *)on_error);

    while (FLASH_ACCESS_PollWrite(lock_id, &success, on_error) == 0) {
        ;
    }
    return success;
}


/*
 * FLASH_ACCESS_Read: blocking read of `size` bytes from flash into RAM
 * (request type 6, one retry), then unlock.  Same frame as
 * FLASH_ACCESS_Identify.  The result of the request lands in `result` only
 * after the wait call: mwcc keeps r0 live across a void-returning call and
 * defers the move.  on_error runs when the wait reports failure.
 * The 20-byte leaf that follows in the image (FLASH_ACCESS_OnWriteDone) saves
 * no lr, so disasm.py gives it no label and infers this function as 188 -> 208
 * bytes.
 */
int FLASH_ACCESS_Read(u32 flash_addr, u32 ram_dst, u32 size, void (*on_error)(void))
{
    int lock_id = OS_GetLockID(flash_addr);
    int result;

    if (lock_id == -3) {
        func_02034714((const char *)flash_access_File, 0xa4, (const char *)flash_access_LockIdAssert);
    }
    func_02075E9C((u16)lock_id);
    result = CARDi_RequestStreamCommand(flash_addr, ram_dst, size, 0, 0, 1, 6, 1, 0);
    result = CARD_WaitBackupAsync();
    func_02075EAC((u16)lock_id);
    OS_ReleaseLockID((u16)lock_id);
    if (result == 0 && on_error != 0) {
        on_error();
    }
    return result;
}


/*
 * FLASH_ACCESS_OnWriteDone: DMA completion callback passed by
 * FLASH_ACCESS_StartWrite; raises the flag that StartWrite lowers before the
 * asynchronous request and that FLASH_ACCESS_PollWrite tests.
 */
void FLASH_ACCESS_OnWriteDone(void)
{
    _WriteDone = 1;
}


/*
 * FLASH_ACCESS_StartWrite: take and lock a lock id, probe the device with a
 * synchronous 4-byte read (a failed probe ends the access with
 * no_response = 1), lower the done flag and start the asynchronous write
 * (request type 7, ten retries, mode 2) with FLASH_ACCESS_OnWriteDone as the
 * callback.  Returns the lock id for the poll.  _AccessBusy is raised before
 * the probe.
 */
u16 FLASH_ACCESS_StartWrite(u32 flash_addr, u32 ram_src, u32 size, void *on_error)
{
    int lock_id = OS_GetLockID(flash_addr);
    u32 probe;

    if (lock_id == -3) {
        func_02034714((const char *)flash_access_File, 0xd4, (const char *)flash_access_LockIdAssert);
    }
    func_02075E9C((u16)lock_id);

    _AccessBusy = 1;
    if (CARDi_RequestStreamCommand(0, (u32)&probe, FLASH_PROBE_LEN, 0, 0, 0, 6, 1, 0) == 0) {
        FLASH_ACCESS_EndAccess((u16)lock_id, 1, on_error);
    }

    _WriteDone = 0;
    CARDi_RequestStreamCommand(ram_src, flash_addr, size, FLASH_ACCESS_OnWriteDone, 0, 1, 7, 10, 2);
    return (u16)lock_id;
}


/*
 * FLASH_ACCESS_PollWrite: when the write finished, unlock and release the id
 * and clear _AccessBusy, then map the CARD result code to *success: 0 gives
 * success, 6 (no response) fails and reports no_response = 1 to on_error, every
 * other code fails with no_response = 0.  Returns 1 once finished, 0 while the
 * write is still running.
 */
int FLASH_ACCESS_PollWrite(u16 lock_id, u32 *success, u32 on_error)
{
    if (_WriteDone == 1) {
        func_02075EAC(lock_id);
        OS_ReleaseLockID(lock_id);
        _AccessBusy = 0;

        switch (func_02075DD8()) {
        case 0:
            *success = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        default:
            *success = 0;
            FLASH_ACCESS_EndAccess(lock_id, 0, (FlashErrorFunc)on_error);
            break;
        case 6:
            *success = 0;
            FLASH_ACCESS_EndAccess(lock_id, 1, (FlashErrorFunc)on_error);
            break;
        }
        return 1;
    }
    return 0;
}


/*
 * FLASH_ACCESS_CancelWrite: if the card layer is not idle, cancel the
 * outstanding request and wait for it; then, if an access is still marked
 * busy, unlock, release the lock id and clear _AccessBusy.
 */
void FLASH_ACCESS_CancelWrite(u16 lock_id)
{
    if (CARD_TryWaitBackupAsync() == 0) {
        func_02076B98();
        CARD_WaitBackupAsync();
    }
    if (_AccessBusy != 1) {
        return;
    }
    func_02075EAC(lock_id);
    OS_ReleaseLockID(lock_id);
    _AccessBusy = 0;
}


/*
 * FLASH_ACCESS_EndAccess: error exit: unlock, release the lock id, clear
 * _AccessBusy and report to on_error (when set) whether the device gave no
 * response.
 */
void FLASH_ACCESS_EndAccess(u16 lock_id, u32 no_response, FlashErrorFunc on_error)
{
    func_02075EAC(lock_id);
    OS_ReleaseLockID(lock_id);
    _AccessBusy = 0;
    if (on_error != 0) {
        on_error(no_response);
    }
}


/*
 * FLASH_ACCESS_GetBusyFlag: accessor for _AccessBusy, returned through a
 * pointer-typed result because the callers store it that way.
 */
void *FLASH_ACCESS_GetBusyFlag(void)
{
    return (void *)_AccessBusy;
}
