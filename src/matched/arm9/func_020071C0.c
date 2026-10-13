/*
 * function: SAVE_CONTROL_GetWrittenSize
 * address:  0x020071C0
 * packet:   pkt_020071C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail-call stub: loads p->field_0x10 and tail-calls BACKUP_SYSTEM_GetWrittenSize.
 * Witness leaf for ov034 REPORT_UpdateSaveAnim.
 *
 * symbols:
 *   BACKUP_SYSTEM_GetWrittenSize 0x02031E68 arm
 */

typedef unsigned int u32;

extern int BACKUP_SYSTEM_GetWrittenSize(const char *ptr);

u32 SAVE_CONTROL_GetWrittenSize(char *p)
{
    return BACKUP_SYSTEM_GetWrittenSize(*(void **)(p + 0x10));
}
