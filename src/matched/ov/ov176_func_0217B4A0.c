/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse
 * address: 0x0217B4A0
 * packet: pkt_ov176_0217B4A0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: stale 0217B550 data label splits its final twelve pool bytes; real next function is separately filed 0217B55C.
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_SetOption 0x0217B93C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone 0x0217B964 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_DrawMenu 0x0217B7D8 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult 0x0217B930 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_HideWindow 0x0217B924 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_FinishMenu 0x0217B970 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse 0x0217B7A0 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuClose 0x0217B55C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1 0x0217B594 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuMain 0x0217B3C0 thumb ov176
 *   APP_ENV_InitParentalControl 0x0202EB44 thumb
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 */
extern void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *,int);
extern int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *,int);
extern unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *,int);
typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse(int *p, int *state, u8 *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(int p, int *state, int *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(int p, int *state, char *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int p, unsigned *state, int *q);
extern int APP_ENV_InitParentalControl(void);
extern void BATTLE_REC_ClearWork(void);
void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p,unsigned *state,int *q)
{
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(q,9); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(q)==1) *state=2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(q,1); *state=3; break;
    case 3:
        result=BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(q);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(APP_ENV_InitParentalControl()==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse);
                else {BATTLE_REC_ClearWork(); BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(q,2);}
                break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuClose); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1); break;
            case 3: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(q);
        }
        break;
    }
}
