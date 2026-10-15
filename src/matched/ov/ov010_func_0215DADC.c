/*
 * function: SCRCMD_MUSICAL_ResetProgramRank
 * address: 0x0215DADC
 * packet: pkt_ov010_0215DADC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetSaveBlock2A 0x02012F44 thumb
 *   MUSICAL_SAVE_GetProgram 0x0200A750 thumb
 */
typedef unsigned char u8;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveBlock2A(void *);
typedef unsigned int   u32;
struct Big;
struct BigSub4;
extern struct BigSub4 *MUSICAL_SAVE_GetProgram(struct Big *p, u32 index);
int SCRCMD_MUSICAL_ResetProgramRank(void *a,void *b)
{
 int i = SCRIPT_WORK_ReadWorkValue(a,b);
 u8 *p = (u8 *)MUSICAL_SAVE_GetProgram(GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(b)), (u8)i);
 p[1] = 0;
 return 0;
}
