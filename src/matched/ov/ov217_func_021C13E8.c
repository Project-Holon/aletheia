/*
 * function: CircleGraph_DrawOutline
 * address:  0x021C13E8
 * packet:   pkt_ov217_021C13E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * GX FIFO line draw: for each entry with state >= 3, a degenerate triangle from the
 * centre (c.x, c.y) to the centre plus vertex t[min]. Closed 2026-10-05 (wD9r lane52):
 * the vertex is indexed as a struct array p->c.t[b[1]] (not a p + k*6 base pointer),
 * the vertex words are packed x first ((u16)x | (u16)y << 16, the GX_FX16PAIR order),
 * and i is declared before n (spill slots n@0, i@4).
 *
 * symbols:
 *   CircleGraph_IsAnimatingImpl  0x021C1D28  thumb  ov217
 *   CircleGraph_GetSlice  0x021C1AB4  thumb  ov217
 *   CircleGraph_GetPointRange  0x021C1B28  thumb  ov217
 *
 * Addresses are Black-image addresses.
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

extern int CircleGraph_IsAnimatingImpl(u8 *p);
extern void *CircleGraph_GetSlice(void *p, u32 n);
extern void CircleGraph_GetPointRange(u8 *e, u8 *a, u8 *b);

void CircleGraph_DrawOutline(struct Big *p)
{
    u8 b[2];
    u8 *e;
    int i;
    int n;

    if (CircleGraph_IsAnimatingImpl((u8 *)p) == 0) {
        *(volatile u32 *)0x040004A4 = 0x001F00C0;
        n = p->c.cnt;
        for (i = 0; i < n; i++) {
            e = CircleGraph_GetSlice((u8 *)p, i);
            CircleGraph_GetPointRange(e, &b[1], &b[0]);
            if (e[8] >= 3) {
                s16 px, py, x, y;
                u32 va, vb;
                px = p->c.x;
                py = p->c.y;
                x = px + p->c.t[b[1]].x;
                y = py + p->c.t[b[1]].y;
                *(volatile u32 *)0x04000500 = 0;
                *(volatile u32 *)0x04000480 = 0;
                va = (u16)px | ((u32)(u16)py << 16);
                vb = (u16)x | ((u32)(u16)y << 16);
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = vb;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x04000504 = 0;
            }
        }
    }
}
