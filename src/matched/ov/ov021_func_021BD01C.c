/*
 * function: FIELD_PLACE_NAME_CreateBmpWin
 * address:  0x021BD01C
 * packet:   pkt_ov021_021BD01C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

typedef unsigned short u16;
extern u16 FIELD_PLACE_NAME_GetHeapId(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

void FIELD_PLACE_NAME_CreateBmpWin(Obj *p)
{
    FIELD_PLACE_NAME_GetHeapId((unsigned char *)p);
    p->f24 = (void *)BMP_WIN_Create(3, 0, 1, 0x20, 2, 0, 0);
}
