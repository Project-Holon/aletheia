/*
 * function: func_021CA164
 * address:  0x021CA164
 * packet:   pkt_ov021_021CA164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * symbols:
 *   func_0200DC08  0x0200DC08  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DBF0  0x0200DBF0  thumb
 *   func_0200DC0C  0x0200DC0C  thumb
 *   func_0200DBFC  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk1AC;
extern u8 func_0200DC08(struct Blk1AC *p);
typedef signed int     s32;
struct Blk1AC;
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void func_0200DBF0(struct Blk1AC *p);
extern u8 func_0200DC0C(struct Blk1AC *p, u32 kind);
extern void func_0200DBFC(struct Blk1AC *p);
extern const u8 data_021DACD0[];

int func_021CA164(void *a, int unused, int mode)
{
    u8 state = (int)func_0200DC08(a);
    u32 v;

    switch (mode) {
    case 0:
        return state;
    case 3:
        func_0200DBA0(a, 0, 2);
        if (state == 10)
            return 0;
        func_0200DBF0(a);
        return 1;
    case 4:
        v = func_0200DC0C(a, 3);
        if (state == 1)
            return 0;
        if (v >= data_021DACD0[state - 1]) {
            func_0200DBFC(a);
            func_0200DC0C(a, 2);
            func_0200DBA0(a, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}
