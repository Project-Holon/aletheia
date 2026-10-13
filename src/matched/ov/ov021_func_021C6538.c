/*
 * function: FIELD_G3DOBJ_AddResource
 * address:  0x021C6538
 * packet:   pkt_ov021_021C6538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3DOBJ_LoadResource  0x021C6874  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 pad[0x28]; } Item;
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; } Mgr;
extern void FIELD_G3DOBJ_LoadResource(Item *it, u32 b, void *c, int d, int e);
u16 FIELD_G3DOBJ_AddResource(Mgr *m, void *c, int d, int e)
{
    u16 i;
    Item *it = m->f8;
    for (i = 0; i < m->f4; i++, it++) {
        if (it->f0 == 0) {
            FIELD_G3DOBJ_LoadResource(it, m->f0, c, d, e);
            return i;
        }
    }
    return 0;
}
