/*
 * function: POKELIST_OnTakeItemChoice
 * address: 0x021BA0A8
 * packet: pkt_ov091_021BA0A8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: preserve duplicated branch bodies for cross-jumping; parenthesize
 *   (base + scaled index) + field offset for the indexed actor load.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   POKELIST_CheckBagItem 0x021BA65C thumb ov091
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   POKELIST_SetHeldItem 0x021BA624 thumb ov091
 *   PLIST_PLATE_Redraw 0x021BB2C0 thumb ov091
 *   PLIST_MENU_ApplyArceusPlateForm 0x021BC24C thumb ov091
 *   PLIST_MENU_ApplyGenesectDriveForm 0x021BC288 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToOrigin 0x021BDBF8 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToAltered 0x021BDC5C thumb ov091
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetItem 0x021BB9AC thumb ov091
 *   PLIST_DEMO_ApplyGiratinaOriginForm 0x021BDC3C thumb ov091
 *   PLIST_DEMO_ApplyGiratinaAlteredForm 0x021BDCA0 thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   POKELIST_SetupModeScreen 0x021B7B98 thumb ov091
 *   POKELIST_EndMessageToList 0x021B9E20 thumb ov091
 *   POKELIST_EndMessageToExit 0x021B9E3C thumb ov091
 *   POKELIST_EndMessageToEvolve 0x021BA4E4 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 func_0202136C(u16);
extern u32 POKELIST_CheckBagItem(u8 *p, u16 id);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void POKELIST_SetHeldItem(u8 *,void *,u16);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern void PLIST_MENU_ApplyArceusPlateForm(void *unused, void *a, int b);
extern void PLIST_MENU_ApplyGenesectDriveForm(int unused, int a, int b);
extern int PLIST_DEMO_CheckGiratinaToOrigin(u8 *,void *);
extern int PLIST_DEMO_CheckGiratinaToAltered(u8 *,void *);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetItem(int a, int b, int c, int d);
extern void PLIST_DEMO_ApplyGiratinaOriginForm(u32 p, void *m);
extern void PLIST_DEMO_ApplyGiratinaAlteredForm(u32 p, void *m);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_SetupModeScreen(u8 *);
extern void POKELIST_EndMessageToList(u8 *p);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_EndMessageToEvolve(u8 *p);
#define W(k) (*(u32 *)(p+(k)))
#define S (*(u8 **)(p+0x280))
void POKELIST_OnTakeItemChoice(u8 *p,int action)
{
    u32 old;
    int a,b;
    if (action == 0xe) {
        old = POKE_TOOL_GetPartyValue((void *)W(0x38),6,0);
        if (POKELIST_CheckBagItem(p,old) == 0x3e7) {
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150));
                POKELIST_ShowMessage(p,0x3f,1,(int)POKELIST_EndMessageToList);
            } else {
                p[0xc] = 0x13;
                PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150));
                POKELIST_ShowMessage(p,0x3f,1,(int)POKELIST_EndMessageToExit);
            }
        } else if (func_0202136C(*(u16 *)(S+0x44)) == 1) {
            *(u32 *)(S+0x3c) = W(0x2c);
            p[0xc] = 0x13;
            *(int *)(S+0x40) = 6;
        } else {
            PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150));
            POKELIST_SetHeldItem(p,(void *)W(0x38),*(u16 *)(S+0x44));
            PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            PLIST_MENU_ApplyArceusPlateForm(p,(void *)W(0x38),(u16)(*(u16 *)(S+0x44)));
            PLIST_MENU_ApplyGenesectDriveForm((int)p,(int)((void *)W(0x38)),*(u16 *)(S+0x44));
            a = PLIST_DEMO_CheckGiratinaToOrigin(p,(void *)W(0x38));
            b = PLIST_DEMO_CheckGiratinaToAltered(p,(void *)W(0x38));
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
            PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)1,(u16)old);
            PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)2,(u16)(*(u16 *)(S+0x44)));
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                if (a == 1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm((u32)p,(void *)W(0x38));
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToEvolve);
                    W(0x264) = 1;
                } else if (b == 1) {
                    PLIST_DEMO_ApplyGiratinaAlteredForm((u32)p,(void *)W(0x38));
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToEvolve);
                    W(0x264) = 2;
                } else {
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToList);
                }
            } else {
                *(int *)(S+0x40) = 0xa;
                if (a == 1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm((u32)p,(void *)W(0x38));
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToEvolve);
                    W(0x264) = 1;
                } else if (b == 1) {
                    PLIST_DEMO_ApplyGiratinaAlteredForm((u32)p,(void *)W(0x38));
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToEvolve);
                    W(0x264) = 2;
                } else {
                    POKELIST_ShowMessage(p,0x40,1,(int)POKELIST_EndMessageToExit);
                }
            }
            PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        }
    } else {
        if (*(int *)(S+0x34) == 0xa) {
            *(int *)(S+0x34) = 0;
            PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150));
            p[0xc] = 2;
            POKELIST_SetupModeScreen(p);
        } else p[0xc] = 0x13;
    }
}
