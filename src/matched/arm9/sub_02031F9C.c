/*
 * PROMOTED TO EXACT.  This file was parked at MATCH because its only open
 * relocation site was the `bl` to 0x02031EF8: that function's one and only
 * branch in the whole image is the one inside this file
 * (match.image_call_sites(0x02031EF8) == [0x02031FCC]), so the `label` class
 * had no outside witness and there was no literal or runtime witness either.
 * 0x02031EF8 is now matched itself (src/matched/func_02031EF8.c), so the site
 * resolves in the `matched` class and every byte here is attested.
 *
 * function: func_02031F9C
 * address:  0x02031F9C
 * packet:   pkt_02031F9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031EE8  0x02031EE8  arm
 *   func_02031EF8  0x02031EF8  arm
 *
 * backup_system.c.  Fills the two-word record descriptor `out` for one of the
 * two copies of a backup area: word 0 is the verification answer from
 * 0x02031EF8 (0 both words of the footer agree, 1 the running check disagrees,
 * 2 the length or the sequence number disagrees), word 1 is the first word of
 * that footer, reached through 0x02031EE8, buf + (p->unk30 - 0x10).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031F9C.c \
 *       --func func_02031F9C --addr 0x02031F9C --cc 1.1p1 --arm
 */
#include "../include/Obj16793.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_02031EE8(void *p, void *buf);
extern u32 func_02031EF8(void *p, void *buf, u32 sel);

void func_02031F9C(u32 *out, void *p, void *buf, u32 sel)
{
    u8 *q;

    q = func_02031EE8(p, buf);
    out[0] = func_02031EF8(p, buf, sel);
    out[1] = ((struct Obj16793 *)q)->f0;
}
