/*
 * function: DWCi_SceneSetError
 * address:  0x021C7CE4
 * packet:   pkt_ov016_021C7CE4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetError (libdwcutil.TWL.HYB.a(sceneseterror.o))
 *
 * symbols:
 *   initGraphics                     0x021C7D00  arm
 *   drawMessage                      0x021C7D80  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit                         0x021C80B8  arm
 */

static void initGraphics(void);
static void drawMessage(void);
extern void DWCi_ChangeScene(void (*scene)(void));
static void procInit(void);

void DWCi_SceneSetError(void)
{
	initGraphics();
	drawMessage();
	DWCi_ChangeScene(procInit);
}
