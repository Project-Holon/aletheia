/*
 * function: PM_GetExitFactor
 * address:  0x0273153C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_02153000 0x02153000 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 pad[0x14];
    u32 f14;
} S2153;
extern S2153 d_02153000;
#define G2153 (&d_02153000)

u32 PM_GetExitFactor(void)
{
    return G2153->f14;
}
