/*
 * function: FIELD_G3D_MAP_ReadNextChunk
 * address:  0x02169620
 * packet:   pkt_ov010_02169620
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct ArcFile;
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);

typedef struct S {
    u8 pad0[0x10];
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

int FIELD_G3D_MAP_ReadNextChunk(S *p)
{
    u32 base;
    u32 cur;
    u32 len;
    u32 tot;
    u32 rem;

    base = p->base;
    cur = p->cur;
    len = p->len;
    tot = p->tot;
    if (tot <= len)
        return 0;
    rem = tot - len;
    if (rem > p->n) {
        ARC_TOOL_ReadHandle((struct ArcFile *)p->h, p->n, (void *)(base + cur));
        p->cur = p->cur + p->n;
        p->len = p->len + p->n;
        return 1;
    }
    ARC_TOOL_ReadHandle((struct ArcFile *)p->h, rem, (void *)(base + cur));
    p->cur = p->cur + rem;
    return 0;
}
