/*
 * function: func_021C6368
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

extern void func_02040E78(int a, void *b, int c, int d);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(int);
extern void func_02040DA8(int, int, int);

void func_021C6368(u8 *p)
{
    Pt pt = {0, 0};

    func_02040E78(p[0], &pt, 8, 0x20);
    func_02041300(p[0], 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_02040DA8(p[0], 1, 0x100);
}
