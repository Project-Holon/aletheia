/*
 * function: BACKUP_SYSTEM_CheckFooter
 * address:  0x02031EF8
 * packet:   pkt_02031EF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_GetFooter  0x02031EE8  arm
 *   BACKUP_SYSTEM_CalcCrcTableCrc  0x02031E7C  arm
 *
 * backup_system.c.  Verifies one copy of a backup area and returns 0 when both
 * words of its footer agree with the descriptor, 1 when the running check
 * disagrees, 2 when the length or the sequence number disagrees.
 *
 * The footer descriptor comes from BACKUP_SYSTEM_GetFooter(p, buf) (src/matched/
 * BACKUP_SYSTEM_GetFooter.c): it is `buf + p->unk30 - 0x10`.  Word +4 and word +8 of that
 * footer are compared against p->unk30 and p->unkC, and the halfword at +0xE is
 * compared against BACKUP_SYSTEM_CalcCrcTableCrc(p, buf), the CRC16 of the area (the packet's
 * only SDK call).  Only 0x02031F9C calls this function anywhere in the image,
 * which is why that file was parked at MATCH until this one landed; it can now
 * be promoted.
 *
 * The third parameter is dead in the body (the original never reads r2) and the
 * callers pass nothing for it; it is kept in the declaration only because
 * src/matched/sub_02031F9C.c declares the same three-argument prototype.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CheckFooter.c \
 *       --func BACKUP_SYSTEM_CheckFooter --addr 0x02031EF8 --cc 1.1p1 --arm
 */
#include "../include/Obj03443.h"
#include "../include/Obj08816.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int BACKUP_SYSTEM_GetFooter(int p0, int p1);
struct SaveBackup;
extern u16 BACKUP_SYSTEM_CalcCrcTableCrc(struct SaveBackup *p, u8 *buf);

u32 BACKUP_SYSTEM_CheckFooter(void *p, void *buf, u32 sel)
{
    u8 *q;

    q = (u8 *)BACKUP_SYSTEM_GetFooter((int)p, (int)buf);

    if (((struct Obj08816 *)q)->f4 != ((struct Obj03443 *)p)->f30)
        return 2;
    if (((struct Obj08816 *)q)->f8 != ((struct Obj03443 *)p)->fC)
        return 2;
    if (((struct Obj08816 *)q)->fE != BACKUP_SYSTEM_CalcCrcTableCrc(p, buf))
        return 1;
    return 0;
}
