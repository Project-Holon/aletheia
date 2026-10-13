/*
 * function: FIELD_PLACE_NAME_CreateMessage
 * address:  0x021BD008
 * packet:   pkt_ov021_021BD008
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm  arm9
 */

typedef struct {
    char pad[0x1C];
    void *f1C;
} Obj;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELD_PLACE_NAME_GetHeapId(u8 *p);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

void FIELD_PLACE_NAME_CreateMessage(Obj *p)
{
    p->f1C = STRBUF_Create(0x21, FIELD_PLACE_NAME_GetHeapId((u8 *)p));
}
