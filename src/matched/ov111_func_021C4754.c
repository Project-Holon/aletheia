/*
 * function: func_021C4754
 * address:  0x021C4754
 * packet:   pkt_ov111_021C4754
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204989C  0x0204989C  arm
 *   d_021C85D8     0x021C85D8  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 lo : 4;
    u8 alt : 1;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
} Work;

typedef struct {
    u32 file[2][2];
} FileTable;

extern void func_0204989C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern const FileTable d_021C85D8;

void func_021C4754(Work *p, int kind)
{
    FileTable t = d_021C85D8;
    int j = 1;

    if (kind == 0x14) {
        j = 0;
    }
    func_0204989C(0x28, t.file[p->info->alt][j], 6, 0, 0, 0, p->heap);
}
