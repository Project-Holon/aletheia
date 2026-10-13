/*
 * unit:     yes
 * function: BTL_ID_IsCopycatExcludedMove, BTL_ID_IsMimicExcludedMove, BTL_ID_GetMetronomeExcludedMoves, BTL_PICK_InitSlotChoices
 * address:  0x0689CA5C
 * packet:   pkt_ov095_0689CA5C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ID_IsCallMoveExcluded  0x0689CA0C  thumb  ov095
 *   BTL_ID_IsInList  0x0689C888  thumb
 *   gCopycatExtraExcludedMoves     0x0689E3AC  data  ov095  a2
 *   gMimicExcludedMoves     0x0689E2CE  data  ov095  a2
 *   gMetronomeExcludedMoves     0x0689E3FC  data  ov095  a4
 */

typedef unsigned char u8;

extern unsigned short gCopycatExtraExcludedMoves[];
extern unsigned short gMimicExcludedMoves[];
extern int gMetronomeExcludedMoves[];

int BTL_ID_IsCallMoveExcluded(unsigned a);
int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);

int BTL_ID_IsCopycatExcludedMove(unsigned a)
{
    if (BTL_ID_IsCallMoveExcluded(a))
        return 1;
    return BTL_ID_IsInList(a, gCopycatExtraExcludedMoves, 0x14);
}

int BTL_ID_IsMimicExcludedMove(unsigned a)
{
    return BTL_ID_IsInList(a, gMimicExcludedMoves, 6);
}

int *BTL_ID_GetMetronomeExcludedMoves(int *p)
{
    *p = 0x29;
    return gMetronomeExcludedMoves;
}

void BTL_PICK_InitSlotChoices(int *p, int a, u8 b, u8 c)
{
    unsigned i;
    ((u8 *)p)[0xb] = c;
    ((u8 *)p)[4] = b;
    *p = a;
    for (i = 0; i < 6; i++)
        ((u8 *)p)[5 + i] = 0;
}
