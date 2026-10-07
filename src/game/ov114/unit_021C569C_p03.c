/*
 * file:     unit_021C569C_p03.c
 * unit:     yes
 * function: func_021C5AB8, func_021C5B80, func_021C5C04, func_021C5C38, func_021C5CFC, func_021C5DB4, func_021C5E14
 * address:  0x021C5AB8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 *   func_021C56CC  0x021C56CC  arm  ov114
 *   func_021C651C  0x021C651C  arm  ov114
 *   func_02059F38  0x02059F38  arm
 *   func_021C5F90  0x021C5F90  arm  ov114
 *   func_021C659C  0x021C659C  arm  ov114
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021C7124  0x021C7124  arm  ov114
 *   func_021C73C0  0x021C73C0  arm  ov114
 *   func_021C666C  0x021C666C  arm  ov114
 *   func_021C757C  0x021C757C  arm  ov114
 */
#include "../../matched/include/G_NdState.h"

struct DWCNdFileInfo;
typedef struct NdState NdState;

typedef struct NdParam {
    unsigned char pad0[0x40];
    int f40;
} NdParam;

extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void func_021C56CC(void);
extern void func_021C651C(void (*callback)(void));
extern int func_02059F38(void);
extern int func_021C5F90(char *attr1, char *attr2, char *attr3);
extern void func_021C659C(int err, int servererror);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_021C7124(void *filelist, int offset, int num);
extern int func_021C73C0(struct DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
extern int func_021C666C(void);
extern int func_021C757C(unsigned long *received, unsigned long *contentlen);
void func_021C5AB8(void);
int func_021C5B80(void);
int func_021C5C04(char *attr1, char *attr2, char *attr3);
int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
int func_021C5DB4(void);
int func_021C5E14(unsigned long *received, unsigned long *contentlen);
extern char g_021D3B84[];
extern struct NdState g_021D3B68;


/*
 * sdk:      DWC_NdProcess (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
void func_021C5AB8(void)
{
    int needCallback = 0;
    int needCleanUpCallback = 0;
    int reason;

    func_02086028(g_021D3B84);
    reason = g_021D3B68.f10;
    if (reason == 0 && g_021D3B68.f14 == 4) {
        if (g_021D3B68.f4 == 0) {
            needCallback = 1;
            g_021D3B68.f4 = 1;
        }
    } else if ((unsigned int)(g_021D3B68.f14 - 3) <= 1) {
        needCallback = 1;
        g_021D3B68.f14 = 1;
    }
    if (reason == 4) {
        g_021D3B68.f14 = 0;
        g_021D3B68.f10 = 0;
        needCleanUpCallback = 1;
    }
    OS_UnlockMutex(g_021D3B84);
    if (g_021D3B68.cb == 0)
        return;
    if (needCleanUpCallback) {
        g_021D3B68.cb(4, 0, -1);
    } else if (needCallback) {
        g_021D3B68.cb(g_021D3B68.f10, g_021D3B68.fC, g_021D3B68.f8);
    }
}


int func_021C5B80(void)
{
    if (g_021D3B68.f14 == 0)
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 == 0) {
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    g_021D3B68.f14 = 2;
    OS_UnlockMutex(g_021D3B84);
    if (((NdParam *)g_021D3B68.svl)->f40 == 0)
        func_021C56CC();
    else
        func_021C651C(func_021C56CC);
    return 1;
}


/*
 * sdk:      DWC_NdSetAttr (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int func_021C5C04(char *attr1, char *attr2, char *attr3)
{
    if (func_02059F38())
        return 0;
    return func_021C5F90(attr1, attr2, attr3);
}


/*
 * sdk:      DWC_NdGetFileListAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int func_021C5C38(void *filelist, unsigned int offset, unsigned int num)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 1) {
        func_021C659C(2, 0);
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    g_021D3B68.f14 = 2;
    OS_UnlockMutex(g_021D3B84);
    MI_CpuFill8(filelist, 0, num * 0xB0);
    if (func_021C7124(filelist, offset, num))
        return 1;
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 1;
    OS_UnlockMutex(g_021D3B84);
    return 0;
}


/*
 * sdk:      DWC_NdGetFileAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int func_021C5CFC(void *fileinfo, char *buf, unsigned int size)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 1) {
        func_021C659C(2, 0);
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    g_021D3B68.f14 = 2;
    OS_UnlockMutex(g_021D3B84);
    if (func_021C73C0(fileinfo, buf, size, 0))
        return 1;
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 1;
    OS_UnlockMutex(g_021D3B84);
    return 0;
}


/*
 * sdk:      DWC_NdCancelAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int func_021C5DB4(void)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 2) {
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    OS_UnlockMutex(g_021D3B84);
    return func_021C666C() != 0;
}


int func_021C5E14(unsigned long *received, unsigned long *contentlen)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 2) {
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    OS_UnlockMutex(g_021D3B84);
    return func_021C757C(received, contentlen);
}
