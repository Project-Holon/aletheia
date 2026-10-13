/*
 * function: STARTMENU_StateSetup
 * address:  0x021BA114
 * packet:   pkt_ov088_021BA114
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009448  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_0200C2F0  0x0200C2F0  thumb
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   STARTMENU_ClearGraphics  0x021BA9D4  thumb  ov088
 *   STARTMENU_SetupBackgrounds  0x021BA9E8  thumb  ov088
 *   STARTMENU_LoadGraphics  0x021BAB64  thumb  ov088
 *   STARTMENU_CreateTextSystem  0x021BAC74  thumb  ov088
 *   STARTMENU_BuildRowList  0x021BB4B4  thumb  ov088
 *   STARTMENU_LoadRowBuffers  0x021BB544  thumb  ov088
 *   STARTMENU_CreateRowWindows  0x021BAD08  thumb  ov088
 *   STARTMENU_CreateActors  0x021BB184  thumb  ov088
 *   STARTMENU_CreateFrameManager  0x021BB380  thumb  ov088
 *   STARTMENU_LayoutRows  0x021BB608  thumb  ov088
 *   STARTMENU_CreateBlinkPalette  0x021BAC24  thumb  ov088
 *   STARTMENU_StartBrightnessEffect  0x021BB484  thumb  ov088
 *   STARTMENU_AddVblankTask  0x021BA9B0  thumb  ov088
 */

struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
struct Blk34;
struct Menu;
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void STARTMENU_ClearGraphics(void);
extern void STARTMENU_SetupBackgrounds(void);
extern void STARTMENU_LoadGraphics(void);
extern void STARTMENU_CreateTextSystem(char *p);
extern void STARTMENU_BuildRowList(char *p);
extern void STARTMENU_LoadRowBuffers(char *p);
extern void STARTMENU_CreateRowWindows(struct Menu *p);
extern void STARTMENU_CreateActors(int *p);
extern void STARTMENU_CreateFrameManager(char *p);
extern void STARTMENU_LayoutRows(char *p);
extern void STARTMENU_CreateBlinkPalette(char *p);
extern void STARTMENU_StartBrightnessEffect(void);
extern void STARTMENU_AddVblankTask(int *p);

int STARTMENU_StateSetup(int *p)
{
    unsigned short z;
    if (func_020092EC((const struct Sub02009210Obj *)func_02009448((void *)p[0])) == 1)
        func_0200C2F0((struct Blk34 *)p[2], 2, 2);
    z = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(unsigned short *)0x04000050 = z;
    *(unsigned short *)0x04001050 = z;
    BG_SYS_SetLcdSwap(1);
    STARTMENU_ClearGraphics();
    STARTMENU_SetupBackgrounds();
    STARTMENU_LoadGraphics();
    STARTMENU_CreateTextSystem((char *)p);
    STARTMENU_BuildRowList((char *)p);
    STARTMENU_LoadRowBuffers((char *)p);
    STARTMENU_CreateRowWindows((struct Menu *)p);
    STARTMENU_CreateActors(p);
    STARTMENU_CreateFrameManager((char *)p);
    STARTMENU_LayoutRows((char *)p);
    STARTMENU_CreateBlinkPalette((char *)p);
    STARTMENU_StartBrightnessEffect();
    STARTMENU_AddVblankTask(p);
    return 4;
}
