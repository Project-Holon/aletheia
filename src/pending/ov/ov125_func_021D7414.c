/*
 * function: func_021D7414
 * address: 0x021D7414
 * packet: pkt_ov125_021D7414
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * 2026-10-04 (wave D2 lane 14): DIFF, 16 bytes. Everything matches except the scheduling of the
 * equality test in the loop: the original loads e[0xC4], e[4], e[8], e[0xC8] into r2,r1,r3,r0, then
 * eors, eors, orrs, beq (no short circuit) and stores r1 and r3. This build gives the same
 * instructions with a different register and load order. Tried: one-expression compare, separate
 * x,a,b,y temps in several orders, u32 array view, 64-bit compare (worse), local hdr pointer
 * declared before base (fixes the sp slots).
 *
 * symbols:
 *   func_021D85E8 0x021D85E8 arm ov125
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F1FC 0x0203F1FC arm
 *   d_021D8D2C 0x021D8D2C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[49]; } Rec;
extern int *func_021D85E8(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, int, u32);
extern int func_0203F1FC(void *, int);
extern char d_021D8D2C[];

int func_021D7414(int unused, char *dst, int n)
{
    int *g = func_021D85E8();
    int *hdr = g + 1;
    char *base;
    int cnt;
    int i;

    cnt = hdr[0];
    if (cnt > n) {
        cnt = n;
        func_02034714(d_021D8D2C, 0, d_021D8D2C);
    }
    func_02082BCC(dst, 0, n * 0xC4);
    i = 0;
    base = (char *)hdr + 4;
    for (i = 0; i < cnt; i++) {
        char *e = base + i * 0xD0;
        u32 a = *(u32 *)(e + 4);
        u32 b = *(u32 *)(e + 8);
        u32 d = (*(u32 *)(e + 0xC4) ^ a) | (*(u32 *)(e + 0xC8) ^ b);
        if (d != 0) {
            *(u32 *)(e + 0xC4) = a;
            *(u32 *)(e + 0xC8) = b;
            *(u16 *)(e + 0xCC) = func_0203F1FC(e + 0x8C, 0x38);
        }
        *(Rec *)(dst + i * 0xC4) = *(Rec *)(e + 0xC);
    }
    return cnt;
}
