/*
 * function: ISS_SYS_Delete
 * address:  0x0202B4F0
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_DUNGEON_SYS_ApplyTrack.c is now a manifest entry (matched class)
 *
 * Release pair: tear the node down with ISS_SYS_DeleteSubsystems, then free it.
 *
 * symbols:
 *   ISS_SYS_DeleteSubsystems  0x0202B5D4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_SYS_Delete.c \
 *       --func ISS_SYS_Delete --addr 0x0202B4F0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void ISS_SYS_DeleteSubsystems(u32 a);
extern u32 func_020307B0(void *p);

void ISS_SYS_Delete(u8 *p)
{
    ISS_SYS_DeleteSubsystems((u32)p);
    func_020307B0(p);
}
