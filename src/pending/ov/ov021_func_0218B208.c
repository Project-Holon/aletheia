/*
 * function: func_0218B208
 * address:  0x0218B208
 * packet:   pkt_ov021_0218B208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * When bit 3 of the flag word is set, runs the object's interaction:
 * func_021AA248 with the map value when func_02013DD0 accepts field 0x10,
 * else func_021A9F40(obj, 0).
 *
 * Blocker: the call to 0x02013DD0 is the one wildcard. In arm9 that address
 * is an unlabelled Thumb veneer (ldr r1, [pc, #4]; ldr r3, [pc, #8]; movs r2,
 * #4; bx r3) with no witness; it closes once arm9 0x02013DD0 is labelled.
 *
 * symbols:
 *   func_02188CE8  0x02188CE8  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_0218DC70  0x0218DC70  thumb
 *   func_021AA248  0x021AA248  thumb
 *   func_021A9F40  0x021A9F40  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

extern void *func_02188CE8(u8 *p);
extern int func_02013DD0(u16 v);
extern void *func_02188C98(u8 *p);
extern u32 func_0218DC70(void *p);
extern int func_021AA248(void *obj, u32 v);
extern int func_021A9F40(void *obj, u32 v);

int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos)
{
    void *obj = func_02188CE8(pos);

    if (!p->b3)
        return 0;
    if (func_02013DD0(p->f10))
        return func_021AA248(obj, func_0218DC70(func_02188C98(pos)));
    return func_021A9F40(obj, 0);
}
