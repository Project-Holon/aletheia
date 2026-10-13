/*
 * function: REPORT_EVENT_DeleteMessageWindow
 * address:  0x02169E98
 * packet:   pkt_02169E98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj19072.h"
#include "../include/Obj19073.h"

typedef unsigned int u32;

struct Descriptor;
u32 BMP_WIN_Delete(struct Descriptor *d);

int REPORT_EVENT_DeleteMessageWindow(char *p)
{
    return BMP_WIN_Delete((struct Descriptor *)(((struct Obj19073 *)(*(char * *)&((struct Obj19072 *)p)->f18))->f8));
}
