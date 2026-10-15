/*
 * function: DIGITALCARDCHECK_Phase3
 * address: 0x0217D964
 * packet: pkt_ov176_0217D964
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DIGITALCARDCHECK_InitRecord 0x0217DC28 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ShowMenu 0x0217DEA4 thumb ov176
 *   DIGITALCARDCHECK_IsInitRecordDone 0x0217DE8C thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   LIVEBATTLEMATCH_IRC_DeleteMenuRecord 0x0217E000 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ToggleSe 0x0217DFF0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_SetMenuValue 0x0217DFD0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetMenuValue 0x0217DFE4 thumb ov176
 *   LIVEBATTLEMATCH_IRC_CreateWindow 0x0217DEDC thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetWindowResult 0x0217DFBC thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeleteWindow 0x0217DFA8 thumb ov176
 *   DIGITALCARDCHECK_IsInitWorkDone 0x0217DE98 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   DIGITALCARDCHECK_EndPhase 0x0217DC20 thumb ov176
 */
extern void DIGITALCARDCHECK_InitRecord(int *);
typedef unsigned char  u8;
extern void LIVEBATTLEMATCH_IRC_ShowMenu(int *p, int a);
extern int DIGITALCARDCHECK_IsInitRecordDone(int *);
typedef unsigned int   u32;
extern u32 KEY_GetTrg(void);
extern void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(int *);
extern int LIVEBATTLEMATCH_IRC_ToggleSe(int, int);
extern void LIVEBATTLEMATCH_IRC_SetMenuValue(int *, int, int);
extern int LIVEBATTLEMATCH_IRC_GetMenuValue(int *);
extern void LIVEBATTLEMATCH_IRC_CreateWindow(char *, int);
extern int LIVEBATTLEMATCH_IRC_GetWindowResult(int *);
extern void LIVEBATTLEMATCH_IRC_DeleteWindow(int *);
extern int DIGITALCARDCHECK_IsInitWorkDone(int *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void DIGITALCARDCHECK_EndPhase(int a);
void DIGITALCARDCHECK_Phase3(int *a, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu((int *)p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3: LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((int)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6D, 1); *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_GetWindowResult(p);
        if (result != -1) {
            LIVEBATTLEMATCH_IRC_DeleteWindow(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)DIGITALCARDCHECK_EndPhase); break;
    }
}
