/*
 * function: FLD_SCENEAREA_Delete
 * address:  0x021AB624
 * packet:   pkt_021AB624
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLD_SCENEAREA_ClearData(void *p);
extern u32 func_020307B0(void *p);

void FLD_SCENEAREA_Delete(u8 *p)
{
    FLD_SCENEAREA_ClearData(p);
    func_020307B0(p);
}
