/*
 * function: func_021D74D8
 * address:  0x021D74D8
 * packet:   pkt_ov125_021D74D8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
 * symbols:
 *   func_021D85E8  0x021D85E8  arm  ov125
 *   func_0203F1FC  0x0203F1FC  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;


extern int *func_021D85E8(void);
typedef unsigned int   u32;
extern int func_0203F1FC(const u8 *src, u32 len);

typedef unsigned long long u64;
int func_021D74D8(void *unused, char **out)
{
    char *p = (char *)func_021D85E8();
    char *s = p + 4;
    u64 id;

    *out = s + 0xC;
    id = *(u64 *)(p + 8);
    if (*(u64 *)(s + 0xC4) != id) {
        *(u64 *)(s + 0xC4) = id;
        *(u16 *)(*out + 0xC0) = func_0203F1FC((u8 *)(*out + 0x80), 0x38);
    }
    return *(int *)(p + 8);
}
