/*
 * function: STARTMENU_CaptureInit
 * address:  0x021B997C
 * packet:   pkt_ov088_021B997C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb
 *   TCBL_Create  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   STARTMENU_CaptureVblankTask  0x021B9954  thumb  ov088
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 */

extern void func_0203F8F4(int);
extern void BMP_WIN_Init(int);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern void GF_FONT_ResetTextColor(void);
extern void *TCBL_Create(int, int, int, int);
extern void *func_020056A0(void *, void *, int);
typedef unsigned int   u32;
extern void STARTMENU_CaptureVblankTask(void *task, short *p);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);

void STARTMENU_CaptureInit(int *p, int heap)
{
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    G3D_SYSTEM_Init(0, 2, 0, 2, 0x1000, heap, 0);
    GF_FONT_ResetTextColor();
    p[0] = (int)TCBL_Create(heap, heap, 4, 0x20);
    p[1] = (int)func_020056A0((void *)STARTMENU_CaptureVblankTask, p, 5);
    BG_SYS_SetLcdSwap(0);
    BG_SYS_ResetSubDisplay();
    ((unsigned short *)p)[4] = 12;
    ((unsigned short *)p)[5] = 4;
}
