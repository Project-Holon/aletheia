/*
 * function: STARTMENU_SaveEraseDeleteWindow
 * address:  0x021BD0C8
 * packet:   pkt_ov088_021BD0C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 */
#include "../include/Obj04351.h"

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);

void STARTMENU_SaveEraseDeleteWindow(unsigned char *p)
{
    BMP_WIN_Delete(((struct Obj04351 *)p)->f1C);
    BMP_WIN_Exit();
}
