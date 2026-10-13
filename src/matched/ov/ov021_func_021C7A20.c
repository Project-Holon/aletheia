/*
 * function: FIELD_TASK_UpdateMmdlDrawOffsetTween
 * address:  0x021C7A20
 * packet:   pkt_ov021_021C7A20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_TASK_CalcOffsetByProgress  0x021C7940  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    int f8;
    u16 fC;
    u16 fE;
    Vec f10;
    Vec f1C;
    int f28;
} Obj;

extern void FIELD_TASK_CalcOffsetByProgress(Vec *, u16, Vec *, u16);
extern void FLDMMDL_SetDrawOffset(int, Vec *);

int FIELD_TASK_UpdateMmdlDrawOffsetTween(Obj *p)
{
    int h = p->f28;
    Vec v;

    if (p->f0 == 0) {
        p->fC = p->fC + 1;
        if (p->f8 == 0) {
            FIELD_TASK_CalcOffsetByProgress(&v, p->fC, &p->f10, p->fE);
        } else if (p->f8 == 1) {
            FIELD_TASK_CalcOffsetByProgress(&v, p->fE - p->fC, &p->f10, p->fE);
        }
        FLDMMDL_SetDrawOffset(h, &v);
        if (p->fE <= p->fC) {
            return 1;
        }
    }
    return 0;
}
