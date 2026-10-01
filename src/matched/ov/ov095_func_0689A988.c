/*
 * function: func_0689A988
 * address: 0x0689A988
 * packet: pkt_ov095_0689A988
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689AA78 0x0689AA78 thumb ov095
 *   func_0689AA88 0x0689AA88 thumb ov095
 *   func_0689AA98 0x0689AA98 thumb ov095
 *   func_0689AAA8 0x0689AAA8 thumb ov095
 *   func_0689AAB8 0x0689AAB8 thumb ov095
 *   func_0689AAC8 0x0689AAC8 thumb ov095
 *   func_0689AAD8 0x0689AAD8 thumb ov095
 *   func_0689AAE8 0x0689AAE8 thumb ov095
 *   func_0689AAF8 0x0689AAF8 thumb ov095
 *   func_0689AB08 0x0689AB08 thumb ov095
 *   func_0689AB18 0x0689AB18 thumb ov095
 *   func_0689AB28 0x0689AB28 thumb ov095
 *   func_0689AB38 0x0689AB38 thumb ov095
 *   d_0689D880 0x0689D880 data a4
 *   d_0689D91C 0x0689D91C data a4
 *   d_0689E128 0x0689E128 data a4
 *   d_0689E054 0x0689E054 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_0689D880[], d_0689D91C[], d_0689E128[], d_0689E054[];
extern u8 func_0689AA78(void *);
extern int func_0689AA88(void *, void *, u32);
extern u8 func_0689AA98(void *, u32);
extern u32 func_0689AAA8(void *);
extern u32 func_0689AAB8(void *);
extern int func_0689AAC8(char *, const char *, int);
extern void func_0689AAD8(void *);
extern u8 func_0689AAE8(void *);
extern u16 func_0689AAF8(void *, u8);
extern void func_0689AB08(void *, u32, u32);
extern void func_0689AB18(void *);
extern u32 func_0689AB28(void *);
extern void func_0689AB38(void *);
int func_0689A988(int unused, u8 *s)
{
    int r;
    const char *q, *n;
    int flag;
    r = func_0689AA98(*(void **)(s + 0xa0), func_0689AA88(*(void **)(s + 0xa0), *(void **)(s + 0xa4), func_0689AA78(*(void **)(s + 0x6c))));
    if (func_0689AAA8(*(void **)(s + 0xa0)) == 2 && r != 4) q = d_0689D880;
    else q = d_0689D91C;
    if (func_0689AAB8(*(void **)(s + 0xa0)) == 2 && r != 4) n = d_0689E128;
    else n = d_0689E054;
    r = func_0689AAC8(*(char **)(s + 0xb0), q, (int)n);
    if (r != -1) {
        if (r & 0x8000) flag = 1;
        else flag = 0;
        r &= ~0x8000;
        if (r == 4) {
            func_0689AAD8(*(void **)(s + 0x70));
            return 1;
        }
        if (r < func_0689AAE8(*(void **)(s + 0x6c))) {
            func_0689AB08(*(void **)(s + 0x70), func_0689AAF8(*(void **)(s + 0x6c), r), 6);
            if (flag) func_0689AB18(*(void **)(s + 0x70));
            return 1;
        }
        if (func_0689AB28(*(void **)(s + 0xa0)) == 2 && r == 5) {
            func_0689AB38(*(void **)(s + 0x70));
            return 1;
        }
    }
    return 0;
}
