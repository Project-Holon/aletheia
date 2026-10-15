/*
 * function: func_021C43E8
 * address:  0x021C43E8
 * packet:   pkt_ov111_021C43E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   d_021C85C8     0x021C85C8  data  a4
 *   d_021C85E8     0x021C85E8  data  a4
 *   d_021C8608     0x021C8608  data  a4
 *   d_021C8628     0x021C8628  data  a4
 *   d_021C8648     0x021C8648  data  a4
 *   d_021C8668     0x021C8668  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct DispConfig {
    u32 w[4];
};

struct BgTemplate {
    u32 w[8];
};

struct BgTemplatePair {
    struct BgTemplate t[2];
};

extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32 bgId);
extern void func_02040588(unsigned char which, unsigned char enable);

extern const struct DispConfig d_021C85C8;
extern const struct BgTemplate d_021C85E8;
extern const struct BgTemplate d_021C8608;
extern const struct BgTemplate d_021C8628;
extern const struct BgTemplate d_021C8648;
extern const struct BgTemplatePair d_021C8668;

void func_021C43E8(void)
{
    *(volatile u16 *)0x04000304 |= 0x8000;
    {
        struct DispConfig disp = d_021C85C8;
        func_0203FC28(&disp);
    }
    {
        struct BgTemplate t = d_021C85E8;
        BG_SYS_InitBgLayer(7, &t, 2);
        func_020414AC(7);
        func_02040588(7, 1);
    }
    {
        struct BgTemplatePair t = d_021C8668;
        BG_SYS_InitBgLayer(4, &t.t[0], 0);
        func_020414AC(4);
        func_02040588(4, 1);
        BG_SYS_InitBgLayer(5, &t.t[1], 0);
        func_020414AC(5);
        func_02040588(5, 1);
    }
    {
        struct BgTemplate t = d_021C8608;
        BG_SYS_InitBgLayer(6, &t, 2);
        func_020414AC(6);
        func_02040588(6, 1);
    }
    {
        struct BgTemplate t = d_021C8628;
        BG_SYS_InitBgLayer(2, &t, 0);
        func_020414AC(2);
        func_02040588(2, 0);
    }
    {
        struct BgTemplate t = d_021C8648;
        BG_SYS_InitBgLayer(3, &t, 0);
        func_020414AC(3);
        func_02040588(3, 1);
    }
}
