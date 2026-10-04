/*
 * function: func_02184398
 * address: 0x02184398
 * packet: pkt_ov168_02184398
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02006CBC 0x02006CBC thumb
 *   func_02034F84 0x02034F84 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02006D94 0x02006D94 thumb
 *   d_02184A20 0x02184A20 data a1
 *
 * 2026-10-04 note (wave D1 lane 05): DIFF. Residue: original keeps raw heap in r4 (u16 cast at each use,
 * done via u16 callee prototypes), size 0x120 in r6 (movs 0x12; lsls 4; later subs #0x20 in place),
 * 4th arg spilled to [sp,#4], p in r5, b in r7. Compiler here constant-folds size (adds #0xff) and
 * allocates p=r4/heap=r5/b=r6/c=r7 with no spill. Tried: size local, size -= 0x20, (u16) casts vs
 * u16 prototypes, u16 param. Not tried: forcing size into a register via a non-constant source.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_02184A20[];
extern void *func_02030734(u16 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02006CBC(u16 heap);
extern void func_02034F84(u32 v);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_02006D94(void);
void func_02184398(u8 *p, u32 heap, u32 b, u32 c)
{
    u8 *buf;
    u32 size = 0x120;
    func_02006CBC(heap);
    func_02034F84(8);
    buf = func_02030734(heap, size, 0, d_02184A20, 0x603);
    func_02082BCC(buf, 0, size);
    *(u8 **)(p + 0x1c) = buf;
    *(u32 *)p = 0;
    *(u32 *)(p + 4) = ((u32)buf + 0x1f) & ~0x1f;
    *(u32 *)(p + 0xc) = 0x1001;
    *(u32 *)(p + 0x10) = 1;
    size -= 0x20;
    *(u32 *)(p + 8) = size;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x18) = c;
    *(u32 *)(p + 0x34) = func_02006D94();
}
