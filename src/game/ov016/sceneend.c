/*
 * file:     sceneend.c
 * unit:     yes
 * function: DWCi_SceneEnd, endScene
 * address:  0x021C1630
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_TSKlOperate  0x021D7794  arm  ov016
 *   DWCi_CEINlRelease  0x021D52B0  arm  ov016
 *   DWCi_HLlEnd  0x021BD660  arm  ov016
 *   DWCi_FOCUSlEnd  0x021BD404  arm  ov016
 *   DWCi_MSGlRelease  0x021C1004  arm  ov016
 *   DWCi_MSGlEnd  0x021C0F98  arm  ov016
 *   DWCi_SETTIGNlEnd  0x021CF3F0  arm  ov016
 *   DWCi_EndUtility  0x021C0F0C  arm  ov016
 *   gCommentWork  0x021DE598  data
 */
#include "../types.h"
typedef _Bool bool;

extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "dwcutil_main.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "task.h"
#include "cellinfo.h"
#include "headline.h"
#include "focus.h"
#include "message.h"
#include "setting.h"
void DWCi_SceneEnd(void);
extern void *gCommentWork;

/*
 * sdk:      DWCi_SceneEnd (libdwcutil.TWL.HYB.a(sceneend.o))
 */

static void endScene(void);
void DWCi_SceneEnd(void)
{
	DWCi_EFFlFade(3, 1, 0x3f, 0x14);
	DWCi_EFFlFade(3, 0, 0x3f, 0x14);
	DWCi_ChangeScene(endScene);
}

static void endScene(void)
{
	if (DWCi_EFFlCheck(1))
		return;
	if (DWCi_EFFlCheck(0))
		return;
	DWCi_TSKlOperate(0, 0);
	DWCi_TSKlOperate(1, 0);
	DWCi_CEINlRelease(1);
	DWCi_CEINlRelease(0);
	DWCi_HLlEnd();
	DWCi_FOCUSlEnd();
	DWCi_MSGlRelease(gCommentWork);
	DWCi_MSGlEnd();
	DWCi_SETTIGNlEnd();
	DWCi_EndUtility();
}
