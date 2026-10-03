/*
 * function: func_021AA548
 * address:  0x021AA548
 * packet:   pkt_ov021_021AA548
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   data_021DDFA4  0x021DDFA4  data
 *   func_02013144  0x02013144  thumb
 *   func_0201347C  0x0201347C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021A9780  0x021A9780  thumb
 *   func_021AA304  0x021AA304  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx { void *f00; u8 pad04[4]; void *f08; };
struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x1C];
    u32 b0 : 5;
    u32 b5 : 1;
};
struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

extern void *func_0201A920(u32 heap);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_0201A98C(void *party, void *mon);
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void func_0201347C(void *a0, void *a1, void *a2, struct Info *a3, u32 a4, u16 a5);
extern void func_02013144(void *p, int v);
extern void func_020307B0(void *p);
extern const char data_021DDFA4[];
extern void func_021A9780(void *mon, void *u, void *src);

void func_021AA548(struct Ctx *ctx, void *a1, void *a2, u16 heap, void *src)
{
    struct Info info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734((u16)((heap & 0x7FFF) | 0x8000), func_020173EC(), 1, data_021DDFA4, 0x2A4);

    func_021A9780(mon, a1, src);
    func_0201A98C(party, mon);
    func_021AA304(&info, ctx->f08, ctx->f00);
    func_0201347C(a2, ctx->f08, party, &info, 0, heap);
    func_02013144(a2, 8);
    func_020307B0(mon);
    func_020307B0(party);
}
