/*
 * function: func_021CDAB8
 * address:  0x021CDAB8
 * packet:   pkt_ov021_021CDAB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CEB64  0x021CEB64  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021CEB20  0x021CEB20  thumb  ov021
 *   func_0203D010  0x0203D010  arm
 *   func_021CEB84  0x021CEB84  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CE7AC  0x021CE7AC  thumb  ov021
 *   func_021CF068  0x021CF068  thumb  ov021
 *   func_021CF0F4  0x021CF0F4  thumb  ov021
 *   func_021CF32C  0x021CF32C  thumb  ov021
 *   func_021CE9A0  0x021CE9A0  thumb  ov021
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF164  0x021CF164  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   data_021DB498  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CE9E4(u8 *p, int n);
struct Req;
struct WordSet;
extern u32 func_02190EF0(u32 *p);
extern void func_021CEB64(u8 *p);
extern void func_021CE81C(void *p);
extern void func_021CEB20(u8 *p);
extern void func_0203D010(void);
extern u32 func_021CEB84(u8 *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021CE7AC(u8 *p);
extern int func_021CF068(u8 *p);
extern void func_021CF0F4(u8 *p);
extern int func_021CF32C(u32 flag);
extern void func_021CE9A0(u8 *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern u32 func_0203D650(void);
extern void *func_0203D798(void);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_021CF17C(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int func_0203CD98(void);
extern void func_021CF164(u32 a);
extern u32 func_0200FB24(void);
extern u8 data_021DB498[];

#define U32(o) (*(u32 *)(p + (o)))

int func_021CDAB8(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        func_021CE9E4(p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 10));
        p[0x51E]++;
        break;
    case 1:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E]++;
        }
        break;
    case 2:
        func_021CEB64(p);
        func_021CE81C(p);
        U32(0x404) = 0;
        func_021CEB20(p);
        func_0203D010();
        p[0x51E]++;
        break;
    case 3:
        switch (func_021CEB84(p)) {
        case 1:
            func_021CEB64(p);
            if (p[0x519] == 1) {
                p[0x51E] = 6;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            } else {
                func_0201F02C((struct WordSet *)U32(4), 0, (void *)U32(0x404));
                func_021CE9E4(p, 0x21);
                p[0x51E] = 4;
            }
            break;
        case 2:
            func_021CEB64(p);
            p[0x51E] = 10;
            break;
        case 3:
            func_021CEB64(p);
            p[0x51E] = 0xe;
            break;
        }
        break;
    case 4:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            func_021CE9E4(p, 0x22);
            func_021CE7AC(p);
            p[0x51E]++;
        }
        break;
    case 5:
        if (func_021CF068(p) == 2) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 0xe;
            break;
        }
        if (p[0x577] == 1) {
            if (func_021CF32C(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        func_021CE9A0(p);
        if (p[0x519] == 1) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 6;
        } else if (p[0x51A] == 1) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 8;
        }
        break;
    case 6:
        if (p[0x520] == 0) {
            func_021CE9E4(p, 0x1e);
        }
        p[0x51E] = 7;
        func_02039C68((struct Link *)func_020399A8(), 1, 0x27);
        break;
    case 7:
        if (p[0x520] != 0 || func_02190EF0((u32 *)U32(0x14)) == 1) {
            if (func_02039CB4((struct Link *)func_020399A8(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xf;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            }
        }
        break;
    case 8:
        func_021CE9E4(p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 8));
        p[0x51E] = 9;
        break;
    case 9:
        if (func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xe;
        }
        break;
    case 10:
        U32(0x484) = func_0203D650();
        func_02082D44(func_0203D798(), p + 0x414, 0x70);
        func_021CF17C();
        func_0203CEAC(0);
        func_0201F02C((struct WordSet *)U32(4), 0, (void *)((int)(p + 0x530)));
        func_021CE9E4(p, 0x1f);
        p[0x51E] = 0xb;
        break;
    case 11:
        if (func_0203CDBC() == 1 && func_02190EF0((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xc;
        }
        break;
    case 12:
        func_0203CBAC((struct Req *)(p + 0x414), 0, (u32)((void *)U32(0x484)));
        p[0x51E] = 0xd;
        break;
    case 13:
        if (func_0203CD98() == 1) {
            func_021CF164((u32)p);
            p[0x51E] = 0;
        }
        break;
    case 14:
        U32(0x2c) = 2;
        p[0x51E] = 0xf;
        break;
    case 15:
        func_021CEB64(p);
        func_021CE81C(p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(p);
        func_021CEB64(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}
