/*
 * unit:     no
 * function: CLACT_InitAnimCtl
 * address:  0x0204D0C4
 * packet:   pkt_0204CFDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactAnimFuncTable  0x020A1394  data
 *   CLACT_GetAnimCtlKind   0x0204D134  arm
 *
 * Constructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner, and the counterpart of the destructor at 0x0204D104:
 * derive the kind tag from the request with CLACT_GetAnimCtlKind, stamp it into
 * word 0, then run row 6 of the handler table at 0x020A1394 with the object
 * and the two forwarded arguments.
 *
 * The kind stays in ip across the table load and is stored only just before
 * the `blx`, which is the ordinary effect of the store having no consumer:
 * the index is needed for the table load either way, so the store sinks to
 * the last position that still precedes the call.
 *
 * The table is row 6 of the one eight-by-three array based at 0x020A1394;
 * see src/matched/CLACT_SetAnimSeq.c for the row map and why the base rather
 * than the row is the relocation's symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitAnimCtl.c \
 *       --func CLACT_InitAnimCtl --addr 0x0204D0C4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Sub {
    u32 kind;
};

typedef signed int     s32;
struct Req;
extern s32 CLACT_GetAnimCtlKind(const struct Req *r);
extern void (*const g_ClactAnimFuncTable[][3])(struct Sub *s, void *c, u32 e);

void CLACT_InitAnimCtl(struct Sub *s, void *c, u32 e)
{
    u32 kind = CLACT_GetAnimCtlKind(c);

    s->kind = kind;
    g_ClactAnimFuncTable[6][kind](s, c, e);
}
