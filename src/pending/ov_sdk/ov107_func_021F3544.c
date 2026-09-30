/*
 * function: MB_RegisterFile
 * address:  0x021F3544
 * packet:   pkt_ov107_021F3544
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: 8 concrete bytes, pure scratch-register tie-break.  Object stamp
 *          4.0.0.1024 confirms 1.1p1.  Fixed this pass: the element access
 *          now folds to `mla i,#0x5D4,mbc; add #0x1000; [r2,#0xd40]` (E(i)
 *          association mbc + i*0x5D4 + 0x1000), the count guard lost its u8
 *          mask, and the `update` copy keeps the loaded value in r0 across
 *          the pointer stores.  Size is now 632/632.
 *          Residue is only the three buffer-offset temps at +01A8..+01E4:
 *          original gives buf+0x1e8->r7 (the dead game_reg), buf+0x258->r3
 *          and reuses r6 (dead buf) for update+1; mwcc here gives
 *          buf+0x1e8->r3, buf+0x258->r6 and update+1->r1.  Every earlier
 *          byte matches, so the live-in set is identical; declaration order
 *          of all locals (0x5D4 / enabled / i / fileID / mdfi / upd / gr,
 *          every permutation) and named p1/p2 temporaries all leave the
 *          choice unchanged.  DWARF locals are enabled(r4), i(r5),
 *          fileID(r10), mdfi(r9) only.
 *          w7: re-measured 8 B.  Also ruled out: reassigning game_reg or buf
 *          for the temps (with/without pressure from a later buf reassign),
 *          void-star, u8-star and char-star parameter types on game_reg and
 *          buf, distinct u8-star/void-star/u32 temp locals, folded/unfolded
 *          offset spellings and operand order, plus a 5000-compile permuter
 *          anneal (plateau at 8, seed 2).  Region hints `ov107` added to the
 *          MBi_/MB_ symbols so the contested overlay labels (ov043/ov051
 *          thumb) do not stop the permuter; 18/18 relocations still resolve.
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
 *   update                   0x021F6EF0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MbDownloadFileInfoHeader;
struct MBGameRegistry;

extern unsigned char *mbc;
extern unsigned char update;
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
    unsigned char i;
    unsigned char fileID = 0xff;
    unsigned long enabled;
    unsigned char upd;
    u32 gr;

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
        gr = *(u32 *)(E(i) + 0xd40);
        if (gr == (u32)game_reg)
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
    upd = update;
    *(u8 *)(E(fileID) + 0xd1f) = upd;
    *(u16 *)(E(fileID) + 0xd4e) = 1;
    *(u32 *)(E(fileID) + 0xd44) = (u32)buf;
    *(u32 *)(E(fileID) + 0xd54) = (u32)buf + 0x1e8;
    *(u32 *)(E(fileID) + 0xd58) = (u32)buf + 0x258;
    update = upd + 1;
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

