/*
 * function: FIELD_GIMMICK_D06_AddStoneMmdl
 * address: 0x021F3D38
 * packet: pkt_ov051_021F3D38
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Scalar stack slots reproduce the In3 aggregate: 0216CE84/8A/8E
 *       read only low halfwords at incoming +0/+4/+8; padding is unread.
 *       The fourth outgoing word feeds x at 0216CE90; 0216CE60 forwards
 *       only the constructed Big record, never the original padding.
 * symbols:
 *   FIELDMAP_GetMmdlSys 0x02188C7C thumb ov021
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   FLDMMDL_AddMmdlParam 0x0216CE6C thumb ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *FLDMMDL_AddMmdlParam(void *, int, int, unsigned short, unsigned, unsigned, unsigned, unsigned);

void *FIELD_GIMMICK_D06_AddStoneMmdl(int a, int x, int y)
{
    void *p = FIELDMAP_GetMmdlSys((u8 *)a);
    int n = FIELDMAP_GetZoneId((u8 *)a);
    return FLDMMDL_AddMmdlParam(p, (short)x, (short)y, 0, 0xfd, 0, 0, n);
}
