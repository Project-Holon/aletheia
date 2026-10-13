/*
 * function: FIELD_G3DOBJ_SetObjectHidden
 * address:  0x021C6678
 * packet:   pkt_ov021_021C6678
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*

 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 k:2; u32 x:1; u32 b:1; u32 rest:28; u8 pad[0x64]; } Elem;
typedef struct { u8 pad[0xc]; Elem *fC; } Mgr;
void FIELD_G3DOBJ_SetObjectHidden(Mgr *m, int idx, int v)
{
    m->fC[idx].b = v;
}
