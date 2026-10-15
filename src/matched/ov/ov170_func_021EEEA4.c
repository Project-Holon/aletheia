/*
 * function: BOX2_UI_CursorInputPage
 * address: 0x021EEEA4
 * packet: pkt_ov170_021EEEA4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb ov170
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_UpdateCursor 0x021EE408 thumb ov170
 *   KEY_GetRepeat 0x0203633C arm
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb ov170
 */
struct WinMgr;
typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_UpdateCursor(char *, int);
extern unsigned int KEY_GetRepeat(void);
extern void BOX2_MAIN_PlayCursorSound(char *);
#define WORK(p) (*(char **)((p)+0x2c))
#define OBJ(p) (*(void **)(WORK(p)+0x70))
unsigned BOX2_UI_CursorInputPage(char *p)
{
    unsigned char sel=CURSOR_MOVE_GetCurrent(OBJ(p));
    unsigned r=CURSOR_MOVE_PollRepeatInput(OBJ(p));
    if(BOX2_UI_IsListOpen(*(struct WinMgr **)(WORK(p)+0x74))==0) {
        if(r>=0x22 && r<=0x23) {
            CURSOR_MOVE_SetCurrent(OBJ(p),sel);
            BOX2_UI_UpdateCursor(p,sel);
            return -1;
        }
        if(r==0x21) {
            CURSOR_MOVE_SetCurrent(OBJ(p),sel);
            return 0x21;
        }
    } else if(r==0x1e || r==0x21) {
        CURSOR_MOVE_SetCurrent(OBJ(p),sel);
        BOX2_UI_UpdateCursor(p,sel);
        return -1;
    }
    if(r==-1) {
        if(KEY_GetRepeat()&0x200) { BOX2_MAIN_PlayCursorSound(p); return 0x1f; }
        if(KEY_GetRepeat()&0x100) { BOX2_MAIN_PlayCursorSound(p); return 0x20; }
    }
    return r;
}
