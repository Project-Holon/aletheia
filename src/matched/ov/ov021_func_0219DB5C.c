/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrReflectProc01
 * address:  0x0219DB5C
 * packet:   pkt_ov021_0219DB5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_MOVE_GetDirMapAttr  0x02163F40  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_GetFldEffCtrl  0x0219DC08  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   FLDEFF_REFLECT_SetMMdl  0x021BBFB8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int FLDMMDL_CheckMoveBitReflect(void *a0);
typedef unsigned short u16;
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FLDMMDL_MOVE_GetDirMapAttr(int a, int dir);
extern int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SetMoveBitReflect(void *a0, int a1);
extern void FLDEFF_REFLECT_SetMMdl(u32, u32, u32, u32);

void FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(void *a, u32 b, u32 c, u8 *d)
{
    u32 m;
    u32 e;
    u32 f;
    if (d[6] != 0 && FLDMMDL_CheckMoveBitReflect((void *)a) == 0) {
        m = -1;
        if (b != -1) {
            if (MAP_ATTR_GetFlags(b) & 0x40) {
                m = b;
            } else {
                b = FLDMMDL_MOVE_GetDirMapAttr((int)a, 1);
                if (MAP_ATTR_GetFlags(b) & 0x40) {
                    m = b;
                }
            }
            if (m != -1) {
                e = FLDMMDL_RAIL_MOVE_GetFldEffCtrl((u32)a);
                f = (u32)FLDMMDL_GetMmdlSys((void *)a);
                FLDMMDL_SetMoveBitReflect(a, 1);
                FLDEFF_REFLECT_SetMMdl(f, (u32)a, e, 1);
            }
        }
    }
}
