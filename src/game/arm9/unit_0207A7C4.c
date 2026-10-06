/*
 * file:     unit_0207A7C4.c
 * unit:     yes
 * function: FSi_MemArchiveProc, func_0207A890, func_0207A940
 * address:  0x0207A7C4
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
 *   func_02078530 0x02078530 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_mem_init  0x02150D40  data
 *   fsi_arc_mem  0x02150D44  data
 *   FSi_InitMemArchive  0x0207A890  arm
 *   FS_OpenFileDirect  0x02078964  arm
 */
typedef unsigned char u8;

typedef unsigned long u32;

typedef int BOOL;

typedef struct FSFile FSFile;

typedef struct FSArchive
{
    u8 pad00[0x14];
    u32 flag;
} FSArchive;

typedef struct FSArchive FSArchive;

extern void func_02078530(void);
extern void func_0208CC78(void);
extern void func_0208D7E0(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void FS_InitArchive(FSArchive *p_arc);
extern void FS_SetArchiveProc(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                           int (*read_func)(FSArchive *, void *, u32, u32),
                           int (*write_func)(FSArchive *, void *, u32, u32));
extern void OS_Terminate(void);
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
asm int FSi_MemArchiveProc(FSFile *p_file, u32 cmd);
void func_0207A890(void);
BOOL func_0207A940(FSFile *p_file, void *buf, u32 size);
extern BOOL fsi_mem_init;
extern FSArchive fsi_arc_mem;

asm int FSi_MemArchiveProc(FSFile *p_file, u32 cmd)
{
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    cmp r1, #6
    addls pc, pc, r1, lsl #2
    b loc_default

    b loc_default
    b loc_default
    b loc_ret4
    b case_3
    b loc_ret4
    b loc_ret4
    b loc_ret4

case_3:
    ldr r5, [r6, #0x28]
    ldr r4, [r6, #0x30]
    cmp r5, #0
    moveq r0, #0
    streq r0, [r4, #0x10]
    streq r0, [r4, #0xc]
    moveq r0, #1
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r5
    bl func_02078530
    mov r7, r0
    bl func_0208CC78
    add r0, r0, #1
    str r0, [r4, #0x10]
    mov r0, #1
    str r0, [r4, #0xc]
    ldr r0, [r6, #0x34]
    cmp r0, #0
    bne loc_nonzero
    ldr r1, [pc, #0x40]
    mov r2, r7
    add r0, r4, #0x14
    bl func_0208D7E0
    ldr r1, [r6, #8]
    mov r0, #0
    str r1, [r4]
    strh r0, [r4, #4]
    strh r0, [r4, #6]
    str r0, [r4, #8]

loc_nonzero:
    ldr r1, [r5, #4]
    mov r0, #0
    str r1, [r6, #0x28]
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

loc_ret4:
    mov r0, #4
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

loc_default:
    ldr r0, [pc, #4]
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

    dcd 0x020A84AC
    dcd 0x00000102
}

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

/*
 * sdk:      FSi_InitMemArchive (libfs.TWL.HYB.a fs_proc_mem.o)
 */
void func_0207A890(void)
{
    u32 bak_cpsr = OS_DisableInterrupts();

    if (!fsi_mem_init || !FS_IsArchiveLoaded(&fsi_arc_mem))
    {
        FS_InitArchive(&fsi_arc_mem);
        FS_SetArchiveProc(&fsi_arc_mem, FSi_MemArchiveProc, 0xFFFFFFFF);
        if (!FS_LoadArchive(&fsi_arc_mem, 0, 0, 0, 0, 0, 0, 0))
        {
            OS_Terminate();
        }
        fsi_mem_init = 1;
    }
    (void)OS_RestoreInterrupts(bak_cpsr);
}

/*
 * sdk:      FS_CreateFileFromMemory (libfs.TWL.HYB.a fs_proc_mem.o)
 */
BOOL func_0207A940(FSFile *p_file, void *buf, u32 size)
{
    func_0207A890();
    return FS_OpenFileDirect(p_file, &fsi_arc_mem, (u32)buf, (u32)buf + size, 0);
}
