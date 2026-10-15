/*
 * function: SCRCMD_SYMBOL_MoveObjectEntryToPairedBand
 * address:  0x0216ACCC
 * packet:   pkt_0216ACCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching INTRUDE_FIELD_GetMmdlParam0 (ov018, EXACT; itself unblocked by
 * FLDMMDL_GetParam): the +0032 call site now attests as `matched`.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   SCRCMD_SYMBOL_GetMmdl  0x0216AED0  thumb  ov010
 *   INTRUDE_FIELD_GetMmdlParam0  0x0217C294  thumb  ov018
 *   SYMBOL_MAP_MoveRecordToPairedBand  0x0216628C  thumb  ov010
 *   SCRCMD_SYMBOL_SendEntryFlag  0x0216AF3C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBlock(void *p);
extern void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id);
extern int INTRUDE_FIELD_GetMmdlParam0(char *a0);
extern int SYMBOL_MAP_MoveRecordToPairedBand(u32 *obj, u32 slot);
extern void SCRCMD_SYMBOL_SendEntryFlag(int a0);

int SCRCMD_SYMBOL_MoveObjectEntryToPairedBand(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    int t7;
    void *w;
    void *r;
    u16 *q;

t4 = a0 + 0;
t5 = a1 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216ACD6:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t5 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0216ACE0:
a0 = t5 + 0;
    w = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216ACE8:
    w = GAME_DATA_GetSaveControl(w);
loc_0216ACEC:
    t6 = SYMBOL_SAVE_GetBlock(w);
loc_0216ACF0:
a0 = t5 + 0;
a1 = t7 + 0;
    r = SCRCMD_SYMBOL_GetMmdl((void *)a0, a1);
loc_0216ACFA:
    if (r == 0) goto loc_0216AD14;
loc_0216ACFE:
    a0 = INTRUDE_FIELD_GetMmdlParam0(r);
loc_0216AD02:
a1 = a0 + 0;
    a0 = SYMBOL_MAP_MoveRecordToPairedBand(t6, a1);
loc_0216AD0A:
*q = a0;
a0 = t5 + 0;
    SCRCMD_SYMBOL_SendEntryFlag(a0);
loc_0216AD12:
    goto loc_0216AD18;
loc_0216AD14:
a0 = 0;
*q = a0;
loc_0216AD18:
a0 = 0;
    return a0;}
