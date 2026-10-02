/*
 * function: func_021BA2E4
 * address: 0x021BA2E4
 * packet: pkt_ov093_021BA2E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: separate per-site product temporaries reproduce the scalar-add operand order.
 * symbols:
 *   func_0201B818 0x0201B818 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021B97A0 0x021B97A0 thumb ov093
 *   func_021B985C 0x021B985C thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021D7F60 0x021D7F60 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B969C 0x021B969C thumb ov093
 *   func_021BA710 0x021BA710 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   data_021EFCF0 0x021EFCF0 data ov093 a1
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B97A0(char *, char *, int);
extern int func_021B985C(char *, int);
extern u32 func_021BA020(char *, int);
extern int func_021D7F60(u32);
extern char *func_021B8714(char **);
extern void func_0201B818(void *, u32, u16);
extern int func_0201AA18(void *);
extern void *func_0201AB28(void *, int);
extern int func_02017E1C(void *, int, int);
extern void func_02017E40(void *, int, int);
extern int func_021D805C(u32, int);
extern void func_0201AC2C(void *, void *);
extern u32 func_021B9064(u8 *, u8, int);
extern void func_021B969C(char *, char *, int, int);
extern u8 func_021BA710(int, int);
extern int func_021B8B9C(u8 *, u8);
extern char *func_021B9AEC(char *, int);
extern u32 func_021B9B94(void *);
extern u8 *func_021B9BF0(void *, u8);
extern u8 func_021D5440(u8 *);
extern int func_021D59B4(u8 *, int);
extern int func_021D5B68(void *);
extern int func_021D62A8(void *);
extern const u8 data_021EFCF0[];
extern u32 _u32_div_f(u32, u32);
void func_021BA2E4(char *p)
{
    void *list;
    u32 n, move, k0, i0, k, slot;
    char *group;
    u32 count, total, maximum, i, base, j, obj;
    void *old, *mon;
    u8 *m;
    u32 tmp, tmp1, tmp2;
    if (*(u8 *)(*(char **)p + 0x23) != 0) return;
    if (*(u32 *)*(char **)p <= 1) {
        func_021B97A0(p + 0x1b0, p, (u8)p[0x46c]);
        list = (void *)func_021B985C(p + 0x1b0, (u8)p[0x46c]);
        if (*(u32 *)*(char **)p == 1 && func_021D7F60((u16)func_021BA020(p, 1)))
            func_0201B818(list, *(u16 *)(func_021B8714((char **)p) + 10), (u16)((*(u16 *)(p + 0x468) & 0x7fff) | 0x8000));
        if (*(u32 *)*(char **)p == 1) {
            n = func_0201AA18(list);
            for (i0 = 0; i0 < n; i0++) {
                old = func_0201AB28(*(void **)(*(char **)p + 0x24), i0);
                mon = func_0201AB28(list, i0);
                move = (u16)func_02017E1C(old, 6, 0);
                if (!func_021D805C(move, 0x10))
                    func_02017E40(mon, 6, move);
                else if (move != func_02017E1C(mon, 6, 0))
                    func_02017E40(mon, 6, 0);
            }
        }
        func_0201AC2C(list, *(void **)(*(char **)p + 0x24));
        for (i0 = 0; i0 < (u32)func_0201AA18(list); i0++) func_0201AB28(list, i0);
    }
    if (*(u32 *)*(char **)p == 0) {
        k0 = (u8)func_021B9064((u8 *)p, (u8)p[0x46c], 0);
        func_021B969C(p + 0x1b0, p, k0, 1);
        func_0201AC2C((void *)func_021B985C(p + 0x1b0, k0), *(void **)(*(char **)p + 0x28));
    }
    if (*(u32 *)*(char **)p == 4) return;
    for (k = 0; k < 4; k++) {
        slot = func_021BA710((u8)p[0x46c], (u8)k);
        for (j = 0; j < 6; j++) { obj = *(u32 *)p; tmp1 = slot * 6; *(u8 *)(j + (tmp1 + obj) + 0xc8) = 0; }
        if (func_021B8B9C((u8 *)p, (u8)slot)) {
            group = func_021B9AEC(p + 0xc8, slot);
            count = func_021B9B94(group);
            total = maximum = 0;
            base = data_021EFCF0[slot];
            for (j = 0; j < count; j++) {
                m = func_021B9BF0(group, (u8)j);
                i = (u8)(func_021D5440(m) - base);
                total += func_021D59B4(m, 13);
                maximum += func_021D59B4(m, 14);
                if (func_021D5B68(m)) { obj = *(u32 *)p; tmp = slot * 6; *(u8 *)(i + (tmp + *(u32 *)p) + 0xc8) = 2; }
                else if (func_021D62A8(m)) { obj = *(u32 *)p; tmp2 = slot * 6; *(u8 *)(i + (tmp2 + obj) + 0xc8) = 1; }
            }
            *(u32 *)(*(char **)p + slot * 4 + 0xe0) = _u32_div_f(total * 100, maximum);
        }
    }
}
