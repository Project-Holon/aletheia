/*
 * function: func_0208C9C4
 * address:  0x0208C9C4
 * packet:   pkt_0208C9C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SCFGi_CommonCallback (libscfg.TWL.HYB.a scfg_proc.o)
 *
 * The PXI FIFO callback: data and err arrive in r1 and r2 behind the unused
 * tag (the DWARF lists only pxiData).
 *
 * symbols:
 *   OS_Terminate                   0x02088234  arm
 *   SCFGi_FuseInfo                 0x02153040  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef void (*SCFGCallback)(u64 fuseData, void *arg);

typedef struct SCFGFuseInfo {
    volatile BOOL lock;
    u64 fuseData;
    u32 readFlag;
    SCFGCallback callback;
    void *callbackArg;
} SCFGFuseInfo;

extern SCFGFuseInfo SCFGi_FuseInfo;

void OS_Terminate(void);

void func_0208C9C4(int tag, u32 pxiData, BOOL err)
{
    u16 command = (u16)((pxiData & 0x03F00000) >> 20);
    u16 ordinal = (u16)((pxiData & 0x000F0000) >> 16);
    u16 data = (u16)pxiData;
    u64 tempData;

    switch (command) {
    case 1:
        SCFGi_FuseInfo.fuseData |= ((u64)data << (ordinal * 16));
        SCFGi_FuseInfo.readFlag |= (1 << ordinal);
        if (SCFGi_FuseInfo.readFlag == 0xF) {
            if (SCFGi_FuseInfo.callback) {
                SCFGi_FuseInfo.callback(SCFGi_FuseInfo.fuseData, SCFGi_FuseInfo.callbackArg);
                SCFGi_FuseInfo.callback = 0;
            }
            SCFGi_FuseInfo.lock = 0;
        }
        break;
    case 2:
        *(u16 *)&tempData = data;
        if (SCFGi_FuseInfo.callback) {
            SCFGi_FuseInfo.callback(tempData, SCFGi_FuseInfo.callbackArg);
            SCFGi_FuseInfo.callback = 0;
        }
        SCFGi_FuseInfo.lock = 0;
        break;
    default:
        OS_Terminate();
    }
}
