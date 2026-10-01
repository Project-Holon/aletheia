/*
 * function: func_021C0234
 * address: 0x021C0234
 * packet: pkt_ov210_021C0234
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_02049238 0x02049238 arm
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_02045EC0 0x02045EC0 arm
 *   d_021C0C20 0x021C0C20 data a4
 */
typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;
extern const Template d_021C0C20;
extern void *func_020490F4(void *, unsigned);
extern void *func_021B7754(void *, unsigned);
extern void func_021B7A10(void *, void *, unsigned, unsigned, unsigned);
extern void func_021B7A4C(void *, void *, unsigned, unsigned, unsigned);
extern void func_02049238(void *);
extern void func_021B79E4(void *, unsigned, unsigned);
extern void *func_02045EC0(void *, unsigned);
void func_021C0234(char *ctx)
{
    void *archive = func_020490F4((void *)159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C20;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    *(void **)(ctx + 0x1e0) = func_021B7754(&config, 123);
    *(unsigned *)(ctx + 0x2ac) = config.count;
    func_021B7A10(*(void **)(ctx + 0x1e0), archive, 97, 0, 0);
    func_021B7A4C(*(void **)(ctx + 0x1e0), archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i < 6; i++) { func_021B79E4(*(void **)(ctx + 0x1e0), 0, i); ((void **)(ctx + 0x1e4))[i] = func_02045EC0(*(void **)(ctx + 0x1d0), i + 25); }
}
