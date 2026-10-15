/*
 * function: VIEWER_MAIN_SetupBgSlot
 * address:  0x021C436C
 * packet:   pkt_ov111_021C436C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   d_021C8E20     0x021C8E20  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 kind;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pad2C[0x31E8 - 0x2C];
    void *f31E8;
    void *f31EC;
} Work;

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern const u32 d_021C8E20[][2];

void VIEWER_MAIN_SetupBgSlot(Work *p, int k, int alt)
{
    int j = 1;
    u32 file;

    if (p->info->kind == 0x14) {
        j = 0;
    } else if (p->info->kind != 0x15) {
        k = 6;
    }
    file = d_021C8E20[k][j];
    func_02049B40(0x28, file, 4, 0, 0x200, p->heap);
    p->f31E8 = ARC_UTIL_LoadPaletteBlockFromArchive(0x28, file, (u32)(&p->f31EC), p->heap);
}
