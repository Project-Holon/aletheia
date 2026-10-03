/*
 * function: func_021A16EC
 * address:  0x021A16EC
 * packet:   pkt_ov021_021A16EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_02049250  0x02049250  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_02047180  0x02047180  arm
 *   d_021DDE5C  0x021DDE5C  data  ov021
 * Addresses are Black-image addresses.
 * `const u8 *s` is what schedules the second (u16)n truncation ahead of the
 * store of the allocation to d+8.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct S02046CE0;
extern int func_02046C94(void);
extern void *func_02049250(void *h, u32 id, u16 heap);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern int func_02047180(u32 *p);
extern const char d_021DDE5C[];

void func_021A16EC(u8 *d, void *a, const u8 *s, u32 n)
{
    void *r;

    d[0] = s[2];
    d[1] = s[3];
    d[2] = s[4];
    d[3] = s[5];
    d[4] = s[6];
    d[5] = s[7];
    *(void **)(d + 8) = func_02030734((u16)n, func_02046C94(), 1, d_021DDE5C, 0x2ad);
    r = func_02049250(a, *(const u16 *)s, n);
    func_02046CE0(*(void **)(d + 8), r);
    func_02047180(*(void **)(d + 8));
    d[6] = 1;
    d[7] = 1;
}
