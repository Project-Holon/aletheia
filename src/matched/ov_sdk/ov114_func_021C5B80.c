/*
 * function: func_021C5B80
 * address:  0x021C5B80
 * packet:   pkt_ov114_021C5B80
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdCleanupAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   func_021C56CC  0x021C56CC  arm  ov114
 *   func_021C651C  0x021C651C  arm  ov114
 *   g_021D3B68     0x021D3B68  data
 *   g_021D3B84     0x021D3B84  data
 */

typedef struct NdParam {
    unsigned char pad0[0x40];
    int f40;
} NdParam;

typedef struct NdState {
    unsigned char pad0[0x14];
    int f14;
    NdParam *f18;
} NdState;

extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void func_021C56CC(void);
extern void func_021C651C(void (*callback)(void));
extern NdState g_021D3B68;
extern char g_021D3B84[];

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
    if (g_021D3B68.f18->f40 == 0)
        func_021C56CC();
    else
        func_021C651C(func_021C56CC);
    return 1;
}
