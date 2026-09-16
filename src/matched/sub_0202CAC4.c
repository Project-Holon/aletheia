/*
 * unit:     no
 * function: sub_0202CAC4
 * address:  0x0202CAC4
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *
 * Copies a decoded tile image into the window record's own buffer: the byte
 * count is the record's two 6-bit size bitfields multiplied together and
 * doubled, so the unit is a 2-byte tile entry, not a pixel. Same 16-byte
 * window record as src/matched/sub_0202CB4C.c.
 *
 * The only two callers are sub_0202CAE4 and sub_0202CB18 (0x0202CB0A and
 * 0x0202CB3E), both immediately after this function. It therefore has to
 * stay its own file: folding it into a unit with either of them would leave
 * the other without a `label` witness for the call site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202CAC4.c \
 *       --func sub_0202CAC4 --addr 0x0202CAC4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

struct Win {
    u32 tiles;
    u16 w:6;
    u16 h:6;
    u16 dirty:1;
    u16 unk04_13:3;
    s8 x;
    s8 y;
    u8 pad_08[2];
    u8 bg;
    u8 pad_0b;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
};

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

void sub_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src)
{
    MIi_CpuCopy16(src, (void *)mgr->wins[idx].tiles,
                  mgr->wins[idx].w * mgr->wins[idx].h * 2);
}
