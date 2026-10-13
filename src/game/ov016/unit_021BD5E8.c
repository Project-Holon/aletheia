/*
 * file:     unit_021BD5E8.c
 * unit:     yes
 * function: func_021BD5E8, func_021BD660, func_021BD674, func_021BD6D4, func_021BD6EC, func_021BD704
 * address:  0x021BD5E8
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
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   GX_LoadBG1Char 0x0207EF90  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   g_021DE554     0x021DE554  data
 *   g_021DAE54     0x021DAE54  data
 *   g_021DAE04     0x021DAE04  data
 *   DWCi_Char        0x021BD170  arm
 *   DWCi_ARClReadEx  0x021D4B68  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   DWCi_ARClRelease 0x021D4C68  arm
 *   DWCi_TSKlForm    0x021D7680  arm
 *   FILE_NAME        0x021DAE04  data  a4
 *   Buffer           0x021DE554  data  a4
 *   taskLoad         0x021BD704  arm
 *   DWCi_SETTIGNlGet             0x021CF404  arm
 *   func_020862F0  0x020862F0  arm
 *   func_021D7724  0x021D7724  arm  ov016
 */
extern void *func_021D6414(unsigned long size, int align);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned int func_021C0ED8(void);
extern void GX_LoadBG1Char(void *, unsigned long, unsigned long);
extern void GX_LoadBG1Scr(void *, unsigned long, unsigned long);
extern void func_021D6438(void **mem);
char *DWCi_Char(char *name);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
void DWCi_ARClRelease(void *file);
void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
void taskLoad(void *task);
typedef struct {
    unsigned char pad[0xF4];
    unsigned char idx;
} SETTINGINFO;
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void func_020862F0(void *addr, unsigned long n);
extern void func_021D7724(int kind, void *task);
void func_021BD5E8(void);
void func_021BD660(void);
void DWCi_HLlLoad(int idx);
void DWCi_HLlLoadSet(void);
void DWCi_HLlLoadList(void);
void func_021BD704(void *task);
extern unsigned short *g_021DE554;
extern char g_021DAE54[];
extern char *g_021DAE04[];
extern char *FILE_NAME[20];
extern unsigned short *Buffer;


/*
 * sdk:      DWCi_HLlInit (libdwcutil.TWL.HYB.a headline.o)
 */
void func_021BD5E8(void)
{
    g_021DE554 = func_021D6414(0xC0, 4);
    func_021BD1D4(g_021DAE54, GX_LoadBG1Char);
    switch (func_021C0ED8()) {
    case 0:
        func_021BD1D4(g_021DAE04[0], GX_LoadBG1Scr);
        break;
    case 1:
        func_021BD1D4(g_021DAE04[1], GX_LoadBG1Scr);
        break;
    }
}


/*
 * Tail-call func_021D6438 with the address of 0x021DE554.
 * Addresses are Black-image addresses.
 */
void func_021BD660(void)
{
    func_021D6438((void *)0x021DE554);
}


void DWCi_HLlLoad(int idx)
{
    char *n = DWCi_Char(FILE_NAME[idx]);
    void *file = DWCi_ARClReadEx(n, 0, 4);
    MIi_CpuCopyFast(file, Buffer, 0xc0);
    DWCi_ARClRelease(file);
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskLoad, 0, 0x78);
}


void DWCi_HLlLoadSet(void)
{
    DWCi_HLlLoad(DWCi_SETTIGNlGet()->idx + 5);
}


void DWCi_HLlLoadList(void)
{
    DWCi_HLlLoad(DWCi_SETTIGNlGet()->idx + 2);
}


void func_021BD704(void *task)
{
    func_020862F0(g_021DE554, 0xC0);
    GX_LoadBG1Scr(g_021DE554, 0, 0xC0);
    func_021D7724(1, task);
}
