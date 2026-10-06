/*
 * file:     unit_02083644_p04.c
 * unit:     yes
 * function: func_020841E8, func_02084204, func_02084260, func_02084288, func_020842A0, func_020842D8, func_02084304, func_02084330, func_020843B4, func_020844A8, func_02084570
 * address:  0x020841E8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150EA0 0x02150EA0 data
 *   nvramw                 0x02150EE0  data
 *   NVRAMi_ReadCallback    0x020837B8  arm
 *   NVRAMi_WriteCallback   0x020839E8  arm
 *   NVRAMi_VerifyCallback  0x02083FA0  arm
 *   OS_SendMessage                 0x02085DBC  arm
 *   OS_Terminate                   0x02088234  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 */
struct OSMessageQueue;
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

typedef unsigned short u16;

typedef unsigned char u8;

extern void g_02150EA0(void);
extern void NVRAMi_ReadCallback(u32 data, BOOL err);
extern void NVRAMi_WriteCallback(u32 data, BOOL err);
extern void NVRAMi_VerifyCallback(u32 data, BOOL err);
int OS_SendMessage(struct OSMessageQueue *mq, void *msg, long flags);
void OS_Terminate(void);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
asm void NVRAMi_IsInitialized(void);
void NVRAMi_Callback(int tag, u32 data, BOOL err);
void func_02084260(int result, void *arg);
void NVRAMi_AlarmHandler(void *arg);
BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size);
BOOL NVRAMi_WriteEnable(void);
BOOL NVRAMi_WriteDisable(void);
BOOL NVRAMi_ReadStatusRegister(u8 *pData);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData);
BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData);
BOOL NVRAMi_SoftwareReset(void);
extern NVRAMWork nvramw;


asm void NVRAMi_IsInitialized(void)
{
    ldr r0, =g_02150EA0
    ldr	r0, [r0]
    cmp	r0, #2
    moveq	r0, #1
    movne	r0, #0
    bx	lr
}


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


/*
 * sdk:      NVRAMi_SyncCallback (libnvram.TWL.HYB.a nvram.o)
 */
void func_02084260(int result, void *arg)
{
    if (!OS_SendMessage((struct OSMessageQueue *)arg, (void *)result, 0)) {
        OS_Terminate();
    }
}


void NVRAMi_AlarmHandler(void *arg)
{
    NVRAMi_Callback(4, (u32)arg, 0);
}


BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size)
{
    u32 i;

    for (i = 0; i < size; i++) {
        if (data0[i] != data1[i]) {
            return 0;
        }
    }
    return 1;
}


BOOL NVRAMi_WriteEnable(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002000, 0)) {
        return 0;
    }
    return 1;
}


BOOL NVRAMi_WriteDisable(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002100, 0)) {
        return 0;
    }
    return 1;
}


BOOL NVRAMi_ReadStatusRegister(u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02002200 | ((u32)pData >> 24), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (((u32)pData >> 8) & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00020000 | (((u32)pData << 8) & 0x0000FF00), 0)) {
        return 0;
    }
    return 1;
}


BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2300 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | (size >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | (size & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00040000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00050000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}


BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2500 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | size, 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00040000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}


BOOL NVRAMi_SoftwareReset(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002D00, 0)) {
        return 0;
    }
    return 1;
}
