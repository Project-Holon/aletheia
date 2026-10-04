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
#include "../include/Obj02784.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
struct Unk021B8CB0;
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *);
extern void *func_021B86B8(void ***p);
extern int func_021CBB34(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag);
extern int func_021B8724(char *p, void *m);
extern void func_021D6E24(void **p, int value);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
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
    count = func_021B8778(((struct Obj02784 *)p)->f4, (unsigned short)((chosen << 8) | func_021B8D8C(((struct Obj02784 *)p)->f4, ((struct Obj02784 *)p)->f8, func_021D5440(a))), buf);
    for (i = 0; i < count; i++) {
        m = func_021B98A4(*(char *const * *)&((struct Obj02784 *)p)->f8, buf[i]);
        if (!func_021D5B68(m)) { chosen = buf[i]; break; }
    }
    if (!func_021B86B8(((struct Obj02784 *)p)->f4)) {
        if (chosen != 6) {
            result = func_021CBB34(p, a, m, b, &out[1], &out[0]);
            if (result) {
                ((struct Obj02784 *)p)->f14 = 6;
                p[0x784] = chosen;
                flag = func_021B8724(((struct Obj02784 *)p)->f4, m) == 0 ? 1 : 0;
                func_021D6E24(m, b);
            } else { flag = 0; }
            func_021CD4B0(((struct Obj02784 *)p)->fC, 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) func_021CD4B0(((struct Obj02784 *)p)->fC, 0x47, chosen, b);
    return 0;
}
