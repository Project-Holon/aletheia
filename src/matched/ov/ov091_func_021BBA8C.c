/*
 * function: PLIST_MENU_Create
 * address:  0x021BBA8C
 * packet:   pkt_ov091_021BBA8C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   gPlistMenuAllocSite     0x021BED38  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gPlistMenuAllocSite[];
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern u32 func_020275E4(void);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

u32 *PLIST_MENU_Create(u16 *h)
{
    u32 *r;

    r = func_02030734(*h, 0x84, 0, (const char *)gPlistMenuAllocSite, 0x63);
    func_02049B40(func_020275E4(), 0x1f, 0, 0x20, 0x40, *h);
    r[0x20] = (u32)ARC_UTIL_LoadBgCharDataFromArchive(func_020275E4(), 0x20, 0, (u32)((void **)&r[0x1f]), *h);
    return r;
}
