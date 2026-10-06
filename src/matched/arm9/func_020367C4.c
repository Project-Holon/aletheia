/*
 * function: func_020367C4
 * address:  0x020367C4
 * packet:   pkt_020367C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203675C  0x0203675C  arm
 *   func_020364D4  0x020364D4  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * Moves one queued send item into an output window: on first touch writes
 * the item's five-byte header (func_0203675C, refused with 0 when a header
 * is required and the window cannot hold rest + 5), then copies as much of
 * the payload as fits -- from the item's own source pointer with
 * MI_CpuCopy8, or out of the ring with func_020364D4 when it has none.  A
 * partial copy leaves the window marked full (0xFFFF) and the item's
 * header flag set; a complete one advances the window.  Exact on the first
 * compile from the image's field widths.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

typedef struct {
    u8  *src;       /* +0x00 */
    u32  pad4;
    u32  pad8;
    u16  rest;      /* +0x0C */
    u16  fE;
    u8   f10;
    u8   headerDone;/* +0x11 */
} NetSendItem;

typedef struct {
    u8  *ptr;       /* +0x00 */
    u16  len;       /* +0x04 */
} NetOutBuf;

extern int func_0203675C(int a0, int a1);
extern int func_020364D4(char *p, unsigned char *dst, int len, int max);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader)
{
    if (item->headerDone == 0) {
        if (needHeader != 0 && out->len < item->rest + 5) {
            return 0;
        }
        func_0203675C((int)item, (int)out);
    }
    if (out->len < item->rest) {
        if (item->src == 0) {
            func_020364D4(ring, out->ptr, out->len, out->len);
        } else {
            MI_CpuCopy8(item->src, out->ptr, out->len);
            item->src += out->len;
        }
        item->rest = item->rest - out->len;
        out->len = 0xffff;
        item->headerDone = 1;
        return 1;
    }
    if (item->src == 0) {
        func_020364D4(ring, out->ptr, item->rest, item->rest);
    } else {
        MI_CpuCopy8(item->src, out->ptr, item->rest);
    }
    out->ptr += item->rest;
    out->len = out->len - item->rest;
    return 1;
}
