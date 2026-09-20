/*
 * function: func_0204A39C
 * address:  0x0204A39C
 * packet:   pkt_0204A39C
 * status:   EXACT
 * symbols:
 *   func_020493D4    0x020493D4 arm
 *   func_02030734    0x02030734 arm
 *   func_0204932C    0x0204932C arm
 *   MI_UncompressLZ8 0x020834C0 arm
 *   func_020307B0    0x020307B0 arm
 *   lbl_020A7F30     0x020A7F30 data
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_020493D4(void *narc, int fileId);
extern void *func_02030734(u32 heapId, u32 size, u32 align, const char *file, u32 line);
extern void func_0204932C(void *narc, int fileId, void *dest);
extern void MI_UncompressLZ8(const void *src, void *dest);
extern void func_020307B0(void *ptr);
extern const char lbl_020A7F30[];

void *func_0204A39C(void *narc, int fileId, int decompress, u16 heapId, u32 *out_size)
{
    void *buf;
    u32 size = func_020493D4(narc, fileId);

    *out_size = size;

    buf = func_02030734(
        (decompress != 0) ? ((heapId & 0x7FFF) | 0x8000) : heapId,
        size,
        0,
        lbl_020A7F30,
        (decompress != 0) ? 1713 : 1709
    );

    if (buf == 0) {
        return 0;
    }

    func_0204932C(narc, fileId, buf);

    if (decompress != 0) {
        u32 uncompressed_size = *(u32 *)buf >> 8;
        void *decomp_buf;

        *out_size = uncompressed_size;
        decomp_buf = func_02030734((u16)heapId, uncompressed_size, 0, lbl_020A7F30, 1725);
        if (decomp_buf != 0) {
            MI_UncompressLZ8(buf, decomp_buf);
            func_020307B0(buf);
            buf = decomp_buf;
        }
    }

    return buf;
}
