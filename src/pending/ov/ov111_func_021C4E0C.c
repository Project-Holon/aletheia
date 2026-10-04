/*
 * function: func_021C4E0C
 * address: 0x021C4E0C
 * packet: pkt_ov111_021C4E0C
 * region: ov111
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * symbols:
 *   func_021C4B74 0x021C4B74 thumb
 *   func_021C4D48 0x021C4D48 thumb
 *
 * note 2026-10-04: DIFF, 35 bytes, size equal (372). State machine on p[0x32C6]
 * (12 cases) is correct in all cases except case 0. There the original keeps the
 * 0x305C constant live after the ldrh (flag in r0, ternary value in r2) and derives
 * 0x304C/0x3050 as base-0x10/-0xc; ours reuses the register and loads a separate
 * 0x304C constant, so the pool gets one extra word (+4 shift in later pool refs).
 * Tried: ternary, if/else, local v, a u32 *q = p+0x305C with q[-4]/q[-3] (size worse).
  *
 * note 2026-10-04 (lane 20, D2): also tried `unsigned off = 0x305C;` with *(u16 *)(p + off) and
 * (p + (off - 0x10)) / (off - 0xC): still 35 bytes, size equal; the compiler folds off and derives
 * 0x304C/0x3050 from a separate pool constant. The original keeps r1 = 0x305C live, so the offset is
 * a non-foldable value (same shape as ov223 021BB18C where r4 = 0x240 is kept and 0x234 = r4 - 0xc).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C4B74(char *p, int flag);
extern void func_021C4D48(int side);
int func_021C4E0C(char *p)
{
    switch (*(u8 *)(p + 0x32C6)) {
    case 0:
        {
            int v;
            if (*(u16 *)(p + 0x305C) == 0) {
                v = 0x20;
            } else {
                v = 0xE0;
            }
            *(u32 *)(p + 0x304C) = v;
        }
        *(u32 *)(p + 0x3050) = 0x98;
        *(u32 *)(p + 0x303C) = 0x103D;
        *(u32 *)(p + 0x3040) = 0x103D;
        *(u8 *)(p + 0x32C6) = 1;
        break;
    case 1:
        *(int *)(p + 0x303C) += 0x100;
        *(int *)(p + 0x3040) += 0x100;
        if (*(int *)(p + 0x303C) >= 0x2000) {
            *(int *)(p + 0x303C) = 0x2000;
            *(int *)(p + 0x3040) = 0x2000;
            *(u8 *)(p + 0x32C6) = 2;
        }
        break;
    case 2:
        *(u16 *)(p + 0x305E) = 1;
        func_021C4B74(p, *(int *)(p + 0x3034));
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 3:
        *(u8 *)(p + 0x32C6) = 4;
        break;
    case 4:
        *(int *)(p + 0x303C) -= 0x100;
        *(int *)(p + 0x3040) -= 0x100;
        if (*(int *)(p + 0x303C) <= 0x1000) {
            *(int *)(p + 0x303C) = 0x1000;
            *(int *)(p + 0x3040) = 0x1000;
            *(u8 *)(p + 0x32C6) = 5;
        }
        break;
    case 5:
        *(int *)(p + 0x304C) = 0x80;
        *(int *)(p + 0x3050) = 0x60;
        *(u16 *)(p + 0x305E) = 0;
        func_021C4B74(p, *(int *)(p + 0x3034));
        func_021C4D48(-1);
        return 1;
    case 6:
        *(u8 *)(p + 0x32C6) = 7;
        break;
    case 7:
        *(int *)(p + 0x304C) -= 8;
        if (*(int *)(p + 0x304C) < 0x20) {
            *(int *)(p + 0x304C) = 0x20;
            *(u8 *)(p + 0x32C6) = 8;
        }
        break;
    case 8:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 9:
        *(u8 *)(p + 0x32C6) = 10;
        break;
    case 10:
        *(int *)(p + 0x304C) += 8;
        if (*(int *)(p + 0x304C) > 0xE0) {
            *(int *)(p + 0x304C) = 0xE0;
            *(u8 *)(p + 0x32C6) = 11;
        }
        break;
    case 11:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    }
    *(u8 *)(p + 0x32CA) |= 4;
    return 0;
}
