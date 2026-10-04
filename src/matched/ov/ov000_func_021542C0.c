/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov000_021542C0
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stage machine on *mode (25 states), same family as ov003 func_021542C0.
 * Pooled small words 0x7B/0x10/0x73/0xAA are linker overlay ids
 * (ov123/ov016/ov115/ov170) handed with a table in that overlay's window.
 * 0x04000208 (IME) and 0x04000304 (POWCNT) are cast hardware constants.
 *
 * 2026-10-04 (wave D2 lane 14): re-checked, still MATCH* with 59 of 60 sites resolved; only
 * ov170_id (+0394) is open. Needs the OVERLAY_ID_CONSUMERS entry below (tools/match.py), not source.
 *
 * Blocker (MATCH, every concrete byte right, 59 of 60 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0x394) has no witness.  It is the id
 * argument (r1) of func_02012444, which is not in OVERLAY_ID_CONSUMERS;
 * func_02012444 (EXACT, arm9) stores its r1 as item[0], and its state
 * machine func_0201240C (EXACT) passes item[0] to func_020120B4's id
 * parameter, so adding 0x02012444 with register 1 to OVERLAY_ID_CONSUMERS
 * in tools/match.py would resolve it as `overlay_id` (integrator's call).
 * No cut helps: the only pool word holding 0xAA is this function's own.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005C18  0x02005C18  thumb
 *   func_02005B24  0x02005B24  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009304  0x02009304  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02012444  0x02012444  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_020121CC  0x020121CC  thumb
 *   ov123_id       0x0000007B  data   a1
 *   ov016_id       0x00000010  data   a1
 *   ov115_id       0x00000073  data   a1
 *   ov170_id       0x000000AA  data   a1
 *   d_021DA674     0x021DA674  data   ov123  a4
 *   d_021DA838     0x021DA838  data   ov123  a4
 *   d_021D77B8     0x021D77B8  data   ov016  a4
 *   d_021D6338     0x021D6338  data   ov115  a4
 *   d_021D654C     0x021D654C  data   ov115  a4
 *   d_021EF78C     0x021EF78C  data   ov170  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef volatile u16   vu16;

extern u32   func_0201210C(u32 a0);
extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void  func_02012374(void *obj, void *out);
extern void *func_020144DC(u32 a0, u32 a1);
extern void  func_02082BCC(void *p, int c, int n);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern u32   func_02005C44(void);
extern void  func_02005C18(void);
extern void  func_02005B24(void);
extern void  func_02005D90(u32 a0, u32 a1);
extern void  func_02005DF8(int x);
extern void *func_020145CC(u32 a0);
extern void  func_02005E9C(void);
extern void  func_02005DE4(int x);
extern void  func_02005E64(void);
extern u32   func_020120F4(u32 a0);
extern u32   func_02012EBC(u32 a0);
extern u32   func_02009448(u32 a0);
extern int   func_02009304(u32 a0);
extern u32   func_0201293C(u32 a0);
extern u32   func_02012934(u32 a0);
extern u32   func_0201292C(u32 a0);
extern u32   func_02012944(u32 a0);
extern int   func_020079A0(u32 a0);
extern u32   func_0200873C(u32 a0);
extern void  func_02012444(void *obj, void *a1, void *a2, void *a3);
extern int   func_0200FB24(void);
extern void  func_0200FB38(void);
extern void  func_0200F7B8(int x);
extern void  func_020121CC(u32 a0);

extern char ov123_id[];
extern char ov016_id[];
extern char ov115_id[];
extern char ov170_id[];
extern char d_021DA674[];
extern char d_021DA838[];
extern char d_021D77B8[];
extern char d_021D6338[];
extern char d_021D654C[];
extern char d_021EF78C[];

#define F(o)  (*(u32 *)(args + (o)))
#define H(o)  (*(u16 *)(args + (o)))
#define B(o)  (*(u8 *)(args + (o)))

u32 func_021542C0(void *obj, u32 *mode, char *args)
{
    u32 h = F(0x0);
    u32 v = func_0201210C(h);
    int r;

    switch (*mode) {
    case 0:
        func_02012374(obj, func_021BE8D4(h, v, 0, 0));
        (*mode)++;
        break;
    case 1:
        func_02012374(obj, func_020144DC(h, v));
        F(0x2c8) = 0;
        *mode = 2;
        break;
    case 2:
        func_02082BCC(args + 0xc, 0, 0x44);
        F(0x50) = 0;
        func_020120B4(h, ov123_id, d_021DA674, args);
        (*mode)++;
        break;
    case 3:
        if (func_020120F0(h) == 0) {
            if (F(0x1c8) == 2)
                *mode = 16;
            else if (F(0x1c8) == 3)
                *mode = 5;
            else
                *mode = 10;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        F(0x1d4) = func_02005C44();
        func_02005C18();
        func_020120B4(h, ov016_id, d_021D77B8, args);
        (*mode)++;
        break;
    case 7:
        if (func_020120F0(h) == 0)
            *mode = 14;
        break;
    case 14:
        {
            vu16 *ime = (vu16 *)0x04000208;
            u16 old = *ime;
            *ime = 1;
            (void)old;
        }
        func_02005B24();
        func_02005D90(F(0x1d4), 0xFFFF);
        func_02005DF8(0x3C);
        *mode = 15;
        break;
    case 15:
        F(0x2c8) = 1;
        *mode = 2;
        break;
    case 10:
        func_02012374(obj, func_020145CC(h));
        (*mode)++;
        break;
    case 11:
        func_02012374(obj, func_021BE92C(h, v, 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 12:
        if (F(0x1cc)) {
            func_02005E9C();
            func_02005DE4(0);
            func_02005DF8(0x3C);
            F(0x1cc) = 0;
        }
        (*mode)++;
        break;
    case 13:
        return 1;
    case 16:
        r = func_02009304(func_02009448(func_02012EBC(func_020120F4(h))));
        if (func_020079A0(func_0201293C(func_020120F4(h))) == 0 && r == 0) {
            F(0x1c8) = 4;
            *mode = 19;
        } else {
            F(0x26c) = 0;
            func_02005DE4(1);
            func_02005E64();
            F(0x1cc) = 1;
            (*mode)++;
        }
        break;
    case 17:
        F(0x268) = (u32)(args + 0x54);
        func_020120B4(h, ov115_id, d_021D6338, args + 0x258);
        (*mode)++;
        break;
    case 18:
        if (func_020120F0(h) == 0) {
            if (F(0x274) == 1) {
                *mode = 10;
            } else {
                if (func_02009304(func_02009448(F(0x8))) == 0) {
                    F(0x1c8) = 3;
                    *mode = 19;
                } else {
                    F(0x1c8) = 0;
                    *mode = 19;
                }
            }
        }
        break;
    case 19:
        func_020120B4(h, ov123_id, d_021DA838, args);
        (*mode)++;
        break;
    case 20:
        if (func_020120F0(h) == 0) {
            if (F(0x1c8) == 1) {
                F(0x2c8) = 0;
                *mode = 2;
            } else if (F(0x1c8) == 5) {
                *mode = 21;
            } else if (F(0x1c8) == 4) {
                *mode = 21;
            } else if (F(0x1c8) == 7) {
                F(0x26c) = 1;
                *mode = 17;
            } else {
                *mode = 23;
            }
        }
        break;
    case 21:
        F(0x29c) = func_020120F4(h);
        F(0x2a0) = func_0201293C(F(0x29c));
        F(0x2a4) = func_02012934(F(0x29c));
        F(0x2a8) = func_0201292C(F(0x29c));
        F(0x2ac) = func_02012944(F(0x29c));
        F(0x2b4) = func_0200873C(func_02012EBC(F(0x29c)));
        F(0x2bc) = (u32)(args + 0x1d8);
        F(0x2b8) = 0;
        F(0x2c0) = 5;
        func_02012444(obj, ov170_id, d_021EF78C, args + 0x29c);
        (*mode)++;
        break;
    case 22:
        if (func_0200FB24()) {
            func_0200FB38();
            func_0200F7B8(0);
            F(0x26c) = 1;
            *mode = 17;
        } else {
            u8 a, b;
            a = B(0x2c6);
            H(0x1d0) = a;
            b = B(0x2c7);
            H(0x1d2) = b;
            if (a == 0xff && b == 0xff) {
                *mode = 23;
            } else {
                if (F(0x1c8) == 4)
                    F(0x1c8) = 2;
                else
                    F(0x1c8) = 1;
                *mode = 19;
            }
        }
        break;
    case 23:
        F(0x280) = func_020120F4(h);
        F(0x284) = 1;
        F(0x288) = 0;
        func_020120B4(h, ov115_id, d_021D654C, args + 0x280);
        (*mode)++;
        break;
    case 24:
        if (func_020120F0(h) == 0) {
            func_020121CC(h);
            *(vu16 *)0x04000304 |= 0x8000;
            F(0x2c8) = 0;
            *mode = 2;
            if (F(0x1cc)) {
                func_02005E9C();
                func_02005DE4(0);
                func_02005DF8(0x3C);
                F(0x1cc) = 0;
            }
        }
        break;
    }
    return 0;
}
