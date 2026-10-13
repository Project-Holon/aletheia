/*
 * unit:     yes
 * function: BTL_PICK_SetSlotState, BTL_PICK_InitList, BTL_PICK_Push, BTL_PICK_Pop, BTL_PICK_GetLocked, BTL_PICK_GetCount, BTL_PICK_GetLast, BTL_PICK_GetSlot
 * address:  0x0689CAD8
 * packet:   pkt_ov095_0689CAD8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void BTL_PICK_SetSlotState(u8 *p, u8 v, int i)
{
    (p + i)[5] = v;
}

void BTL_PICK_InitList(u8 *p, const u8 *q)
{
    p[6] = 0;
    p[7] = q[4];
}

void BTL_PICK_Push(u8 *p, u8 a, u8 b)
{
    if (p[6] < p[7]) {
        p[p[6]] = b;
        (p + p[6])[3] = a;
        p[6]++;
    }
}

void BTL_PICK_Pop(u8 *p)
{
    if (p[6])
        p[6]--;
}

int BTL_PICK_GetLocked(u8 *p)
{
    return p[8];
}

int BTL_PICK_GetCount(u8 *p)
{
    return p[6];
}

int BTL_PICK_GetLast(u8 *p)
{
    u8 n = p[6];
    if (n)
        return p[n - 1];
    return 6;
}

int BTL_PICK_GetSlot(u8 *p, u8 i)
{
    if (i < p[6])
        return p[i];
    return 6;
}
