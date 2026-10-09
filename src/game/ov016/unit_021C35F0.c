/*
 * file:     unit_021C35F0.c
 * function: DWCi_SceneOptMovConfirm
 * address:  0x021C35F0
 * packet:   pkt_ov016_021C35F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics                     0x021C3610  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit                         0x021C3678  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol DWCi_SceneOptMovConfirm
 * (name and prototype from the vendor object DWARF). The object is stamped Metrowerks
 * C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on 1.1p1.
 */

extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ChangeScene(void (*scene)());

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneOptMovConfirm(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x1a);
    DWCi_ChangeScene(procInit);
}
