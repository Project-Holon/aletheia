/*
 * file:     unit_0207A980_p01.c
 * unit:     yes
 * function: func_0207A980, func_0207A9C8, func_0207A9EC, FSi_RomArchiveProc
 * address:  0x0207A980
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FS_GetArchiveName                0x02078530 arm
 *   STD_CompareString                0x0208cd94 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   CARD_GetOwnRomHeader             0x02075df8 arm
 *   g_020A84B0                       0x020a84b0 data
 *   CARD_IsPulledOut                 0x020774b0 arm
 *   FS_NotifyArchiveAsyncEnd         0x02078734 arm
 *   CARDi_ReadRom                    0x020771b4 arm
 *   FSi_OnRomReadDone                0x0207a9c8 arm
 *   fsi_default_dma_no               0x02150da0 data
 *   func_02075E10 0x02075E10 arm
 *   func_02075E80 0x02075E80 arm
 *   func_0207A980 0x0207A980 arm
 *   g_02150DA0 0x02150DA0 data
 */
typedef struct FSArchive FSArchive;

typedef struct CARDRomHeader {
    unsigned char head[0x92];
    unsigned short twl_ltd_area_rom_offset;
} CARDRomHeader;

typedef enum FSResult {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_PROC_ASYNC = 0x100
} FSResult;

typedef unsigned short u16;

extern char *func_02078530(FSArchive *arc);
extern int func_0208CD94(const char *str1, const char *str2);
extern int OS_IsRunOnTwl(void);
extern void *func_020774B0(void);
extern void func_02078734(FSArchive *arc, FSResult ret);
extern void CARDi_ReadRom(unsigned long dma, const void *src, void *dst, unsigned long len,
                          void (*callback)(void *), void *arg, int is_async);
extern void func_0207A9C8(void *arg);
extern void func_02075E10(u16 lock_id);
extern void func_02075E80(void);
asm int FSi_RomArchiveProc(void *p_file, int cmd);
extern unsigned long fsi_default_dma_no;
extern int g_02150DA0;

extern const char g_020A84B0[]; /* "rom", the vendor object's @12296 */
extern CARDRomHeader *CARD_GetOwnRomHeader(void);

/*
 * sdk:      FSi_IsUnreadableRomOffset (fs_proc_rom.o)
 */
int func_0207A980(FSArchive *arc, unsigned long offset)
{
    int result = 0;

    if (func_0208CD94(func_02078530(arc), g_020A84B0) == 0 && !OS_IsRunOnTwl()) {
        CARDRomHeader *header = CARD_GetOwnRomHeader();
        if (offset >= (unsigned long)header->twl_ltd_area_rom_offset * 0x80000) {
            result = 1;
        }
    }
    return result;
}

/*
 * sdk:      FSi_OnRomReadDone (fs_proc_rom.o)
 */
static void func_0207A9C8(void *arg)
{
    func_02078734((FSArchive *)arg, func_020774B0() ? FS_RESULT_ERROR : FS_RESULT_SUCCESS);
}

/*
 * sdk:      FSi_ReadRomCallback (fs_proc_rom.o)
 */
static FSResult func_0207A9EC(FSArchive *p_arc, void *dst, unsigned long src, unsigned long len)
{
    CARDi_ReadRom(fsi_default_dma_no, (const void *)src, dst, len, func_0207A9C8, p_arc, 1);
    return FS_RESULT_PROC_ASYNC;
}

asm int FSi_RomArchiveProc(void *p_file, int cmd)
{
    stmfd sp!, {r3, lr}
    mov r2, r0
    cmp r1, #0xa
    addls pc, pc, r1, lsl #2
    b loc_default

    b loc_default
    b loc_ret4
    b loc_default
    b loc_default
    b loc_default
    b loc_default
    b loc_default
    b case_7
    b loc_default
    b case_9
    b case_10

case_9:
    ldr r0, [pc, #0x5c]
    ldr r0, [r0, #4]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl func_02075E10
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_10:
    ldr r0, [pc, #0x40]
    ldr r0, [r0, #4]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl func_02075E80
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_7:
    ldr r0, [r2, #8]
    ldr r1, [r2, #0x30]
    bl func_0207A980
    cmp r0, #0
    movne r0, #9
    ldreq r0, [pc, #0x14]
    ldmfd sp!, {r3, pc}

loc_ret4:
    mov r0, #4
    ldmfd sp!, {r3, pc}

loc_default:
    ldr r0, [pc, #8]
    ldmfd sp!, {r3, pc}

    dcd g_02150DA0
    dcd 0x00000101
    dcd 0x00000102

    mov r0, #4
    cmp r1, #1
    ldrne r0, [pc]
    bx lr
    dcd 0x00000102

    mov r0, #4
    bx lr

    mov r0, #4
    bx lr
}
