/*
 * function: GFL_NET_LOWER_DATA_RecvChunk
 * address:  0x0203ECD8
 * packet:   pkt_0203EC7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F4     0x021469F4  data
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *
 * Credit `delta` to the score record of player `idx` (0xff meaning "me",
 * folded to slot 0 on entry).  The record table hangs off the one global the
 * whole file uses, g_021469F4, whose first words are the per-slot record
 * pointers and whose +0x38 / +0x40 are the mode and the dirty flag.
 *
 * Both entry guards are one `||` apiece, which is what makes the `cmpne` /
 * `ldrne` / `popeq` chain: the table pointer and the slot's record are tested
 * together and the null exit is each guard's own conditional return
 * (contrast GFL_NET_LOWER_DATA_GetPostEndAddress in this packet, which shares one exit block; see
 * docs/notes/pkt_0203EC7C.c.txt).  The global is re-read after every call
 * because each callee may publish a new table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_LOWER_DATA_RecvChunk.c \
 *       --func GFL_NET_LOWER_DATA_RecvChunk --addr 0x0203ECD8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8  pad_00[0xc];
    u32 unk_0c;
};

struct Tbl {
    struct Rec *ent[0xe];
    u32 unk_38;
    u8  pad_3c[4];
    u32 unk_40;
};

struct Ctx {
    u8  pad_00[0x64];
    u8  unk_64;
};

extern struct Tbl *g_021469F4;

extern void *GFL_NET_GetInitParam(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);

void GFL_NET_LOWER_DATA_RecvChunk(u32 idx, u32 delta, u32 a2, u32 a3, u32 who)
{
    struct Ctx *ctx;
    struct Rec *rec;

    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 == 0 || g_021469F4->ent[idx] == 0) {
        return;
    }

    ctx = GFL_NET_GetInitParam();

    if (g_021469F4 == 0 || g_021469F4->ent[idx] == 0) {
        return;
    }

    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() != who && ctx->unk_64 == 0) {
        return;
    }

    rec = g_021469F4->ent[idx];
    rec->unk_0c += delta;

    if (g_021469F4->unk_38 != 1) {
        return;
    }

    if (idx != GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()))) {
        g_021469F4->unk_40 = 1;
    }
}
