/*
 * function: sub_0201C6FC
 * address:  0x0201C6FC
 * packet:   pkt_0201C6FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0214655C    0x0214655C  data
 *   sub_0201C808  0x0201C808  thumb
 *   sub_0201C758  0x0201C758  thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed short       s16;
typedef unsigned long long u64;

struct PrintCtx {
    s16 unk00;
    s16 unk02;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

struct PrintSys;

extern struct PrintCtx g_0214655C;

extern void sub_0201C808(struct PrintCtx *c, u32 a, u32 b, u32 d, u32 e);
extern void sub_0201C758(struct PrintSys *p, struct PrintCtx *c, void *s);

void sub_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e)
{
    sub_0201C808(&g_0214655C, e, a, b, c);
    sub_0201C758(p, &g_0214655C, s);
}
