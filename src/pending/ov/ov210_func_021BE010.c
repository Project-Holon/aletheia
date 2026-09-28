/*
 * function: func_021BE010
 * address:  0x021BE010
 * packet:   pkt_ov210_021BE010
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  all 5 relocations resolve; 178 vs 180 bytes.  The switch dispatch
 *           and every arm are semantically right, but mwcc lays the shared
 *           "RET19" and the else-block out in a different order (bhi target
 *           0x21BE09A vs 0x21BE0BE), shifting case arms by 2-4 bytes.
 *           Tried return-per-arm and break-with-single-return spellings.
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   func_021BEDE0  0x021BEDE0  thumb ov210
 *   func_021BF728  0x021BF728  thumb ov210
 *   func_021BFF30  0x021BFF30  thumb ov210
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  func_020355C4(void);
extern int  func_021BEDE0(int);
extern void func_021BF728(void *, int);
extern void func_021BFF30(void *, int, int);

int func_021BE010(u8 *p)
{
    if (*(u8 *)(p + 0x2C0) == 0) {
        switch (*(u8 *)(p + 0x2C2)) {
        case 0:
        case 2:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 1);
                *(u8 *)(p + 0x2C3) = 4;
                *(u8 *)(p + 0x2C2) = *(u8 *)(p + 0x2C2) + 1;
            } else {
                *(u8 *)(p + 0x2C3) = *(u8 *)(p + 0x2C3) - 1;
            }
            break;
        case 1:
        case 3:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 2);
                *(u8 *)(p + 0x2C3) = 4;
                *(u8 *)(p + 0x2C2) = *(u8 *)(p + 0x2C2) + 1;
            } else {
                *(u8 *)(p + 0x2C3) = *(u8 *)(p + 0x2C3) - 1;
            }
            break;
        case 4:
            if (func_020355C4() == 1)
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 1);
            else
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 3);
            return *(u32 *)(p + 0x1C);
        }
        return 0x19;
    }
    if (func_021BEDE0(*(u8 *)(p + 0x2C1)) == 0) {
        if (*(u32 *)(p + 0x1E0) != 0)
            func_021BF728(p, 0);
        return *(u32 *)(p + 0x1C);
    }
    return 0x19;
}
