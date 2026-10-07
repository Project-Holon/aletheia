/*
 * file:     unit_021CA5D0.c
 * unit:     yes
 * function: func_021CA5D0, func_021CA5F0
 * address:  0x021CA5D0
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
 *   initGraphics                     0x021ca5f0 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_SETTINGlSet                 0x021cf8d8 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procInit                         0x021ca684 arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB600    0x021DB600  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_021DB618    0x021DB618  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_021DB630    0x021DB630  data
 *   dat_0207EB78    0x0207EB78  data
 */
typedef unsigned short u16;

extern void DWCi_HLlLoadSet(void);
extern void DWCi_SETTINGlSet(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
void DWCi_SceneSetListSave(void);
void func_021CA5F0(void);
extern unsigned short dat_021DB600[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_021DB618[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_021DB630[];
extern unsigned short dat_0207EB78[];


static void initGraphics(void);

static void procInit(void);


void DWCi_SceneSetListSave(void)
{
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_SETTINGlSet();
    DWCi_ChangeScene(procInit);
}


/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of
 * 0x04001008, 0x0400100A, 0x0400000A and 0x0400000C.
 * Addresses are Black-image addresses.
 */
void func_021CA5F0(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB600), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB618), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB630), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
