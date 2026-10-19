/*
 * file:     move.c
 * unit:     yes
 * function: DWCi_MOVlInit, DWCi_MOVlEnd, DWCi_MoveTaskEnd, DWCi_MOVlIsEnd, DWCi_MOVlChangeCallback, DWCi_MOVlAdmitChild, DWCi_MOVlGetChild, taskFramework
 * address:  0x021C1074
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * ARM tail-call thunk into DWCi_MOVStartDownloadandBootChild.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOVlAdmitChild.c \
 *       --func DWCi_MOVlAdmitChild --addr 0x021C11EC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_MOVStartDownloadandBootChild 0x021D3D8C  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_MSGlGet  0x021C1030  arm  ov016
 *   kDWCi_Language  0x021C0F20  arm  ov016
 *   DWCi_MOVInit  0x021D3B18  arm  ov016
 *   DWCi_MOVStartAdmitChild  0x021D3D44  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gMoveWork  0x021DE590  data
 *   sMoveTable  0x021DB0B0  data
 *   gCommentWork  0x021DE598  data
 *   taskFramework  0x021C1210  arm  ov016
 *   DWCi_MoveTaskEnd                          0x021C117C  arm
 *   DWCi_MOVFinalize  0x021D3BF8  arm  ov016
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_MOVFramework  0x021D3DC0  arm  ov016
 *   DWCi_MOVGetStatus  0x021D40F4  arm  ov016
 *   DWCi_GetChildInfo  0x021D4138  arm  ov016
 *   MIi_CpuCopy16      0x02082A60  arm
 *   DWCi_HEAPlFree_    0x021D6438  arm  ov016
 */
typedef struct {
	int w[7];
} MovData;

typedef void (*MoveCallback)(int);

typedef struct MoveWork {
	unsigned char body[0x1e280];
	unsigned char childInfo[0x18];
	MoveCallback callback;
	void *task;
	unsigned char reportPending;
	unsigned char ended;
	unsigned char pad[2];
} MoveWork;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx);
extern unsigned char kDWCi_Language(void);
extern void DWCi_MOVInit(void *wm, MovData *md);
extern int DWCi_MOVStartAdmitChild(void);
extern void OS_Terminate(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern int DWCi_MOVFinalize(void);
extern int DWCi_MOVStartDownloadandBootChild(void);
extern void DWCi_MOVFramework(void);
extern void DWCi_MOVGetStatus(unsigned char *stt, unsigned char *change_f);
extern void *DWCi_GetChildInfo(void);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_HEAPlFree_(void **mem);
void DWCi_MOVlInit(void (*callback)(int));
void DWCi_MOVlEnd(void);
int DWCi_MOVlIsEnd(void);
void DWCi_MOVlChangeCallback(unsigned int v);
void DWCi_MOVlAdmitChild(void);
char *DWCi_MOVlGetChild(void);
void taskFramework(void *task);
extern MoveWork *gMoveWork;
extern MovData sMoveTable;
extern void *gCommentWork;
extern void *MemMovFree;


/*
 * sdk:      DWCi_MOVlInit (libdwcutil.TWL.HYB.a(move.o))
 */

static void DWCi_MoveTaskEnd(void *task);
void DWCi_MOVlInit(void (*callback)(int))
{
	MovData dat;

	gMoveWork = DWCi_HEAPlAllocEx(0x1e2a4, 0x20);
	gMoveWork->callback = callback;
	gMoveWork->reportPending = 0;
	gMoveWork->ended = 0;
	dat = sMoveTable;
	dat.w[1] = (int)DWCi_MSGlGet(gCommentWork, 0);
	dat.w[2] = (int)DWCi_MSGlGet(gCommentWork, 1);
	*(unsigned char *)&dat.w[6] = kDWCi_Language();
	DWCi_MOVInit(gMoveWork, &dat);
	if (DWCi_MOVStartAdmitChild() == 0)
		OS_Terminate();
	gMoveWork->task = DWCi_TSKlForm(0, taskFramework, 0, 0x78);
}


void DWCi_MOVlEnd(void)
{
    DWCi_TSKlForm(0, DWCi_MoveTaskEnd, 0, 0x78);
}


/*
 * sdk:      DWCi_MoveTaskEnd (libdwcutil.TWL.HYB.a(move.o))
 */
static void DWCi_MoveTaskEnd(void *task)
{
	if (DWCi_MOVFinalize() == 0)
		return;
	gMoveWork->ended = 1;
	DWCi_TSKlDelete(0, task);
}


int DWCi_MOVlIsEnd(void)
{
    return gMoveWork == 0;
}


/*
 * Store a word at +0x1e298 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOVlChangeCallback.c \
 *       --func DWCi_MOVlChangeCallback --addr 0x021C11D4 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MOVlChangeCallback(unsigned int v)
{
    gMoveWork->callback = (MoveCallback)v;
}


void DWCi_MOVlAdmitChild(void)
{
    DWCi_MOVStartDownloadandBootChild();
}


/*
 * Address of the object behind the global pointer, +0x1e280.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOVlGetChild.c \
 *       --func DWCi_MOVlGetChild --addr 0x021C11F8 --region ov016 --cc dsi/1.1p1 --arm
 */
char *DWCi_MOVlGetChild(void)
{
    return *(char **)0x021DE590 + 0x1e280;
}


void taskFramework(void *task)
{
	unsigned char state;
	unsigned char change;
	void (*func)(int);

	DWCi_MOVFramework();
	if (gMoveWork->reportPending != 0) {
		if (gMoveWork->ended == 0) {
			func = gMoveWork->callback;
			if (func != 0)
				func(0);
			return;
		}
	}
	DWCi_MOVGetStatus((unsigned char *)&state, &change);
	switch (state) {
	case 1:
	case 2:
	case 3:
	case 4:
		break;
	case 5:
		if (change != 0) {
			char *dst;
			void *src;
			dst = (char *)gMoveWork->childInfo;
			src = DWCi_GetChildInfo();
			MIi_CpuCopy16(src, dst, 0x16);
			func = gMoveWork->callback;
			if (func == 0) {
				gMoveWork->reportPending = 1;
				return;
			}
			func(0);
		}
		break;
	case 13:
		if (change != 0) {
			func = gMoveWork->callback;
			if (func == 0) {
				gMoveWork->reportPending = 1;
				return;
			}
			func(1);
		}
		break;
	case 20:
	case 23:
		if (change != 0) {
			func = gMoveWork->callback;
			if (func == 0) {
				gMoveWork->reportPending = 1;
				return;
			}
			func(3);
		}
		break;
	case 26:
	case 29:
		if (change != 0) {
			func = gMoveWork->callback;
			if (func == 0) {
				gMoveWork->reportPending = 1;
				return;
			}
			func(4);
		}
		break;
	case 12:
		if (change != 0) {
			func = gMoveWork->callback;
			if (func == 0) {
				gMoveWork->reportPending = 1;
				return;
			}
			func(2);
		}
		break;
	case 34:
		DWCi_TSKlDelete(0, task);
		DWCi_HEAPlFree_(&MemMovFree);
		break;
	}
}
