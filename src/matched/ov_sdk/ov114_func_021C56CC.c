/*
 * function: DWCi_NdCleanupCallback
 * address:  0x021C56CC
 * packet:   pkt_021C56CC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_JoinThread  0x02085710  arm
 *   DWCi_NdFree  0x021C56B4  arm  ov114
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   gDwcNdState     0x021D3B68  data ov114
 *   gDwcNdMutex     0x021D3B84  data ov114
 */

typedef struct Ov114Global {
    char pad[0x10];
    int  f10;
    int  f14;
    int  f18;
} Ov114Global;

extern Ov114Global gDwcNdState;
extern char        gDwcNdMutex;

void OS_JoinThread(void *p);
void DWCi_NdFree(int a);
void func_02086028(void *p, int a);
void func_02086078(void *p, int a);

void DWCi_NdCleanupCallback(void)
{
    OS_JoinThread((char *)gDwcNdState.f18 + 0x1b8 + 0x800);
    DWCi_NdFree((int)((void *)gDwcNdState.f18));
    gDwcNdState.f18 = 0;
    func_02086028(&gDwcNdMutex, 0);
    gDwcNdState.f14 = 3;
    gDwcNdState.f10 = 4;
    func_02086078(&gDwcNdMutex, 4);
}
