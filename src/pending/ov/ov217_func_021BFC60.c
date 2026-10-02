/*
 * function: func_021BFC60
 * address:  0x021BFC60
 * packet:   pkt_ov217_021BFC60
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021BF740 0x021BF740 thumb ov217
 *   func_021BF8B0 0x021BF8B0 thumb ov217
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200E4B0 0x0200E4B0 thumb
 *   func_0200E4F8 0x0200E4F8 thumb
 *   d_021C367C 0x021C367C data a1
 *   d_021C3D44 0x021C3D44 data a1
 *   d_021C386C 0x021C386C data a1
 *   d_021C3900 0x021C3900 data a1
 *   d_021C3994 0x021C3994 data a1
 *
 * blocker (2026-10-02, lane04 wC1): 203 bytes differ, relocations all resolve.
 * Locals now laid out like the original (sh, A, B, va, vb, buf declaration
 * order gives the right stack slots). Left: the original keeps the first
 * loop counter in memory (sp+0x20) and addresses buf+3 as reg+reg, has one
 * more spill word (frame sub sp 0x4c vs 0x48), first byte in sp+0x1c, and
 * spills buf[4] to sp+8. Opus lane to finish.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 d_021C367C[];
extern u8 d_021C3D44[][17];
extern u8 d_021C386C[];
extern u8 d_021C3900[];
extern u8 d_021C3994[];
extern void func_021BF740(void *p);
extern u8 func_021BF8B0(void *p);
extern void func_02012EBC(void);
extern void *func_0200E394(void);
extern u8 func_0200E44C(void *h, u32 i);
extern u16 func_0200E458(void *h, u32 i);
extern u32 func_0200E47C(void *h, u32 i);
extern u32 func_0200E4B0(void *h, u32 g, u32 j);
extern u32 func_0200E4F8(void *h, u32 g, u32 j);
void func_021BFC60(char *p)
{
    u16 sh[3][17];
    u32 A[3][17];
    u32 B[3][17];
    u32 va[3];
    u32 vb[3];
    u8 buf[6];
    void *h;
    u8 first;
    u8 c0, c1, c2;
    int i, j, k;
    func_021BF740(p);
    func_02012EBC();
    h = func_0200E394();
    first = func_021BF8B0(p);
    i = 0;
    buf[3] = func_0200E44C(h, 0);
    buf[4] = func_0200E44C(h, 1);
    buf[5] = func_0200E44C(h, 2);
    c0 = buf[3];
    buf[0] = d_021C367C[c0];
    c1 = buf[4];
    buf[1] = d_021C367C[c1];
    c2 = buf[5];
    buf[2] = d_021C367C[c2];
    va[0] = func_0200E458(h, c0);
    va[1] = func_0200E458(h, c1);
    va[2] = func_0200E458(h, c2);
    vb[0] = func_0200E47C(h, c0);
    vb[1] = func_0200E47C(h, c1);
    vb[2] = func_0200E47C(h, c2);
    for (i = 0; i < 3; i++) {
        u8 g = buf[3 + i];
        int n = buf[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = func_0200E4B0(h, g, j + 1);
            B[i][j] = func_0200E4F8(h, g, j + 1);
        }
    }
    *(u8 *)(p + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = p + k * 0xd4;
        u32 a = va[k];
        *(u8 *)(q + 0x3c) = buf[3 + k];
        *(u8 *)(q + 0x3d) = buf[k];
        *(u16 *)(q + 0x3e) = a;
        *(u32 *)(q + 0x40) = a + vb[k];
        if (*(u32 *)(q + 0x40) > 999999) {
            *(u32 *)(q + 0x40) = 999999;
        }
        for (j = 0; j < 17; j++) {
            char *r = q + j * 12;
            u16 s = sh[k][j];
            u32 x;
            *(u16 *)(r + 0x44) = s;
            *(u8 *)(r + 0x46) = d_021C386C[s];
            *(u8 *)(r + 0x47) = d_021C3900[s];
            *(u8 *)(r + 0x48) = d_021C3994[s];
            x = A[k][j];
            *(u16 *)(r + 0x4a) = x;
            *(u32 *)(r + 0x4c) = x + B[k][j];
        }
    }
}
