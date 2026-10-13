/*
 * function: PLIST_BATTLE_FinishEffect
 * address: 0x021BD8E4
 * packet: pkt_ov091_021BD8E4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_DEMO_DeleteParticles 0x021BDBE0 thumb ov091
 *   POKELIST_ShutdownLight 0x021B7040 thumb ov091
 *   POKELIST_SetupBgPlanes 0x021B6F0C thumb ov091
 *   PLIST_MESSAGE_LoadWindowFrame 0x021BBA54 thumb ov091
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon 0x021BB99C thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   POKELIST_EndMessageToExit 0x021B9E3C thumb ov091
 *   POKELIST_EndMessageToList 0x021B9E20 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void PLIST_DEMO_DeleteParticles(unsigned int p);
extern void POKELIST_ShutdownLight(unsigned p);
extern void POKELIST_SetupBgPlanes(void *p);
extern void PLIST_MESSAGE_LoadWindowFrame(unsigned short *a, u32 b);
typedef unsigned short u16;
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void POKELIST_ShowMessage(u8 *,int,int,int);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_EndMessageToList(u8 *);
#define W(o) (*(u32 *)(p+(o)))
void PLIST_BATTLE_FinishEffect(u8 *p)
{
    void (*cb)(u8 *);
    PLIST_DEMO_DeleteParticles((unsigned int)p);
    POKELIST_ShutdownLight((unsigned int)p);
    POKELIST_SetupBgPlanes(p);
    PLIST_MESSAGE_LoadWindowFrame((short unsigned int *)p,W(0x150));
    if (W(0x264) == 1) {
        cb = (void (*)(u8 *))POKELIST_EndMessageToExit;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = POKELIST_EndMessageToList;
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        POKELIST_ShowMessage(p,0xa6,1,(int)cb);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
    } else if (W(0x264) == 2) {
        cb = (void (*)(u8 *))POKELIST_EndMessageToExit;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = POKELIST_EndMessageToList;
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        POKELIST_ShowMessage(p,0xa6,1,(int)cb);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
    } else if (W(0x264) == 3) {
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        POKELIST_ShowMessage(p,0xa6,1,(int)POKELIST_EndMessageToExit);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
    } else {
        p[0xc] = 0x13;
    }
}
