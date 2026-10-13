/*
 * function: func_021C1678
 * address:  0x021C1678
 * packet:   pkt_ov016_021C1678
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneend.o))
 *
 * symbols:
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

extern int DWCi_EFFlCheck(int lcd);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void DWCi_TSKlOperate(u32 index, u8 val);
extern void DWCi_CEINlRelease(int lcd);
extern void DWCi_HLlEnd(void);
extern void DWCi_FOCUSlEnd(void);
extern void DWCi_MSGlRelease(void *msg);
extern void DWCi_MSGlEnd(void);
extern void DWCi_SETTIGNlEnd(void);
extern void DWCi_EndUtility(void);
extern void *gCommentWork;

void func_021C1678(void)
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
