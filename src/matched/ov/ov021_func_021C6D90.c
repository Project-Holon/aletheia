/*
 * function: FIELD_TASK_MANAGER_Update
 * address:  0x021C6D90
 * packet:   pkt_ov021_021C6D90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TASK_MANAGER_UpdateSlot  0x021C6E94  thumb  ov021
 *   FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone  0x021C6EA8  thumb  ov021
 *   FIELD_TASK_MANAGER_FreeSlotIfFinished  0x021C6EDC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_TASK_MANAGER_UpdateSlot(u8 *p, u8 i);
extern void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(u8 *p, u8 i);
extern void FIELD_TASK_MANAGER_FreeSlotIfFinished(u8 *p, u8 i);

void FIELD_TASK_MANAGER_Update(u8 *p)
{
    int i;

    for (i = 0; i < p[0]; i++)
        FIELD_TASK_MANAGER_UpdateSlot(p, i);
    for (i = 0; i < p[0]; i++)
        FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(p, i);
    for (i = 0; i < p[0]; i++)
        FIELD_TASK_MANAGER_FreeSlotIfFinished(p, i);
}
