/*
 * function: DWCi_MOVlInit
 * address:  0x021C1074
 * packet:   pkt_ov016_021C1074
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVlInit (libdwcutil.TWL.HYB.a(move.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_MSGlGet  0x021C1030  arm  ov016
 *   func_021C0F20  0x021C0F20  arm  ov016
 *   DWCi_MOVInit  0x021D3B18  arm  ov016
 *   DWCi_MOVStartAdmitChild  0x021D3D44  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gMoveWork  0x021DE590  data
 *   sMoveTable  0x021DB0B0  data
 *   gCommentWork  0x021DE598  data
 *   func_021C1210  0x021C1210  arm  ov016
 */

typedef struct {
	int w[7];
} MovData;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx);
extern unsigned char func_021C0F20(void);
extern void DWCi_MOVInit(void *wm, MovData *md);
extern int DWCi_MOVStartAdmitChild(void);
extern void OS_Terminate(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021C1210(void *task, void *arg);
extern char *gMoveWork;
extern MovData sMoveTable;
extern void *gCommentWork;

void DWCi_MOVlInit(void (*callback)(int))
{
	MovData dat;

	gMoveWork = DWCi_HEAPlAllocEx(0x1e2a4, 0x20);
	*(void (**)(int))(gMoveWork + 0x1e298) = callback;
	gMoveWork[0x1e2a0] = 0;
	gMoveWork[0x1e2a1] = 0;
	dat = sMoveTable;
	dat.w[1] = (int)DWCi_MSGlGet(gCommentWork, 0);
	dat.w[2] = (int)DWCi_MSGlGet(gCommentWork, 1);
	*(unsigned char *)&dat.w[6] = func_021C0F20();
	DWCi_MOVInit(gMoveWork, &dat);
	if (DWCi_MOVStartAdmitChild() == 0)
		OS_Terminate();
	*(void **)(gMoveWork + 0x1e29c) = DWCi_TSKlForm(0, func_021C1210, 0, 0x78);
}
