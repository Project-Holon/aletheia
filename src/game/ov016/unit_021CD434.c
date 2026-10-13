/*
 * file:     unit_021CD434.c
 * unit:     yes
 * function: func_021CD434, func_021CD458, func_021CD4F4, func_021CD55C, func_021CD570
 * address:  0x021CD434
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
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CFBD4  0x021CFBD4  arm  ov016
 *   func_0205BE6C  0x0205BE6C  arm
 *   func_020589C4  0x020589C4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   g_021DE61C     0x021DE61C  data
 *   func_021C7CE4  0x021C7CE4  arm  ov016
 *   func_021CD580  0x021CD580  arm  ov016
 *   func_0205BC78  0x0205BC78  arm
 *   func_021BD7F4  0x021BD7F4  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_0205BD64  0x0205BD64  arm
 *   func_021C82EC  0x021C82EC  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021CD40C  0x021CD40C  arm  ov016
 *   DWCi_HEAPlAllocEx            0x021D6414  arm
 *   DWCi_HEAPlFree2              0x021D647C  arm
 */
extern int func_021D5580(int lcd);
extern void func_021C0E40(unsigned int v);
extern void *func_021CFBD4(void);
extern int func_0205BE6C(void);
extern void *func_020589C4();
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int lcd);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C7CE4(void);
extern void func_021CD580(void);
extern int func_0205BC78(void);
extern void func_021BD7F4(void);
extern void func_021D0014(void);
extern int func_0205BD64(void);
extern void func_021C82EC(unsigned int v);
extern void func_021CFFAC(unsigned int v);
extern void func_021D7724(int kind, void *task);
extern void func_021CD40C(void);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree2(void *mem);
void func_021CD434(void);
void func_021CD458(void);
void func_021CD4F4(void *task);
void *acAlloc(void *unused, unsigned long size);
void acFree(void *unused, void *ptr);
extern unsigned char g_021DE61C;


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD434.c \n *       --func func_021CD434 --addr 0x021CD434 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD434(void)
{
    if (func_021D5580(0))
        return;
    func_021C0E40((unsigned int)func_021CD458);
}


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesettest.o)
 */
void func_021CD458(void)
{
    unsigned char *map = func_021CFBD4();
    if (func_0205BE6C() == 0)
        return;
    func_02082D44(func_020589C4(), map + 0xF0, 14);
    func_02082D44(func_020589C4(), map + 0x1F0, 14);
    func_021BC8EC();
    func_021D5CA8(0);
    func_021D6090(0, 21);
    if (g_021DE61C == 0) {
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021C7CE4);
    } else {
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021CD580);
    }
}


/*
 * sdk:      taskAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD4F4.c \n *       --func func_021CD4F4 --addr 0x021CD4F4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD4F4(void *task)
{
    int rs = func_0205BC78();
    if (rs == 0)
        return;
    func_021BD7F4();
    func_021D0014();
    if (rs > 0) {
        g_021DE61C = 1;
        func_021CFFAC(17);
    } else {
        func_021C82EC(func_0205BD64());
        func_021CFFAC(18);
    }
    func_021C0E40((unsigned int)func_021CD40C);
    func_021D7724(0, task);
}


void *acAlloc(void *unused, unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}


void acFree(void *unused, void *ptr)
{
    DWCi_HEAPlFree2(ptr);
}
