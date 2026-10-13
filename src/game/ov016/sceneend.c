/*
 * file:     sceneend.c
 * unit:     yes
 * function: func_021C1630, func_021C1678
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
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D7794  0x021D7794  arm  ov016
 *   func_021D52B0  0x021D52B0  arm  ov016
 *   func_021BD660  0x021BD660  arm  ov016
 *   func_021BD404  0x021BD404  arm  ov016
 *   func_021C1004  0x021C1004  arm  ov016
 *   func_021C0F98  0x021C0F98  arm  ov016
 *   func_021CF3F0  0x021CF3F0  arm  ov016
 *   func_021C0F0C  0x021C0F0C  arm  ov016
 *   g_021DE598  0x021DE598  data
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern int func_021D5580(int lcd);
extern void func_021D7794(u32 index, u8 val);
extern void func_021D52B0(int lcd);
extern void func_021BD660(void);
extern void func_021BD404(void);
extern void func_021C1004(void *msg);
extern void func_021C0F98(void);
extern void func_021CF3F0(void);
extern void func_021C0F0C(void);
void func_021C1630(void);
void func_021C1678(void);
extern void *g_021DE598;


/*
 * sdk:      DWCi_SceneEnd (libdwcutil.TWL.HYB.a(sceneend.o))
 */
void func_021C1630(void)
{
	func_021D55A4(3, 1, 0x3f, 0x14);
	func_021D55A4(3, 0, 0x3f, 0x14);
	func_021C0E40((unsigned int)func_021C1678);
}


void func_021C1678(void)
{
	if (func_021D5580(1))
		return;
	if (func_021D5580(0))
		return;
	func_021D7794(0, 0);
	func_021D7794(1, 0);
	func_021D52B0(1);
	func_021D52B0(0);
	func_021BD660();
	func_021BD404();
	func_021C1004(g_021DE598);
	func_021C0F98();
	func_021CF3F0();
	func_021C0F0C();
}
