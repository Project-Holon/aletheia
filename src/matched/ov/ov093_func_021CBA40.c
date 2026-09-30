/*
 * function: func_021CBA40
 * address: 0x021CBA40
 * packet: pkt_ov093_021CBA40
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate six-byte selection and two-byte output arrays reproduce
 * the unaligned stack base; a u16 third parameter pins its early home store.
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8778 0x021B8778 thumb ov093
 *   func_021B98A4 0x021B98A4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021CBB34 0x021CBB34 thumb ov093
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D6E24 0x021D6E24 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(void *);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8778(void *, int, u8 *);
extern void *func_021B98A4(void *, u8);
extern int func_021D5B68(void *);
extern void *func_021B86B8(void *);
extern int func_021CBB34(u8 *, void *, void *, int, u8 *, u8 *);
extern int func_021B8724(void *, void *);
extern void func_021D6E24(void *, int);
extern void func_021CD4B0(void *, u32, ...);
int func_021CBA40(u8 *p, void *a, u16 b)
{
    void *m = 0;
    u8 chosen = 6;
    u8 buf[6];
    u8 out[2];
    u8 count;
    u8 i;
    u8 result;
    u8 flag;
    count = func_021B8778(*(void **)(p + 4), (unsigned short)((chosen << 8) | func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a))), buf);
    for (i = 0; i < count; i++) {
        m = func_021B98A4(*(void **)(p + 8), buf[i]);
        if (!func_021D5B68(m)) { chosen = buf[i]; break; }
    }
    if (!func_021B86B8(*(void **)(p + 4))) {
        if (chosen != 6) {
            result = func_021CBB34(p, a, m, b, &out[1], &out[0]);
            if (result) {
                *(int *)(p + 20) = 6;
                p[0x784] = chosen;
                flag = func_021B8724(*(void **)(p + 4), m) == 0 ? 1 : 0;
                func_021D6E24(m, b);
            } else { flag = 0; }
            func_021CD4B0(*(void **)(p + 12), 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) func_021CD4B0(*(void **)(p + 12), 0x47, chosen, b);
    return 0;
}
