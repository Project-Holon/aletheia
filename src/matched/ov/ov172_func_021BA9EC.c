/*
 * function: func_021BA9EC
 * address:  0x021BA9EC
 * packet:   pkt_ov172_021BA9EC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02 (lane C1-04): byte-correct; one relocation wildcarded.
 * Blocker: func_021BE02C has no witness in ov172 (unlabelled leaf: 021BE02C
 * is `ldr r0, [r0, #0x10]; bx lr`, 021BE030 is the paired setter
 * `str r1, [r0, #0x10]; bx lr`; both missing from the layout, a figure
 * move). The only other file for that address is ov203's unrelated function.
 * The +0x96 wrap-around reload is a volatile read in the else arm.
 *
 * Scene state machine, one switch on the state word at +0, then the
 * per-frame tail (window release checks, key handling, colour fade).
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE02C  0x021BE02C  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BE0B0  0x021BE0B0  thumb  ov172
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021BE08C  0x021BE08C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021B7B3C  0x021B7B3C  thumb  ov172
 *   func_021B8084  0x021B8084  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B34  0x021B8B34  thumb  ov172
 *   func_021B8B48  0x021B8B48  thumb  ov172
 *   func_021B77B4  0x021B77B4  thumb  ov172
 *   func_021BB938  0x021BB938  thumb  ov172
 *   func_021BB8F4  0x021BB8F4  thumb  ov172
 *   func_021BAE58  0x021BAE58  thumb  ov172
 *   func_021BAEE0  0x021BAEE0  thumb  ov172
 *   func_021BB4D0  0x021BB4D0  thumb  ov172
 *   func_021BB288  0x021BB288  thumb  ov172
 *   d_020A1B38     0x020A1B38  data a2
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u16  func_021BE00C(void *c);
extern u32  func_021BE02C(void *c);
extern u32  func_021BDFDC(void *c);
extern u32  func_021BDFE4(void *c);
extern void func_021BE0B0(void *c, u32 v);
extern u32  func_021BE0B4(void *c);
extern u8   func_021BE0A4(void *c);
extern void func_021BE08C(void *c);
extern u32  func_021BE044(void *c);
extern int  func_021B7590(void *c, u32 v);
extern void func_021B7578(void *c, u32 v);
extern void func_021B7B80(void *c, u32 v);
extern void func_021B7B3C(void *c, u32 v, u32 k);
extern void func_021B8084(void *c, u32 v);
extern u32  func_021B8740(void *c, u32 v, u8 k, u32 z);
extern void func_021B8B34(void *c, u32 v, u32 k);
extern int  func_021B8B48(void *c, u32 v, u32 k);
extern u32  func_021B77B4(void *c, u32 v);
extern void func_021BB938(void *c, char *q, int id);
extern int  func_021BB8F4(void *c, char *q);
extern void func_021BAE58(void *c, char *q);
extern void func_021BAEE0(void *c, char *q);
extern void func_021BB4D0(void *c, char *q);
extern void func_021BB288(void *c, char *q);
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32  func_020221A4(void);
extern u32  func_02035C60(void);
extern u32  func_020362DC(void);
extern u32  func_0201C6C4(u32 a, u32 b);
extern u32  func_02045770(u32 w);
extern void func_0201F73C(u32 w, u32 a, u32 b, u32 c);
extern void func_02045334(u32 w);
extern void func_02045374(u32 w);
extern void func_02041B6C(u32 a);
extern void func_020409B4(u32 a);
extern void func_020061E4(u32 id);
extern void func_02061CA4(u32 a, u32 b, void *c, u32 d);
extern void func_0204B3DC(u32 a, u32 b);

extern s16 d_020A1B38[];

int func_021BA9EC(void *a0, char *p)
{
    u32 v;
    u32 flag;
    u32 z;
    u8 i;
    u32 t;
    u32 s;
    u32 k;

    v = func_021BE00C(a0);
    z = 0;
    *(u32 *)(p + 8) = z;
    switch (*(u32 *)p) {
    case 0:
        if (func_021BE02C(a0) == 1) {
            func_0202208C(z, 1, 1, z, 6, 1, v);
        } else {
            func_0202208C(4, 1, 1, z, 6, 1, v);
        }
        *(u32 *)p = 1;
        break;
    case 1:
        if (func_020221A4() == 1) {
            *(u32 *)(p + 0x18) = 1;
            *(u32 *)p = 4;
        }
        break;
    case 2:
        t = func_021BDFDC(a0);
        if (*(u32 *)(p + 0x20) != 0) {
            if (func_021B7590(a0, t) != 1) {
                break;
            }
        }
        func_0202208C(0, 0, 0, 0, 6, 1, v);
        *(u32 *)p = 3;
        *(u32 *)(p + 0x18) = 0;
        break;
    case 3:
        if (func_020221A4() == 1) {
            if (*(u32 *)(p + 0x1c) == 0) {
                return 1;
            }
            return 4;
        }
        break;
    case 4:
        if (func_021BB8F4(a0, p) == 0) {
            func_021BAE58(a0, p);
        }
        break;
    case 5:
        if (func_021BB8F4(a0, p) == 0) {
            func_021BAEE0(a0, p);
        }
        break;
    case 6:
        func_021B8084(a0, func_021BDFE4(a0));
        func_021BB938(a0, p, 0x24);
        flag = 1;
        func_021BE0B0(a0, 1);
        *(u32 *)p = 7;
        func_021B7B80(a0, func_021BDFDC(a0));
        *(u32 *)(p + 0x20) = flag;
        break;
    case 7:
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            *(u32 *)(p + 0x1c) = flag = 1;
            *(u32 *)p = 2;
            func_021BE0B0(a0, 1);
            func_021B7578(a0, func_021BDFDC(a0));
            *(u32 *)(p + 0x20) = flag;
        }
        break;
    case 8:
        if (func_021B8740(a0, func_021BDFE4(a0), 10, z) == 1) {
            *(u32 *)p = 9;
        }
        break;
    case 9:
        func_021B8084(a0, func_021BDFE4(a0));
        func_021BB938(a0, p, 0x25);
        flag = 1;
        func_021BE0B0(a0, 1);
        *(u32 *)p = 10;
        *(u16 *)(p + 0x54) = z;
        func_021B7B80(a0, func_021BDFDC(a0));
        *(u32 *)(p + 0x20) = flag;
        break;
    case 10:
        *(u16 *)(p + 0x54) = *(u16 *)(p + 0x54) + 1;
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0
            || *(u16 *)(p + 0x54) >= 300) {
            *(u32 *)p = 11;
        }
        break;
    case 11:
        func_021B8B34(a0, func_021BDFE4(a0), 0x2f);
        *(u32 *)p = 12;
        break;
    case 12:
        if (func_021B8B48(a0, func_021BDFE4(a0), 0x2f) == 1) {
            *(u32 *)(p + 0x1c) = flag = 1;
            *(u32 *)p = 2;
            func_021BE0B0(a0, 1);
            func_021B7578(a0, func_021BDFDC(a0));
            *(u32 *)(p + 0x20) = flag;
        }
        break;
    case 13:
        func_021B8084(a0, func_021BDFE4(a0));
        func_021BB938(a0, p, 0x26);
        flag = 1;
        func_021BE0B0(a0, 1);
        *(u32 *)p = 14;
        func_021B7B80(a0, func_021BDFDC(a0));
        *(u32 *)(p + 0x20) = flag;
        break;
    case 14:
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            *(u32 *)(p + 0x1c) = flag = 1;
            *(u32 *)p = 2;
            func_021BE0B0(a0, 1);
            func_021B7578(a0, func_021BDFDC(a0));
            *(u32 *)(p + 0x20) = flag;
        }
        break;
    }
    func_021BB4D0(a0, p);
    if (*(u32 *)(p + 0x18) == 1) {
        func_021BB288(a0, p);
    }
    if (*(u32 *)(p + 0x38) == 1) {
        t = func_021BE044(a0);
        if (func_0201C6C4(t, func_02045770(*(u32 *)(p + 0x48))) == 0) {
            func_0201F73C(*(u32 *)(p + 0x48), 2, 0x140, 9);
            func_02045334(*(u32 *)(p + 0x48));
            func_02045374(*(u32 *)(p + 0x48));
            func_02041B6C(4);
            i = 0;
            *(u32 *)(p + 0x38) = 0;
            if (*(u32 *)(p + 0x3c) == 1) {
                k = 1;
                for (i = 0; i < 5; i++) {
                    func_0204B3DC(*(u32 *)(p + i * 4 + 0x70), k);
                }
            } else {
                k = i;
                for (i = 0; i < 5; i++) {
                    func_0204B3DC(*(u32 *)(p + i * 4 + 0x70), k);
                }
            }
        }
    }
    if (*(u32 *)(p + 0x40) == 1) {
        t = func_021BE044(a0);
        if (func_0201C6C4(t, func_02045770(*(u32 *)(p + 0x4c))) == 0) {
            func_02045334(*(u32 *)(p + 0x4c));
            func_02045374(*(u32 *)(p + 0x4c));
            func_020409B4(4);
            *(u32 *)(p + 0x40) = 0;
        }
    }
    if (*(u32 *)(p + 0x44) == 1 && *(u32 *)(p + 0x50) != 0) {
        t = func_021BE044(a0);
        if (func_0201C6C4(t, func_02045770(*(u32 *)(p + 0x50))) == 0) {
            func_02045334(*(u32 *)(p + 0x50));
            func_02045374(*(u32 *)(p + 0x50));
            func_020409B4(0);
            *(u32 *)(p + 0x44) = 0;
        }
    }
    if (*(s32 *)p <= 5 && func_021BE0B4(a0) == 0) {
        v = func_021BDFDC(a0);
        if (func_020362DC() & 0x40) {
            func_021B7B3C(a0, v, 0);
        }
        if (func_020362DC() & 0x10) {
            func_021B7B3C(a0, v, 5);
        }
        if (func_020362DC() & 0x80) {
            func_021B7B3C(a0, v, 1);
        }
        if (func_020362DC() & 0x20) {
            func_021B7B3C(a0, v, 3);
        }
    }
    if (func_021BE0A4(a0) == 0 && (func_020362DC() & 0x200)) {
        if (func_021B77B4(a0, func_021BDFDC(a0)) == 0) {
            func_021BE08C(a0);
            func_020061E4(0x66C);
        }
    }
    t = *(volatile u16 *)(p + 0x96);
    *(u16 *)(p + 0x96) = ((s32)(t + 0x400) >= 0x10000) ? t - 0xFC00 : *(volatile u16 *)(p + 0x96) + 0x400;
    s = d_020A1B38[(*(u16 *)(p + 0x96) >> 4) * 2 + 1];
    s = (s16)((s32)(s + 0x1000) / 2);
    s = (u8)(((s32)s * -9 >> 12) + 0x1c);
    *(u16 *)(p + 0x94) = s | (s << 5) | (s << 10);
    func_02061CA4(0xe, 0xde, p + 0x94, 2);
    return 3;
}
