/*
 * function: IRC_COMPATIBLE_MENU_HandleStartTests
 * address: 0x021B7F24
 * packet: pkt_ov102_021B7F24
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: 0200ED48's void legacy declaration is a tail call to pointer-returning 020071CC; preserve the incoming save object and live pointer result through 020120F4/02012EBC/0200ED48.
 * symbols:
 * IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 * IRC_APPBAR_Reset 0x021B7264 thumb ov101
 * IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 * IRC_APPBAR_SetLabel 0x021B72A8 thumb ov101
 * COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 * COMPATIBLE_IRC_SYS_StepStartSession 0x021B6150 thumb ov101
 * COMPATIBLE_IRC_SYS_StepConnectChild 0x021B6254 thumb ov101
 * COMPATIBLE_IRC_SYS_StepSyncTiming 0x021B62AC thumb ov101
 * COMPATIBLE_IRC_SYS_StepSendProfile 0x021B6568 thumb ov101
 * COMPATIBLE_IRC_SYS_GetPartnerProfile 0x021B657C thumb ov101
 * COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 * COMPATIBLE_IRC_SYS_SendProfileRequest 0x021B6518 thumb ov101
 * COMPATIBLE_IRC_SYS_PollProfileRequest 0x021B652C thumb ov101
 * COMPATIBLE_IRC_SYS_SendProfileAck 0x021B6540 thumb ov101
 * COMPATIBLE_IRC_SYS_PollProfileAck 0x021B6554 thumb ov101
 * COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 * COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 * COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 * IRC_COMPATIBLE_MENU_SetHandler 0x021B7F08 thumb ov102
 * IRC_COMPATIBLE_MENU_PrintMessage 0x021B7DFC thumb ov102
 * IRC_COMPATIBLE_MENU_ResetButtonPalettes 0x021B8724 thumb ov102
 * IRC_COMPATIBLE_MENU_HandleOpen 0x021B8320 thumb ov102
 * IRC_COMPATIBLE_MENU_HandleFinish 0x021B82DC thumb ov102
 * IRC_COMPATIBLE_MENU_HandleCheckLink 0x021B83E0 thumb ov102
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * BG_SYS_PushTile 0x020409B4 arm
 * GAMESYSTEM_GetGameData 0x020120F4 thumb
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 * func_02008530 0x02008530 thumb
 * MET_TRAINERS_Insert 0x0200ED54 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define O ((u8 *)W(0x48c))
#define C (*(void **)(O+4))
struct L0200ED54;
extern int IRC_APPBAR_GetResult(int *p);
struct R;
extern void IRC_APPBAR_Reset(int p);
extern void IRC_APPBAR_SetActive(int p, int b);
struct Big;
struct Ctx;
struct Obj;
struct Sub0200852CObj;
extern void IRC_APPBAR_SetLabel(unsigned *p, unsigned b);
extern void COMPATIBLE_IRC_SYS_ResetStep(int *p);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *p, int n);
extern int COMPATIBLE_IRC_SYS_StepStartSession(struct Obj *p);
extern int COMPATIBLE_IRC_SYS_StepConnectChild(int *p);
extern int COMPATIBLE_IRC_SYS_StepSyncTiming(int *p);
extern int COMPATIBLE_IRC_SYS_StepShareValue(int *p, int value);
extern int COMPATIBLE_IRC_SYS_StepSendProfile(int *p, int resource);
extern int COMPATIBLE_IRC_SYS_SendProfileRequest(u32 p, u32 a, u32 b);
extern void COMPATIBLE_IRC_SYS_GetPartnerProfile(int *p, struct R *out);
extern int COMPATIBLE_IRC_SYS_PollProfileRequest(u32 p);
extern int COMPATIBLE_IRC_SYS_SendProfileAck(u32 p);
extern int COMPATIBLE_IRC_SYS_PollProfileAck(int *p);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(int p);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *p);
extern void IRC_COMPATIBLE_MENU_SetHandler(unsigned p, unsigned x);
extern void IRC_COMPATIBLE_MENU_PrintMessage(u8 *,void *,int,int,short);
extern void IRC_COMPATIBLE_MENU_ResetButtonPalettes(u8 *);
extern void IRC_COMPATIBLE_MENU_HandleOpen(u8 *,u16 *);
extern void IRC_COMPATIBLE_MENU_HandleFinish(u8 *,u16 *);
extern void IRC_COMPATIBLE_MENU_HandleCheckLink(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BG_SYS_PushTile(u32);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
void IRC_COMPATIBLE_MENU_HandleStartTests(u8 *p,u16 *state)
{
    void *save;
    if(*state<14 && IRC_APPBAR_GetResult((void *)W(0x468))==1) {
        COMPATIBLE_IRC_SYS_ResetStep(C);
        IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleOpen);
        IRC_APPBAR_Reset((int)((void *)W(0x468)));
        IRC_APPBAR_SetLabel((void *)W(0x468),0);
        BG_SYS_PushTile(0);
        IRC_COMPATIBLE_MENU_PrintMessage(p+0xac,p+0x9c,5,0,0);
        IRC_COMPATIBLE_MENU_ResetButtonPalettes(p+0xc0);
        return;
    }
    switch(*state) {
    case 0: COMPATIBLE_IRC_SYS_ResetStep(C); *state=1; break;
    case 1:
        if(COMPATIBLE_IRC_SYS_StepStartSession(C)) { GFL_USE_PlaySeDefaultVolume(1620); IRC_APPBAR_SetActive((int)((void *)W(0x468)),1); *state=2; }
        break;
    case 2: if(COMPATIBLE_IRC_SYS_StepConnectChild(C)) *state=3; break;
    case 3: IRC_COMPATIBLE_MENU_PrintMessage(p+0xac,p+0x9c,4,0,0); *state=4; break;
    case 4: if(COMPATIBLE_IRC_SYS_StepSyncTiming(C)) *state=5; break;
    case 5:
        if(COMPATIBLE_IRC_SYS_StepSendProfile(C,*(u32 *)O)) {
            COMPATIBLE_IRC_SYS_GetPartnerProfile(C,(struct R *)(*(u32 *)(O+16)));
            if(*(u32 *)O) {
                save=MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(*(void **)O)));
                MET_TRAINERS_Insert(save,func_02008530((const struct Sub0200852CObj *)(*(u8 **)(O+16)+12)));
            }
            *state=6;
        }
        break;
    case 6: if(COMPATIBLE_IRC_SYS_StepShareValue(C,0)) *state=8; break;
    case 8:
        W(0x4a0)=1;
        if(COMPATIBLE_IRC_SYS_SendProfileRequest((u32)C,W(0x498),W(0x494))) *state=9;
        break;
    case 9: if(COMPATIBLE_IRC_SYS_PollProfileRequest((u32)C)) *state=10; break;
    case 10: if(COMPATIBLE_IRC_SYS_SendProfileAck((u32)C)) *state=11; break;
    case 11: if(COMPATIBLE_IRC_SYS_PollProfileAck(C)) *state=12; break;
    case 12: COMPATIBLE_IRC_SYS_SetOwnValue(C,1); if(COMPATIBLE_IRC_SYS_SendOwnValue((int)C)) *state=13; break;
    case 13: if(COMPATIBLE_IRC_SYS_StepShareValue(C,1)) { IRC_APPBAR_SetActive((int)((void *)W(0x468)),0); *state=14; } break;
    case 14:
        if(H(0x486)>=60) { GFL_USE_PlaySeDefaultVolume(1611); IRC_COMPATIBLE_MENU_PrintMessage(p+0xac,p+0x9c,2,0,0); *state=15; }
        break;
    case 15:
        if(W(0x49c)++>=30) { *(u32 *)(O+12)=0; IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleFinish); }
        return;
    }
    if(*state>=3 && *state<=14 && H(0x486)<=60) H(0x486)++;
    if(*state<12 && COMPATIBLE_IRC_SYS_GetValueDifference(C)) IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleCheckLink);
}
