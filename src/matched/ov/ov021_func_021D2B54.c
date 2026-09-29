/*
 * function: func_021D2B54
 * address:  0x021D2B54
 * packet:   pkt_ov021_021D2B54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   d_021DD774     0x021DD774  data  ov021
 *   func_02008DFC  0x02008DFC  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021D2CE8  0x021D2CE8  thumb  ov021
 *   func_021D2D24  0x021D2D24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012944(u32 a);
extern u32 func_02158F74(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern void func_0201F02C(u32 ws, u32 i, u32 a);
extern void *func_02012934(u32 a);
extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0201EE60(u32 ws, u32 i, u16 v);
extern void func_0203F4CC(RtcTime *t);
extern u32 func_020056EC(u32 v);
extern u32 func_02012F2C(u32 a);
extern const Entry d_021DD774[];
extern u32 func_02008DFC(u32 p, u32 v);
extern void func_0201EFA4(u32 ws, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_02008550(u32 a);
extern int func_021D2CE8(u32 h, int k);
extern u16 func_021D2D24(u32 h, int k, u32 v);

int func_021D2B54(u32 a, u32 b)
{
    u32 o, h, name, ws, v;
    u16 *out;
    void *party;
    int i, n;
    void *mon;
    RtcTime t;
    int base;
    int k;
    u32 s0, s1;
    u32 tr;
    u32 e0, e1;

    o = func_0215A5F4(b);
    h = func_020120F4(func_0215A5DC(b));
    name = func_02012944(h);
    ws = func_02158F74(o);
    v = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    func_0201F02C(ws, 0, name);
    party = func_02012934(h);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            func_0201EE60(ws, 3, func_02017E1C(mon, 5, 0));
            break;
        }
    }
    func_0203F4CC(&t);
    if (t.minute < 10) {
        base = 0;
        k = func_020056EC(0x1D);
        s0 = 0;
        s1 = 0;
        tr = func_02012F2C(h);
        e0 = d_021DD774[k].a;
        if (e0 != -1) {
            s0 = func_02008DFC(tr, e0);
            func_0201EFA4(ws, 1, s0, d_021DD774[k].c, 0, 1);
        }
        e1 = d_021DD774[k].b;
        if (e1 != -1) {
            s1 = func_02008DFC(tr, e1);
            func_0201EFA4(ws, 2, s1, d_021DD774[k].d, 0, 1);
        }
        if (k < 11) {
            if (e0 != -1 && e1 != -1) {
                if (s0 == 0 || s1 == 0) {
                    k = 0;
                }
            } else if (e1 == -1 && s0 == 0) {
                k = 0;
            }
        }
        if (k < 11) {
            if ((u8)func_02008550(name) == 1) {
                k += 11;
            }
        } else {
            k += 11;
        }
    } else if (t.minute < 0x23) {
        base = 0x28;
        k = func_020056EC(0x32);
    } else {
        base = 0x5A;
        k = func_020056EC(0x50);
    }
    *out = func_021D2D24(h, func_021D2CE8(h, base + k), v);
    return 0;
}
