/*
 * function: DWCi_OVRlInit
 * address:  0x021D6F9C
 * packet:   pkt_ov016_021D6F9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OVRlInit (libdwcutil.TWL.HYB.a(objvram.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_LSTlForm  0x021D6D44  arm  ov016
 *   DWCi_LSTlPushFront  0x021D6E04  arm  ov016
 *   DWCi_LSTlPushBack  0x021D6DF4  arm  ov016
 *   gObjvramWork  0x021DE6AC  data
 */

typedef struct {
	int a;
	int b;
	short size;
	short d;
} OvrNode;

typedef struct {
	char pad[0x180];
	OvrNode node[2];
	void *list;
	void *que;
} OvrInfo;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void *DWCi_QUElFormEx(long size, void *data, long dsize);
struct ListCB;
extern struct ListCB *DWCi_LSTlForm(void);
extern void DWCi_LSTlPushFront(char *p, void *ob);
extern void DWCi_LSTlPushBack(char *p, void *ob);
extern OvrInfo *gObjvramWork;

void DWCi_OVRlInit(void)
{
	int i;

	gObjvramWork = DWCi_HEAPlAllocEx(0x340, 4);
	for (i = 0; i < 2; i++) {
		gObjvramWork[i].que = DWCi_QUElFormEx(0x20, &gObjvramWork[i], 0xc);
		gObjvramWork[i].list = DWCi_LSTlForm();
		gObjvramWork[i].node[0].size = 0x300;
		gObjvramWork[i].node[1].size = 0x400;
		DWCi_LSTlPushFront(gObjvramWork[i].list, &gObjvramWork[i].node[0]);
		DWCi_LSTlPushBack(gObjvramWork[i].list, &gObjvramWork[i].node[1]);
	}
}
