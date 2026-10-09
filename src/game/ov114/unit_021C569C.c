/*
 * file:     unit_021C569C.c
 * unit:     yes
 * function: func_021C569C, func_021C56B4, func_021C56CC, func_021C5724, func_021C58C8, func_021C5928, func_021C5AB8, func_021C5B80, func_021C5C04, func_021C5C38, func_021C5CFC, func_021C5DB4, func_021C5E14
 * address:  0x021C569C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085710  0x02085710  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   g_021D3B68     0x021D3B68  data ov114
 *   g_021D3B84     0x021D3B84  data ov114
 *   func_02168040  0x02168040  arm  ov009
 *   strlen         0x0209477C  arm
 *   func_02084F80  0x02084F80  arm
 *   func_02059B40  0x02059B40  arm
 *   func_021C6348  0x021C6348  arm  ov114
 *   func_02059E18  0x02059E18  arm
 *   func_02059F54  0x02059F54  arm
 *   func_02085A38  0x02085A38  arm
 *   func_021C659C  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   func_02059F38  0x02059F38  arm
 *   func_02086004  0x02086004  arm
 *   func_02082BCC  0x02082BCC  arm
 *   strncpy        0x02094860  arm
 *   func_02167FA8  0x02167FA8  arm
 *   func_020853C0  0x020853C0  arm
 *   func_02085868  0x02085868  arm
 *   g_021CF370     0x021CF370  data
 *   func_021C651C  0x021C651C  arm  ov114
 *   func_021C5F90  0x021C5F90  arm  ov114
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021C7124  0x021C7124  arm  ov114
 *   func_021C73C0  0x021C73C0  arm  ov114
 *   func_021C666C  0x021C666C  arm  ov114
 *   func_021C757C  0x021C757C  arm  ov114
 *   @16277         0x021CF348  data
 *   @16278         0x021CF35C  data
 */
#include "../../matched/include/G_NdState.h"
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_NdState.h"

struct DWCNdFileInfo;
typedef unsigned char u8;

typedef unsigned int u32_021C569C;

typedef unsigned long u32_021C5724;

typedef struct SvlResult {
    char gamecd[0x20];          /* +0x00 */
    char passwd[0x20];          /* +0x20 */
    int status;                 /* +0x40 */
    char pad44[4];
    char svlhost[0x89 - 0x48];  /* +0x48 */
    char svltoken[1];           /* +0x89 */
} SvlResult;

typedef struct NdState NdState;

typedef struct NdParam {
    char gamecd[0x20];
    char passwd[0x20];
    int f40;
    unsigned char svl[0x1b8 - 0x44];
    unsigned char stack[0x800];
    unsigned char thread[0xa78 - 0x9b8];
} NdParam;

extern void *func_0205A17C(int name, unsigned long size, int align);
extern void func_0205A1B0(int, int, int);
void func_02085710(void *p);
void func_02086028(void *mutex);
void OS_UnlockMutex(void *mutex);
extern int func_02168040(void);
extern int func_02084F80(char *dst, u32_021C5724 len, const char *fmt, ...);
extern int func_02059B40(char *src, u32_021C5724 srclen, char *dst, u32_021C5724 dstlen);
extern int func_021C6348(void *(*alloc)(u32_021C5724, int), void (*free)(void *), char *url,
                         char *token, char *gamecd, char *passwd,
                         void (*callback)(int, int, int));
extern int func_02059E18(int *errorCode);
extern void func_02059F54(int error, int errorCode);
extern void func_02085A38(u32_021C5724 msec);
extern void func_021C659C(int err, int servererror);
extern int func_02059F38(void);
extern void func_02086004(void *mutex);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern int func_02167FA8(char *svl, void *result);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack,
                          unsigned long stackSize, unsigned long prio);
