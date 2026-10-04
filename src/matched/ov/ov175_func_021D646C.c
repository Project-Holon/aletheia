/*
 * function: func_021D646C
 * address: 0x021D646C
 * packet: pkt_ov175_021D646C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_0200DFE4 0x0200DFE4 thumb
 */
typedef unsigned int u32;
extern u32 func_0200DFD8(u32, u32, u32);
extern void func_0200DFE4(u32, u32, u32, u32);
int func_021D646C(u32 save, u32 kind, u32 obj)
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
    changed = (a != func_0200DFD8(save, kind + 5, 0) || b != func_0200DFD8(save, kind + 5, 1) || c != func_0200DFD8(save, kind + 5, 2));
    func_0200DFE4(save, kind + 5, 0, a);
    func_0200DFE4(save, kind + 5, 1, b);
    func_0200DFE4(save, kind + 5, 2, c);
    return changed;
}
