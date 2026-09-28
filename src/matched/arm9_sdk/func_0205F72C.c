/*
 * function: func_0205F72C
 * address:  0x0205F72C
 * packet:   pkt_0205F72C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFG_ReadBackupMemory (libncfg.TWL.HYB.a backup.o)
 *
 * symbols:
 *   NCFGi_InitBackupMemory 0x0205F648 arm
 *   getSlotInfo            0x0205F8A0 arm
 *   DC_InvalidateRange     0x020862B8 arm
 *   ReadNVRAM              0x0205F970 arm
 */

typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed long    s32;

extern s32  NCFGi_InitBackupMemory(void);
extern int  getSlotInfo(s32 index, u32 *address, u32 *size);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern int  ReadNVRAM(u32 address, u32 size, void *pData);

s32 func_0205F72C(void *buf, u32 size, s32 index)
{
    s32 result;
    u32 address;
    u32 readSize;

    result = NCFGi_InitBackupMemory();
    if (result != 0)
        return result;
    if (buf == 0)
        return -1;
    if (!getSlotInfo(index, &address, &readSize))
        return -1;
    if (readSize > size)
        readSize = size;
    DC_InvalidateRange(buf, readSize);
    if (ReadNVRAM(address, (u16)readSize, buf) == 0)
        return (s32)readSize;
    return -1;
}
