/*
 * function: TIME_ICON_Alloc
 * address:  0x0202EF60
 * packet:   pkt_0202EC44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   g_020A7814     0x020A7814  data
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

struct Obj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 unk10;
    u8  pad[0xa];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Bmp;
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern const char g_020A7814[];

struct Obj *TIME_ICON_Alloc(u32 heap)
{
    struct Obj *obj = func_02030734(heap, 0x1c, 0, g_020A7814, 0xa6);

    obj->unk10 = (u16)heap;
    obj->unk0C = (u32)BMP_CreateFromArchive(0xc6, 0, 1, obj->unk10);
    obj->unk08 = 0;
    obj->unk00 = 0;
    obj->unk04 = 0;
    return obj;
}
