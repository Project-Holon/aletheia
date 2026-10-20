/*
 * file:     sceneinit.c
 * unit:     yes
 * function: DWCi_SceneInit, procFade, DWCi_SceneInitProcWait
 * address:  0x021C16F4
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
 *   DWCi_SETTIGNlInit     0x021CF3B0  arm  ov016
 *   DWCi_MSGlInit     0x021C0F60  arm  ov016
 *   DWCi_FOCUSlInit     0x021BD3E4  arm  ov016
 *   DWCi_HLlInit     0x021BD5E8  arm  ov016
 *   DWCi_COMMENTlInit     0x021BD04C  arm  ov016
 *   DWCi_Language     0x021C0EC8  arm  ov016
 *   DWCi_Flag     0x021C0EF0  arm  ov016
 *   DWCi_MSGlRead     0x021C0FAC  arm  ov016
 *   DWCi_Char     0x021BD170  arm  ov016
 *   DWCi_CEINlRead     0x021D5280  arm  ov016
 *   DWCi_CMNlLoadResource     0x021BD1D4  arm  ov016
 *   DWCi_Entry     0x021C0ED8  arm  ov016
 *   DWCi_GXlVisible     0x021D603C  arm  ov016
 *   DWCi_ChangeScene     0x021C0E40  arm  ov016
 *   GXS_LoadBG1Char   0x0207F024  arm
 *   GXS_LoadBGPltt    0x0207E468  arm
 *   GXS_LoadOBJ       0x0207E804  arm
 *   GXS_LoadOBJPltt   0x0207E5D0  arm
 *   GX_LoadBG2Char    0x0207F0B8  arm
 *   GX_LoadBGPltt     0x0207E3D0  arm
 *   GX_LoadOBJ        0x0207E780  arm
 *   GX_LoadOBJPltt    0x0207E51C  arm
 *   GXS_LoadBG1Scr    0x0207EABC  arm
 *   sSceneInitTable1        0x021DB13C  data
 *   sSceneInitTable2        0x021DB158  data
 *   sSceneInitTable3        0x021DB168  data
 *   sSceneInitTable4        0x021DB17C  data
 *   sSceneInitPathJtBgMainChar        0x021DB190  data
 *   sSceneInitPathJtBgMainPltt        0x021DB1A4  data
 *   sSceneInitPathJtObjMainChar        0x021DB1B8  data
 *   sSceneInitPathXtObjMainPltt        0x021DB1D0  data
 *   sSceneInitPathJbBgStep1Char        0x021DB1E8  data
 *   sSceneInitPathJbBgStep1Pltt        0x021DB200  data
 *   sSceneInitPathJbObjMainChar        0x021DB218  data
 *   sSceneInitPathYbObjMainPltt        0x021DB230  data
 *   sSceneInitPathJtTopScr        0x021DB248  data
 *   sSceneInitPathJtStep1Scr        0x021DB25C  data
 *   gCommentWork        0x021DE598  data
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 *   DWCi_SceneSetSelectAp  0x021CBC90  arm  ov016
 */
typedef void (*LoadFunc)(void *, unsigned long, unsigned long);

