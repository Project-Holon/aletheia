/*
 * function: func_02184398
 * address:  0x02184398
 * packet:   pkt_ov168_02184398
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD8 lane06): closed with plain literals (no size local). mwcc keeps one constant of the
 *   block in a callee-saved register and derives the others from it: with the 0x100 store written right
 *   after the aligned-pointer store, 0x120 wins r6 and 0x100 becomes `subs r6,#0x20`. With the 0x100 store
 *   last, 1 wins and 0x100 becomes `adds r0,#0xff` (108 bytes). Earlier lanes needed an enum local here.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02006CBC 0x02006CBC thumb
 *   func_02034F84 0x02034F84 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02006D94 0x02006D94 thumb
 *   d_02184A20 0x02184A20 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_02184A20[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02006CBC(u16 heap);
extern void func_02034F84(u32 v);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_02006D94(void);
void func_02184398(u8 *p, int heap, u32 b, u32 c)
{
    u8 *buf;
    func_02006CBC(heap);
    func_02034F84(8);
    buf = func_02030734((u16)heap, 0x120, 0, d_02184A20, 0x603);
    func_02082BCC(buf, 0, 0x120);
    *(u8 **)(p + 0x1c) = buf;
    *(u32 *)p = 0;
    *(u32 *)(p + 4) = ((u32)buf + 0x1f) & ~0x1f;
    *(u32 *)(p + 8) = 0x100;
    *(u32 *)(p + 0xc) = 0x1001;
    *(u32 *)(p + 0x10) = 1;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x18) = c;
    *(u32 *)(p + 0x34) = func_02006D94();
}
