/*
 * function: SWEET_SCENT_FadeCleanup
 * address:  0x021C6368
 * packet:   pkt_ov021_021C6368
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040E78  0x02040E78  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef unsigned int   u32;
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);

void SWEET_SCENT_FadeCleanup(u8 *p)
{
    Pt pt = {0, 0};

    func_02040E78(p[0], &pt, 8, 0x20);
    func_02041300(p[0], 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_02040DA8(p[0], 1, 0x100);
}
