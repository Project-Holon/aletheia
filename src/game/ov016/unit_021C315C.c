/*
 * file:     unit_021C315C.c
 * unit:     yes
 * function: func_021C315C, func_021C3194, func_021C3214, func_021C3250
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
 *   func_021C3358  0x021C3358  arm  ov016
 *   DWCi_SceneOptMovComm_procScene  0x021C3280  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

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
extern void func_021C3358(int state);
extern void DWCi_SceneOptMovComm_procScene(void);
void func_021C315C(void);
void func_021C3194(void);
void func_021C3214(void);
void func_021C3250(void);


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
