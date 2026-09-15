/*
 * unit:     no
 * function: func_0216237C
 * address:  0x0216237C
 * packet:   pkt_0216237C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   g_0217299C     0x0217299C  data
 *   sub_02030734   0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *
 * The constructor of the field event-data system, and the only place in
 * the image that names archive id 125.  It opens three persistent NARC
 * handles side by side with func_020490F4 (arc_tool.c's "allocate a
 * handle and open archive `id`"), and the three ids identify each other:
 *
 *   125 = a/1/2/5 -> +0x04, the per-zone event data
 *   126 = a/1/2/6 -> +0x08, the wild encounter tables (already decoded)
 *    57 = a/0/5/7 -> +0x0c, the script archive (already decoded)
 *
 * a/1/2/5 therefore sits in the classic per-zone triple of events,
 * encounters and scripts, and its 428 sub-files are the 427 zones plus the
 * usual trailing entry.  The member index is not the zone id directly:
 * func_021624B0 passes it through sub_02013B38's sibling accessor in
 * arm9's zonedata.c first.
 *
 * g_0217299C is the __FILE__ argument of the allocation, and its bytes
 * spell "eventdata_system.c".
 *
 * Blocked at MATCH on the `string` evidence class: g_0217299C is the
 * __FILE__ pointer, and the bytes immediately before "eventdata_system.c"
 * are a three-word pointer table, not a NUL-terminated string, so nothing
 * outside the compared range fixes the run's start
 * (docs/idioms/a-string-after-a-data-table-has-no-witness.md).  Every
 * concrete byte is correct; only that one relocation field stays
 * wildcarded.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0216237C.c \
 *       --func func_0216237C --addr 0x0216237C --region ov010 \
 *       --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct EventDataSystem {
    u32   unk_00;
    void *eventArc;
    void *encounterArc;
    void *scriptArc;
};

extern char g_0217299C[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u32 tag);
extern void *func_020490F4(u32 archive_id, u32 heapId);

struct EventDataSystem *func_0216237C(u32 heapId)
{
    struct EventDataSystem *sys =
        sub_02030734(heapId, 0xAA8, 1, g_0217299C, 0xAF);

    sys->eventArc = func_020490F4(125, heapId);
    sys->encounterArc = func_020490F4(126, heapId);
    sys->scriptArc = func_020490F4(57, heapId);
    return sys;
}
