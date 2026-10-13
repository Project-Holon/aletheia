/*
 * file:     sceneoptmovcomm.c
 * unit:     yes
 * function: func_021C315C, func_021C3194, func_021C3214, func_021C3250, DWCi_SceneOptMovComm_procScene, DWCi_SceneOptMovComm_input, DWCi_SceneOptMovComm_draw, func_021C3298, func_021C32C0, func_021C3358
 * address:  0x021C315C
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
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021BC820  0x021BC820  arm  ov016
 *   func_021BD744  0x021BD744  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021C11B8  0x021C11B8  arm
 *   func_021BD7F4  0x021BD7F4  arm
 *   func_021BC8EC  0x021BC8EC  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   g_021DE5B4     0x021DE5B4  data
 *   func_021C3D8C  0x021C3D8C  arm
 *   func_021C3B8C  0x021C3B8C  arm
 *   func_021C33CC  0x021C33CC  arm
 *   func_021CFC20  0x021CFC20  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021C115C  0x021C115C  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef unsigned char u8;

extern void func_021BD29C(int msg);
extern void func_021BC820(int color);
extern void func_021BD744(int type);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021D603C(int lcd, int plane);
extern int func_021D5580(int lcd);
extern void func_021C11D4(unsigned int v);
extern int  func_021C11B8(void);
extern void func_021BD7F4(void);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int x);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C3D8C(void);
extern void func_021C3B8C(void);
extern void func_021C33CC(void);
extern void func_021CFC20(void);
extern void func_021D0014(void);
extern void func_021C115C(void);
void func_021C315C(void);
void func_021C3194(void);
void func_021C3214(void);
void func_021C3250(void);
void DWCi_SceneOptMovComm_procScene(void);
void DWCi_SceneOptMovComm_input(void);
void DWCi_SceneOptMovComm_draw(void);
void func_021C3298(void);
void func_021C32C0(void);
void func_021C3358(int state);
extern u8   g_021DE5B4;



/*
 * sdk:      DWCi_SceneOptMovComm (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
void func_021C315C(void)
{
	func_021C3194();
	func_021BD29C(0x1e);
	func_021BC820(0);
	func_021BD744(1);
	func_021CFFAC(0xb);
	func_021C0E40((unsigned int)func_021C3214);
}



void func_021C3194(void)
{
    func_021BD1D4((void *)0x021DB368, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}



/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
void func_021C3214(void)
{
	func_021D55A4(2, 0, 0x15, 8);
	func_021D603C(0, 0x15);
	func_021C0E40((unsigned int)func_021C3250);
}



void func_021C3250(void)
{
	if (func_021D5580(0))
		return;
	func_021C11D4((unsigned int)func_021C3358);
	func_021C0E40((unsigned int)DWCi_SceneOptMovComm_procScene);
}



void DWCi_SceneOptMovComm_procScene(void)
{
    DWCi_SceneOptMovComm_input();
    DWCi_SceneOptMovComm_draw();
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_input.c \
 *       --func DWCi_SceneOptMovComm_input --addr 0x021C3290 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_input(void)
{
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_draw.c \
 *       --func DWCi_SceneOptMovComm_draw --addr 0x021C3294 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_draw(void)
{
}




/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
void func_021C3298(void)
{
	func_021D55A4(3, 0, 0x15, 8);
	func_021C0E40((unsigned int)func_021C32C0);
}




void func_021C32C0(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (func_021C11B8() == 0)
        return;
    func_021BD7F4();
    func_021BC8EC();
    func_021D5CA8(0);
    func_021D6090(0, 0x15);
    func_021C0E50(0, 1);
    if (g_021DE5B4 == 0) {
        func_021C0E40((unsigned int)func_021C3D8C);
        return;
    }
    if (g_021DE5B4 == 2) {
        func_021C0E40((unsigned int)func_021C3B8C);
        return;
    }
    func_021C0E40((unsigned int)func_021C33CC);
}



/*
 * sdk:      cbMov (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 */
void func_021C3358(int state)
{
	if (state == 2) {
		func_021CFC20();
		g_021DE5B4 = 1;
		func_021D0014();
		func_021CFFAC(0x10);
	} else if (state == 3) {
		g_021DE5B4 = 2;
		func_021D0014();
		func_021CFFAC(0x12);
	} else {
		g_021DE5B4 = 0;
		func_021D0014();
		func_021CFFAC(0x12);
	}
	func_021C11D4(0);
	func_021C115C();
	func_021C0E40((unsigned int)func_021C3298);
}
