/*
 * function: func_021B9460
 * address: 0x021B9460
 * packet: pkt_ov093_021B9460
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05 (wave P5, pengy share): EXACT. Needs #pragma opt_lifetimes off (per-function
 * pragma) and the clear of nw written AFTER the func_021BA178 call (l2 = f(...); nw = 0;).
 * Written before the call, the zero took r0 instead of the original r1. Other levers: raw
 * offsets, early locals qs = a + 4 and qo = c * 0x1c, declaration order qo, qs, list, n, v, nw,
 * x, j, i, y, cnt, comma-form loop headers, e = func_0201AB28() as its own statement.
 * symbols:
 *   func_021BA178 0x021BA178 thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021D4D84 0x021D4D84 thumb ov093
 *   func_021B9B54 0x021B9B54 thumb ov093
 *   func_021B9634 0x021B9634 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5848 0x021D5848 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_021B9B60 0x021B9B60 thumb ov093
 *   data_021EFCF0 0x021EFCF0 data ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern const u8 data_021EFCF0[4];
extern void *func_021BA178(void *p, int i, int mode);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_021D4D84(void *a, u8 b, u32 c);
extern void func_021B9B54(void *q, void *v);
extern int func_021B9634(void *a);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D5848(void *p, void *v);
extern void *func_021B86B8(void ***p);
extern u32 func_021D5444(void *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_021B9B60(void *p);
#pragma opt_lifetimes off
void func_021B9460(char *a, char *b, u8 c)
{
    u32 qo;
    char *qs;
    void *list;
    u32 n;
    u8 *v;
    void *e;
    u8 nw;
    u8 x;
    u32 j;
    int i;
    u8 y;
    int cnt;
    list = func_021BA178(b, c, *(u32 *)(a + 0xe4));
    qs = a + 4;
    qo = c * 0x1c;
    n = func_0201AA18(list);
    x = data_021EFCF0[c];
    *(void **)(a + c * 4 + 0x74) = list;
    for (i = 0, y = x; i < n; i++, y++) {
        e = func_0201AB28(list, i);
        *(void **)(a + y * 4 + 0x84) = func_021D4D84(e, y, 0x12);
        func_021B9B54(qs + qo, *(void **)(a + y * 4 + 0x84));
    }
    cnt = func_021B9634(list);
    if (cnt > 0) {
        for (i = 0, y = x; i < cnt; i++, y++) {
                if (func_021D59B4(*(u8 **)(a + y * 4 + 0x84), 0x11) == 0x95)
                    func_021D5848(*(void **)(a + y * 4 + 0x84), func_0201AB28(list, cnt));
            }
    }
    if (func_021B86B8((void ***)b) == 0 && c == 1) {
        for (j = 0; j < n; j++, x++) {
            v = *(u8 **)(a + x * 4 + 0x84);
            if (func_021D5444(v) == 0x23B && func_021D59B4(v, 0x11) == 0x95) {
                void *l2;
                u8 m, q;
                l2 = func_021BA178(b, 0, *(u32 *)(a + 0xe4));
                nw = 0;
                m = func_0201AA18(l2);
                for (q = 0; q < m; q++) {
                    u16 s = func_02017E1C(func_0201AB28(l2, q), 5, 0);
                    if (s == 0xf3) { nw = 0xf4; break; }
                    if (s == 0xf4) { nw = 0xf5; break; }
                    if (s == 0xf5) { nw = 0xf3; break; }
                }
                if (nw != 0) {
                    if (*(void **)(b + 0x2c0) == 0)
                        *(void **)(b + 0x2c0) = func_020173F0(nw, func_021D59B4(v, 0xf), 0, *(u16 *)(b + 0x468));
                    func_021D5848(v, *(void **)(b + 0x2c0));
                }
            }
        }
    }
    func_021B9B60(qs + qo);
}
#pragma opt_lifetimes reset
