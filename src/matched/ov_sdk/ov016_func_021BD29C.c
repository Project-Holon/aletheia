/*
 * function: DWCi_CMNlMsgDraw
 * address:  0x021BD29C
 * packet:   pkt_ov016_021BD29C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_MSGlGet                     0x021C1030  arm
 *   DWCi_CMNlFontFlag                0x021BD3CC  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCiMsgCmn                       0x021DE598  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(common.o), symbol DWCi_CMNlMsgDraw (name and prototype
 * from the vendor object DWARF). Callee of DWCi_SceneOptMovConfirm/SceneOptMovWait. The
 * object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so 1.1p1.
 */

extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern unsigned short *DWCi_MSGlGet(void *msg, int id);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color,
                              unsigned long flag, unsigned short *txt);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void *DWCiMsgCmn;

void DWCi_CMNlMsgDraw(int msgId)
{
    void *canvas = DWCi_FNTlFormBgEx(0, 0);
    unsigned short *msg = DWCi_MSGlGet(DWCiMsgCmn, msgId);
    unsigned long flag = DWCi_CMNlFontFlag();

    DWCi_FNTlDrawRect(canvas, 0xd, 0x28, 0xe6, 0x70, 2, flag, msg);
    DWCi_FNTlRenewBg(canvas);
}
