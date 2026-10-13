/*
 * function: DWCi_OBJlDelete
 * address:  0x021D6F38
 * packet:   pkt_ov016_021D6F38
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlDelete (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   gObjWork  0x021DE6A8  data
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 */

extern void DWCi_QUElPushBack(void *que, void *elem);
extern char *gObjWork;

void DWCi_OBJlDelete(unsigned int *obj)
{
	int lcd;

	*obj = (*obj & 0xc1fffcff) | 0x200;
	lcd = 0;
	if ((char *)obj >= gObjWork + 0x400)
		lcd = 1;
	DWCi_QUElPushBack(*(void **)(gObjWork + 0x800 + lcd * 4), obj);
}
