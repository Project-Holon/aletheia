/*
 * function: FIELD_PLACE_NAME_CreateClactRenderer
 * address:  0x021BC730
 * packet:   pkt_ov021_021BC730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldPlaceNameRendererParam     0x021D9B78  data  a4
 *   CLACT_CreateRenderer  0x0204B034  arm  arm9
 */

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x2A];
    void *f38;
} Obj;

extern int gFieldPlaceNameRendererParam;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);

void FIELD_PLACE_NAME_CreateClactRenderer(Obj *p)
{
    p->f38 = CLACT_CreateRenderer((u8 *)(&gFieldPlaceNameRendererParam), 1, p->hC);
}
