/*
 * function: func_021C6028
 * address: 0x021C6028
 * packet: pkt_ov136_021C6028
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020436FC 0x020436FC arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02008F84 0x02008F84 thumb
 *   func_02045924 0x02045924 arm
 *   func_02045770 0x02045770 arm
 *   func_020439A0 0x020439A0 arm
 *   func_02008F9C 0x02008F9C thumb
 *   func_021C5F80 0x021C5F80 thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
struct Bmp;
struct CharBuf;
struct Descriptor;
struct Obj020437AC;
struct Sub02008F80Obj;
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
extern void func_02045924(void *, void *);
extern void *func_02045770(struct Descriptor *p);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u8 func_02008F9C(const struct Sub02008F80Obj *obj);
extern void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_020437AC(struct Obj020437AC *p);

void func_021C6028(u8 *p, u32 a1, int idx, int sel)
{
    void *mon;
    void *b0;
    void *b1;
    void *win;
    u8 *slot;
    u32 i;

    b0 = func_020436FC(*(u8 **)(p + 8) + 4, 1, 1, 0x20, 0x66);
    b1 = func_020436FC(*(u8 **)(p + 8) + 0x24, 1, 1, 0x20, 0x66);
    win = *(void **)(*(u8 **)(p + 8) + idx * 4 + 0x44);
    mon = *(void **)(*(u8 **)(p + 8) + sel * 4 + 0x298);
    slot = *(u8 **)(p + 8) + 0xC4 + idx * 8;

    func_02043B5C(b0, 4);
    func_02043B5C(b1, 4);
    func_02045924(*(void **)(*(u8 **)(p + 8) + 0x1D8), func_02008F84(mon));
    for (i = 0; i < 8; i++) {
        func_020439A0(func_02045770(win), b0, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
        func_020439A0(func_02045770(win), b1, 0, 0, i * 8, 8, 8, 8, 0xFFFF);
    }
    func_02043B5C(func_02045770(win), 4);
    if (func_02008F9C(mon) == 0) {
        func_021C5F80(win, *(void **)(*(u8 **)(p + 8) + 0x1D8), slot,
                      *(void **)(*(u8 **)(p + 8) + 0x1C4), 0, 0, *(u32 *)(p + 0x18), 0x14C4, 0);
    } else {
        func_021C5F80(win, *(void **)(*(u8 **)(p + 8) + 0x1D8), slot,
                      *(void **)(*(u8 **)(p + 8) + 0x1C4), 0, 0, *(u32 *)(p + 0x18), 0x1D04, 0);
    }
    func_0202CEBC(**(void ***)(p + 8), a1, win);
    func_020437AC(b1);
    func_020437AC(b0);
}
