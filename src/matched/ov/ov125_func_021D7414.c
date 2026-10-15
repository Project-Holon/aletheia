/*
 * function: GDS_RAP_GetSearchResults
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
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_STANDARD_SetupCalc 0x0203F1FC arm
 *   sGdsEmptyString2 0x021D8D2C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u32 w[49]; } Rec;
extern char *GDS_SOCKET_GetReply(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *, int, u32);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern char sGdsEmptyString2[];

int GDS_RAP_GetSearchResults(char *unused, char *dst, int n)
{
    int *g = (int *)GDS_SOCKET_GetReply();
    int *hdr = g + 1;
    char *base;
    int cnt;
    int i;

    cnt = hdr[0];
    if (cnt > n) {
        cnt = n;
        func_02034714(sGdsEmptyString2, 0, sGdsEmptyString2);
    }
    MI_CpuFill8(dst, 0, n * 0xC4);
    i = 0;
    base = (char *)hdr + 4;
    for (i = 0; i < cnt; i++) {
        char *e = base + i * 0xD0;
        u64 id = *(u64 *)(e + 4);
        if (*(u64 *)(e + 0xC4) != id) {
            *(u64 *)(e + 0xC4) = id;
            *(u16 *)(e + 0xCC) = GF_STANDARD_SetupCalc((const u8 *)(e + 0x8C), 0x38);
        }
        *(Rec *)(dst + i * 0xC4) = *(Rec *)(e + 0xC);
    }
    return cnt;
}
