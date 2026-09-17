/*
 * function: func_0202B3A0
 * address:  0x0202B3A0
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Allocates a 0x38-byte node, fills its header fields, resolves the +0x14
 * sub-object through func_0202B2FC and runs func_0202B454 over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B3A0.c \
 *       --func func_0202B3A0 --addr 0x0202B3A0 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Node;

extern void *func_02030734(u32 heapId, u32 size, u32 zero,
                           const void *file, u32 line);
extern u32   func_0202B2FC(u32 heapId);
extern void  func_0202B454(struct Node *p);

struct Node *func_0202B3A0(u32 a, u32 b, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x38, 0,
                                                  (const void *)0x020A7718, 0x109);

    *(u16 *)((u8 *)p) = (u16)heapId;
    *(u32 *)((u8 *)p + 0x8) = a;
    *(u32 *)((u8 *)p + 0x4) = b;
    *(u32 *)((u8 *)p + 0xc) = 0;
    *(u16 *)((u8 *)p + 0x10) = 0xffff;
    *(u16 *)((u8 *)p + 0x12) = 0xffff;
    *(u32 *)((u8 *)p + 0x14) = func_0202B2FC(heapId);
    *(u32 *)((u8 *)p + 0x18) = 0;
    func_0202B454(p);
    return p;
}
