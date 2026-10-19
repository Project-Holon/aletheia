/*
 * function: SCRCMD_WORK_CmdCheckMiscByte
 * address: 0x0215B158
 * packet: pkt_ov010_0215B158
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_GetSlotState 0x0200C308 thumb
 */
typedef unsigned short u16;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Blk34;
extern void *GAME_DATA_GetMiscSave(int *p);
extern u8 MISC_GetSlotState(struct Blk34 *p, u32 i);
int SCRCMD_WORK_CmdCheckMiscByte(int a,int b)
{
    int k = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a,(void *)b);
    if (MISC_GetSlotState(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData((void *)b)),k) == 3) *out = 1; else *out = 0;
    return 0;
}
