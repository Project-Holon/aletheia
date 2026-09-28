/*
 * function: func_02076B2C
 * address:  0x02076B2C
 * packet:   pkt_02076B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_IdentifyBackup (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   OS_Terminate  0x02088234  arm
 *   CARDi_BeginBackupCommand  0x02076A70  arm
 *   CARDi_IdentifyBackupCore2  0x020766D8  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   CARDi_IdentifyBackupCore  0x02076A20  arm
 */

typedef unsigned long u32;
typedef int BOOL;

typedef struct CARDiCommon CARDiCommon;

extern void OS_Terminate(void);
extern void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg);
extern void CARDi_IdentifyBackupCore2(int type);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void CARDi_IdentifyBackupCore(CARDiCommon *p);

BOOL func_02076B2C(int type)
{
    if (type == 0)
    {
        OS_Terminate();
    }
    CARDi_BeginBackupCommand(0, 0, 0);
    CARDi_IdentifyBackupCore2(type);
    return CARDi_ExecuteOldTypeTask(CARDi_IdentifyBackupCore, 0);
}
