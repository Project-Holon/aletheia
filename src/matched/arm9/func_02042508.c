/*
 * function: BG_SYS_LoadTileDataEx
 * address:  0x02042508
 * packet:   pkt_02042508
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   func_02040968  0x02040968  arm
 *   BG_SYS_LoadTileLayerEx  0x020425B4  arm
 *
 * bg_sys.c.  Upload tile data to a layer, decompressing first when the
 * caller asks for mode 0.  The mode parameter does double duty: it is the
 * conversion selector on the mode-0 path and, on the direct path, it is
 * passed straight through to BG_SYS_LoadTileLayerEx as that call's own fourth
 * argument, which is why "movs r6, r2" tests it and keeps it live.
 *
 * Three declarations carry this function, all of them from the family
 * header (docs/families/bg_sys.h):
 *   - the allocator's signature, GFL_HEAP_Alloc(heapId, size, clear, site,
 *     tag), with the u16 heap id first and the __FILE__ anchor fourth;
 *   - the scratch heap id spelling (g_02146A44->heapId & 0x7fff) | 0x8000,
 *     the same masked form BG_SYS_InitRun and BG_SYS_Init use;
 *   - the source's first word being a header whose top 24 bits are the
 *     decompressed byte count, hence "lsr r4, r2, #8" on *src.
 * The allocator tag is 2963 and the site string is the bg_sys.c anchor at
 * 0x020A7E5C.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_LoadTileDataEx.c \
 *       --func BG_SYS_LoadTileDataEx --addr 0x02042508 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot { u16 heapId; };
extern struct Slot *g_02146A44;
extern char g_020A7E5C[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern void  func_02040968(const void *src, void *dst, u32 mode);
extern void  BG_SYS_LoadTileLayerEx(u32 index, const void *src, u32 size, u32 offset);

void BG_SYS_LoadTileDataEx(u32 index, const u32 *src, u32 mode, u32 size)
{
    if (mode == 0) {
        u32   n = *src >> 8;
        void *buf;

        buf = GFL_HEAP_Alloc((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                           n, 0, g_020A7E5C, 2963);
        func_02040968(src, buf, mode);
        BG_SYS_LoadTileLayerEx(index, buf, size, n);
        GFL_HEAP_Free(buf);
    } else {
        BG_SYS_LoadTileLayerEx(index, src, size, mode);
    }
}
