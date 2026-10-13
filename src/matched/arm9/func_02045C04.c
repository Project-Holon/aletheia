/*
 * function: MSGDATA_Delete
 * address:  0x02045C04
 * packet:   pkt_02045AA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *
 * Tear down the record: when the +0x14 handle is live, release the two
 * buffers it owns (the second only if non-NULL) and close the handle, then
 * free the record itself either way.
 *
 * The +0x14 guard reads the field once and the close reads it again, which
 * is why the original has two `ldr r0, [r4, #0x14]` around the calls: the
 * intervening frees may alias it, so no `const` local is involved.  The
 * second buffer's guard needs no register move, the guarded call consuming
 * the value the `cmp` already loaded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_Delete.c \
 *       --func MSGDATA_Delete --addr 0x02045C04 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Rec {
    void *unk_00;
    void *unk_04;
    u8    pad_08[0xc];
    void *unk_14;
};

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *handle);

u32 MSGDATA_Delete(struct Rec *rec)
{
    if (rec->unk_14 != 0) {
        func_020307B0(rec->unk_00);
        if (rec->unk_04 != 0) {
            func_020307B0(rec->unk_04);
        }
        ARC_TOOL_DeleteHandle(rec->unk_14);
    }
    return func_020307B0(rec);
}
