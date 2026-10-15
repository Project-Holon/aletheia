/*
 * function: STARTMENU_CaptureDelete
 * address:  0x021B99EC
 * packet:   pkt_ov088_021B99EC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   TCBL_Destroy  0x02031140  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
struct Node;
struct S02031140;
extern void func_02030EAC(struct Node *n);
extern void TCBL_Destroy(struct S02031140 *p);
extern void G3D_SYSTEM_Exit(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);

void STARTMENU_CaptureDelete(int *p)
{
    BG_SYS_SetLcdSwap(1);
    BG_SYS_ResetSubDisplay();
    func_02030EAC((struct Node *)p[1]);
    TCBL_Destroy((struct S02031140 *)p[0]);
    G3D_SYSTEM_Exit();
    BMP_WIN_Exit();
    BG_SYS_Delete();
}
