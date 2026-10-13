/*
 * function: SAVE_CONTROL_GetWorkArea
 * address:  0x020071D8
 * packet:   pkt_020071D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: BACKUP_SYSTEM_GetWork(ctrl->unk10); sibling of SAVE_CONTROL_GetBlock.
 *
 * symbols:
 *   BACKUP_SYSTEM_GetWork  0x02031994  arm
 */

struct Ctrl020071D8 {
    unsigned char pad[16];
    void *unk10;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BACKUP_SYSTEM_GetWork(u8 *p, u32 *out);

void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out)
{
    return (void *)BACKUP_SYSTEM_GetWork(ctrl->unk10, (u32 *)out);
}
