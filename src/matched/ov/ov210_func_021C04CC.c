/*
 * function: func_021C04CC
 * address: 0x021C04CC
 * packet: pkt_ov210_021C04CC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Template is 40 bytes with ctx at 36; a 44-byte decode adds a stack word and moves its store.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_02049238 0x02049238 arm
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   d_021C0CC0 0x021C0CC0 data a4
 */
typedef unsigned short u16;
typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;
extern const Template d_021C0CC0;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_021B7754(void *, unsigned);
extern void func_021B7A10(void *, void *, unsigned, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_02049238(void *);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
void func_021C04CC(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    *(void **)(ctx + 0x1e0) = func_021B7754(&config, 123);
    *(unsigned *)(ctx + 0x2ac) = config.count;
    func_021B7A10(*(void **)(ctx + 0x1e0), archive, 98, 0, 0);
    func_021B7A4C(*(void **)(ctx + 0x1e0), archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i < 14; i++) func_021B79E4(*(void **)(ctx + 0x1e0), 0, i);
}
