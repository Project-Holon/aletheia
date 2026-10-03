/*
 * unit: yes
 * function: func_021BAA4C
 * address: 0x021BAA4C
 * packet: pkt_ov206_021BAA4C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: *(p+0x1e0) is read first into a local, so 0x1e0 is the first constant built and the
 *   0x1e4..0x1f0 and 0x2b0 offsets derive from it. The last loop stores the constant 0 (a copy of k's 0).
 * symbols:
 *   func_021BAA08 0x021BAA08 thumb ov206
 *   func_021BA960 0x021BA960 thumb ov206
 *   func_021BAF7C 0x021BAF7C thumb ov206
 *   func_0201AF80 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   d_020A7370 0x020A7370 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *d_020A7370;
extern void func_021BAA08(int heap, int window, int bank, int printer, int font, int message, u16 x, u16 y, u16 color, int alignment, int expansion);
extern void func_021BA960(int heap, int window, int printer, int font, int input, u16 right, u16 y, u16 color, int alignment, int expansion);
extern void func_021BAF7C(char *p);
struct MsgBank;
struct U16Vec;
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void func_020307B0(void *p);
extern u32 func_0201EC64(u32 a);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201ED04(u32 p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045770(void *p);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, void *text, u32 f, u16 color);
extern void func_02045808(struct U16Vec *vec);
void func_021BAA4C(char *p)
{
    int l2c = *(int *)(p+0x1e0);
    int l28 = *(int *)(p+0x1e4);
    int l24 = *(int *)(p+0x1e8);
    int l20 = *(int *)(p+0x1ec);
    int l1c = *(int *)(p+0x1f0);
    u16 t = *(u16 *)(p+0xc);
    u16 i = 0;
    u32 h2;
    u16 r7;
    u16 r6;
    u16 m;
    void *name;
    u8 k;
    if (*(u16 *)(p+0xe) != 0) {
        u16 *arr = *(u16 **)(p+0x2b0);
        do {
            t = arr[t];
            if (t == 0) break;
            i = (u16)(i + 1);
        } while (i != *(u16 *)(p+0xe));
    }
    if (t == 0) t = *(u16 *)(p+0xc);
    if (*(int *)(p+0x18) != 2) {
        func_021BAA08(*(u16 *)p, *(int *)(p+0x6c), l2c, *(int *)(p+0x2c), *(int *)(p+0x28), 0x90, 0, 5, 0x3c40, 2, 0);
    }
    r7 = *(u16 *)(p+0xc);
    if (*(int *)(p+4) == 0) {
        u16 *tab = func_0201AF80(*(u16 *)p, 0);
        r7 = tab[*(u16 *)(p+0xc)];
        func_020307B0(tab);
    }
    if (r7 != 0x3e7) {
        h2 = func_0201EC64(*(u16 *)p);
        func_0201EFA4(h2, 0, r7, 3, 2, 1);
        func_021BA960(*(u16 *)p, *(int *)(p+0x70), *(int *)(p+0x2c), *(int *)(p+0x28), *(int *)(p+0x270), 8, 5, 0x3e7 + 0x59, 0, h2);
        func_0201ED04(h2);
    } else {
        func_021BA960(*(u16 *)p, *(int *)(p+0x70), *(int *)(p+0x2c), *(int *)(p+0x28), *(int *)(p+0x274), 8, 5, 0x3e7 + 0x59, 0, 0);
    }
    name = func_02045EC0(d_020A7370, *(u16 *)(p+0xc));
    func_0201C724(*(int *)(p+0x2c), func_02045770(*(void **)(p+0x70)), 0x30, 5, name, *(int *)(p+0x28), 0x440);
    func_02045808(name);
    m = 0;
    if (*(int *)(p+8) != 0) m = *(u16 *)(p+0xc);
    func_021BAA08(*(u16 *)p, *(int *)(p+0x70), l28, *(int *)(p+0x2c), *(int *)(p+0x28), m, 0, 0x16, 0x440, 2, 0);
    func_021BA960(*(u16 *)p, *(int *)(p+0x74), *(int *)(p+0x2c), *(int *)(p+0x28), *(int *)(p+0x278), 0, 4, 0x440, 0, 0);
    func_021BA960(*(u16 *)p, *(int *)(p+0x74), *(int *)(p+0x2c), *(int *)(p+0x28), *(int *)(p+0x27c), 0, 0x14, 0x440, 0, 0);
    r6 = 0;
    if (*(int *)(p+8) != 0) r6 = t;
    func_021BAA08(*(u16 *)p, *(int *)(p+0x74), l24, *(int *)(p+0x2c), *(int *)(p+0x28), r6, 0x65, 4, 0x440, 1, 0);
    r6 = 0;
    if (*(int *)(p+8) != 0) r6 = t;
    func_021BAA08(*(u16 *)p, *(int *)(p+0x74), l20, *(int *)(p+0x2c), *(int *)(p+0x28), r6, 0x66, 0x14, 0x440, 1, 0);
    t = 0;
    if (*(int *)(p+8) != 0) t = *(u16 *)(p+0xc);
    func_021BAA08(*(u16 *)p, *(int *)(p+0x78), l1c, *(int *)(p+0x2c), *(int *)(p+0x28), t, 4, 5, 0x3c40, 0, 0);
    for (k = 0; k < 4; k++) {
        *(int *)(p + k * 4 + 0x7c) = 0;
    }
    func_021BAF7C(p);
}
