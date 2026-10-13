/*
 * function: func_021A1428
 * address:  0x021A1428
 * packet:   pkt_ov021_021A1428
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   BEACON_VIEW_Create  0x021F2234  thumb  ov032
 *   abs_id_20      0x00000020  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_20[];
extern int func_02034AC4(int);
extern void *FIELDMAP_GetGameSystem(void *p);
extern char *BEACON_VIEW_Create(u32 a0, u32 a1);

void func_021A1428(u32 *p)
{
    func_02034AC4((int)abs_id_20);
    p[8] = (u32)BEACON_VIEW_Create((u32)FIELDMAP_GetGameSystem((void *)p[5]), (u32)p);
}
