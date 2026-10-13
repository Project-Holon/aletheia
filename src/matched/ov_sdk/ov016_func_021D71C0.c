/*
 * function: DWCi_OVRlFree
 * address:  0x021D71C0
 * packet:   pkt_ov016_021D71C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OVRlFree (libdwcutil.TWL.HYB.a(objvram.o))
 *
 * symbols:
 *   func_021D6D8C  0x021D6D8C  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 *   gObjvramWork  0x021DE6AC  data
 */

typedef struct {
	char pad[0x180];
	int node[6];
	void *list;
	void *que;
} OvrInfo;

extern void func_021D6D8C(void *ob);
extern void DWCi_QUElPushBack(void *que, void *data);
extern OvrInfo *gObjvramWork;

void DWCi_OVRlFree(void *ovram)
{
	int lcd = 0;

	func_021D6D8C(ovram);
	if ((char *)ovram >= (char *)gObjvramWork + 0x1a0)
		lcd = 1;
	DWCi_QUElPushBack(gObjvramWork[lcd].que, ovram);
}
