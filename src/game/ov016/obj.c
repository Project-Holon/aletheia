/*
 * file:     obj.c
 * unit:     yes
 * function: func_021D6E14, func_021D6EA4, func_021D6EEC, func_021D6F18, func_021D6F38, func_021D6F84
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_02082AC0  0x02082AC0  arm
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE6A8  0x021DE6A8  data
 *   func_020862F0  0x020862F0  arm
 *   func_0207E684  0x0207E684  arm
 *   func_0207E708  0x0207E708  arm
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
 */
extern void *func_021D6414(unsigned long size, int align);
extern void func_02082AC0(unsigned long data, void *dst, unsigned long size);
extern void *func_021D5410(long size, void *data, long dsize);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_020862F0(void *start, unsigned long n);
extern void func_0207E684(void *src, unsigned long off, unsigned long sz);
extern void func_0207E708(void *src, unsigned long off, unsigned long sz);
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void func_021D6438(void **mem);
extern void *func_021D54C4(void *queue);
extern void func_021D546C(void *que, void *elem);
void func_021D6E14(void);
void func_021D6EA4(void);
void func_021D6EEC(void);
void func_021D6F18(unsigned int i);
void func_021D6F38(unsigned int *obj);
char *func_021D6F84(unsigned int a, unsigned int b);
extern char *g_021DE6A8;


/*
 * sdk:      DWCi_OBJlInit (libdwcutil.TWL.HYB.a(obj.o))
 */
void func_021D6E14(void)
{
	int i;

	g_021DE6A8 = func_021D6414(0x80c, 4);
	func_02082AC0(0x200, g_021DE6A8, 0x800);
	for (i = 0; i < 2; i++)
		*(void **)(g_021DE6A8 + i * 4 + 0x800) = func_021D5410(0x40, g_021DE6A8 + i * 0x400, 8);
	*(void **)(g_021DE6A8 + 0x808) = func_021D7680(1, (void (*)(void *, void *))func_021D6EA4, 0, 0xc8);
}


void func_021D6EA4(void)
{
	func_020862F0(g_021DE6A8, 0x800);
	func_0207E684(g_021DE6A8, 0, 0x400);
	func_0207E708(g_021DE6A8 + 0x400, 0, 0x400);
}


/*
 * sdk:      DWCi_OBJlEnd (libdwcutil.TWL.HYB.a(obj.o))
 */
void func_021D6EEC(void)
{
	DWCi_TSKlDeleteByIndex(1, *(void **)(g_021DE6A8 + 0x808));
	func_021D6438((void *)0x021DE6A8);
}


/*
 * Tail-call func_021D54C4 with an indexed pointer out of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D6F18.c \
 *       --func func_021D6F18 --addr 0x021D6F18 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D6F18(unsigned int i)
{
    char *p = *(char **)0x021DE6A8;
    func_021D54C4(*(void **)(p + (i << 2) + 0x800));
}


/*
 * sdk:      DWCi_OBJlDelete (libdwcutil.TWL.HYB.a(obj.o))
 */
void func_021D6F38(unsigned int *obj)
{
	int lcd;

	*obj = (*obj & 0xc1fffcff) | 0x200;
	lcd = 0;
	if ((char *)obj >= g_021DE6A8 + 0x400)
		lcd = 1;
	func_021D546C(*(void **)(g_021DE6A8 + 0x800 + lcd * 4), obj);
}

/*
 * Index a (a,b) record of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D6F84.c \
 *       --func func_021D6F84 --addr 0x021D6F84 --region ov016 --cc dsi/1.1p1 --arm
 */
char *func_021D6F84(unsigned int a, unsigned int b)
{
    return *(char **)0x021DE6A8 + (a << 10) + (b << 3);
}
