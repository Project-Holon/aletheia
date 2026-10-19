/*
 * file:     gimmick.c
 * unit:     yes
 * function: GIMMICK_WORK_GetSize, GIMMICK_WORK_Init, GIMMICK_WORK_Reset, GIMMICK_WORK_InitWithId, GIMMICK_WORK_GetWork, GIMMICK_WORK_GetSubWork, GIMMICK_WORK_GetId, GIMMICK_WORK_Save, GIMMICK_WORK_Load
 * address:  0x0200B364
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "battle_rec_types.h"
#include "../types.h"

/* Save block 0x30: the field gimmick work.  The id says which gimmick owns the
 * two work areas; -1 is none. */
struct GimmickWork {
    s32 id;
    s32 work[32];
    u8  subWork[0x10];
};

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void MIi_CpuCopy32(const void *src, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

u32 GIMMICK_WORK_GetSize(void);

void GIMMICK_WORK_Init(struct GimmickWork *gimmick);

void GIMMICK_WORK_Reset(struct GimmickWork *gimmick);

s32 *GIMMICK_WORK_InitWithId(struct GimmickWork *gimmick, s32 id);

s32 *GIMMICK_WORK_GetWork(struct GimmickWork *gimmick, u32 id);

u8 *GIMMICK_WORK_GetSubWork(struct GimmickWork *gimmick, u32 id);

s32 GIMMICK_WORK_GetId(struct GimmickWork *gimmick);

void GIMMICK_WORK_Save(const struct GimmickWork *src, struct SaveControl *save);

void GIMMICK_WORK_Load(struct SaveControl *save, struct GimmickWork *dest);

/*
 * GIMMICK_WORK_GetSize and GIMMICK_WORK_Init open the 0x94-byte gimmick work
 * block (save id 0x30); see src/matched/unit_0200B348.c for the original
 * packet.  They are not recorder code.
 */
u32 GIMMICK_WORK_GetSize(void)
{
    return sizeof(struct GimmickWork);
}

void GIMMICK_WORK_Init(struct GimmickWork *gimmick)
{
    MI_CpuFill8(gimmick, 0, sizeof(struct GimmickWork));
    gimmick->id = -1;
}

void GIMMICK_WORK_Reset(struct GimmickWork *gimmick)
{
    int i;
    gimmick->id = -1;
    for (i = 0; i < 32; i++) {
        gimmick->work[i] = 0;
    }
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           GIMMICK_WORK_Save, GIMMICK_WORK_Load, BATTLE_REC_Create
 *
 * 108 bytes, 0x0200B394..0x0200B400, 7 functions, four of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71C4 spells "battle_rec.c", the third original source file
 * name recovered by this project, attested by the `string` class off the
 * terminator of "regulation.c" at 0x020A71C2.  The constructor at 0x0200B3DC
 * allocates 0x2000 bytes at line 0x67 and hands them to BATTLE_REC_Clear, which
 * is the first function of the next packet.
 *
 * Near miss, and the reason this unit starts at 0x0200B394 rather than
 * 0x0200B37C: GIMMICK_WORK_Reset, 24 bytes, which writes -1 into the first word
 * and then fills a 32-entry array with 0..31.  The original carries one more
 * instruction than any spelling tried here, an `adds r2, r3, #0` that copies
 * the loop counter before the body and lets the increment be scheduled ahead
 * of the store, and it initialises the counter before the -1 store rather
 * than after.  Five loop spellings (for, while, do/while, a separate value
 * variable, a hoisted array pointer) all produce the same eleven
 * instructions in the other order, so the difference is a register the
 * original had a reason to spend and this source does not give it.  Nineteen
 * bytes differ and the size is right to the padding.
 */
s32 *GIMMICK_WORK_InitWithId(struct GimmickWork *gimmick, s32 id)
{
    GIMMICK_WORK_Reset(gimmick);
    gimmick->id = id;
    return gimmick->work;
}

s32 *GIMMICK_WORK_GetWork(struct GimmickWork *gimmick, u32 id)
{
    return gimmick->work;
}

u8 *GIMMICK_WORK_GetSubWork(struct GimmickWork *gimmick, u32 id)
{
    return gimmick->subWork;
}

s32 GIMMICK_WORK_GetId(struct GimmickWork *gimmick)
{
    return gimmick->id;
}

void GIMMICK_WORK_Save(const struct GimmickWork *src, struct SaveControl *save)
{
    MIi_CpuCopy32(src, SAVE_CONTROL_GetBlock(save, 0x30), sizeof(struct GimmickWork));
}

void GIMMICK_WORK_Load(struct SaveControl *save, struct GimmickWork *dest)
{
    MIi_CpuCopy32(SAVE_CONTROL_GetBlock(save, 0x30), dest, sizeof(struct GimmickWork));
}
