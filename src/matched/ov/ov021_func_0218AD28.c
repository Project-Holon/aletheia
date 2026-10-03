/*
 * function: func_0218AD28
 * address:  0x0218AD28
 * packet:   pkt_ov021_0218AD28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up the tile attribute under the position and starts the matching tile
 * task (func_021C8A30 or func_021C8C88); returns the task or 0.
 *
 * symbols:
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021C8A74  0x021C8A74  thumb
 *   func_021C8A30  0x021C8A30  thumb
 *   func_021C8CF0  0x021C8CF0  thumb
 *   func_021C8C88  0x021C8C88  thumb
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

extern void func_021A3038(void *p, int *out);
extern void *func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021C8A74(u32 a);
extern void *func_021C8A30(u32 prio, void *sys, u8 *owner);
extern int func_021C8CF0(u32 a);
extern void *func_021C8C88(u32 prio, void *sys, u8 *owner);

void *func_0218AD28(struct FieldCtx *p, u8 *pos)
{
    int buf[3];
    u16 attr;

    func_021A3038(p->f18, buf);
    attr = func_021AB0F0(func_021AB0D4(func_02188C98(pos), buf));
    if (func_021C8A74(attr))
        return func_021C8A30(0, p->f4, pos);
    if (func_021C8CF0(attr))
        return func_021C8C88(0, p->f4, pos);
    return 0;
}
