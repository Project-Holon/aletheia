/*
 * function: func_021881D8
 * address:  0x021881D8
 * packet:   pkt_021881D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   ISA  (blocked, not verifiable as written)
 *
 * The image's Thumb `bl` at +0x11A targets 0x021C6534, which is a Thumb
 * callee; declared `arm ov016` the whole function verifies with only the two
 * bytes of that call instruction differing (bl vs blx).  With the correct
 * `thumb` declaration match.py hard-refuses: isa_evidence finds the
 * func_021C6534 label in ov016 and declares the image ARM, so the site can
 * never resolve -- no overlay labels 0x021C6534 Thumb (ov021 has data there,
 * ov016 ARM code).  Witness class: none; needs a Thumb label seed at
 * 0x021C6534 or the ov016 label corrected.  All other 1038 bytes reproduce.
 *
 * Seven-step field init sequence, one step per call; returns 1 once the last step has run.
 *
 * symbols:
 *   data_021D8F00  0x021D8F00  data  ov021
 *   data_021D8F10  0x021D8F10  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02012994  0x02012994  thumb
 *   func_020129AC  0x020129AC  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02013BBC  0x02013BBC  thumb
 *   func_02013C20  0x02013C20  thumb
 *   func_02013C9C  0x02013C9C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013EEC  0x02013EEC  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_020140DC  0x020140DC  thumb
 *   func_02014110  0x02014110  thumb
 *   func_02014470  0x02014470  thumb
 *   func_02026388  0x02026388  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_0216447C  0x0216447C  thumb  ov010
 *   func_0217F8C0  0x0217F8C0  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02189154  0x02189154  thumb  ov021
 *   func_02189204  0x02189204  thumb  ov021
 *   func_021895E8  0x021895E8  thumb  ov021
 *   func_02189614  0x02189614  thumb  ov021
 *   func_02189684  0x02189684  thumb  ov021
 *   func_02189758  0x02189758  thumb  ov021
 *   func_02189ACC  0x02189ACC  thumb  ov021
 *   func_02189B30  0x02189B30  thumb  ov021
 *   func_0218B8AC  0x0218B8AC  thumb  ov021
 *   func_0218CEE4  0x0218CEE4  thumb  ov021
 *   func_0218D158  0x0218D158  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218E018  0x0218E018  thumb  ov021
 *   func_021901EC  0x021901EC  thumb  ov021
 *   func_021A0104  0x021A0104  thumb  ov021
 *   func_021A02C4  0x021A02C4  thumb  ov021
 *   func_021A0338  0x021A0338  thumb  ov021
 *   func_021A03D0  0x021A03D0  thumb  ov021
 *   func_021A0CF4  0x021A0CF4  thumb  ov021
 *   func_021A19E8  0x021A19E8  thumb  ov021
 *   func_021A1B74  0x021A1B74  thumb  ov021
 *   func_021A2E50  0x021A2E50  thumb  ov021
 *   func_021A9ED8  0x021A9ED8  thumb  ov021
 *   func_021AB5F4  0x021AB5F4  thumb  ov021
 *   func_021AB7E4  0x021AB7E4  thumb  ov021
 *   func_021ABD50  0x021ABD50  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABF68  0x021ABF68  thumb  ov021
 *   func_021AC1EC  0x021AC1EC  thumb  ov021
 *   func_021BB1F4  0x021BB1F4  thumb  ov021
 *   func_021BB2F8  0x021BB2F8  thumb  ov021
 *   func_021BB890  0x021BB890  thumb  ov021
 *   func_021BC388  0x021BC388  thumb  ov021
 *   func_021BE1DC  0x021BE1DC  thumb  ov021
 *   func_021BE2A8  0x021BE2A8  thumb  ov021
 *   func_021C1A08  0x021C1A08  thumb  ov021
 *   func_021C1AF4  0x021C1AF4  thumb  ov021
 *   func_021C31D4  0x021C31D4  thumb  ov021
 *   func_021C6534  0x021C6534  thumb  ov021
 *   func_021C7F70  0x021C7F70  thumb  ov021
 *   func_021CF45C  0x021CF45C  thumb  ov021
 *   func_021D33A8  0x021D33A8  thumb  ov021
 *   func_021D33F8  0x021D33F8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } Vec3;
typedef struct { void *f0; void (*f4)(void *, Vec3 *, void *); } VTbl;

typedef struct {
    u16 id;             /* 0x00 */
    u16 pad02;
    void *x04;          /* 0x04 */
    void *x08;          /* 0x08 */
    void *x0C;          /* 0x0C */
    void *x10;          /* 0x10 */
    void *x14;          /* 0x14 */
    void *x18;          /* 0x18 */
    void *x1C;          /* 0x1C */
    void *x20;          /* 0x20 */
    void *x24;          /* 0x24 */
    void *x28;          /* 0x28 */
    u32 x2C;            /* 0x2C */
    void *x30;          /* 0x30 */
    void *x34;          /* 0x34 */
    u32 x38;
    void *x3C;          /* 0x3C */
    void *x40;          /* 0x40 */
    void *x44;          /* 0x44 */
    void *x48;          /* 0x48 */
    u32 x4C;
    u8 x50[0x3C];       /* 0x50 */
    void *x8C;          /* 0x8C */
    void *x90;          /* 0x90 */
    void *x94;          /* 0x94 */
    void *x98;          /* 0x98 */
    void *x9C;          /* 0x9C */
    void *xA0;          /* 0xA0 */
    void *xA4;          /* 0xA4 */
    void *xA8;          /* 0xA8 */
    u8 padAC[0x10];
    void *xBC;          /* 0xBC */
    u8 padC0[8];
    u8 state;           /* 0xC8 */
    u8 padC9[7];
    u16 xD0;            /* 0xD0 */
    u16 padD2;
    u8 xD4[0x20];       /* 0xD4 */
    Vec3 xF4;           /* 0xF4 */
    u32 x100;
    void *x104;         /* 0x104 */
    VTbl *x108;         /* 0x108 */
    u8 pad10C[0xC];
    u8 x118[8];         /* 0x118 */
    void *x120;         /* 0x120 */
    void *x124;         /* 0x124 */
    void *x128;         /* 0x128 */
    u32 x12C;           /* 0x12C */
    void *x130;         /* 0x130 */
    u8 pad134[8];
    void *x13C;         /* 0x13C */
} FieldSys;

