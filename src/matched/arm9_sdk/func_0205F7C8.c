/*
 * function: func_0205F7C8
 * address:  0x0205F7C8
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFG_WriteBackupMemory (libncfg.TWL.HYB.a backup.o)
 *
 * symbols:
 *   NCFGi_InitBackupMemory 0x0205F648 arm
 *   getSlotInfo            0x0205F8A0 arm
 *   DC_StoreRange          0x020862D4 arm
 *   WriteNVRAM             0x0205F9D8 arm
 *   VerifyNVRAM            0x0205FA40 arm
 */

typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed long    s32;

extern s32  NCFGi_InitBackupMemory(void);
extern int  getSlotInfo(s32 index, u32 *address, u32 *size);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern int  WriteNVRAM(u32 address, u32 size, void *pData);
extern int  VerifyNVRAM(u32 address, u32 size, void *pData);

s32 func_0205F7C8(s32 index, void *buf, u32 size)
{
    s32 result;
    u32 address;
    u32 writeSize;
    int iRetry;
    s32 nvramResult;

    result = NCFGi_InitBackupMemory();
    if (result != 0)
        return result;
    if (buf == 0) {
        result = -1;
    } else if (!getSlotInfo(index, &address, &writeSize)) {
        result = -1;
    } else {
        if (writeSize > size)
            writeSize = size;
        DC_StoreRange(buf, writeSize);
        result = -1;
        for (iRetry = 0; iRetry < 3; iRetry++) {
            nvramResult = WriteNVRAM(address, (u16)writeSize, buf);
            if (nvramResult != 0) {
                result = -1;
                break;
            }
            nvramResult = VerifyNVRAM(address, (u16)writeSize, buf);
            if (nvramResult == 0) {
                result = (s32)writeSize;
                break;
            }
            if (nvramResult != 6) {
                result = -1;
                break;
            }
        }
    }
    return result;
}
