/*
 * unit:     no
 * function: BG_SYS_PushTileSource
 * address:  0x020409E0
 * packet:   pkt_020409E0
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
 *   sub_02030734   0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02040968  0x02040968  arm
 *   func_0204241C  0x0204241C  arm
 *
 * Push a tile source into slot `index` of the 0x2c-byte table behind
 * 0x02146A44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_PushTileSource.c \
 *       --func BG_SYS_PushTileSource --addr 0x020409E0 --cc 1.1p1 --arm
 */
#include "../include/Obj16005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u16   heapId;
    u8    pad_02[6];
    void *tiles;
    u32   unk_0c;
    u32   unk_10;
    u8    pad_14[0x18];
};

extern struct Slot *g_02146A44;
extern char g_020A7E5C[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02040968(const void *src, void *dst, u32 mode);
extern void func_0204241C(u32 index, const void *src, u32 offset, u32 size);

void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset)
{
    if (mode == 0) {
        void *tiles = g_02146A44[index].tiles;

        if (tiles != 0) {
            func_02040968(src, tiles, mode);
            func_0204241C(index, tiles, g_02146A44[index].unk_10 * 2,
                          g_02146A44[index].unk_0c);
        } else {
            u32   size = *(const u32 *)&((struct Obj16005 *)src)->f0 >> 8;
            void *buf = sub_02030734(
                (u16)((g_02146A44->heapId & 0x7fff) | 0x8000), size, 0,
                g_020A7E5C, 1252);

            func_02040968(src, buf, mode);
            func_0204241C(index, buf, offset * 2, size);
            func_020307B0(buf);
        }
    } else {
        func_0204241C(index, src, offset * 2, mode);
    }
}
