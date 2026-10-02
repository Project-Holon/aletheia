/*
 * function: func_021881D8
 * address:  0x021881D8
 * packet:   pkt_ov021_021881D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0216447C  0x0216447C  thumb  ov010
 *   func_021901EC  0x021901EC  thumb  ov021
 *   func_021BC388  0x021BC388  thumb  ov021
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021C7F70  0x021C7F70  thumb  ov021
 *   func_02013BBC  0x02013BBC  thumb
 *   func_0218E018  0x0218E018  thumb  ov021
 *   func_021AB5F4  0x021AB5F4  thumb  ov021
 *   func_021AB7E4  0x021AB7E4  thumb  ov021
 *   func_021BB1F4  0x021BB1F4  thumb  ov021
 *   func_021D33A8  0x021D33A8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_02012974  0x02012974  thumb
 *   func_02189B30  0x02189B30  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_021D33F8  0x021D33F8  thumb  ov021
 *   func_0218B8AC  0x0218B8AC  thumb  ov021
 *   func_021C6534  0x021C6534  thumb  ov021
 *   func_02189614  0x02189614  thumb  ov021
 *   func_02014110  0x02014110  thumb
 *   func_0218CEE4  0x0218CEE4  thumb  ov021
 *   func_02013C9C  0x02013C9C  thumb
 *   func_021BB2F8  0x021BB2F8  thumb  ov021
 *   func_02189ACC  0x02189ACC  thumb  ov021
 *   func_021895E8  0x021895E8  thumb  ov021
 *   func_02189204  0x02189204  thumb  ov021
 *   func_021ABD50  0x021ABD50  thumb  ov021
 *   func_021ABF68  0x021ABF68  thumb  ov021
 *   func_021AC1EC  0x021AC1EC  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   d_021D8F00     0x021D8F00  data
 *   d_021D8F10     0x021D8F10  data
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_0217F8C0  0x0217F8C0  thumb  ov019
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02013C20  0x02013C20  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A2E50  0x021A2E50  thumb  ov021
 *   func_0218D158  0x0218D158  thumb  ov021
 *   func_02189758  0x02189758  thumb  ov021
 *   func_021BE2A8  0x021BE2A8  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02189154  0x02189154  thumb  ov021
 *   func_021A0104  0x021A0104  thumb  ov021
 *   func_021A02C4  0x021A02C4  thumb  ov021
 *   func_02013EEC  0x02013EEC  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_021A0338  0x021A0338  thumb  ov021
 *   func_020140DC  0x020140DC  thumb
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_0202E83C  0x0202E83C  thumb
 *   func_021A03D0  0x021A03D0  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_021A19E8  0x021A19E8  thumb  ov021
 *   func_02012994  0x02012994  thumb
 *   func_021A1B74  0x021A1B74  thumb  ov021
 *   func_021BE1DC  0x021BE1DC  thumb  ov021
 *   func_020129AC  0x020129AC  thumb
 *   func_021A0CF4  0x021A0CF4  thumb  ov021
 *   func_021A9ED8  0x021A9ED8  thumb  ov021
 *   func_02026388  0x02026388  thumb
 *   func_021BB890  0x021BB890  thumb  ov021
 *   func_021C1A08  0x021C1A08  thumb  ov021
 *   func_021C1AF4  0x021C1AF4  thumb  ov021
 *   func_021CF45C  0x021CF45C  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_021C31D4  0x021C31D4  thumb  ov021
 *   func_02189684  0x02189684  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} V3;

typedef struct {
    void *f0;
    void (*f4)(char *p, V3 *v, int c);
} Ops;

extern int d_021D8F00;
extern int d_021D8F10[];

extern int func_020120F4(int x);
extern void func_0216447C(int sys, u16 id);
extern int func_021901EC(u16 heap, int b);
extern int func_021BC388(int a, int b, int c);
extern int func_02012B38(int a);
extern int func_02014470(int a);
extern int func_021C7F70(int flags, u16 heap);
extern int func_02013BBC(u16 id);
extern int func_0218E018(int a0, int a1, int a2, void *a3, u16 heap);
extern int func_021AB5F4(u16 heap, int a, void *b);
extern int func_021AB7E4(u16 heap);
extern int func_021BB1F4(u16 a, int b, int c, int d);
extern int func_021D33A8(u16 heap, int a, void *p, u16 id);
extern int func_0218DC6C(int a);
extern int func_02012974(int a);
extern void func_02189B30(u16 a, int x, void *out, int obj);
extern int func_02012138(int a);
extern int func_021D33F8(int a);
extern void func_0218B8AC(int p, u16 a, int b, int c);
extern void func_021C6534(int p, int v);
extern void func_02189614(int sys, void *q, u16 id);
extern void func_02014110(void *p, u16 a, int b, int c, int d, int e, int f, int g);
extern void func_0218CEE4(int p, void *src, int c);
extern int func_02013C9C(u16 id);
extern void func_021BB2F8(int a, int b, u16 c);
extern int func_02189ACC(u16 id);
extern void func_021895E8(void *p, u16 id, u16 c);
extern void func_02189204(void *p);
extern int func_021ABD50(void *a, int b, u16 c);
extern void func_021ABF68(int t, int n);
extern void func_021AC1EC(int p, int v);
extern void func_021ABE30(int t, int *arr, int n);
extern int func_02013CC8(u16 a);
extern int func_02013CE0(u16 a);
extern int func_0217F8C0(u16 id);
extern int func_020120F8(int a);
extern int func_02012AE4(int a);
extern int func_02012B28(int a);
extern int func_02013C20(u16 id);
extern void func_02012B2C(int a, int b);
extern int func_02012944(int a);
extern int func_02008550(int a);
extern int func_021A2E50(int a, void *b, V3 *c, int d, u16 heap);
extern void func_0218D158(int a, V3 *b);
extern void func_02189758(void *p);
extern int func_021BE2A8(int a, int b, u16 heap);
extern int func_02188C9C(void *p);
extern void func_02189154(int a, int b);
extern int func_021A0104(u16 heap);
extern int func_021A02C4(u16 heap);
extern int func_02013EEC(u16 id);
extern int func_02013F2C(u16 id);
extern void func_021A0338(int h, int a, int b, int c);
extern int func_020140DC(int q);
extern int func_0203F4FC(void);
extern int func_0202E83C(int x);
extern int func_021A03D0(int a, int b, int c, int d, int e, u16 f);
extern int func_02012A30(int p);
extern int func_021A19E8(int a0, int a1, int a2, int a3, int a4, int a5, int heap);
extern int func_02012994(int a);
extern void func_021A1B74(int p, u16 a, int f);
extern void func_021BE1DC(void *arg);
extern int func_020129AC(int p);
extern int func_021A0CF4(u16 a, void *b, int c);
extern int func_021A9ED8(void *a);
extern void func_02026388(int p, void *a);
extern int func_021BB890(void *a, u16 b, int n);
extern int func_021C1A08(int a);
extern int func_021C1AF4(int a, int b);
extern int func_021CF45C(u16 heap, void *v);
extern int func_02012EBC(int p);
extern int func_0200BDB0(int sys);
extern int func_021C31D4(u16 heap, void *a, int b);
extern void func_02189684(void *p, u16 v);

#define F16(o)  (*(u16 *)(p + (o)))
#define F32(o)  (*(int *)(p + (o)))

int func_021881D8(int a, char *p)
{
    int sys = func_020120F4(a);
    int flag = 1;

    switch (*(u8 *)(p + 0xc8)) {
    case 0: {
        int x;
        func_0216447C(sys, F16(0xd0));
        x = func_021901EC(F16(0), F32(0xa4));
        F32(0x2c) = 0;
        F32(0x28) = x;
        F32(0x30) = func_021BC388(a, 0x93, x);
        F32(0xa0) = func_021C7F70(func_02014470(func_02012B38(F32(8))), F16(0));
        F32(0x10) = func_0218E018(func_02013BBC(F16(0xd0)), 0, F32(0xa4), p + 0xf4, F16(0));
        F32(0x40) = func_021AB5F4(F16(0), F32(0x10), p);
        F32(0x44) = func_021AB7E4(F16(0));
        break;
    }
    case 1: {
        int m;
        int t;
        F32(0x3c) = func_021BB1F4(F16(0), F32(0x10), F32(0x40), F32(0x44));
        F32(0x9c) = func_021D33A8(F16(0), a, p, F16(0xd0));
        m = func_0218DC6C(F32(0x48));
        func_02189B30(F16(0xd0), F32(0xc), p + 0x50, func_02012974(F32(8)));
        func_02012138(F32(4));
        t = func_021D33F8(F32(0x9c));
        func_0218B8AC(m, F16(0xd0), F32(0xc), t);
        func_021C6534(F32(0x130), t);
        func_02189614(sys, p, F16(0xd0));
        break;
    }
    case 2: {
        int v;
        func_02014110(p + 0xd4, F16(0xd0), 0, 0, 0, F32(0xf4), F32(0xf8), F32(0xfc));
        func_02012138(F32(4));
        func_0218CEE4(F32(0x48), p + 0x50, func_021D33F8(F32(0x9c)));
        v = func_02013C9C(F16(0xd0));
        if (v != -1) {
            func_021BB2F8(F32(0x3c), v, F16(0));
        }
        F32(0x104) = func_02189ACC(F16(0xd0));
        func_021895E8(p, F16(0xd0), F16(0));
        break;
    }
    case 3:
        func_02189204(p);
        F32(0x94) = func_021ABD50(p, 0x18, F16(0));
        func_021ABF68(F32(0x94), 0x5e);
        func_021AC1EC(F32(0x94), func_021D33F8(F32(0x9c)));
        func_021ABE30(F32(0x94), d_021D8F10, d_021D8F00);
        if (func_02013CC8(F16(0xd0)) == 1 || func_02013CE0(F16(0xd0)) == 1) {
            F32(0x98) = func_0217F8C0(F16(0));
        }
        break;
    case 4: {
        int w;
        int k;
        V3 *pos;
        int r;
        int g;
        w = func_020120F8(a);
        k = func_02012AE4(w);
        pos = (V3 *)(w + 4);
        if (func_02012B28(w) == 1 && func_02013C20(F16(0xd0)) == 0) {
            func_02012B2C(w, 0);
        }
        F32(0x8c) = func_021A2E50(w, p, pos, func_02008550(func_02012944(sys)), F16(0));
        *(V3 *)(p + 0xf4) = *pos;
        (*(Ops **)(p + 0x108))->f4(p, (V3 *)(p + 0xf4), k);
        func_0218D158(F32(0x48), (V3 *)(p + 0xf4));
        func_02189758(p + 0x118);
        F32(0x34) = func_021BE2A8(0x3c, 0x23, F16(0));
        func_02189154(F32(0xc), func_02188C9C(p));
        F32(0x18) = func_021A0104(F16(0));
        F32(0x1c) = func_021A02C4(F16(0));
        r = func_02013EEC(F16(0xd0));
        func_021A0338(F32(0x1c), r, func_02013F2C(F16(0xd0)), 1);
        r = func_020140DC(F32(0xc));
        g = func_0203F4FC();
        F32(0x14) = func_021A03D0(r, g, func_0202E83C(a), F32(0x18), F32(0xa8), F16(0));
        r = func_02012A30(F32(8));
        F32(0x20) = func_021A19E8(F32(0x10), F32(0x14), F32(0x18), F32(0x1c), r, func_0202E83C(a), 0x92);
        func_021A1B74(F32(0x20), func_02012994(F32(8)), 0x92);
        func_021BE1DC(p);
        break;
    }
    case 5:
        F32(0x24) = func_021A0CF4(F16(0), p, func_020129AC(sys));
        break;
    case 6:
        F32(0x90) = func_021A9ED8(p);
        func_02026388(func_02012138(a), p);
        F32(0xbc) = func_021BB890(p, F16(0), 0x20);
        F32(0x120) = func_021C1A08(0x50);
        F32(0x124) = func_021C1AF4(0x50, F32(0x120));
        F32(0x13c) = func_021CF45C(F16(0), p);
        F32(0x128) = func_021C31D4(F16(0), p, func_0200BDB0(func_02012EBC(F32(8))));
        func_02189684(p, F16(0xd0));
        flag = 0;
        break;
    }
    (*(u8 *)(p + 0xc8))++;
    F32(0x12c) = 0;
    return flag == 0;
}
