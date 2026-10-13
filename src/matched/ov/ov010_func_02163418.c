/*
 * function: FLDMMDL_MOVE_AttrSetDrawOffset
 * address: 0x02163418
 * packet: pkt_ov010_02163418
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 * symbols:
 *   FLDMMDL_CheckStatusBitAttrOffsetOff 0x0216DC00 thumb ov010
 *   func_021AB41C 0x021AB41C thumb ov021
 *   FLDMMDL_SetAttrOffset 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 */
typedef struct { int x, y, z; } V;
typedef struct { char pad[10]; unsigned short f; } S;
extern int FLDMMDL_CheckStatusBitAttrOffsetOff(void *a0);
extern int func_021AB41C(unsigned short);
extern void FLDMMDL_SetAttrOffset(int, const V *);
extern V d_021714D0;
static inline void vzero(V *p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}
void FLDMMDL_MOVE_AttrSetDrawOffset(int a, S *s)
{
    V v;
    V *pz;
    if (FLDMMDL_CheckStatusBitAttrOffsetOff((void *)a) == 0 && func_021AB41C(s->f) != 0) {
        v = d_021714D0;
        FLDMMDL_SetAttrOffset(a, &v);
        return;
    }
    {
        unsigned char buf[12];
        V *z = (V *)buf;
        vzero(z);
        FLDMMDL_SetAttrOffset(a, z);
    }
}
