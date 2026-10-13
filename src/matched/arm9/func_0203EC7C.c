/*
 * function: GFL_NET_LOWER_DATA_GetPostEndAddress
 * address:  0x0203EC7C
 * packet:   pkt_0203EC7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   g_021469F4     0x021469F4  data
 *
 * net_lower_data.c: end offset (+0x00 base plus +0x0C length) of record
 * idx (0xFF meaning 0) in the table g_021469F4 points to, re-checked after
 * func_0203D798; 0 when the table or record is missing.  Same double guard
 * as the matched GFL_NET_LOWER_DATA_RecvChunk, but the FIRST guard is a wrapping positive
 * test (`!= 0 && != 0`) whose failure falls through to the one trailing
 * return 0, which is the shared null-exit block the earlier note wanted.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec {
    u32 unk_00;
    u8  pad_04[8];
    u32 unk_0c;
};
struct Tbl {
    struct Rec *ent[0xe];
};

extern struct Tbl *g_021469F4;
extern void *func_0203D798(void);

u32 GFL_NET_LOWER_DATA_GetPostEndAddress(u32 idx)
{
    struct Rec *rec;
    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 != 0 && g_021469F4->ent[idx] != 0) {
        func_0203D798();
        if (g_021469F4 == 0 || g_021469F4->ent[idx] == 0) {
            return 0;
        }
        rec = g_021469F4->ent[idx];
        return rec->unk_00 + rec->unk_0c;
    }
    return 0;
}
