/*
 * function: func_0219C4AC
 * address:  0x0219C4AC
 * packet:   pkt_ov021_0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (Ilias's). Verified C, EXACT under --arm --region arm9:
 *     u32 func_02050080(u32 *p) { return p[1]; }
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 *   func_02050080  0x02050080  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0204F044  0x0204F044  arm
 *   func_02050238  0x02050238  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D75C4     0x021D75C4  data  a4
 *   d_021D8064     0x021D8064  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u16 d_021D75C4[][2];
extern u16 d_021D8064[];
extern int func_02046FF8(u32);
extern u32 func_02050080(u32);
extern u32 func_02047388(u32);
extern u32 func_020473B8(u32);
extern u32 func_0204F044(u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02050238(u32, u32, u32);
extern void func_02046EFC(u32);

int func_0219C4AC(u32 a, u32 b, u32 c, u32 d)
{
    int r = -1;
    if (func_02046FF8(b) == 1) {
        u32 x = func_02050080(a);
        u16 *e = d_021D75C4[c];
        u32 w = func_02047388(b);
        r = func_02050238(a, func_0204F044(x, w, func_020473B8(b), 0, d_021D8064[d], (u8)e[0], (u8)e[1]), 0);
        func_02046EFC(b);
    }
    return r;
}
