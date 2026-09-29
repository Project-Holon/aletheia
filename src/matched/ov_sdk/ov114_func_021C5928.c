/*
 * function: func_021C5928
 * address:  0x021C5928
 * packet:   pkt_ov114_021C5928
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdInitAsync (libdwcnd.TWL.HYB.a(dwc_nd.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086004  0x02086004  arm
 *   func_02086028  0x02086028  arm
 *   func_021C659C  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   func_021C569C  0x021C569C  arm  ov114
 *   func_02082BCC  0x02082BCC  arm
 *   strncpy        0x02094860  arm
 *   func_02167FA8  0x02167FA8  arm
 *   func_021C56B4  0x021C56B4  arm  ov114
 *   func_020853C0  0x020853C0  arm
 *   func_02085868  0x02085868  arm
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 *   g_021CF370     0x021CF370  data
 *   func_021C5724  0x021C5724  arm  ov114
 */

typedef struct NdParam {
    char gamecd[0x20];
    char passwd[0x20];
    int f40;
    unsigned char svl[0x1b8 - 0x44];
    unsigned char stack[0x800];
    unsigned char thread[0xa78 - 0x9b8];
} NdParam;

typedef struct NdState {
    void (*userCallback)(int, int, int);
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    NdParam *f18;
} NdState;

extern int func_02059F38(void);
extern void func_02086004(void *mutex);
extern void func_02086028(void *mutex);
extern void func_021C659C(int err, int servererror);
extern void OS_UnlockMutex(void *mutex);
extern void *func_021C569C(unsigned long size, int align);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern int func_02167FA8(char *svl, void *result);
extern void func_021C56B4(void *ptr);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack,
                          unsigned long stackSize, unsigned long prio);
extern void func_02085868(void *thread);
extern void func_021C5724(void *);

extern NdState g_021D3B68;
extern char g_021D3B84[];
extern char g_021CF370[];

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
    g_021D3B68.fc = 0;
    g_021D3B68.f8 = 0;
    g_021D3B68.userCallback = callback;
    g_021D3B68.f4 = 0;
    g_021D3B68.f18 = func_021C569C(sizeof(NdParam), 0x20);
    if (g_021D3B68.f18 == 0) {
        func_021C659C(1, 0);
        return 0;
    }
    func_02082BCC(g_021D3B68.f18, 0, sizeof(NdParam));
    g_021D3B68.f18->f40 = 0;
    strncpy(g_021D3B68.f18->gamecd, gamecd, 31);
    strncpy(g_021D3B68.f18->passwd, passwd, 31);
    if (func_02167FA8(g_021CF370, g_021D3B68.f18->svl) == 0) {
        func_021C56B4(g_021D3B68.f18);
        g_021D3B68.f18 = 0;
        return 0;
    }
    func_020853C0(g_021D3B68.f18->thread, func_021C5724, 0,
                  g_021D3B68.f18->stack + sizeof(g_021D3B68.f18->stack), 0x800, 0x10);
    func_02085868(g_021D3B68.f18->thread);
    return 1;
}
