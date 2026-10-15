/*
 * function: C_GEAR_SetupBackgrounds
 * address:  0x021F1624
 * packet:   pkt_ov029_021F1624
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021F1722 ldr / 0x021F1726 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write, hardware register)
 *
 * Twin of ov030 NO_GEAR_SetupBackgrounds (same three BgTemplate blocks), plus the
 * C_GEAR_SetupSubScreenBlend call and the sub-screen window-mask clear. d_021F33AC's
 * ov029 hint is contested by another overlay, so its line carries only a4.
 *
 * symbols:
 *   C_GEAR_SetupBackgrounds  0x021F1624  thumb  ov029
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   C_GEAR_SetupSubScreenBlend  0x021F1740  thumb  ov029
 *   d_021F338C     0x021F338C  data  ov029  a4
 *   d_021F33AC     0x021F33AC  data  a4
 *   d_021F336C     0x021F336C  data  ov029  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void C_GEAR_SetupSubScreenBlend(void *p);

extern struct BgTemplate d_021F338C;
extern struct BgTemplate d_021F33AC;
extern struct BgTemplate d_021F336C;

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)

void C_GEAR_SetupBackgrounds(void *p)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588((u8)i, 0);
    }
    {
        struct BgTemplate t = d_021F338C;
        BG_SYS_InitBgLayer(6, &t, 0);
        func_02040588((u8)6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F33AC;
        BG_SYS_InitBgLayer(5, &t, 0);
        func_02040588((u8)5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F336C;
        BG_SYS_InitBgLayer(4, &t, 0);
        func_02040588((u8)4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
    C_GEAR_SetupSubScreenBlend(p);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}
