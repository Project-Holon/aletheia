/*
 * function: ITEMMENU_Init
 * address:  0x021B86B8
 * packet:   pkt_ov070_021B86B8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   KEY_GetRepeatSpeed  0x02036370  arm
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   TCBL_Create  0x0203101C  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0200816C  0x0200816C  thumb
 *   func_02008284  0x02008284  thumb
 *   func_02008270  0x02008270  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_02008288  0x02008288  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_020056A0  0x020056A0  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   ITEMMENU_SetupGraphics  0x021B9280  thumb  ov070
 *   ITEMMENU_InitWindows  0x021B9BDC  thumb  ov070
 *   ITEMMENU_LoadPocketGraphics  0x021B9EF4  thumb  ov070
 *   ITEMMENU_CreateTabActors  0x021BA8C0  thumb  ov070
 *   ITEMMENU_ForceRedrawList  0x021B6120  thumb  ov070
 *   ITEMMENU_CreateCursorActors  0x021BA028  thumb  ov070
 *   ITEMMENU_CreateBlinkPalAnm  0x021B8B24  thumb  ov070
 *   ITEMMENU_AllocPalAnmSlots  0x021B8E48  thumb  ov070
 *   ITEMMENU_PrintPocketName  0x021BAE98  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_ResetDisplayLayers  0x021B913C  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_HandleTouchTarget  0x021B83B8  thumb  ov070
 *   ITEMMENU_VBlankCallback  0x021B8600  thumb  ov070
 *   ITEMMENU_TaskStartFadeIn  0x021B8640  thumb  ov070
 *   d_021BBA04     0x021BBA04  data  a4
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef short s16;
/*
 * The clamped scroll and cursor go back to func_02008288 (its definition
 * takes them as s16 arguments 3 and 4). Without them the clamp loop coloured
 * scroll/cur in r1/r2 instead of r2/r3 (28 bytes differed).
 */
struct MyItemSave;
typedef struct Args {
    int f00, f04, f08;
    struct MyItemSave *f0C;
    int f10, f14[6], f2C, f30;
} Args;
typedef struct Work {
    int f00, f04, f08;
    int *f0C;
    int f10;
    struct MyItemSave *f14;
    int f18, f1C;
    u8 pad20[0x50C - 0x20];
    int f50C, f510, f514, f518, f51C, f520, f524, f528, f52C, f530;
    u8 pad534[0x544 - 0x534];
    u16 f544;
    u8 pad546[0x694 - 0x546];
    int f694, f698;
    u8 pad69C[0x730 - 0x69C];
    int f730;
    u8 pad734[0x7E0 - 0x734];
    int f7E0;
    u8 pad7E4[0x80C - 0x7E4];
    int f80C, f810, f814;
    u8 pad818[0x858 - 0x818];
    int f858;
    u8 pad85C[0x86C - 0x85C];
    int f86C, f870;
} Work;
extern void GFL_HEAP_CreateChildHeap(); extern void *PROCSYS_AllocProcWork(); extern void MI_CpuFill8(); extern void KEY_GetRepeatSpeed();
extern void func_0200816C(); extern int func_02008284(struct MyItemSave *p); extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b); extern int func_02007FA0(); extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern int func_02045B38(); extern int STRBUF_Create(); extern int WORDSET_CreateDefault(); extern int PRINTSYS_QUE_CreateEx();
extern int APP_KEYCURSOR_CreateDefault(); extern int GF_FONT_Create(); extern int BUTTON_MAN_Create(); extern int func_020056A0(); extern int TCBL_Create();
extern int APP_TASKMENU_RES_Create(); extern void GFL_NET_RefreshWmIconAtTopRight(); extern int func_020355C4();
extern void ITEMMENU_SetupGraphics(), ITEMMENU_InitWindows(), ITEMMENU_LoadPocketGraphics(), ITEMMENU_CreateTabActors(), ITEMMENU_ForceRedrawList(), ITEMMENU_CreateCursorActors(), ITEMMENU_CreateBlinkPalAnm(), ITEMMENU_AllocPalAnmSlots(), ITEMMENU_PrintPocketName(), ITEMMENU_SetCursorActive(), ITEMMENU_ResetDisplayLayers(), ITEMMENU_SetTask();
extern void ITEMMENU_HandleTouchTarget(), ITEMMENU_VBlankCallback(), ITEMMENU_TaskStartFadeIn(); extern char d_021BBA04[];
int ITEMMENU_Init(void *proc, int st, Args *a)
{
    Work *o; u16 i; s16 scr, cur;
    GFL_HEAP_CreateChildHeap(1, 0xe, 0x34000);
    o = PROCSYS_AllocProcWork(proc, 0x874, 0xe);
    MI_CpuFill8(o, 0, 0x874);
    KEY_GetRepeatSpeed(&o->f86C, &o->f870);
    o->f544 = 0xe;
    o->f858 = 1;
    o->f00 = a->f00; o->f08 = a->f08; o->f04 = a->f04;
    o->f14 = a->f0C; o->f18 = a->f10;
    o->f0C = a->f14;
    o->f10 = a->f2C; o->f1C = a->f30;
    func_0200816C(o->f18, o->f1C);
    o->f80C = func_02008284(o->f14);
    for (i = 0; i < 5; i++) {
        int n;
        func_02008270(o->f14, i, &scr, &cur);
        n = (u16)func_02007FA0(o->f18, i);
        for (;;) {
            if (scr == 0 && cur == 0) break;
            if (cur + 5 >= n && cur != 0) { cur--; continue; }
            if (scr + cur < n) break;
            if (cur != 0) cur--; else scr--;
        }
        if (i == o->f80C) { o->f810 = scr; o->f814 = cur - 1; }
        func_02008288(o->f14, i, scr, cur);
    }
    o->f51C = func_02045B38(0, 2, 3, o->f544);
    o->f524 = STRBUF_Create(0xc8, o->f544);
    o->f528 = STRBUF_Create(0xc8, o->f544);
    o->f52C = STRBUF_Create(0x40, o->f544);
    o->f520 = WORDSET_CreateDefault(o->f544);
    o->f50C = PRINTSYS_QUE_CreateEx(0x40 << 6, o->f544);
    o->f518 = APP_KEYCURSOR_CreateDefault(0xf, 1, 1, o->f544);
    o->f530 = GF_FONT_Create(0x17, 0, 0, 0, o->f544);
    ITEMMENU_SetupGraphics(o); ITEMMENU_InitWindows(o); ITEMMENU_LoadPocketGraphics(o); ITEMMENU_CreateTabActors(o); ITEMMENU_ForceRedrawList(o); ITEMMENU_CreateCursorActors(o);
    o->f694 = BUTTON_MAN_Create(d_021BBA04, ITEMMENU_HandleTouchTarget, o, o->f544);
    ITEMMENU_CreateBlinkPalAnm(o); ITEMMENU_AllocPalAnmSlots(o);
    o->f698 = func_020056A0(ITEMMENU_VBlankCallback, o, 0);
    o->f730 = TCBL_Create(o->f544, o->f544, 1, 0);
    ITEMMENU_PrintPocketName(o);
    o->f7E0 = APP_TASKMENU_RES_Create(3, 9, o->f530, o->f50C, o->f544);
    GFL_NET_RefreshWmIconAtTopRight(1, o->f544);
    ITEMMENU_SetCursorActive(o, func_020355C4() ? 0 : 1);
    ITEMMENU_ResetDisplayLayers();
    ITEMMENU_SetTask(o, ITEMMENU_TaskStartFadeIn);
    return 1;
}
