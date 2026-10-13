/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrReflectProc2
 * address:  0x0219DBC8
 * packet:   pkt_ov021_0219DBC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_MOVE_GetDirMapAttr  0x02163F40  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int FLDMMDL_CheckMoveBitReflect(void *a0);
typedef unsigned short u16;
extern int FLDMMDL_MOVE_GetDirMapAttr(int a, int dir);
extern int FLDMMDL_SetMoveBitReflect(void *a0, int a1);
extern u16 MAP_ATTR_GetFlags(u32 attr);

void FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(void *a, u32 b, u32 c, u8 *d)
{
    int r;
    if (d[6] != 0 && FLDMMDL_CheckMoveBitReflect((void *)a) != 0) {
        r = FLDMMDL_MOVE_GetDirMapAttr((int)a, 1);
        if (r == -1) {
            FLDMMDL_SetMoveBitReflect(a, 0);
            return;
        }
        if ((MAP_ATTR_GetFlags(r) & 0x40) == 0) {
            FLDMMDL_SetMoveBitReflect(a, 0);
        }
    }
}
