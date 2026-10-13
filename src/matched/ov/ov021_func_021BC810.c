/*
 * function: FIELD_PLACE_NAME_CreateArcHandle
 * address:  0x021BC810
 * packet:   pkt_ov021_021BC810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 */

typedef struct {
    char pad[0x10];
    void *f10;
} Obj;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 FIELD_PLACE_NAME_GetHeapId(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);

void FIELD_PLACE_NAME_CreateArcHandle(Obj *p)
{
    p->f10 = func_020490F4(0x54, FIELD_PLACE_NAME_GetHeapId((u8 *)p));
}
