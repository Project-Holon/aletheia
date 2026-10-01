/*
 * function: MB_RegisterFile
 * address:  0x021F3544
 * packet:   pkt_ov107_021F3544
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01 lane07: EXACT.  `update` is a function-scope `static u8 update = 0;`
 *          (vendor symbol _ZZ15MB_RegisterFile...E6update), incremented in place as
 *          `= update++`.  A function-scope static cannot alias the pointer stores, so
 *          the scheduler sinks the `update` store to the end and the +1 temp is created
 *          early, which gives the image's r7/r3/r6 colours.  An extern or file-scope
 *          static `update` keeps the store in place.  The stand-in locals upd/gr are gone
 *          (DWARF has none).  Symbols line uses our object's mangled static name.
 *
 * sdk:      MB_RegisterFile (libmb.TWL.HYB.a(mb_fileinfo.o))
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   MBi_IsStarted            0x021F6314  arm  ov107
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   MBi_MakeDownloadFileInfo 0x021F37BC  arm  ov107
 *   MI_CpuCopy8              0x02082D44  arm
 *   MBi_MakeBlockInfoTable   0x021F398C  arm  ov107
 *   MBi_MakeGameInfo         0x021F3D04  arm  ov107
 *   MB_AddGameInfo           0x021F3F34  arm  ov107
 *   MBi_IsTaskAvailable      0x021F6610  arm  ov107
 *   MBi_InitTaskInfo         0x021F662C  arm  ov107
 *   MBi_InitTaskThread       0x021F6590  arm  ov107
 *   mbc                      0x021F6FA0  data
 *   _ZZ15MB_RegisterFileP14MBGameRegistryPvE6update  0x021F6EF0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MbDownloadFileInfoHeader;
struct MBGameRegistry;

extern unsigned char *mbc;
extern unsigned long OS_DisableInterrupts(void);
extern int MBi_IsStarted(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MBi_MakeDownloadFileInfo(struct MbDownloadFileInfoHeader *, void *);
extern void MI_CpuCopy8(void *, void *, unsigned long);
extern int MBi_MakeBlockInfoTable(void *, struct MbDownloadFileInfoHeader *);
extern void MBi_MakeGameInfo(void *, struct MBGameRegistry *, void *);
extern void MB_AddGameInfo(void *);
extern int MBi_IsTaskAvailable(void);
extern void MBi_InitTaskInfo(void *);
extern void MBi_InitTaskThread(void *, unsigned long);

#define E(i) ((unsigned char *)mbc + (i) * 0x5D4 + 0x1000)

int MB_RegisterFile(struct MBGameRegistry *game_reg, void *buf)
{
    struct MbDownloadFileInfoHeader *mdfi;
    static unsigned char update = 0;
    unsigned char i;
    unsigned char fileID = 0xff;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (!MBi_IsStarted())
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (*(unsigned char *)((unsigned char *)mbc + 0x1524) + 1 > 0x10)
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }

    for (i = 0; i < 0x10; i++)
    {
        if (*(struct MBGameRegistry **)(E(i) + 0xd40) == game_reg)
        {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        if (*(u8 *)(E(i) + 0xd52) == 0)
        {
            fileID = i;
            break;
        }
    }
    if (i == 0x10)
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }

    *(u32 *)(E(fileID) + 0xd40) = (u32)game_reg;
    mdfi = (struct MbDownloadFileInfoHeader *)((unsigned char *)mbc + 0x1788 + fileID * 0x5D4);
    MBi_MakeDownloadFileInfo(mdfi, buf);
    MI_CpuCopy8((unsigned char *)game_reg + 0x1c, (unsigned char *)mdfi + 0xc4, 0x20);
    if (!MBi_MakeBlockInfoTable((unsigned char *)mbc + 0x1d2c + fileID * 0x5D4, mdfi))
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    MBi_MakeGameInfo((unsigned char *)mbc + 0x186c + fileID * 0x5D4, game_reg,
                     (unsigned char *)mbc + 0x1300);
    *(u8 *)(E(fileID) + 0xd21) = fileID;
    MB_AddGameInfo((unsigned char *)mbc + 0x186c + fileID * 0x5D4);
    *(u8 *)(E(fileID) + 0xd1f) = update++;
    *(u16 *)(E(fileID) + 0xd4e) = 1;
    *(u32 *)(E(fileID) + 0xd44) = (u32)buf;
    *(u32 *)(E(fileID) + 0xd54) = (u32)buf + 0x1e8;
    *(u32 *)(E(fileID) + 0xd58) = (u32)buf + 0x258;
    if (*(u32 *)(*(u32 *)(E(fileID) + 0xd54) + 0x6c) != 0 && !MBi_IsTaskAvailable())
    {
        MBi_InitTaskInfo((unsigned char *)mbc + 0x7ce0);
        MBi_InitTaskThread((unsigned char *)mbc + 0x74e0, 0x800);
    }
    *(u8 *)(E(fileID) + 0xd52) = 1;
    *(unsigned char *)((unsigned char *)mbc + 0x1524) += 1;
    OS_RestoreInterrupts(enabled);
    return 1;
}

