/*
 * function: func_021EFF54
 * address:  0x021EFF54
 * packet:   pkt_ov030_021EFF54
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F014C     0x021F014C  data  ov030  a4
 *   d_021F016C     0x021F016C  data  ov030  a4
 *   d_021F018C     0x021F018C  data  ov030  a4
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

extern void func_02040588(u8 which, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int a, int b);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);

extern struct BgTemplate d_021F014C;
extern struct BgTemplate d_021F016C;
extern struct BgTemplate d_021F018C;

void func_021EFF54(void)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588(i, 0);
    }
    {
        struct BgTemplate t = d_021F014C;
        func_0203FCA0(6, &t, 0);
        func_02040588(6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F016C;
        func_0203FCA0(5, &t, 0);
        func_02040588(5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F018C;
        func_0203FCA0(4, &t, 0);
        func_02040588(4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
}