extern void func_02085868(void *thread);
extern void func_021C651C(void (*callback)(void));
extern int func_021C5F90(char *attr1, char *attr2, char *attr3);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_021C7124(void *filelist, int offset, int num);
extern int func_021C73C0(struct DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
extern int func_021C666C(void);
extern int func_021C757C(unsigned long *received, unsigned long *contentlen);
void *func_021C569C(unsigned long size, int align);
void func_021C56B4(void *ptr);
void func_021C56CC(void);
void func_021C58C8(int reason, int error, int servererror);
int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
void func_021C5AB8(void);
int func_021C5B80(void);
int func_021C5C04(char *attr1, char *attr2, char *attr3);
int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
int func_021C5DB4(void);
int func_021C5E14(unsigned long *received, unsigned long *contentlen);
extern struct NdState g_021D3B68;
extern char g_021D3B84[];
extern char g_021CF370[];



/*
 * Thunk: func_0205A17C(10, a, b) through the literal pool.
 */
void *func_021C569C(unsigned long size, int align)
{
    return func_0205A17C(0xa, size, align);
}



/*
 * Thunk: func_0205A1B0(10, a, 0) through the literal pool.
 */
void func_021C56B4(void *ptr)
{
    func_0205A1B0(0xa, (int)ptr, 0);
}



void func_021C56CC(void)
{
    func_02085710((char *)g_021D3B68.svl + 0x1b8 + 0x800);
    func_021C56B4(g_021D3B68.svl);
    g_021D3B68.svl = 0;
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 3;
    g_021D3B68.f10 = 4;
    OS_UnlockMutex(g_021D3B84);
}




/*
 * sdk:      DWCi_SVLTokenWaitThread (libdwcnd.TWL.HYB.a(dwc_nd.o))
 *
 * DWC_SVLProcess (0x02168040) is catalogued in ov009 (libdwcnas.TWL.HYB.a,
 * dwc_nasfunc.o), which the ov009 token on its line records.  The file statics
 * of dwc_nd.o are reached through s_userCallback (0x021D3B68); +0x18 holds the
 * SVL result pointer.
 */
static void func_021C5724(void)
{
    char url[256];
    char token[400];
    int errorcode;

    while (1) {
        switch (func_02168040()) {
        case 3:
            if (strlen(((SvlResult *)g_021D3B68.svl)->svlhost) + strlen("https:///download") > sizeof(url) - 1) {
                func_021C58C8(0, 8, -1);
                return;
            }
            func_02084F80(url, sizeof(url), "https://%s/download", ((SvlResult *)g_021D3B68.svl)->svlhost);
            if (func_02059B40(((SvlResult *)g_021D3B68.svl)->svltoken, strlen(((SvlResult *)g_021D3B68.svl)->svltoken),
                              token, sizeof(token)) < 0) {
                func_021C58C8(0, 8, -1);
                return;
            }
            if (!func_021C6348(func_021C569C, func_021C56B4, url, token, ((SvlResult *)g_021D3B68.svl)->gamecd,
                               ((SvlResult *)g_021D3B68.svl)->passwd, func_021C58C8)) {
                func_021C58C8(0, 8, -1);
                return;
            }
            ((SvlResult *)g_021D3B68.svl)->status = 1;
            func_021C58C8(0, 0, -1);
            return;
        case 4:
            func_02059E18(&errorcode);
            func_02059F54(13, errorcode);
            func_021C58C8(0, 3, -1);
            return;
        case 5:
            func_021C58C8(0, 6, -1);
            return;
        }
        func_02085A38(100);
    }
}





void func_021C58C8(int reason, int error, int servererror)
{
    if (error != 0)
        func_021C659C(error, servererror);
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 3;
    g_021D3B68.f10 = reason;
    g_021D3B68.fC = error;
    g_021D3B68.f8 = servererror;
    if (error != 0)
        g_021D3B68.f14 = 4;
    OS_UnlockMutex(g_021D3B84);
}





/*
 * sdk:      DWC_NdInitAsync (libdwcnd.TWL.HYB.a(dwc_nd.o))
 */
int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd)
{
    if (func_02059F38())
        return 0;
    func_02086004(g_021D3B84);
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 0) {
        func_021C659C(2, 0);
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    g_021D3B68.f14 = 2;
    OS_UnlockMutex(g_021D3B84);
    g_021D3B68.f10 = 0;
    g_021D3B68.fC = 0;
    g_021D3B68.f8 = 0;
    g_021D3B68.cb = callback;
    g_021D3B68.f4 = 0;
    g_021D3B68.svl = func_021C569C(sizeof(NdParam), 0x20);
    if (g_021D3B68.svl == 0) {
        func_021C659C(1, 0);
        return 0;
    }
    func_02082BCC(g_021D3B68.svl, 0, sizeof(NdParam));
    ((NdParam *)g_021D3B68.svl)->f40 = 0;
    strncpy(((NdParam *)g_021D3B68.svl)->gamecd, gamecd, 31);
    strncpy(((NdParam *)g_021D3B68.svl)->passwd, passwd, 31);
    if (func_02167FA8(g_021CF370, ((NdParam *)g_021D3B68.svl)->svl) == 0) {
        func_021C56B4((void *)((int)g_021D3B68.svl));
        g_021D3B68.svl = 0;
        return 0;
    }
    func_020853C0(((NdParam *)g_021D3B68.svl)->thread, (void (*)(void *))func_021C5724, 0,
                  ((NdParam *)g_021D3B68.svl)->stack + sizeof(((NdParam *)g_021D3B68.svl)->stack), 0x800, 0x10);
    func_02085868(((NdParam *)g_021D3B68.svl)->thread);
    return 1;
}




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