extern void *func_020120F4(void *);
extern void *func_020120F8(void *);
extern void func_0216447C(void *, u16);
extern void *func_021901EC(u16, void *);
extern void *func_021BC388(void *, u32, void *);
extern void *func_02012B38(void *);
extern void *func_02014470(void *);
extern void *func_021C7F70(void *, u16);
extern void *func_02013BBC(u16);
extern void *func_0218E018(void *, u32, void *, Vec3 *, u16);
extern void *func_021AB5F4(u16, void *, FieldSys *);
extern void *func_021AB7E4(u16);
extern void *func_021BB1F4(u16, void *, void *, void *);
extern void *func_021D33A8(u16, void *, FieldSys *, u16);
extern void *func_0218DC6C(void *);
extern void *func_02012974(void *);
extern void func_02189B30(u16, void *, void *, void *);
extern void *func_02012138(void *);
extern void *func_021D33F8(void *);
extern void func_0218B8AC(void *, u16, void *, void *);
extern void func_021C6534(void *, void *);
extern void func_02189614(void *, FieldSys *, u16);
extern void func_02014110(void *, u16, u32, u32, u32, u32, u32, u32);
extern void func_0218CEE4(void *, void *, void *);
extern int func_02013C9C(u16);
extern void func_021BB2F8(void *, int, u16);
extern void *func_02189ACC(u16);
extern void func_021895E8(FieldSys *, u16, u16);
extern void func_02189204(FieldSys *);
extern void *func_021ABD50(FieldSys *, u32, u16);
extern void func_021ABF68(void *, u32);
extern void func_021AC1EC(void *, void *);
extern void func_021ABE30(void *, u32, u32);
extern u32 data_021D8F00;
extern u8 data_021D8F10[];
extern int func_02013CC8(u16);
extern int func_02013CE0(u16);
extern void *func_0217F8C0(u16);
extern void *func_02012AE4(void *);
extern int func_02012B28(void *);
extern int func_02013C20(u16);
extern void func_02012B2C(void *, u32);
extern void *func_02012944(void *);
extern void *func_02008550(void *);
extern void *func_021A2E50(void *, FieldSys *, void *, void *, u16);
extern void func_0218D158(void *, Vec3 *);
extern void func_02189758(void *);
extern void *func_021BE2A8(u32, u32, u16);
extern void *func_02188C9C(FieldSys *);
extern void func_02189154(void *, void *);
extern void *func_021A0104(u16);
extern void *func_021A02C4(u16);
extern void *func_02013EEC(u16);
extern void *func_02013F2C(u16);
extern void func_021A0338(void *, void *, void *, u32);
extern void *func_020140DC(void *);
extern void *func_0203F4FC(void);
extern void *func_0202E83C(void *);
extern void *func_021A03D0(void *, void *, void *, void *, void *, u16);
extern void *func_02012A30(void *);
extern void *func_021A19E8(void *, void *, void *, void *, void *, void *, u32);
extern u32 func_02012994(void *);
extern void func_021A1B74(void *, u16, u32);
extern void func_021BE1DC(FieldSys *);
extern void *func_020129AC(void *);
extern void *func_021A0CF4(u16, FieldSys *, void *);
extern void *func_021A9ED8(FieldSys *);
extern void *func_02026388(void *, FieldSys *);
extern void *func_021BB890(FieldSys *, u16, u32);
extern void *func_021C1A08(u32);
extern void *func_021C1AF4(u32, void *);
extern void *func_021CF45C(u16, FieldSys *);
extern void *func_02012EBC(void *);
extern void *func_0200BDB0(void *);
extern void *func_021C31D4(u16, FieldSys *, void *);
extern void func_02189684(FieldSys *, u16);

