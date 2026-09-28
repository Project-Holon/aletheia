/*
 * function: NVRAMi_Callback
 * address:  0x02084204
 * packet:   pkt_02084204
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: the PXI FIFO callback for tag 4, dispatching on
 * nvramw.lock (read 1, write 2, verify 3).  data and err arrive in r1 and r2
 * behind the unused tag, which the DWARF leaves out.
 *
 * symbols:
 *   nvramw                 0x02150EE0  data
 *   NVRAMi_ReadCallback    0x020837B8  arm
 *   NVRAMi_WriteCallback   0x020839E8  arm
 *   NVRAMi_VerifyCallback  0x02083FA0  arm
 */

typedef unsigned long u32;
typedef int BOOL;

typedef enum NVRAMLock {
    NVRAM_LOCK_OFF = 0,
    NVRAM_LOCK_READ,
    NVRAM_LOCK_WRITE,
    NVRAM_LOCK_VERIFY
} NVRAMLock;

typedef struct NVRAMWork {
    NVRAMLock lock;
} NVRAMWork;

extern NVRAMWork nvramw;
extern void NVRAMi_ReadCallback(u32 data, BOOL err);
extern void NVRAMi_WriteCallback(u32 data, BOOL err);
extern void NVRAMi_VerifyCallback(u32 data, BOOL err);

void NVRAMi_Callback(int tag, u32 data, BOOL err)
{
    switch (nvramw.lock) {
    case NVRAM_LOCK_READ:
        NVRAMi_ReadCallback(data, err);
        break;
    case NVRAM_LOCK_WRITE:
        NVRAMi_WriteCallback(data, err);
        break;
    case NVRAM_LOCK_VERIFY:
        NVRAMi_VerifyCallback(data, err);
        break;
    }
}
