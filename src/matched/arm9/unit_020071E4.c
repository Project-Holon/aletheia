/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020071E4
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SAVE_CONTROL_IsNewGame, SAVE_CONTROL_GetLoadFlags, SAVE_CONTROL_HasFlashSave, SAVE_CONTROL_WouldOverwriteSave,
 *           SAVE_CONTROL_GetOutsideSaveLoaded, SAVE_CONTROL_SetOutsideSaveLoaded, SAVE_CONTROL_GetOutsideSaveBroken, SAVE_CONTROL_SetOutsideSaveBroken,
 *           SAVE_CONTROL_ResetToNewGame, SAVE_CONTROL_EraseMainSave, SAVE_CONTROL_GetDiffSize
 *
 * symbols:
 *   BACKUP_SYSTEM_ClearWork    0x020319C0  arm
 *   BACKUP_SYSTEM_Erase    0x020319F0  arm
 *   BACKUP_SYSTEM_GetDiffSize  0x020319E4  arm
 *
 * Eleven accessors on the save_control block, and eight of the eleven carry
 * no label at all: they are two and three instruction bodies ending in
 * `bx lr` or in a pool word and a `bx`, so the generated listing prints them
 * as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  The run was
 * read out of the bytes and the section map that `tu` prints is what checks
 * the boundaries.
 *
 * SAVE_CONTROL_GetDiffSize tail-calls through 0x020319E4, which is a linker veneer and
 * not a function: the twelve bytes there are `ldr ip, [pc, #0]; bx ip` and a
 * pointer word.  The extern is therefore declared at the veneer's address
 * and marked `arm`, which is also the name disasm.py gives it in the
 * listing; see
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * The range is cut where it is for evidence rather than for structure.  Two
 * twelve byte functions of exactly the same shape sit just below it, at
 * 0x020071C0 and 0x020071D8, and tail-call 0x02031E68 and 0x02031994; both
 * of those are ARM bodies with no register-saving prologue, so disasm.py
 * never labelled them, and each is named by exactly one word in the image,
 * the pool word of its own caller.  `literal` discards a witness inside the
 * compared range and `label` has no label to read, so neither can be
 * attested at any cut and both functions are left out.  The range stops
 * before 0x02007248 for the same reason: that function's only external
 * reference is the ARM 0x020334E8 and its only `blx` anywhere in the image
 * is the one inside it, so the witness is the call itself.
 *
 * The one near miss above this range is sub_02006F20, the constructor, 336
 * bytes at 0x02006F20.  It calls four addresses in overlay space, 0x021DFC20,
 * 0x021DFE90, 0x021DFE98 and 0x021DFDB8, and none of them is attestable: the
 * cross-region index knows the branches, but `attest_overlay_label` also
 * demands that some overlay's own listing carry a `func_` label at the
 * address, and no overlay labels any of the four.  0x021DFDB8 is the case
 * docs/MATCHING.md already records, inside seven overlays and labelled by
 * none of them.  Nothing about the C is in question and no cut helps, since
 * the targets are outside the region entirely.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020071E4Ctrl {
    u8    unk00;
    u8    unk01;
    u8    unk02;
    u8    unk03;
    u8    unk04;
    u8    unk05;
    u8    pad06[6];
    u32   unk0C;
    void *unk10;
    void *unk14[9];
};

extern void *BACKUP_SYSTEM_ClearWork(void *p);
struct Job;
extern int BACKUP_SYSTEM_Erase(struct Job *job, u32 heap);
extern void *BACKUP_SYSTEM_GetDiffSize(void *p);

u8 SAVE_CONTROL_IsNewGame(const struct Sub020071E4Ctrl *ctrl)
{
    return ctrl->unk00;
}

u32 SAVE_CONTROL_GetLoadFlags(const struct Sub020071E4Ctrl *ctrl)
{
    return ctrl->unk0C;
}

u8 SAVE_CONTROL_HasFlashSave(const struct Sub020071E4Ctrl *ctrl)
{
    return ctrl->unk01;
}

int SAVE_CONTROL_WouldOverwriteSave(struct Sub020071E4Ctrl *ctrl)
{
    if (SAVE_CONTROL_IsNewGame(ctrl) == 1 && SAVE_CONTROL_HasFlashSave(ctrl) == 1) {
        return 1;
    }
    return 0;
}

u8 SAVE_CONTROL_GetOutsideSaveLoaded(const struct Sub020071E4Ctrl *ctrl)
{
    return ctrl->unk04;
}

void SAVE_CONTROL_SetOutsideSaveLoaded(struct Sub020071E4Ctrl *ctrl, u8 v)
{
    ctrl->unk04 = v;
}

u8 SAVE_CONTROL_GetOutsideSaveBroken(const struct Sub020071E4Ctrl *ctrl)
{
    return ctrl->unk05;
}

void SAVE_CONTROL_SetOutsideSaveBroken(struct Sub020071E4Ctrl *ctrl, u8 v)
{
    ctrl->unk05 = v;
}

void *SAVE_CONTROL_ResetToNewGame(struct Sub020071E4Ctrl *ctrl)
{
    ctrl->unk00 = 1;
    ctrl->unk02 = 1;
    return BACKUP_SYSTEM_ClearWork(ctrl->unk10);
}

void *SAVE_CONTROL_EraseMainSave(struct Sub020071E4Ctrl *ctrl)
{
    return (void *)BACKUP_SYSTEM_Erase(ctrl->unk10, 1);
}

void *SAVE_CONTROL_GetDiffSize(struct Sub020071E4Ctrl *ctrl)
{
    return BACKUP_SYSTEM_GetDiffSize(ctrl->unk10);
}
