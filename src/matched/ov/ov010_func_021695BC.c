/*
 * function: FIELD_G3D_MAP_BeginChunkedLoad
 * address:  0x021695BC
 * packet:   pkt_ov010_021695BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * lever: The archive length call takes the still-live member argument; the remaining two bytes are zero alignment padding.
 *
 * symbols:
 *   FIELD_G3D_MAP_ReadWhole  0x02169A88  thumb  ov010
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern void FIELD_G3D_MAP_ReadWhole(u8 *p, u32 n);
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *h, u32 b, u32 c, u32 d, void *e);

typedef struct S {
    u16 pad0;
    u16 busy;
    u8 pad4[0x0c];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S;

void FIELD_G3D_MAP_BeginChunkedLoad(S *p, int b)
{
    u32 t;

    if (p->busy != 0) {
        FIELD_G3D_MAP_ReadWhole((u8 *)p, b);
        return;
    }
    t = p->base + p->cur;
    p->tot = ARC_TOOL_GetHandleMemberSize((struct ArcFile *)p->h, b);
    p->len = 0;
    ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)p->h, b, 0, p->n, (void *)t);
    p->cur = p->cur + p->n;
    p->len = p->len + p->n;
}
