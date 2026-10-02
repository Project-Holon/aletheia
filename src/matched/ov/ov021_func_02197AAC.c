/*
 * function: func_02197AAC
 * address:  0x02197AAC
 * packet:   pkt_ov021_02197AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_020121CC  0x020121CC  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0202223C  0x0202223C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0201283C(u32);
extern u32 func_0201058C(void *key);
extern void func_02027974(u32);
extern void func_02028178(u32);
extern void func_02040618(u32, u32, u32);
extern void func_020310C4(u32);
extern void func_0201C4E4(u32);
extern void func_0204A600(void);
extern u32 func_02155A90(u32);
extern void func_020121CC(u32);
extern u32 func_020221A4(void);
extern u32 func_02012204(u32);
extern void func_0202223C(u32, u32);

u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a)
{
    u32 ret;
    void (*cb)(u8 *);

    cb = *(void (**)(u8 *))a;
    ret = 1;
    func_0201058C(func_0201283C(*(u32 *)(a + 0x30)));
    if (cb != 0) {
        cb(a);
        ret = 0;
    }
    if (*(u32 *)(a + 0x2c0) != 0) {
        func_02027974(*(u32 *)(a + 0x2c0));
    }
    if (*(u32 *)(a + 0x2e0) != 0) {
        func_02028178(*(u32 *)(a + 0x2e0));
    }
    func_02040618(4, 3, *(u32 *)(a + 0x2ac));
    *(u32 *)(a + 0x2ac) = *(u32 *)(a + 0x2ac) - 1;
    func_020310C4(*(u32 *)(a + 0x2b8));
    func_0201C4E4(*(u32 *)(a + 0x2bc));
    func_0204A600();
    if (*(u8 *)(a + 0x306) == 0) {
        func_020121CC(func_02155A90(*(u32 *)(a + 0x2e4)));
    }
    if (func_020221A4() != 0) {
        if (func_02012204(func_02155A90(*(u32 *)(a + 0x2e4))) != 0) {
            *(u32 *)(a + 8) = 12;
            ret = 1;
            func_0202223C(0, 0);
            func_0202223C(1, 0);
        }
    }
    return ret;
}
