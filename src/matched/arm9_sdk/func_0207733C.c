/*
 * function: CARDi_InitRom
 * address:  0x0207733C
 * packet:   pkt_0207733C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_InitRom (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   CARD_LockRom  0x02075E10  arm
 *   CARDi_ReadRomWithCPU  0x02076E4C  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   OS_ReleaseLockID  0x02084F10  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   CARDi_InitRomHash  0x0272EA74  arm
 *   cardi_rom_base  0x02150840  data
 *   CARDiOwnSignature  0x0215086C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct CARDRomHeader
{
    u8 pad00[0x80];
    u32 rom_size;
} CARDRomHeader;

typedef struct CARDiRomState
{
    u32 rom_base;
    BOOL (*read_func)(void *userdata, void *buffer, u32 offset, u32 length);
} CARDiRomState;

extern CARDiRomState cardi_rom_base;
extern u8 CARDiOwnSignature[136];

extern u16 OS_GetBootType(void);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern s32 OS_GetLockID(void);
extern void CARD_LockRom(u16 lock_id);
extern BOOL CARDi_ReadRomWithCPU(void *userdata, void *buffer, u32 offset, u32 length);
extern void CARD_UnlockRom(u16 lock_id);
extern void OS_ReleaseLockID(u16 lockID);
extern BOOL OS_IsRunOnTwl(void);
extern void CARDi_InitRomHash(void);

void CARDi_InitRom(void)
{
    cardi_rom_base.read_func = CARDi_ReadRomWithCPU;
    if ((OS_GetBootType() == 1) && (CARD_GetOwnRomHeader()->rom_size != 0))
    {
        u16 id = (u16)OS_GetLockID();

        CARD_LockRom(id);
        (void)CARDi_ReadRomWithCPU(0, CARDiOwnSignature, CARD_GetOwnRomHeader()->rom_size, sizeof(CARDiOwnSignature));
        CARD_UnlockRom(id);
        OS_ReleaseLockID(id);
    }
    if (OS_IsRunOnTwl())
    {
        CARDi_InitRomHash();
    }
}
