/*
 * function: func_0201F93C
 * address:  0x0201F93C
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734   0x02030734  arm
 *   sBmpMenuFile    0x020A7384  data
 *   func_02020D18   0x02020D18  thumb
 *   func_02020DC8   0x02020DC8  thumb
 *   func_0201FC1C   0x0201FC1C  thumb
 *   func_0201FC5C   0x0201FC5C  thumb
 *   func_0201FD18   0x0201FD18  thumb
 *
 * bmp_menu.c constructor (line 0x61, __FILE__ 0x020A7384 "bmp_menu.c"):
 * allocate the 0x38-byte menu, copy the 0x24-byte header in, create the
 * cursor, record cancel mask, start position, widest item (func_0201FC1C),
 * heap id and the pixel origin, then draw (func_0201FC5C) and place the
 * cursor (func_0201FD18).
 *
 * The residue in docs/notes/func_0201F93C.c.txt (the stack-passed u16 heap
 * cached once in a callee-saved register instead of reloaded, 92 bytes out)
 * depended on the conversion at the allocation call: the allocator's heap
 * parameter is `u32`, and the explicit `(u32)(int)heap` keeps that site's
 * signed conversion distinct from the other uses. Without it, the u16 value
 * is zero-extended once and CSE'd into all four uses. With the conversion,
 * the first `ldrh` feeds r0 directly, the header pointer's register is
 * reused for the second load, and the frame shrinks to the original's
 * push {r3-r7,lr} / sub sp,#8.  Found by tools/permuter.py hill (a
 * `(int)heap` cast at that one site), then retained explicitly at the call
 * while preserving the allocator's unsigned-word parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F93C.c \
 *       --func func_0201F93C --addr 0x0201F93C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 unk00[3];
    u16 unk0c;
    u16 unk0e;
    u32 unk10[5];
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24 */
    u32 cancel;         /* +0x28 */
    u8  pad2c;
    u8  pos;            /* +0x2D */
    u8  width;          /* +0x2E */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xmax;           /* +0x31 */
    u8  ymax;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

extern char sBmpMenuFile[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02020D18(u32 heap);
extern void  func_02020DC8(void *cursor, u32 heap);
extern u8    func_0201FC1C(BmpMenu *m);
extern void  func_0201FC5C(BmpMenu *m);
extern void  func_0201FD18(BmpMenu *m);

BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel)
{
    BmpMenu *m = func_02030734((u32)(int)heap, sizeof(BmpMenu), 1, sBmpMenuFile, 0x61);

    m->hdr = *hdr;
    m->cursor = func_02020D18(heap);
    m->cancel = cancel;
    m->pos = pos;
    m->width = func_0201FC1C(m);
    m->heap = heap;
    m->px = px;
    m->py = py;
    func_02020DC8(m->cursor, heap);
    m->xmax = m->hdr.unk0c;
    m->ymax = m->hdr.unk0e;
    func_0201FC5C(m);
    func_0201FD18(m);
    return m;
}
