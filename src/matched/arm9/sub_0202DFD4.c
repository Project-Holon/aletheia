/*
 * unit:     no
 * function: PMS_DRAW_ReleaseResources
 * address:  0x0202DFD4
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *
 * Three teardown calls on three consecutive pointer fields, each a
 * different ARM entry point, in the order the fields sit in the struct.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_ReleaseResources.c \
 *       --func PMS_DRAW_ReleaseResources --addr 0x0202DFD4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct Obj0202DFD4 {
    u8    pad[8];
    void *unk08;
    void *unk0C;
    void *unk10;
};

typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void PMS_DRAW_ReleaseResources(struct Obj0202DFD4 *p)
{
    CLACT_ReleasePalette((u32)p->unk08);
    CLACT_ReleaseCharacter((u32)p->unk0C);
    CLACT_ReleaseCellAnim((u32)p->unk10);
}
