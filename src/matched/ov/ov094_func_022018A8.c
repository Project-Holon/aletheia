/*
 * function: BTLV_MCSS_CalcSlotPosition
 * address:  0x022018A8
 * packet:   pkt_ov094_022018A8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvMcssSlotPosSingle  0x0220A050  data  ov094
 *   gBtlvMcssSlotPosDouble  0x0220A080  data  ov094
 *   gBtlvMcssSlotPosTrainer  0x0220A110  data  ov094
 *   gBtlvMcssSlotPosTriple  0x0220A158  data  ov094
 *   gBtlvMcssSlotPosRotation  0x0220A1A0  data  ov094
 */
typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    char pad[0x510];
    Flags flags;
} Unit;

extern const Vec gBtlvMcssSlotPosSingle[];
extern const Vec gBtlvMcssSlotPosDouble[];
extern const Vec gBtlvMcssSlotPosTrainer[];
extern const Vec gBtlvMcssSlotPosTriple[];
extern const Vec gBtlvMcssSlotPosRotation[];

void BTLV_MCSS_CalcSlotPosition(Unit *u, Vec *out, int i)
{
    const Vec *t = (const Vec *)u;

    switch (i) {
    case 0:
    case 1:
        t = &gBtlvMcssSlotPosSingle[i];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (u->flags.b1)
            t = &gBtlvMcssSlotPosRotation[i - 2];
        else if (u->flags.b0)
            t = &gBtlvMcssSlotPosTriple[i - 2];
        else
            t = &gBtlvMcssSlotPosDouble[i - 2];
        break;
    case 6:
    case 7:
        if (u->flags.b1)
            t = &gBtlvMcssSlotPosRotation[i - 2];
        else
            t = &gBtlvMcssSlotPosTriple[i - 2];
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        t = &gBtlvMcssSlotPosTrainer[i - 8];
        break;
    }
    out->x = t->x;
    out->y = t->y;
    out->z = t->z;
}
