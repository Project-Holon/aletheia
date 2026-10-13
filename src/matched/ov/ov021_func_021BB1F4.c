/*
 * function: FIELD_NOGRID_MAPPER_Create
 * address:  0x021BB1F4
 * packet:   pkt_ov021_021BB1F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_RAIL_Create  0x021B7884  thumb  ov021
 *   FIELD_RAIL_LOADER_Create  0x0219EF44  thumb  ov021
 *   RAIL_ATTR_Create  0x021BB088  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_02030734(u32, u32, int, const char *, u16);
typedef unsigned char  u8;
struct Obj;
extern struct Obj *FIELD_RAIL_Create(u16 heap, u32 n, int a2);
extern u8 *FIELD_RAIL_LOADER_Create(u32 heap);
extern void *RAIL_ATTR_Create(int a);
extern int d_021DE2D0;

u32 *FIELD_NOGRID_MAPPER_Create(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_02030734((u16)a, 0x18, 1, (const char *)&d_021DE2D0, 0x47);

    p[0] = (u32)FIELD_RAIL_Create(a, 0x30, b);
    p[1] = (u32)FIELD_RAIL_LOADER_Create(a);
    p[3] = c;
    p[4] = d;
    p[2] = (u32)RAIL_ATTR_Create(a);
    return p;
}
