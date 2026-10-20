/*
 * file:     aes_fifo.c
 * unit:     yes
 * function: AESi_PxiSendFirst, AESi_PxiSendSecond, AESi_PxiSendData, AESi_PxiSendCmd, AESi_PxiSendResult
 * address:  0x02707994
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libaes.TWL.HYB.a aes_fifo.o
 */
#include "../types.h"

#include "../arm9/pxi_fifo.h"

void AESi_PxiSendFirst(int tag, u32 a, u32 b);
void AESi_PxiSendSecond(int tag, u32 payload);
void AESi_PxiSendData(int tag, const u8 *buf, u32 len);
void AESi_PxiSendCmd(u32 a, const u8 *buf, u32 len);
void AESi_PxiSendResult(u32 a, u32 b);

void AESi_PxiSendFirst(int tag, u32 command, u32 param)
{
    u32 data = ((command << 21) & 0x1E00000) | 0x2000000 | (param & 0xFFFF);
    while (PXI_SendWordByFifo(tag, data, 0) < 0) {
    }
}

void AESi_PxiSendSecond(int tag, u32 payload)
{
    u32 data = payload & 0xFFFFFF;
    while (PXI_SendWordByFifo(tag, data, 0) < 0) {
    }
}

void AESi_PxiSendData(int tag, const u8 *buf, u32 len)
{
    u32 i = 0;
    while (len - i >= 3) {
        AESi_PxiSendSecond(tag, (buf[i] << 16) | (buf[i + 1] << 8) | buf[i + 2]);
        i += 3;
    }
    if (len - i == 2) {
        AESi_PxiSendSecond(tag, (buf[i] << 16) | (buf[i + 1] << 8));
    } else if (len - i == 1) {
        AESi_PxiSendSecond(tag, buf[i] << 16);
    }
}

void AESi_PxiSendCmd(u32 command, const u8 *buf, u32 len)
{
    AESi_PxiSendFirst(0x13, (unsigned short)command, 0);
    AESi_PxiSendData(0x13, buf, len);
}

void AESi_PxiSendResult(u32 command, u32 result)
{
    AESi_PxiSendFirst(0x13, (unsigned short)command, (unsigned short)result);
}
