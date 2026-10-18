/*
 * function: ZUKAN_LIST_StateMain
 * address: 0x021BCE98
 * packet: pkt_ov209_021BCE98
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ov067 region follows the paired loader path 021BCC94/021BCD48.
 * 021B93D4's value is full width here: original subtract feeds r1 without narrowing.
 * symbols:
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZUKAN_LIST_UpdateArrowActors 0x021BE5D4 thumb ov209
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 *   ZUKAN_LIST_StartButtonAnim 0x021BD2C4 thumb ov209
 *   ZUKAN_LIST_ShowAllActors 0x021BE4A8 thumb ov209
 *   ZUKAN_LIST_HandleTouchInput 0x021BE658 thumb ov209
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   ZUKAN_LIST_IsSpeciesEntryValid 0x021BD2F4 thumb ov209
 *   ZUKAN_LIST_StateSelectSpecies 0x021BD340 thumb ov209
 *   ZUKAN_LIST_StoreLastViewedSpecies 0x021BD314 thumb ov209
 *   ZUKAN_LIST_ToggleSaveFlag15 0x021BD354 thumb ov209
 *   ZUKAN_LIST_UpdateScrollBarActor 0x021BE588 thumb ov209
 *   ZUKAN_LIST_HideAllActors 0x021BE43C thumb ov209
 *   func_020355C4 0x020355C4 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_SetViewMode 0x0200CA5C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Input {u32 a;void *save;u32 b,c,state;};
struct Context {struct Input *in;u8 pad4[0x10];u32 state;u8 pad18[0xc24-0x18];u16 flags;u8 padc26[6];void *list;};
struct Blk37;
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern void ZUKAN_LIST_UpdateArrowActors(char *p, int flag);
extern void ZUKAN_LIST_StartActorAnim(char *p, int idx, int value);
extern int ZUKAN_LIST_StartButtonAnim(char *p, int a, int b, int c);
extern void ZUKAN_LIST_ShowAllActors(char *p);
extern int ZUKAN_LIST_HandleTouchInput(void *ctx_);
extern int FRAME_LIST_GetSelectedIndex(char *p);
extern int FRAME_LIST_GetScrollPos(char *p);
extern void FRAME_LIST_SetCursor(struct S *s, int v);
extern int ZUKAN_LIST_IsSpeciesEntryValid(char *p, int i);
extern int ZUKAN_LIST_StateSelectSpecies(char *a, int arg);
extern void ZUKAN_LIST_StoreLastViewedSpecies(char *p, int i);
extern void ZUKAN_LIST_ToggleSaveFlag15(char *p);
extern void ZUKAN_LIST_UpdateScrollBarActor(char *p);
extern void ZUKAN_LIST_HideAllActors(char *p);
extern u8 func_020355C4(void);
extern void UI_SetInputMode(u8);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern void ZUKAN_SAVE_SetViewMode(struct Blk37 *p, u32 v);
int ZUKAN_LIST_StateMain(struct Context *p)
{
    int result=4;
    int selected;
    u32 action;
    u8 old;
    switch(FRAME_LIST_Update(p->list)){
    case -12: break;
    case -11:case -10:case -9:case -8:
        ZUKAN_LIST_UpdateArrowActors((char *)p,0);break;
    case -7:
        ZUKAN_LIST_StartActorAnim((char *)p,7,12);
        p->flags=(p->flags&~0xfffe)|14;p->state=0;result=5;break;
    case -6:
        ZUKAN_LIST_StartActorAnim((char *)p,6,13);
        p->flags=(p->flags&~0xfffe)|12;p->state=0;result=5;break;
    case -5:return ZUKAN_LIST_StartButtonAnim((char *)p,7,12,4);
    case -4:return ZUKAN_LIST_StartButtonAnim((char *)p,6,13,4);
    case -3:case -2:
        ZUKAN_LIST_ShowAllActors((char *)p);
        p->flags=(p->flags&~0xfffe)|120;p->state=1;result=5;break;
    case -1:
        old=func_020355C4();
        action=ZUKAN_LIST_HandleTouchInput(p);
        switch(action){
        case 0:
            selected=FRAME_LIST_GetSelectedIndex(p->list);
            if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);}
            UI_SetInputMode(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+FRAME_LIST_GetScrollPos(p->list)-1;
            if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){
                GFL_USE_PlaySeDefaultVolume(1356);FRAME_LIST_SetCursor(p->list,action-1);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);
            }break;
        case 8:
            GFL_USE_PlaySeDefaultVolume(1356);p->in->state=4;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,9,4,8);
        case 9:
            GFL_USE_PlaySeDefaultVolume(1356);
            if(ZUKAN_SAVE_GetViewMode(p->in->save)==1)ZUKAN_SAVE_SetViewMode(p->in->save,0);else ZUKAN_SAVE_SetViewMode(p->in->save,1);
            p->in->state=2;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,8,5,8);
        case 10:GFL_USE_PlaySeDefaultVolume(1606);ZUKAN_LIST_ToggleSaveFlag15((char *)p);break;
        case 11:
            GFL_USE_PlaySeDefaultVolume(1366);p->in->state=1;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,4,8,8);
        case 12:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,3,9,8);
        case 13:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,3,9,8);
        }
        break;
    default:
        selected=FRAME_LIST_GetSelectedIndex(p->list);ZUKAN_LIST_UpdateArrowActors((char *)p,0);
        if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);}
        break;
    }
    ZUKAN_LIST_UpdateScrollBarActor((char *)p);ZUKAN_LIST_HideAllActors((char *)p);return result;
}
