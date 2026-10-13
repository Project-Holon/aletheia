/*
 * function: BACKUP_SYSTEM_WriteCrcTable
 * address:  0x02032C84
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_GetAreaAddr  0x02031EAC  arm
 *   BACKUP_SYSTEM_GetCrcTable  0x02031ECC  arm
 *   FLASH_ACCESS_StartWrite  0x020336B8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  Writes the trailing block of a backup record: the length is
 * the +0x140 field, the destination is that many bytes back from the end
 * of the area, and the source is whatever 0x02031ECC hands back.  The
 * destination has to be computed before the 0x02031ECC call so that the
 * register holding `p` can be reused for it, which is what keeps the frame
 * down to three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_WriteCrcTable.c \n *       --func BACKUP_SYSTEM_WriteCrcTable --addr 0x02032C84 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 pad38[0x108];
    u32 unk140;
};

extern struct { u8 pad000[0x208]; u32 unk208; } *unk_02146994;

extern u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel);
extern int BACKUP_SYSTEM_GetCrcTable(int p0);
extern int FLASH_ACCESS_StartWrite(u32 a0, u32 a1, u32 a2, void *a3);

int BACKUP_SYSTEM_WriteCrcTable(struct SaveBackup *p, u32 sel)
{
    u32 dst;
    u32 src;

    dst = p->unk30 + BACKUP_SYSTEM_GetAreaAddr((u32 *)p, sel);
    dst = dst - 0x10 - p->unk140;
    src = BACKUP_SYSTEM_GetCrcTable((int)p);
    return FLASH_ACCESS_StartWrite(dst, src, p->unk140, (void *)unk_02146994->unk208);
}
