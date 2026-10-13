/*
 * function: STARTMENU_StateWaitPrint
 * address:  0x021BA2C8
 * packet:   pkt_ov088_021BA2C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (112) runs 2 bytes past the compiled function (110);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   STARTMENU_RefreshSaveStatus  0x021BC0C8  thumb  ov088
 *   STARTMENU_BeginFadeOut  0x021BC054  thumb  ov088
 */
#include "../include/Obj06203.h"

typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int STARTMENU_RefreshSaveStatus(char *p);
extern int STARTMENU_BeginFadeOut(char *p, int v);

int STARTMENU_StateWaitPrint(char *p)
{
    unsigned i;
    void *t;
    PRINTSYS_QUE_Main(((struct Obj06203 *)p)->f68);
    for (i = 0; i < 14; i++) {
        t = ((struct Obj06203 *)p)->f68;
        if (*(unsigned char *)(p + i * 8 + 0x84) != 0 && func_0201C6C4(t, func_02045770(*(void **)(p + i * 8 + 0x80))) == 0) {
            BMP_WIN_TransferChars(*(void **)(p + i * 8 + 0x80));
            *(unsigned char *)(p + i * 8 + 0x84) = 0;
        }
    }
    if (func_0201C6B4(((struct Obj06203 *)p)->f68) == 1) {
        if (STARTMENU_RefreshSaveStatus(p) == 1)
            return 10;
        return STARTMENU_BeginFadeOut(p, 5);
    }
    return 4;
}
