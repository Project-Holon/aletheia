/*
 * A whole translation-unit range, matched as one byte range.
 *
 * unit:     yes
 * function: ZONEDATA_Exit, ZONEDATA_SetChangeZoneEnable
 * address:  0x02013A48
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x02013A80 is an unlabelled follower: it saves no lr, so disasm.py prints it
 * as the tail of ZONEDATA_Exit instead of as a function of its own, and
 * ZONEDATA_Exit alone verifies EXACT* for that reason.  Taking the two as one
 * 76-byte unit closes the star; seed 0x02013A80 into
 * layout/function_starts.txt anyway.
 *
 * symbols:
 *   g_ZoneDataMgr  0x02146264  data
 *   func_020307B0     0x020307B0  arm
 *   ARC_TOOL_DeleteHandle     0x02049238  arm
 *
 * The destructor of the zone-header subsystem allocated by ZONEDATA_Init, and
 * a second, independent reading of the manager's field map: it frees +0x44,
 * +0x3c and +0x38 with the plain heap free func_020307B0, which is what makes
 * those three heap buffers rather than pointers into the image, and closes
 * +0x00 with ARC_TOOL_DeleteHandle (archive close plus free), which is what makes
 * +0x00 an archive handle and not a fourth buffer.  The manager itself is
 * freed last and the global cleared.
 *
 * Release order is the reverse of the order ZONEDATA_Init fills the fields
 * in, so the two functions together fix the field order as well as the types.
 *
 * The global is reloaded before every call because it is an ordinary extern,
 * not a same-file static: each `ldr r0, [r4]` in the original is a fresh read
 * of 0x02146264, and writing the frees through the global directly (rather
 * than caching it in a local) is what reproduces them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_Exit.c \
 *       --func ZONEDATA_Exit --addr 0x02013A48 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ZoneDataMgr {
    void *archive;
    u8    record[0x34 - 0x04];
    u16   cached_id;
    u16   pad36;
    void *table38;
    void *table3c;
    u16   count40;
    u8    count42;
    u8    count43;
    void *table44;
    u8    subst_on[0x4c - 0x48];
};

extern struct ZoneDataMgr *g_ZoneDataMgr;

extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *handle);

void ZONEDATA_Exit(void)
{
    if (g_ZoneDataMgr == 0)
        return;

    func_020307B0(g_ZoneDataMgr->table44);
    func_020307B0(g_ZoneDataMgr->table3c);
    func_020307B0(g_ZoneDataMgr->table38);
    ARC_TOOL_DeleteHandle(g_ZoneDataMgr->archive);
    func_020307B0(g_ZoneDataMgr);
    g_ZoneDataMgr = 0;
}

void ZONEDATA_SetChangeZoneEnable(u32 index, u8 on)
{
    if (g_ZoneDataMgr != 0)
        g_ZoneDataMgr->subst_on[index] = on;
}
