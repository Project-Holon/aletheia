/*
 * function: func_021C13E8
 * address:  0x021C13E8
 * packet:   pkt_ov217_021C13E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD5 lane19): still DIFF 198 B. Tried: u32 i/n, const base pointer through the whole chain (callee prototypes const), const callee prototypes only: allocation unchanged (orig keeps i and n on the stack, e in r7).
 *
 * Note 2026-10-04 (wD2 lane12): decoded. Original is the same GX writes with every hoisted address kept on the stack by the allocator (copy then add spill pairs). p offsets 0x1b4/0x1b6/0x1ba/0x1bc are 0x1ac (spilled const) + 8/0xa/0xe/0x10: model p as struct Big { u8 pad[0x1AC]; struct Cam c; } with c = {u8 cnt; pad[7]; s16 x,y,z; Ent t[]} so each field gets its own hoisted offset (this draft, 252 bytes; original 244, frame 0x28). Keep (u32)r +- K arithmetic for the GX regs (r[0x17] index form folds the constant, wrong). Open: q = p + b*6 then ldrsh [q, 0x1ba]; hoisted-offset count and slot order.
 *
 * Note 2026-10-02: DIFF draft (GX FIFO writes: 0x040004A4 polygon attr, +0x5C BEGIN_VTXS,
 * -0x24 COLOR, -0x18 VTX_16, +0x60 END_VTXS). Structure decoded, compiles to 252 vs 244 bytes;
 * original spills six base+offset address constants to the stack. Needs an Opus pass.
 *
 * symbols:
 *   func_021C1D28  0x021C1D28  thumb  ov217
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *   func_021C1B28  0x021C1B28  thumb  ov217
 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD1 lane06): Not retried (GX FIFO address spills, needs a long pass).
 *
 * note 2026-10-05 (wD4 lane13): read p->c.x and p->c.y once into s16 locals px/py (original loads each once and reuses them for the vertex word): size now 244 bytes, equal to the original. Residue: allocator choice. Original spills i and n to the stack ([sp,#4], [sp]) and keeps the call result e in r7, p in r5, GX vertex address in r4, r>>12 in r6; ours keeps i in r7 and spills e. Five declaration orders of b/r/e/n/i give the same code.
 * 2026-10-05 (wD6 lane17): still DIFF 198 B. Callee definitions checked (021C1AB4(p, u32 n),
 *   021C1B28(u8 *, u8 *, u8 *), no hidden arguments). Tried the sibling 021C18F8 `struct Range { u8 max, min; }`
 *   for b: same. New finding: the pool order differs (the original references 0x040004A4 before 0x001F00C0
 *   and spills r to [sp,#8] at once), so in the original r is a memory-resident variable from the start;
 *   in ours the address constant stays in r0 for the derived values.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Ent { s16 x, y, z; };
struct Cam {
    u8 cnt;
    u8 pad1[7];
    s16 x, y, z;
    struct Ent t[4];
};
struct Big { u8 pad[0x1AC]; struct Cam c; };

extern int func_021C1D28(u8 *p);
extern u8 *func_021C1AB4(u8 *p, int i);
extern void func_021C1B28(u8 *e, u8 *a, u8 *b);

void func_021C13E8(struct Big *p)
{
    u8 b[2];
    volatile u32 *r;
    u8 *e;
    int n;
    int i;

    if (func_021C1D28((u8 *)p) == 0) {
        r = (volatile u32 *)0x040004A4;
        *r = 0x001F00C0;
        n = p->c.cnt;
        for (i = 0; i < n; i++) {
            e = func_021C1AB4((u8 *)p, i);
            func_021C1B28(e, &b[1], &b[0]);
            if (e[8] >= 3) {
                struct Big *q = (struct Big *)((u8 *)p + b[1] * 6);
                s16 px = p->c.x;
                s16 py = p->c.y;
                s16 x = px + q->c.t[0].x;
                s16 y = py + q->c.t[0].y;
                u32 va, vb;
                *(volatile u32 *)((u32)r + 0x5C) = 0;
                *(volatile u32 *)((u32)r - 0x24) = 0;
                va = ((u32)(u16)py << 16) | (u16)px;
                vb = ((u32)(u16)y << 16) | (u16)x;
                *(volatile u32 *)((u32)r - 0x18) = va;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r - 0x18) = va;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r - 0x18) = vb;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r + 0x60) = 0;
            }
        }
    }
}
