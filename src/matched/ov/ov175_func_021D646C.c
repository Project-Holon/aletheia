/*
 * function: WIFIBATTLEMATCH_NET_GetSetBsubwayStat
 * address: 0x021D646C
 * packet: pkt_ov175_021D646C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   BSUBWAY_SAVEDATA_SetStat 0x0200DFE4 thumb
 */
typedef unsigned int u32;
extern u32 BSUBWAY_SAVEDATA_GetStat(u32, u32, u32);
extern void BSUBWAY_SAVEDATA_SetStat(u32, u32, u32, u32);
int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(u32 save, u32 kind, u32 obj)
{
    int *q;
    u32 a;
    u32 b;
    u32 c;
    int changed;
    switch (kind) {
    case 0:
        q = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        a = q[3];
        b = q[0x40 / 4];
        c = q[0x3C / 4];
        break;
    case 1:
        q = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        a = q[0];
        b = q[0x28 / 4];
        c = q[0x24 / 4];
        break;
    case 2:
        q = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        a = q[0x10 / 4];
        b = q[0x48 / 4];
        c = q[0x44 / 4];
        break;
    case 3:
        q = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        a = q[1];
        b = q[0x30 / 4];
        c = q[0x2C / 4];
        break;
    case 4:
        q = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        a = q[2];
        b = q[0x38 / 4];
        c = q[0x34 / 4];
        break;
    }
    changed = (a != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 0) || b != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 1) || c != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 2));
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 0, a);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 1, b);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 2, c);
    return changed;
}
