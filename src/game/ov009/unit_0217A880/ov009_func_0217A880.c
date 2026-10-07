/*
 * function: func_0217A880
 * address:  0x0217A880
 * packet:   pkt_ov009_0217A880
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Netcheck_Create (dwc_netcheck.o)
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   OS_InitMutex   0x02086004  arm
 *   func_0217AAF4  0x0217AAF4  arm  ov009
 *   g_021ACE5C     0x021ACE5C  data
 */

#include "../../../matched/include/G_G.h"

typedef struct {
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    int extra;
} Param;
typedef struct {
    void *http;
    char *nc;
    int pad[3];
    int flag;
} G;
extern struct G g_021ACE5C;
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_InitMutex(void *mutex);
extern void func_0217AAF4(void);

int func_0217A880(Param *param)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    if (g_021ACE5C.nc != 0) {
        return 4;
    }
    g_021ACE5C.nc = alloc(0, 0x11f4);
    if (g_021ACE5C.nc == 0) {
        return 4;
    }
    MI_CpuFill8(g_021ACE5C.nc, 0, 0x11f4);
    *(int *)(g_021ACE5C.nc + 0x1004) = 0xfffe7961;
    *(Param *)(g_021ACE5C.nc + 0x1108) = *param;
    if (g_021ACE5C.http != 0) {
        return 4;
    }
    g_021ACE5C.http = alloc(0, 0x1c50);
    if (g_021ACE5C.http == 0) {
        return 4;
    }
    g_021ACE5C.flag = 0;
    OS_InitMutex(g_021ACE5C.nc + 0x11dc);
    func_0217AAF4();
    return 0;
}
