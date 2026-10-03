/*
 * function: func_0220157C
 * address:  0x0220157C
 * packet:   pkt_0220157C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_022022B8  0x022022B8  thumb  ov135
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_0200ADE0  0x0200ADE0  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x22
 * (with the two 0x0200ADxx queries and a 0x022022B8 call, or 0x1c when the
 * s8 flag at +0x207 is set), then the 0x2b pair (index 12 with the +0x38
 * archive, index 11 without), 0x2d, the +0x38/0x2b group and the plain
 * redraw; indexes 4..10 and 14 are table holes.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_022022B8(u8 *p, u32 a, u32 b, s32 c);
extern u32 func_0200ADB4(u32 a);
extern u32 func_0200ADE0(u32 a);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);

int func_0220157C(u8 *p)
{
    s32 n;
    s32 v;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        *(u32 *)(p + 0xf8c) = 0;
        switch (n + 15) {
        case 15:
            v = *(s8 *)(p + 0x207);
            if (v != 0) {
                *(u32 *)(p + 0x28) = 0x1c;
            } else {
                func_022022B8(p, func_0200ADB4(*(u32 *)(*(u32 *)p)),
                              func_0200ADE0(*(u32 *)(*(u32 *)p)), v);
                *(u32 *)(p + 0x28) = 0x22;
            }
            break;
        case 12:
            *(u32 *)(p + 0x28) = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 11:
            *(u32 *)(p + 0x28) = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 3:
            *(u32 *)(p + 0x38) = n;
            *(u32 *)(p + 0x28) = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            *(u32 *)(p + 0x38) = n;
            *(u32 *)(p + 0x28) = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++*(u32 *)(p + 0xf8c) == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}
