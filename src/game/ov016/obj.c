/*
 * file:     obj.c
 * unit:     yes
 * function: DWCi_OBJlInit, taskTransfer, DWCi_OBJlEnd, DWCi_OBJlFormGx, DWCi_OBJlDelete, DWCi_OBJlGetOam
 * address:  0x021D6E14
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
 *   DWCi_QUElPopBack               0x021D54C4  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gObjWork  0x021DE6A8  data
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 */
extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void MIi_CpuClearFast(unsigned long data, void *dst, unsigned long size);
extern void *DWCi_QUElFormEx(long size, void *data, long dsize);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DC_FlushRange(void *start, unsigned long n);
extern void GX_LoadOAM(void *src, unsigned long off, unsigned long sz);
extern void GXS_LoadOAM(void *src, unsigned long off, unsigned long sz);
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_QUElPopBack(void *queue);
extern void DWCi_QUElPushBack(void *que, void *elem);
void DWCi_OBJlInit(void);
void DWCi_OBJlEnd(void);
void DWCi_OBJlFormGx(unsigned int i);
void DWCi_OBJlDelete(unsigned int *obj);
char *DWCi_OBJlGetOam(unsigned int a, unsigned int b);
extern char *gObjWork;


/*
 * sdk:      DWCi_OBJlInit (libdwcutil.TWL.HYB.a(obj.o))
 */

static void taskTransfer(void);
void DWCi_OBJlInit(void)
{
	int i;

	gObjWork = DWCi_HEAPlAllocEx(0x80c, 4);
	MIi_CpuClearFast(0x200, gObjWork, 0x800);
	for (i = 0; i < 2; i++)
		*(void **)(gObjWork + i * 4 + 0x800) = DWCi_QUElFormEx(0x40, gObjWork + i * 0x400, 8);
	*(void **)(gObjWork + 0x808) = DWCi_TSKlForm(1, (void (*)(void *, void *))taskTransfer, 0, 0xc8);
}


static void taskTransfer(void)
{
	DC_FlushRange(gObjWork, 0x800);
	GX_LoadOAM(gObjWork, 0, 0x400);
	GXS_LoadOAM(gObjWork + 0x400, 0, 0x400);
}


/*
 * sdk:      DWCi_OBJlEnd (libdwcutil.TWL.HYB.a(obj.o))
 */
void DWCi_OBJlEnd(void)
{
	DWCi_TSKlDeleteByIndex(1, *(void **)(gObjWork + 0x808));
	DWCi_HEAPlFree_((void *)0x021DE6A8);
}


/*
 * Tail-call DWCi_QUElPopBack with an indexed pointer out of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_OBJlFormGx.c \
 *       --func DWCi_OBJlFormGx --addr 0x021D6F18 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_OBJlFormGx(unsigned int i)
{
    char *p = *(char **)0x021DE6A8;
    DWCi_QUElPopBack(*(void **)(p + (i << 2) + 0x800));
}


/*
 * sdk:      DWCi_OBJlDelete (libdwcutil.TWL.HYB.a(obj.o))
 */
void DWCi_OBJlDelete(unsigned int *obj)
{
	int lcd;

	*obj = (*obj & 0xc1fffcff) | 0x200;
	lcd = 0;
	if ((char *)obj >= gObjWork + 0x400)
		lcd = 1;
	DWCi_QUElPushBack(*(void **)(gObjWork + 0x800 + lcd * 4), obj);
}

/*
 * Index a (a,b) record of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_OBJlGetOam.c \
 *       --func DWCi_OBJlGetOam --addr 0x021D6F84 --region ov016 --cc dsi/1.1p1 --arm
 */
char *DWCi_OBJlGetOam(unsigned int a, unsigned int b)
{
    return *(char **)0x021DE6A8 + (a << 10) + (b << 3);
}
