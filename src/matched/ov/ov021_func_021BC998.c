/*
 * function: FIELD_PLACE_NAME_CreateBmpOamSys
 * address:  0x021BC998
 * packet:   pkt_ov021_021BC998
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 *   BMP_OAM_CreateSys  0x02025538  thumb  arm9
 */

typedef struct {
    char pad[0x30];
    void *f30;
    void *f34;
} Obj;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELD_PLACE_NAME_GetHeapId(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

void FIELD_PLACE_NAME_CreateBmpOamSys(Obj *p)
{
    p->f30 = BMP_OAM_CreateSys(FIELD_PLACE_NAME_GetHeapId((u8 *)p), p->f34);
}
