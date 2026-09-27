/*
 * function: func_021DEFAC
 * address:  0x021DEFAC
 * packet:   pkt_021DEFAC
 * region:   ov121
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02012944  0x02012944  thumb
 *   sub_020084F4   0x020084F4  thumb
 *   sub_02008530   0x02008530  thumb
 *   sub_02008550   0x02008550  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   gMsgBank       0x020A7370  data
 *   d_0209DF08     0x0209DF08  data
 *   d_0209DF0C     0x0209DF0C  data
 *   tbl_021DFB2C   0x021DFB2C  data  ov121  a4
 *
 * True extent 0x021DEFAC..0x021DF4F0 (0x544 bytes: code + the inline pool at
 * 0x021DF33C + the tail pool at 0x021DF4E4), NOT the enumerator's 3156 bytes,
 * which run to the region end through an unrelated static data tail.
 *
 * WIP first draft; see docs/notes/ov121-lane-func_021DEFAC.c.txt.
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): still DIFF, 1065 concrete bytes.
 * The whole body is still being reconstructed (frame 0x50 vs 0x4c and every
 * window offset shifted); no promotion attempted this pass.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;

struct Src {
    u32 f00;
    u32 f04;
    u32 f08;
    u16 f0c;
    u16 f0e;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
    u8  f1c;
    u8  f1d;
    u16 f1e;
    u8  pad20[0x14];
    u8  f34;
    u8  f35;
    u8  f36;
    u8  f37;
    u16 f38;
    u16 f3a;
    u8  f3c;
    u8  f3d;
    u8  f3e;
    u8  f3f;
    u8  f40;
    u8  f41;
    u8  f42;
    u8  f43;
    u8  f44;
    u8  f45;
    u8  f46;
    u8  f47;
    u8  f48;
    u8  f49;
    u16 f4a;
    u8  pad4c[0xe];
    u8  f5a;
    u8  f5b;
    u8  f5c;
    u8  pad5d[3];
    u16 f60[0x25];
    u8  pad_aa[2];
    u32 fac;
    u16 fb0;
    u8  padb2;
    u8  fb3;
};

struct Mon;

extern u16 func_02045A98(void);
extern u32 func_020056EC(int a0);
extern u8 *func_02012944(void *p);
extern u32 sub_020084F4(u8 *p);
extern u32 sub_02008530(const void *p);
extern u8  sub_02008550(const void *p);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 sub_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, u32 move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void func_020307B0(void *p);
extern void func_020185F0(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020185C4(void *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *sub_02045EC0(void *bank, u32 index);
extern void sub_02045808(void *vec);

extern void *gMsgBank;
extern u8 d_0209DF08;
extern u8 d_0209DF0C;
extern u32 tbl_021DFB2C[];

s32 func_021DEFAC(struct Src *p, void *a1, u16 a2)
{
    s32 v18, v1c, v20, v24, v28, v2c, v30, v34, v38;
    s32 cnt = 0;
    u8 buf[0x10];
    s32 x;
    u32 packed;
    void *mon;
    void *flag;
    s32 i;
    s32 found = 1;
    s32 zero = 0;

    for (i = 0; i < 0x25; i++) {
        if (func_02045A98() == p->f60[i])
            found = zero;
    }
    if (found != 0)
        cnt++;

    if (p->fb0 >= 0x800)
        cnt++;

    if (p->fb3 == 0 || p->fb3 >= 4)
        cnt++;

    switch (p->fb3) {
    case 1:
        v20 = p->f5b;
        v18 = p->f00;
        v24 = p->f1a;
        v30 = p->f35;
        v34 = p->f36;
        buf[0] = p->f43;
        buf[1] = p->f44;
        buf[2] = p->f45;
        buf[3] = p->f47;
        buf[4] = p->f48;
        buf[5] = p->f46;
        ((u16 *)(buf + 6))[0] = p->f12;
        ((u16 *)(buf + 6))[1] = p->f14;
        ((u16 *)(buf + 6))[2] = p->f16;
        ((u16 *)(buf + 6))[3] = p->f18;

        if (p->fb3 != 1)
            goto fail;
        if (v24 > 0x289)
            goto fail;
        if (v24 == 0)
            goto fail;
        if (v20 > 0x64)
            goto fail;
        if (p->f10 > 0x272)
            goto fail;

        if (v20 == 0)
            v20 = (func_020056EC(0x64) + 1) & 0xffff;
        if (p->f00 == 0)
            v18 = sub_02008530(func_02012944(a1));

        if (v30 == 0xff)
            v30 = 2;

        for (i = 0; i < 6; i++) {
            if (buf[i] == 0xff)
                buf[i] = func_020056EC(0x20);
        }

        v1c = 0;
        mon = func_020173F0((u16)v24, v20, (u64)(u32)v18, a2);

        packed = ((buf[5] & 0x1f) << 25) | ((buf[4] & 0x1f) << 20)
               | ((buf[3] & 0x1f) << 15) | ((buf[2] & 0x1f) << 10)
               | ((buf[1] & 0x1f) << 5) | (buf[0] & 0x1f);

        if (v34 == 4)
            v34 = func_020056EC(3) & 0xff;

        switch (v34) {
        case 0: x = 0; break;
        case 1: x = 1; break;
        case 2: x = 0; break;
        case 3: x = 2; break;
        default: goto fail;
        }

        if (p->f08 == 0) {
            if (p->f37 == 0) {
                v2c = 0;
                v28 = func_020186C8(v18, (u16)v24, p->f1c, v30, x, 0);
            } else if (p->f37 == 1) {
                v28 = func_020186C8(v18, (u16)v24, p->f1c, v30, x, 2);
                v2c = 0;
            } else if (p->f37 == 2) {
                v28 = func_020186C8(v18, (u16)v24, p->f1c, v30, x, 1);
                v2c = 0;
            }
        } else {
            v28 = p->f08;
            v2c = 0;
        }

        func_02017588((struct Mon *)mon, p->f1a, v20, (u64)(u32)v18, packed,
                      ((u64)(u32)v2c << 32) | (u32)v28);
        func_02017E40(mon, 6, p->f10);
        func_02017FA8(mon);

        for (i = 0; i < 4; i++) {
            u16 id = ((u16 *)(buf + 6))[i];

            if (id != 0 && id < 0x230) {
                if (sub_0201808C(mon, id) == 0xffff)
                    func_020180F4(mon, id);
            }
        }

        if (p->f08 == 0 && v34 == 2)
            func_02018A00(mon, v24, p->f1c);

        func_02017E40(mon, 0x6f, p->f1c);

        if (p->f0e != 0 && p->f0e <= 0x19)
            func_02017E40(mon, 0x98, p->f0e);
        else
            func_02017E40(mon, 0x98, 4);

        if (p->f3c != 0)
            func_02017E40(mon, 0x99, p->f3c);
        func_02017E40(mon, 0x13, p->f3d);
        func_02017E40(mon, 0x14, p->f3e);
        func_02017E40(mon, 0x15, p->f3f);
        func_02017E40(mon, 0x16, p->f40);
        func_02017E40(mon, 0x17, p->f41);
        func_02017E40(mon, 0x18, p->f41);

        for (i = 0; i < 0xf; i++) {
            if (p->f0c & (1 << i))
                func_02017E40(mon, tbl_021DFB2C[i], 1);
        }

        func_02017E40(mon, 0x77, p->f04 != 0 ? p->f04 : d_0209DF08);
        func_02017E40(mon, 0xc, p->f1d != 0 ? p->f1d : d_0209DF0C);

        if (p->f1e == 0)
            goto fail_free;

        if (func_02045A98() != p->f1e)
            func_02017E40(mon, 0x74, p->f1e);

        if (p->f34 == 0xff)
            func_02017E40(mon, 0x70, func_020056EC(0x19) & 0xff);
        else
            func_02017E40(mon, 0x70, p->f34);
        func_02017E40(mon, 0x95, p->f38);
        func_02017E40(mon, 0x96, p->f3a);

        if (p->f4a == 0)
            goto fail_free;

        if (func_02045A98() != p->f4a)
            func_02017E40(mon, 0x8e, p->f4a);
        else
            func_02017E40(mon, 0x8e, sub_020084F4(func_02012944(a1)));

        if (p->f5a > 2)
            func_02017E40(mon, 0x9a, sub_02008550(func_02012944(a1)));
        else
            func_02017E40(mon, 0x9a, p->f5a);

        if (p->f5c != 0) {
            void *s;

            func_02017E40(mon, 0x4c, 1);
            s = sub_02045EC0(gMsgBank, 0x28a);
            func_02017E40(mon, 0x73, (u32)s);
            func_02045808(s);
            func_02017E40(mon, 9, 0xa);
        }

        v38 = (p->fac >> 16) & 0xffff;
        func_020185F0(mon);
        func_0202F2AC(mon, p->f5c != 0 ? p->f38 : p->f3a,
                      v38 - 0x7d0, (p->fac >> 8) & 0xff, p->fac & 0xff);
        func_020185C4(mon);

        if (func_02017E1C(mon, 3, 0) != 0) {
            func_020307B0(mon);
            flag = 0;
        } else {
            flag = mon;
        }
        goto done;

    case 2:
        v28 = 0;
        if (p->f00 > 0 && p->f00 <= 0x272)
            v28 = (u16)p->f00;
        if ((u16)v28 != 0)
            return cnt;
        cnt++;
        return cnt;

    case 3:
        v28 = 0x30;
        if (p->f00 >= 0x21 && p->f00 <= 0x26)
            v28 = p->f00;
        if ((u16)v28 != 0x30)
            return cnt;
        cnt++;
        return cnt;
    }
    return cnt;

fail:
    flag = 0;
    goto done;
fail_free:
    func_020307B0(mon);
    flag = 0;
done:
    if (flag != 0)
        func_020307B0(flag);
    else
        cnt++;
    return cnt;
}
