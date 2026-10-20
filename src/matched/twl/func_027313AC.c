/*
 * function: PMi_GetBatteryLevelCore
 * address:  0x027313AC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208BC8C 0x0208BC8C arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0208BC8C(u32 cmd, u32 a, u16 *buf);

u32 PMi_GetBatteryLevelCore(u16 *levelBuf)
{
    u16 v;
    int r = func_0208BC8C(15, 1, &v);
    if (r == 0 && levelBuf != 0) {
        *levelBuf = v;
    }
    return r;
}
