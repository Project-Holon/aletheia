/*
 * function: func_021B9E68
 * address: 0x021B9E68
 * packet: pkt_ov206_021B9E68
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: a3 is u16 here (u16 field, strh); the matched caller ov206_func_021B9DE0 declares it unsigned.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_021BBE5C 0x021BBE5C thumb ov206
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02041300 0x02041300 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049990 0x02049990 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02062A98 0x02062A98 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BAFC4 0x021BAFC4 thumb ov206
 *   func_021BB0FC 0x021BB0FC thumb ov206
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA864 0x021BA864 thumb ov206
 *   func_021BB304 0x021BB304 thumb ov206
 *   func_021BB9E0 0x021BB9E0 thumb ov206
 *   func_021BA890 0x021BA890 thumb ov206
 *   func_021BBC38 0x021BBC38 thumb ov206
 *   func_021BB13C 0x021BB13C thumb ov206
 *   func_0207D658 0x0207D658 arm
 *   func_02040618 0x02040618 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BC220 0x021BC220 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021BC220[];
typedef signed int     s32;
struct ArcFile;
struct NitroFileHeader;
struct Personal;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_0201C440(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_021BBE5C(char *p);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020307B0(void *p);
extern void func_021BAFC4(char *p);
extern void func_021BB0FC(void *obj);
extern void *func_020056A0(void (*cb)(int, char *), void *arg, int pri);
extern void func_021BA864(int unused, char *p);
extern void func_021BB304(char *p);
extern void func_021BB9E0(char *p);
extern void func_021BA890(char *p);
extern void func_021BBC38(char *p);
extern void func_021BB13C(void *a0, void *a1, void *a2, void *a3);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020409B4(u32 layer);
static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    *(volatile u16 *)0x04000044 = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}
static inline void G2_SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04000048 = (u16)tmp;
}
static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}
void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9,
                    u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16)
{
    char *p;
    void *h;
    void *buf;
    void *res;
    char *data;
    u8 i;
    u8 k;
    int x;
    int y;
    u32 hh;

    p = func_02030734(heap, 0x2b4, 0, d_021BC220, 0x42f);
    func_02082BCC(p, 0, 0x2b4);
    *(u16 *)p = heap;
    *(u16 *)(p+0xc) = a1;
    *(u16 *)(p+0xe) = a2;
    *(u16 *)(p+0x10) = a3;
    *(u16 *)(p+0x12) = a4;
    *(u32 *)(p+0x14) = a5;
    *(u32 *)(p+4) = a6;
    *(u32 *)(p+8) = a7;
    *(u32 *)(p+0x18) = a8;
    *(u32 *)(p+0x1c) = a9;
    *(u8 *)(p+0x20) = a10;
    *(u32 *)(p+0x24) = a11;
    *(u32 *)(p+0x28) = a12;
    *(void **)(p+0x2c) = (void *)func_0201C440((void *)(*(u16 *)p));
    *(u32 *)(p+0x1b8) = a14;
    *(u32 *)(p+0x1bc) = a15;
    *(u32 *)(p+0x1c0) = a16;
    if (*(u32 *)(p+0x1c) == 0) {
        *(int *)(p+0x48) = 0;
        *(u8 *)(p+0x4c) = 3;
        *(u8 *)(p+0x4d) = 2;
        *(u8 *)(p+0x4e) = 0;
    } else {
        *(int *)(p+0x48) = 4;
        *(u8 *)(p+0x4c) = 7;
        *(u8 *)(p+0x4d) = 6;
        *(u8 *)(p+0x4e) = 4;
    }
    func_0204047C(*(u8 *)(p+0x4c), *(u8 *)(p+0x20));
    func_0204047C(*(u8 *)(p+0x4d), (u8)(*(u8 *)(p+0x20) + 1));
    func_0204047C(*(u8 *)(p+0x4e), (u8)(*(u8 *)(p+0x20) + 2));
    *(u8 *)(p+0x38) = 0;
    *(u8 *)(p+0x39) = 0;
    switch (*(u32 *)(p+0x18)) {
    case 0:
        *(int *)(p+0x54) = 0;
        break;
    case 1:
        *(int *)(p+0x54) = 5;
        break;
    case 2:
        *(int *)(p+0x54) = 7;
        break;
    }
    *(int *)(p+0x58) = 0;
    *(int *)(p+0x5c) = 0;
    *(int *)(p+0x60) = 0;
    *(int *)(p+0x64) = 0;
    *(u16 *)(p+0x194) = 0;
    if (*(u32 *)(p+0x18) == 2 && *(u32 *)(p+0x1c) == 0) {
        *(int *)(p+0x1b4) = -0x18;
    } else {
        *(int *)(p+0x1b4) = 0;
    }
    func_021BBE5C(p);
    hh = (u16)func_0201AE1C(*(void **)(p+0x26c), 0x20);
    if (*(u16 *)(p+0xe) >= hh) *(u16 *)(p+0xe) = 0;
    h = *(void **)(p+0x1c4);
    func_02049B68(h, 9, *(int *)(p+0x48), 0, 0x60, *(u16 *)p);
    *(u32 *)(p+0x30) = func_02049740(h, 0x19, *(u8 *)(p+0x4d), 0x1000, 0, *(u16 *)p);
    func_020498F4(h, 0x28, *(u8 *)(p+0x4d), (u16)*(u32 *)(p+0x30), 0x800, 0, *(u16 *)p);
    *(u32 *)(p+0x34) = func_02049740(h, 0x19, *(u8 *)(p+0x4e), 0x1000, 0, *(u16 *)p);
    func_020498F4(h, 0x1f, *(u8 *)(p+0x4e), (u16)*(u32 *)(p+0x34), 0x800, 0, *(u16 *)p);
    *(int *)(p+0x40) = 0;
    *(int *)(p+0x44) = 0;
    if (*(u32 *)(p+0x18) == 2 && *(u32 *)(p+0x1c) == 1) {
        func_02041300(*(u8 *)(p+0x4d), 0, 0, 0, 0x20, 3, 0x11);
        h = *(void **)(p+0x1c4);
        func_02049BDC(h, 2, *(int *)(p+0x48), 0, 0x80, 0x40, *(u16 *)p);
        *(u32 *)(p+0x3c) = func_02049740(h, 0xc, *(u8 *)(p+0x4e), 0x2000, 0, *(u16 *)p);
        *(int *)(p+0x40) = 1;
        func_02049990(h, 0x24, *(u8 *)(p+0x4e), 0x400, (u16)*(u32 *)(p+0x3c), 0x800, 0, *(u16 *)p);
        func_020413B0(*(u8 *)(p+0x4e), 0, 0x20, 0x20, 0x15, 4);
        func_020413B0(*(u8 *)(p+0x4e), 0, 0x35, 0x20, 3, 5);
    }
    h = *(void **)(p+0x1c4);
    buf = func_02030734(*(u16 *)p, func_020493D4(h, 9), 0, d_021BC220, 0x4f7);
    func_0204932C(h, 9, buf);
    func_02062A98(buf, &res);
    data = *(char **)((char *)res + 0xc);
    for (i = 0; i < 5; i++) {
        *(u16 *)(p + i * 2 + 0x1a0) = *(u16 *)(data + i * 2 + 0x22);
        *(u16 *)(p + i * 2 + 0x1aa) = *(u16 *)(data + i * 2 + 0x42);
    }
    func_020307B0(buf);
    func_021BAFC4(p);
    func_021BB0FC(p);
    *(void **)(p+0x50) = func_020056A0(func_021BA864, p, 1);
    func_021BB304(p);
    func_021BB9E0(p);
    if (*(u32 *)(p+0x18) == 0 || *(u32 *)(p+0x18) == 2) {
        func_021BA890(p);
        func_021BBC38(p);
    }
    for (k = 0; k < 2; k++) {
        *(int *)(p + k * 4 + 0xac) = 0;
    }
    *(int *)(p+0xb4) = 0;
    switch (*(u32 *)(p+0x18)) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + *(int *)(p+0x1b4))), (void *)(*(int *)(p+0xb4)));
    if (*(u32 *)(p+0x18) == 0) {
        *(int *)(p+0x68) = 0x88;
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x2000;
        G2_SetWnd0Position(0, 8, 100, *(int *)(p+0x68));
        G2_SetWnd0InsidePlane(0x1f, 1);
        G2_SetWndOutsidePlane(0x1f, 0);
        func_0207D658((u32)((volatile u16 *)0x04000050), 0x10, -0x10);
    }
    func_02040618(*(u8 *)(p+0x4d), 3, -*(int *)(p+0x1b4));
    func_02040618(*(u8 *)(p+0x4e), 3, -*(int *)(p+0x1b4));
    func_02040618(*(u8 *)(p+0x4c), 3, -*(int *)(p+0x1b4));
    func_020409B4(*(u8 *)(p+0x4d));
    func_020409B4(*(u8 *)(p+0x4e));
    return p;
}
