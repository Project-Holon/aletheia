/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuMain
 * address: 0x0217B3C0
 * packet: pkt_ov176_0217B3C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_SetOption 0x0217B93C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone 0x0217B964 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_DrawMenu 0x0217B7D8 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult 0x0217B930 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_HideWindow 0x0217B924 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_FinishMenu 0x0217B970 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse 0x0217B4A0 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtra 0x0217B6AC thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm 0x0217B468 thumb ov176
 */
extern void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *,int);
extern int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *,int);
extern unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *,int);
extern void func_021E8AA0(int *p, int v);
typedef unsigned char  u8;
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p, unsigned *state, int *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int p, unsigned *state, int *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(int *p, int *state, u8 *q);
void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int p, unsigned *state, int *q)
{
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(q,0); *state = 1; break;
    case 1: if (BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(q) == 1) *state = 2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(q,0); *state = 3; break;
    case 3:
        result = BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(q);
        if (result != -1) {
            switch (result) {
            case 0: func_021E8AA0((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
            case 1: func_021E8AA0((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra); break;
            case 2: func_021E8AA0((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm); break;
            case 3: BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(q,1); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(q);
        }
        break;
    }
}