int func_021881D8(void *sys, FieldSys *p)
{
    void *s;
    int more;
    void *c;
    void *a, *b;
    int t;

    s = func_020120F4(sys);
    more = 1;

    switch (p->state) {
    case 0:
        func_0216447C(s, p->xD0);
        p->x28 = a = func_021901EC(p->id, p->xA4);
        p->x2C = 0;
        p->x30 = func_021BC388(sys, 0x93, a);
        p->xA0 = func_021C7F70(func_02014470(func_02012B38(p->x08)), p->id);
        p->x10 = func_0218E018(func_02013BBC(p->xD0), 0, p->xA4, &p->xF4, p->id);
        p->x40 = func_021AB5F4(p->id, p->x10, p);
        p->x44 = func_021AB7E4(p->id);
        break;
    case 1:
        p->x3C = func_021BB1F4(p->id, p->x10, p->x40, p->x44);
        p->x9C = func_021D33A8(p->id, sys, p, p->xD0);
        a = func_0218DC6C(p->x48);
        func_02189B30(p->xD0, p->x0C, p->x50, func_02012974(p->x08));
        func_02012138(p->x04);
        b = func_021D33F8(p->x9C);
        func_0218B8AC(a, p->xD0, p->x0C, b);
        func_021C6534(p->x130, b);
        func_02189614(s, p, p->xD0);
        break;
    case 2:
        func_02014110(p->xD4, p->xD0, 0, 0, 0, p->xF4.a, p->xF4.b, p->xF4.c);
        func_02012138(p->x04);
        func_0218CEE4(p->x48, p->x50, func_021D33F8(p->x9C));
        t = func_02013C9C(p->xD0);
        if (t != -1) {
            func_021BB2F8(p->x3C, t, p->id);
        }
        p->x104 = func_02189ACC(p->xD0);
        func_021895E8(p, p->xD0, p->id);
        break;
    case 3:
        func_02189204(p);
        p->x94 = func_021ABD50(p, 24, p->id);
        func_021ABF68(p->x94, 94);
        func_021AC1EC(p->x94, func_021D33F8(p->x9C));
        func_021ABE30(p->x94, (u32)data_021D8F10, data_021D8F00);
        if (func_02013CC8(p->xD0) == 1 || func_02013CE0(p->xD0) == 1) {
            p->x98 = func_0217F8C0(p->id);
        }
        break;
    case 4: {
        void *ev = func_020120F8(sys);
        Vec3 *pos;
        c = func_02012AE4(ev);
        pos = (Vec3 *)((u8 *)ev + 4);
        if (func_02012B28(ev) == 1 && func_02013C20(p->xD0) == 0) {
            func_02012B2C(ev, 0);
        }
        p->x8C = func_021A2E50(ev, p, pos, func_02008550(func_02012944(s)), p->id);
        p->xF4 = *pos;
        p->x108->f4(p, &p->xF4, c);
        func_0218D158(p->x48, &p->xF4);
        func_02189758(p->x118);
        p->x34 = func_021BE2A8(60, 35, p->id);
        func_02189154(p->x0C, func_02188C9C(p));
        p->x18 = func_021A0104(p->id);
        p->x1C = func_021A02C4(p->id);
        a = func_02013EEC(p->xD0);
        func_021A0338(p->x1C, a, func_02013F2C(p->xD0), 1);
        a = func_020140DC(p->x0C);
        b = func_0203F4FC();
        p->x14 = func_021A03D0(a, b, func_0202E83C(sys), p->x18, p->xA8, p->id);
        a = func_02012A30(p->x08);
        p->x20 = func_021A19E8(p->x10, p->x14, p->x18, p->x1C, a, func_0202E83C(sys), 0x92);
        func_021A1B74(p->x20, (u16)func_02012994(p->x08), 0x92);
        func_021BE1DC(p);
        break;
    }
    case 5:
        p->x24 = func_021A0CF4(p->id, p, func_020129AC(s));
        break;
    case 6:
        p->x90 = func_021A9ED8(p);
        func_02026388(func_02012138(sys), p);
        p->xBC = func_021BB890(p, p->id, 32);
        p->x120 = b = func_021C1A08(80);
        p->x124 = func_021C1AF4(80, b);
        p->x13C = func_021CF45C(p->id, p);
        p->x128 = func_021C31D4(p->id, p, func_0200BDB0(func_02012EBC(p->x08)));
        func_02189684(p, p->xD0);
        more = 0;
        break;
    }
    p->state++;
    p->x12C = 0;
    if (more) {
        return 0;
    }
    return 1;
}
