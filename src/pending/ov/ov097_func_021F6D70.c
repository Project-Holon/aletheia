/*
 * function: func_021F6D70
 * address:  0x021F6D70
 * packet:   pkt_ov097_021F6D70
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wD3 lane 15): DIFF, 376 bytes (right size), 25 diff bytes, all in the third draw call (block 3). The
 * original loads p+0x10 and sets r3=0x20 first and computes r7+w8 (reload of w8 from [sp,#0x24], add, lsls/asrs) last;
 * this draft computes it first. Blocks 1 and 2 are exact, slots exact (f1,f2,x,f3,h declared at top in that order).
 * Tried: (s16)(r7+w8) inline, local x before or after the y call, w8+r7, callee param s16/u32/int.
 * Siblings with the same text-draw shape: ov198 func_0220D494, ov223 func_021BB18C.
 * 2026-10-05 (wD4 lane 08): DIFF, 376 bytes, 13 diff lines, all in the third draw call argument setup. Fixed the
 *   operand order: (s16)(r7 + w8) now gives adds r2,r7,r2 as in the original. Residue is scheduling only: the original
 *   emits the r2 computation (ldr r2,[sp,#0x24]; adds; lsls/asrs) after the stack stores and r3=0x20, the draft emits it
 *   first. Tried: plain r7 + w8 with no cast (same), reuse of the block-2 local x assigned before or after the y call
 *   (same), w8 as u8 (worse) or int (same), r7 as int with (u8) at the assignment (worse).
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern u32   func_02045770(u32 h);
extern void  func_02045808(void *a);
extern u32   func_0201D304(void *s, u32 a, u32 b);
extern void  func_0201C724(u32 a, u32 b, s16 c, u32 d, void *e, u32 f, u16 g);
extern u32   func_02017E1C(u32 mon, u32 id, u32 v);
extern void  func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_0201F250(u32 a, void *b, void *c);

void func_021F6D70(char *p, int idx)
{
    void *buf;
    void *t1;
    void *t2;
    void *t3;
    u32 w8;
    u8 r7;
    u32 f1;
    u32 f2;
    s16 x;
    u32 f3;
    u32 h;

    buf = func_020457B0(0x20, 0x8071);
    t1 = func_02045EC0(*(void **)(p + 0x14), 0xc);
    w8 = (u8)func_0201D304(t1, *(u32 *)(p + 0x10), 0);
    r7 = 0x5c - (w8 >> 1);
    {
        u32 y;
        f1 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f1, y, (s16)r7, 0x20, t1, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t1);

    t2 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4(*(u32 *)(p + 0x18), 0, func_02017E1C(*(u32 *)(p + 0xf8 + idx * 4), 0xa0, 0), 3, 0, 1);
    func_0201F250(*(u32 *)(p + 0x18), buf, t2);
    {
        u32 y;
        h = *(u32 *)(p + 0x10);
        x = r7 - func_0201D304(buf, h, 0);
        f2 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f2, y, x, 0x20, buf, h, 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t2);

    t3 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4(*(u32 *)(p + 0x18), 0, func_02017E1C(*(u32 *)(p + 0xf8 + idx * 4), 0xa1, 0), 3, 0, 1);
    func_0201F250(*(u32 *)(p + 0x18), buf, t3);
    {
        u32 y;
        f3 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f3, y, (s16)(r7 + w8), 0x20, buf, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t3);
    func_02045808(buf);
}
