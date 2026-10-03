/*
 * function: func_02031EF8
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
 *   func_02031EE8  0x02031EE8  arm
 *   func_02031E7C  0x02031E7C  arm
 *
 * backup_system.c.  Verifies one copy of a backup area and returns 0 when both
 * words of its footer agree with the descriptor, 1 when the running check
 * disagrees, 2 when the length or the sequence number disagrees.
 *
 * The footer descriptor comes from func_02031EE8(p, buf) (src/matched/
 * func_02031EE8.c): it is `buf + p->unk30 - 0x10`.  Word +4 and word +8 of that
 * footer are compared against p->unk30 and p->unkC, and the halfword at +0xE is
 * compared against func_02031E7C(p, buf), the CRC16 of the area (the packet's
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
 *   python tools/match.py one --src src/matched/func_02031EF8.c \
 *       --func func_02031EF8 --addr 0x02031EF8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8  *func_02031EE8(void *p, void *buf);
struct SaveBackup;
extern u16 func_02031E7C(struct SaveBackup *p, u8 *buf);

u32 func_02031EF8(void *p, void *buf, u32 sel)
{
    u8 *q;

    q = func_02031EE8(p, buf);

    if (*(u32 *)(q + 4) != *(u32 *)((u8 *)p + 0x30))
        return 2;
    if (*(u32 *)(q + 8) != *(u32 *)((u8 *)p + 0x0C))
        return 2;
    if (*(u16 *)(q + 0x0E) != func_02031E7C(p, buf))
        return 1;
    return 0;
}
