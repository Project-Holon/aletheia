/*
 * function: BACKUP_SYSTEM_GetAreaAddr
 * address:  0x02031EAC
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * backup_system.c.  The length accessor of the backup header: it reports the
 * length word at +4, but only when the sequence word at +0 differs from it;
 * when the two agree the length at +0 is returned instead.  `sel` chooses the
 * copy: only sel == 2 gets the +4 length, everything else gets 0.  Callers
 * feed the answer straight to a read, e.g. src/pending/sub_02031FE0.c:
 * `FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr(p, 1), buf0, p->unk30, ...)`.
 *
 * Both loads happen in source order (+4 first), and the equal case returns the
 * halfword already in r0, so the tail is a bare `bxeq lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetAreaAddr.c \
 *       --func BACKUP_SYSTEM_GetAreaAddr --addr 0x02031EAC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel)
{
    u32 len;

    len = p[1];
    if (p[0] == len)
        return p[0];
    if (sel != 2)
        len = p[0];
    return len;
}
