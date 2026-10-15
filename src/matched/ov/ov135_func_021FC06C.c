/*
 * function: WORLDTRADE_DETAIL_Init
 * address: 0x021FC06C
 * packet: pkt_ov135_021FC06C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup: WIPE_SYS_Start declared with an int return (first-check lever). With void the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 * symbols:
 *   WORLDTRADE_NoOp 0x0200ADB4 thumb
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   func_020084F4 0x020084F4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_DETAIL_CreateStrings 0x021FC528 thumb ov135
 *   WORLDTRADE_DETAIL_SetupBgPlanes 0x021FC1C0 thumb ov135
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_DETAIL_LoadBgGraphics 0x021FC2C0 thumb ov135
 *   WORLDTRADE_DETAIL_CreateWindows 0x021FC3E0 thumb ov135
 *   WORLDTRADE_DETAIL_CreateActors 0x021FC360 thumb ov135
 *   WORLDTRADE_DETAIL_PrintMonInfo 0x021FC8CC thumb ov135
 *   WORLDTRADE_DETAIL_PrintMonName 0x021FCA8C thumb ov135
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 *   WORLDTRADE_DETAIL_LoadMonGraphics 0x021FCB54 thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
extern void *WORLDTRADE_NoOp(void *);
extern void *POKE_TOOL_Dummy(void *);
extern void *func_020084F4(void *);
extern int WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void WORLDTRADE_DETAIL_CreateStrings(char *);
extern void WORLDTRADE_DETAIL_SetupBgPlanes(void);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *,u32,u32);
extern void WORLDTRADE_DETAIL_LoadBgGraphics(void *);
extern void WORLDTRADE_DETAIL_CreateWindows(void *);
extern void WORLDTRADE_DETAIL_CreateActors(char *);
extern void WORLDTRADE_DETAIL_PrintMonInfo(void *,void *,void *,void **,void *,void *,void *);
extern void WORLDTRADE_DETAIL_PrintMonName(void *,void *,void *,void *,void *,void *);
extern int WORLDTRADE_DEPOSIT_GetConditionIndex(int,int,int);
extern void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *,void *,int,u8 *,u32,int,int,void *);
extern void WORLDTRADE_DETAIL_LoadMonGraphics(void *);
int WORLDTRADE_DETAIL_Init(u8 *p)
{
    void *mon;
    int index;
    mon=WORLDTRADE_NoOp(*(void **)(*(u8 **)p));
    WORLDTRADE_DETAIL_CreateStrings((char *)p);
    WORLDTRADE_DETAIL_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DETAIL_LoadBgGraphics(p);
    WORLDTRADE_DETAIL_CreateWindows(p);
    WORLDTRADE_DETAIL_CreateActors((char *)p);
    WORLDTRADE_DETAIL_PrintMonInfo(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),(void **)(p+0xD90),POKE_TOOL_Dummy(mon),p+0x1D0,p+0xFA0);
    WORLDTRADE_DETAIL_PrintMonName(*(void **)(p+0xB6C),p+0xDAC,func_020084F4(*(void **)(*(u8 **)p+0x1C)),mon,p+0xDC0,p+0xFA0);
    index=WORLDTRADE_DEPOSIT_GetConditionIndex(*(s8 *)(p+0x1D7),*(s8 *)(p+0x1D8),0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(int *)(p+0xB68),p+0xDB4,*(s16 *)(p+0x1D4),*(s8 *)(p+0x1D6),index,p+0xFA0);
    WORLDTRADE_DETAIL_LoadMonGraphics(mon);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x12E4)=0;
    return 1;
}
