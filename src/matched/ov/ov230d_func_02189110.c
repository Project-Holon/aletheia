/*
 * function: OV230_CheckCardImage0
 * address:  0x02189110
 * packet:   pkt_ov230d_02189110
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_checks_card_image.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_CheckCardImage0  0x02189110  arm  ov230d
 *   OV230_CheckCardImage1  0x02189228  arm  ov230d
 *   OV230_CallSealedBody12  0x02189098  arm  ov230d
 *   OV230_CallSealedBody13  0x021890D4  arm  ov230d
 *   OS_GetLockID  0x02084EB8  arm
 *   CARD_LockRom  0x02075E10  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   OS_ReleaseLockID  0x02084F10  arm
 *   CARDi_ReadRom  0x020771B4  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern s32 OS_GetLockID(void);
extern void CARD_LockRom(u16 lockId);
extern void CARD_UnlockRom(u16 lockId);
extern void OS_ReleaseLockID(u16 lockId);
extern void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len, void *callback, void *arg, int isAsync);
extern void OV230_CallSealedBody12(u8 *dst, u32 offset, u32 size);
extern u32 OV230_CallSealedBody13(const u8 *data, u32 size);

u32 OV230_CheckCardImage0(void)
{
    u32 buffer[128];
    u32 crc[7];
    u16 lockId;
    u32 offset;
    u32 tag;
    int i;

    offset = 0x1000;
    lockId = OS_GetLockID();
    CARD_LockRom(lockId);
    for (i = 0; i < 3; i++) {
        OV230_CallSealedBody12((u8 *)buffer, offset, 0x200);
        crc[i] = OV230_CallSealedBody13((u8 *)buffer, 0x200);
        CARDi_ReadRom(-1, (const void *)(offset + 0x7000), buffer, 0x200, 0, 0, 0);
        crc[i + 3] = OV230_CallSealedBody13((u8 *)buffer, 0x200);
        offset += 0x200;
    }
    CARD_UnlockRom(lockId);
    OS_ReleaseLockID(lockId);
    for (i = 0; i < 3; i++) {
        if (crc[3] != crc[i]) {
            tag = 0xFB;
            goto done;
        }
    }
    if (crc[3] == crc[4] && crc[3] == crc[5]) {
        tag = 0xFB;
    } else {
        tag = 0xF1;
    }
done:
    for (i = 0; i < 128; i++) {
        buffer[i] = i;
    }
    return tag * 0xBF;
}
