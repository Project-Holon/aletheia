/*
 * file:     unit_021C3D8C.c
 * unit:     yes
 * function: func_021C3D8C, func_021C3DC8, func_021C3E48
 * address:  0x021C3D8C
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
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021BD1D4  0x021BD1D4  arm
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C3EC4  0x021C3EC4  arm  ov016
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

extern void func_021BD29C();
extern int func_021BD060();
extern void func_021C0E40(unsigned int v);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D55A4();
extern void func_021D603C(int lcd, int plane);
extern void func_021C3EC4();
void func_021C3D8C(void);
void func_021C3DC8(void);
void func_021C3E48(void);
extern unsigned char g_021DE5C0;


/*
 * sdk:      DWCi_SceneOptMovFailure (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
void func_021C3D8C(void)
{
    func_021C3DC8();
    func_021BD29C(0x20);
    g_021DE5C0 = func_021BD060(0x3C, -1, 0);
    func_021C0E40((unsigned int)func_021C3E48);
}


void func_021C3DC8(void)
{
    func_021BD1D4((void *)0x021DB3A4, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}


/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
void func_021C3E48(void)
{
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(0, 0x15);
    if (g_021DE5C0) {
        func_021D55A4(2, 1, 1, 8);
        func_021D603C(1, 1);
    }
    func_021C0E40((unsigned int)func_021C3EC4);
}
