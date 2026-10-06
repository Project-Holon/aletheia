/*
 * function: func_021D7414
 * address: 0x021D7414
 * packet: pkt_ov125_021D7414
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
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
typedef unsigned long long u64;
typedef struct { u32 w[49]; } Rec;
extern char *func_021D85E8(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, int, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern char d_021D8D2C[];

int func_021D7414(char *unused, char *dst, int n)
{
    int *g = (int *)func_021D85E8();
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
        u64 id = *(u64 *)(e + 4);
        if (*(u64 *)(e + 0xC4) != id) {
            *(u64 *)(e + 0xC4) = id;
            *(u16 *)(e + 0xCC) = func_0203F1FC((const u8 *)(e + 0x8C), 0x38);
        }
        *(Rec *)(dst + i * 0xC4) = *(Rec *)(e + 0xC);
    }
    return cnt;
}
