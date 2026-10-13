/*
 * function: UNION_EFF_UpdateIconGroup
 * address: 0x0217FD04
 * packet: pkt_ov019_0217FD04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_CheckStatusBitUse 0x0216DA30 thumb ov010
 *   UNION_EFF_UpdateIconObj 0x0217FCC0 thumb ov019
 *   UNION_EFF_DeleteIconObj 0x0217FCA4 thumb ov019
 */

typedef unsigned int u32;
struct E { u32 a,b,c,d; unsigned short h; };
extern int FLDMMDL_CheckStatusBitUse(u32 a);
extern void UNION_EFF_UpdateIconObj(struct E *e);
extern void UNION_EFF_DeleteIconObj(u32 *p);
void UNION_EFF_UpdateIconGroup(struct E *p)
{
    int i;
    for (i=0;i<10;i++) {
        struct E *e=&p[i];
        if (e->d != 0) {
            if (FLDMMDL_CheckStatusBitUse(e->a) == 1) UNION_EFF_UpdateIconObj(e);
            else UNION_EFF_DeleteIconObj((u32 *)e);
        }
    }
}
