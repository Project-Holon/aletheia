/*
 * function: OEKAKI_DeleteWindows
 * address:  0x02185004
 * packet:   pkt_ov023_02185004
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_DeleteAllTasks  0x0203115C  arm
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 */
#include "../include/Obj03624.h"

typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
struct S02031140;
struct Tcbl;
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);

void OEKAKI_DeleteWindows(char *p)
{
    int i;

    TCBL_DeleteAllTasks((struct Tcbl *)(((struct Obj03624 *)p)->f170));
    TCBL_Destroy((struct S02031140 *)(((struct Obj03624 *)p)->f170));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    for (i = 0; i < 5; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(u32 *)(p + 0x104 + i * 4)));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03624 *)p)->f118));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03624 *)p)->f11C));
    BMP_WIN_Exit();
}
