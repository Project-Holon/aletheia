/*
 * function: func_021BF728
 * address:  0x021BF728
 * packet:   pkt_021BF728
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct, but func_021B93B0/021B93B8/021B93C0 sit below ov210's
 *           window (0x021BC240); 11 overlays label them and none is the region
 *           under test, so their relocations stay wildcarded (MATCH*).
 *
 * symbols:
 *   func_021B93B0  0x021B93B0  thumb ov210
 *   func_021B93B8  0x021B93B8  thumb ov210
 *   func_021B93C0  0x021B93C0  thumb ov210
 *   func_021BEDB8  0x021BEDB8  thumb ov210
 *   func_021BEDD0  0x021BEDD0  thumb ov210
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  func_021B93B0(u32);
extern int  func_021B93B8(u32);
extern int  func_021B93C0(u32);
extern void func_021BEDB8(void *, int, int);
extern int  func_021BEDD0(void *, int);

void func_021BF728(u8 *p, int a)
{
    int r6 = func_021B93B0(*(u32 *)(p + 0x1E0));

    if (func_021BEDD0(p, 6) != 0xC || a == 0) {
        if (func_021B93B8(*(u32 *)(p + 0x1E0)) == 0 && r6 == 0)
            func_021BEDB8(p, 6, 0x12);
        else
            func_021BEDB8(p, 6, 4);
    }
    if (func_021BEDD0(p, 5) != 0xD || a == 0) {
        if (func_021B93C0(*(u32 *)(p + 0x1E0)) == 0 &&
            r6 == *(u32 *)(p + 0x2AC) - 1)
            func_021BEDB8(p, 5, 0x13);
        else
            func_021BEDB8(p, 5, 5);
    }
}
