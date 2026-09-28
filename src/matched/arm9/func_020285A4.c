/*
 * function: func_020285A4
 * address:  0x020285A4
 * packet:   pkt_02028590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_020436FC      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char app_keycursor_File[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);
extern void *func_020436FC(void *pixels, u32 width, u32 height, u32 depth,
                           u16 heap);

struct KeyCursor {
    u32 *item;    /* 0x00 */
    u8   unk4;    /* 0x04 */
    u8   unk5;    /* 0x05 */
    u8   unk6;    /* 0x06 */
    u8   live : 1;   /* 0x07 bit 0 */
    u8   flip : 1;   /* 0x07 bit 1 */
    u16  id;      /* 0x08 */
};

struct KeyCursor *func_020285A4(u16 id, u32 live, u32 flip, u16 heap,
                                void *pixels)
{
    struct KeyCursor *k;

    k = func_02030734(heap, sizeof(struct KeyCursor), 1, app_keycursor_File,
                      149);

    k->id = id;
    k->live = live;
    k->flip = flip;
    k->item = func_020436FC(pixels, 2, 2, 0x20, heap);

    return k;
}