extern void DWCi_SETTIGNlInit(void);
extern void DWCi_MSGlInit(void);
extern void DWCi_FOCUSlInit(void);
extern void DWCi_HLlInit(void);
extern void DWCi_COMMENTlInit(void);
extern unsigned char DWCi_Language(void);
extern int DWCi_Flag(unsigned long flag);
extern void *DWCi_MSGlRead(char *file);
extern unsigned char *DWCi_Char(unsigned char *name);
extern void DWCi_CEINlRead(int lcd, char *file);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned int DWCi_Entry(void);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(unsigned int v);
extern void GXS_LoadBG1Char(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GXS_LoadBGPltt(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GXS_LoadOBJ(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GXS_LoadOBJPltt(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GX_LoadBG2Char(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GX_LoadBGPltt(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GX_LoadOBJ(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GX_LoadOBJPltt(void *pSrc, unsigned int offset, unsigned int szByte);
extern void GXS_LoadBG1Scr(void *pSrc, unsigned int offset, unsigned int szByte);
typedef _Bool bool;
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneMenu(void);
extern void DWCi_SceneSetSelectAp(void);
void DWCi_SceneInit(void);
extern char *sSceneInitTable1[7];
extern char sSceneInitTable2[];
extern char sSceneInitTable3[];
extern char sSceneInitTable4[];
extern char sSceneInitPathJtBgMainChar[];
extern char sSceneInitPathJtBgMainPltt[];
extern char sSceneInitPathJtObjMainChar[];
extern char sSceneInitPathXtObjMainPltt[];
extern char sSceneInitPathJbBgStep1Char[];
extern char sSceneInitPathJbBgStep1Pltt[];
extern char sSceneInitPathJbObjMainChar[];
extern char sSceneInitPathYbObjMainPltt[];
extern char sSceneInitPathJtTopScr[];
extern char sSceneInitPathJtStep1Scr[];
extern void *gCommentWork;


/*
 * sdk:      DWCi_SceneInit (libdwcutil.TWL.HYB.a(sceneinit.o))
 */

static void procFade(void);
static void DWCi_SceneInitProcWait(void);
void DWCi_SceneInit(void)
{
    char *n;

    DWCi_SETTIGNlInit();
    DWCi_MSGlInit();
    DWCi_FOCUSlInit();
    DWCi_HLlInit();
    DWCi_COMMENTlInit();
    if (DWCi_Language() == 1 && DWCi_Flag(2)) {
        n = sSceneInitTable2;
        gCommentWork = DWCi_MSGlRead(n);
    } else {
        n = sSceneInitTable1[DWCi_Language()];
        gCommentWork = DWCi_MSGlRead(n);
    }
    DWCi_CEINlRead(1, (char *)DWCi_Char((unsigned char *)sSceneInitTable3));
    DWCi_CEINlRead(0, (char *)DWCi_Char((unsigned char *)sSceneInitTable4));
    DWCi_CMNlLoadResource(sSceneInitPathJtBgMainChar, (LoadFunc)GXS_LoadBG1Char);
    DWCi_CMNlLoadResource(sSceneInitPathJtBgMainPltt, (LoadFunc)GXS_LoadBGPltt);
    DWCi_CMNlLoadResource(sSceneInitPathJtObjMainChar, (LoadFunc)GXS_LoadOBJ);
    DWCi_CMNlLoadResource(sSceneInitPathXtObjMainPltt, (LoadFunc)GXS_LoadOBJPltt);
    DWCi_CMNlLoadResource(sSceneInitPathJbBgStep1Char, (LoadFunc)GX_LoadBG2Char);
    DWCi_CMNlLoadResource(sSceneInitPathJbBgStep1Pltt, (LoadFunc)GX_LoadBGPltt);
    DWCi_CMNlLoadResource(sSceneInitPathJbObjMainChar, (LoadFunc)GX_LoadOBJ);
    DWCi_CMNlLoadResource(sSceneInitPathYbObjMainPltt, (LoadFunc)GX_LoadOBJPltt);
    switch (DWCi_Entry()) {
    case 0:
        DWCi_CMNlLoadResource(sSceneInitPathJtTopScr, (LoadFunc)GXS_LoadBG1Scr);
        break;
    case 1:
        DWCi_CMNlLoadResource(sSceneInitPathJtStep1Scr, (LoadFunc)GXS_LoadBG1Scr);
        break;
    }
    *(volatile unsigned short *)0x0400100A = (*(volatile unsigned short *)0x0400100A & ~3) | 3;
    *(volatile unsigned short *)0x0400000A = (*(volatile unsigned short *)0x0400000A & ~3) | 3;
    *(volatile unsigned short *)0x0400000A = (*(volatile unsigned short *)0x0400000A & ~3) | 3;
    DWCi_GXlVisible(1, 2);
    DWCi_GXlVisible(0, 2);
    DWCi_ChangeScene((unsigned int)procFade);
}


static void procFade(void)
{
	DWCi_EFFlFade(2, 1, 2, 0x14);
	DWCi_EFFlFade(2, 0, 2, 0x14);
	DWCi_ChangeScene((unsigned int)DWCi_SceneInitProcWait);
}


static void DWCi_SceneInitProcWait(void)
{
	if (DWCi_EFFlCheck(1))
		return;
	if (DWCi_EFFlCheck(0))
		return;
	switch (DWCi_Entry()) {
	case 0:
		DWCi_SetParam_(0, (unsigned int)(1));
		DWCi_ChangeScene((unsigned int)DWCi_SceneMenu);
		break;
	case 1:
		DWCi_SetParam_((unsigned int)(1), (unsigned int)(1));
		DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectAp);
		break;
	}
}
