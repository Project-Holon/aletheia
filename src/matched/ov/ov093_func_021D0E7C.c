/*
 * function: func_021D0E7C
 * address: 0x021D0E7C
 * packet: pkt_ov093_021D0E7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 * symbols:
 *   func_021D0C78 0x021D0C78 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021D102C 0x021D102C thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021D0B10 0x021D0B10 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CE068 0x021CE068 thumb ov093
 *   func_021D1058 0x021D1058 thumb ov093
 *   func_021D83C4 0x021D83C4 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021E9B14 0x021E9B14 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   func_021D0B6C 0x021D0B6C thumb ov093
 *   func_021D0BB0 0x021D0BB0 thumb ov093
 *   func_021CE0E0 0x021CE0E0 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021EA7FC 0x021EA7FC thumb ov093
 *   func_021EA814 0x021EA814 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;
extern u8 func_021D0C78(void *, u8 *);
extern u8 func_021D0980(u8 *, u8 *);
extern int func_021D102C(u8 *);
struct S2;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern void func_021D8394(void *, u8, u8);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r);
extern void func_021CE068(u8 *);
extern int func_021D1058(u8 *, void *);
extern void func_021D83C4(void *);
extern void func_021D8434(void *);
extern int func_021CE08C(u8 *);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021D0B6C(u8 *g, u8 *s);
extern void func_021D0BB0(u8 *p);
extern void func_021CE0E0(u8 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
int func_021D0E7C(u8 *p, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)p)->count = func_021D0C78(p, p + 0x1B5);
        if (((CountField *)p)->count != 0) {
            n = func_021D0980(p, order);
            if (n != 0) {
                count = ((CountField *)p)->count;
                if (count > n) count = n;
                if (func_021D102C(p) != 0) {
                    mon = func_021B9C00(*(void **)(p + 0x118), 0);
                    if (n == 1 && func_021D5B68(mon) != 0) {
                        func_021D8394(p + 0x124, 0, order[0]);
                        *(u8 **)(p + 0xD8) = p + 0x124;
                        *(int *)(p + 0xDC) = 4;
                        *state = 4;
                        break;
                    }
                }
                func_021B8E28(*(u8 **)p, p[0x1B5], &pair[1], &pair[0]);
                func_021D0B10(p, param, count, p + 0x184, p + 0x190);
                func_021E9A78(*(void **)(p + 0x54), p + 0x184, pair[0], 0, p + 0x190);
                func_021CE068(p);
                *state = 1;
            } else {
                if (func_021D102C(p) != 0 && (mode = func_021D1058(p, p + 0x124)) != 0) {
                    *(int *)(p + 0xDC) = mode;
                    *(u8 **)(p + 0xD8) = p + 0x124;
                    *state = 4;
                } else {
                    func_021D83C4(p + 0x124);
                    *(u8 **)(p + 0xD8) = p + 0x124;
                    *(int *)(p + 0xDC) = 4;
                    *state = 4;
                }
            }
        } else {
            func_021D8434(p + 0x124);
            *(u8 **)(p + 0xD8) = p + 0x124;
            *(int *)(p + 0xDC) = 4;
            *state = 4;
        }
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021E9B14(*(void **)(p + 0x54));
            *state = 2;
        } else if (func_021E9B20(*(void **)(p + 0x54)) != 0) {
            func_021D0B6C(p, p + 0x190);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(*(void **)(p + 0x54)) != 0) {
            func_021D0BB0(p);
            *state = 3;
        }
        break;
    case 3:
        func_021CE0E0(p);
        *state = 4;
        break;
    case 4:
        if (func_021B86C0(*(void **)p) != 0) {
            p[0x1A9] = 1;
            func_021EA7FC(*(void **)(p + 0x54));
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(*(void **)(p + 0x54)) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}
