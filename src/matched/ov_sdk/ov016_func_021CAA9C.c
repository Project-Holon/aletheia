/*
 * function: endScene2
 * address:  0x021CAA9C
 * packet:   pkt_ov016_021CAA9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_RAKUlEnd                    0x021c14f4 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Choose                           0x021de5f8 data
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetRakuButton1         0x021cac64 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakubutt), symbol endScene2 (name and prototype
 * from the vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025;
 * no build in tools/mwccarm writes that stamp, so this stays on the default dsi/1.1p1.
 *
 * The load-bearing structural point: DWCi_GXlInvisible(1, 1) sits INSIDE the
 * `if (Choose == 0)` block, sharing that block with DWCi_COMMENTlDelete, and the
 * `bne` at 0x021CAAF4 targets 0x021CAB08 -- past the first GXlInvisible. Hoisting
 * that call out of the guard is what makes the 1 escape the constant pool and costs
 * a callee-saved register; inside it, 1.1p1 rematerialises the 1 and still pools the
 * 0 into r4, which is the image. Same shape as the static sibling 0x021CB5D8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CAA9C.c \
 *       --func endScene2 --addr 0x021CAA9C --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_RAKUlEnd(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Choose;
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetRakuButton1(void);

static void endScene2(void)
{
    if (DWCi_EFFlCheck(0)) {
        return;
    }
    if (Choose == 0) {
        if (DWCi_EFFlCheck(1)) {
            return;
        }
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 0) {
        DWCi_RAKUlEnd();
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetRakuButton1);
    }
}
