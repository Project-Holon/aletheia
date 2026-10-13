/*
 * function: SCRCMD_IsItemMachine
 * address:  0x021AF6C4
 * packet:   pkt_ov021_021AF6C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_GetItemMachineFlag  0x021AF750  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRCMD_GetItemMachineFlag(u32 a);

int SCRCMD_IsItemMachine(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = SCRCMD_GetItemMachineFlag(x);
    return 0;
}
