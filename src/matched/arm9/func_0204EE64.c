/*
 * function: BILLBOARD_BindImageResource
 * address:  0x0204EE64
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_TransVramTexture   0x02046FF8  arm
 *   G3D_SYSTEM_GetTexVramKey   0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey   0x020473B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_BindImageResource.c \
 *       --func BILLBOARD_BindImageResource --addr 0x0204EE64 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Layer;
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);

struct Struct_0204EE64 {
    u32 heapId;
    u8 pad[0xc - 4];
    u32 offC;
    u32 off10;
    u8 pad2[0x20 - 0x14];
    u32 off20;
    u32 off24;
};

void BILLBOARD_BindImageResource(struct Struct_0204EE64 *p, u32 heapId)
{
    u32 res;

    p->heapId = heapId;
    if (G3D_SYSTEM_TransVramTexture((int *)heapId) == 0) {
        p->offC = 0;
        p->off10 = 0;
        return;
    }

    p->off20 = G3D_SYSTEM_GetTexVramKey((struct Layer *)heapId);
    res = G3D_SYSTEM_GetPlttVramKey((struct Layer *)heapId);

    p->off24 = res;
    p->offC = (u32)(p->off20 << 16) >> 13;
    p->off10 = (u32)(res << 16) >> 13;
}
