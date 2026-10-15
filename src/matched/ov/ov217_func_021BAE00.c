/*
 * function: RESEARCH_LIST_HandleScrollInput
 * address: 0x021BAE00
 * packet: pkt_ov217_021BAE00
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   RESEARCH_LIST_GetInputFlag 0x021BC6D0 thumb ov217
 *   RESEARCH_LIST_StartEntryPaletteAnime 0x021BBAD0 thumb ov217
 *   RESEARCH_LIST_SetEntryHandled 0x021BB934 thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 *   RESEARCH_LIST_ShowCursor 0x021BBD68 thumb ov217
 *   RESEARCH_LIST_ShowEntryLabels 0x021BC128 thumb ov217
 *   RESEARCH_LIST_IsValidIndex 0x021BC6F4 thumb ov217
 *   RESEARCH_LIST_SelectEntry 0x021BBAA4 thumb ov217
 *   RESEARCH_LIST_SetSelectedIndex 0x021BC6EC thumb ov217
 *   RESEARCH_LIST_StartListPaletteAnime 0x021BC580 thumb ov217
 *   RESEARCH_LIST_PrintCurrentEntry 0x021BC06C thumb ov217
 *   RESEARCH_LIST_NeedsScrollbar 0x021BC428 thumb ov217
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void *RESEARCH_COMMON_GetTouchRects(void *);
extern u32 RESEARCH_LIST_GetInputFlag(void *);
extern void RESEARCH_LIST_StartEntryPaletteAnime(u32);
extern void RESEARCH_LIST_SetEntryHandled(u8 *,u32);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *,u32);
extern void RESEARCH_LIST_ShowCursor(u8 *);
extern u32 RESEARCH_LIST_ShowEntryLabels(u32);
extern u32 RESEARCH_LIST_IsValidIndex(u32 a0, u32 a1);
extern u32 RESEARCH_LIST_SelectEntry(u32,u8);
extern void RESEARCH_LIST_SetSelectedIndex(void *,u8);
extern void RESEARCH_LIST_StartListPaletteAnime(char *,int);
extern int RESEARCH_LIST_PrintCurrentEntry(char *);
extern int RESEARCH_LIST_NeedsScrollbar(void *);
/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void RESEARCH_LIST_HandleScrollInput(u8 *p)
{
    u32 keys=KEY_GetTrg();
    int sel=TOUCHPANEL_HitTrg(p+0x64);
    int flag;
    u32 a,b;
    flag=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a,&b);
    if(RESEARCH_LIST_GetInputFlag(p)!=0 || flag==0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled(p,1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,5);
        return;
    }
    if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled(p,0);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        RESEARCH_LIST_ShowCursor(p);
        RESEARCH_LIST_ShowEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(RESEARCH_LIST_IsValidIndex((u32)p,(u8)sel)==1) {
                RESEARCH_LIST_SelectEntry((u32)p,sel);
                RESEARCH_LIST_SetSelectedIndex(p,p[0x32]);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                RESEARCH_LIST_StartListPaletteAnime((char *)p,2);
                RESEARCH_LIST_PrintCurrentEntry((char *)p);
                RESEARCH_LIST_ShowEntryLabels((u32)p);
                RESEARCH_LIST_SetCommandReady(p);
                RESEARCH_LIST_PushCommand(p,7);
                return;
            }
        }
    } else {
        if(TOUCHPANEL_HitCont(p+0x90)==0 || TOUCHPANEL_HitTrg(p+0x90)==0) {
            if(RESEARCH_LIST_NeedsScrollbar(p)==1) {
                RESEARCH_LIST_SetCommandReady(p);
                RESEARCH_LIST_PushCommand(p,4);
                RESEARCH_LIST_PushCommand(p,1);
            }
        }
    }
}
