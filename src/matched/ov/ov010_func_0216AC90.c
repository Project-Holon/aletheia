/*
 * function: SCRCMD_SYMBOL_SelectObjectEntry
 * address:  0x0216AC90
 * packet:   pkt_0216AC90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching INTRUDE_FIELD_GetMmdlParam0 (ov018, EXACT; itself unblocked by
 * FLDMMDL_GetParam): the +0026 call site now attests as `matched`.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   SCRCMD_SYMBOL_GetMmdl  0x0216AED0  thumb  ov010
 *   INTRUDE_FIELD_GetMmdlParam0  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   SCRCMD_SYMBOL_SendEntryFlag  0x0216AF3C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E0B0(void *p);
extern void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id);
extern int INTRUDE_FIELD_GetMmdlParam0(char *a0);
extern int func_0200E18C();
extern void SCRCMD_SYMBOL_SendEntryFlag(int a0);

int SCRCMD_SYMBOL_SelectObjectEntry(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *w;
    void *r;

t5 = a1 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216AC98:
t4 = a0 + 0;
a0 = t5 + 0;
    w = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216ACA0:
    w = GAME_DATA_GetSaveControl(w);
loc_0216ACA4:
    t6 = func_0200E0B0(w);
loc_0216ACA8:
a0 = t5 + 0;
a1 = t4 + 0;
    r = SCRCMD_SYMBOL_GetMmdl((void *)a0, a1);
loc_0216ACB2:
    if (r == 0) goto loc_0216ACC8;
loc_0216ACB6:
    a0 = INTRUDE_FIELD_GetMmdlParam0(r);
loc_0216ACBA:
a1 = a0 + 0;
    a0 = func_0200E18C(t6, a1);
loc_0216ACC2:
a0 = t5 + 0;
    SCRCMD_SYMBOL_SendEntryFlag(a0);
loc_0216ACC8:
a0 = 0;
    return a0;}
