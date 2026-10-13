/*
 * function: PARTICLE_LoadArchiveMember
 * address:  0x0205121C
 * packet:   pkt_0205121C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Truncating forwarding wrapper: zero-extend the third argument to u16 and
 * tail-call ARC_TOOL_LoadMember.  The ARM9 listing emits it as a .word run (no
 * func_ label), so a `matched` entry is the only witness its callers can
 * use.
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 */

typedef unsigned int u32;

extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);

int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c)
{
    return (int)ARC_TOOL_LoadMember(a, b, (unsigned short)c);
}
