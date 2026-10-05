/*
 * function: func_021BB954
 * address:  0x021BB954
 * packet:   pkt_ov099_021BB954
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): lane17 wave D2: 116 bytes, original keeps the data base in r2 across the join (ldr in each arm, one shared 0x70 store) with temps in r1 and t in r3. Best form: g assigned per arm (g = d_021C3A70 in both arms), g[0x18]/g[0x1A]/g[0x1C] stores; residue is g r1 vs r2 (full swap of r1/r2 temps). Tried global at each use (reloads g after the join), g before the if (hoisted load), a/b temps before g, char* vs u32* g, declaration order.
 *
 * note: 2026-10-05 (wD4 lane20): not changed; no new hypothesis beyond the 2026-10-04 note (g r1 vs r2 temp swap).
 * symbols:
 *   d_021C3A70  0x021C3A70  data  a4
 *   d_021C3B68  0x021C3B68  data  a4
 *   d_021C3AD0  0x021C3AD0  data  a4
 *   func_021BAC24  0x021BAC24  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct Pair { u32 a, b; };
extern char d_021C3A70[];
extern char d_021C3B68[];
extern struct Pair d_021C3AD0[];
extern void func_021BAC24(char *, struct Desc *, struct Pair *, int, int, u32);

void func_021BB954(char *p, int flag)
{
    u32 *g;
    u32 t;
    u32 a, b;
    if (flag) {
        char *q = *(char **)(p + 0x248);
        a = *(u8 *)(q + 0x21) + 0x83;
        g = (u32 *)d_021C3A70;
        g[0x18] = a;
        b = *(u8 *)(q + 0x22) + 0x87;
        g[0x1A] = b;
        t = *(u8 *)(q + 0x20);
    } else {
        a = *(u16 *)(p + 0x134C) + 0x83;
        g = (u32 *)d_021C3A70;
        g[0x18] = a;
        b = *(u16 *)(p + 0x134E) + 0x87;
        g[0x1A] = b;
        t = *(u8 *)(*(char **)(p + 0x248) + 0x48);
    }
    g[0x1C] = 0x8A - t;
    func_021BAC24(p, (struct Desc *)d_021C3B68, d_021C3AD0, 6, 0, 0x1E);
}
