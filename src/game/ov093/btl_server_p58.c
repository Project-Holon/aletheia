/*
 * file:     btl_server_p58.c
 * unit:     yes
 * function: func_021C334C, func_021C3370
 * address:  0x021C334C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C3394 0x021C3394 thumb ov093
 *   func_021C33E8 0x021C33E8 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 */
typedef unsigned char u8;

extern int func_021C3394(u8 *, u8 *, int);
extern void func_021C33E8(int, int, int);
extern int func_021D5B7C(void *);
extern int func_021D5B48(u8 *p);
int func_021C334C(u8 *p, u8 *q, int a, int b);
int func_021C3370(u8 *p, void *q);

int func_021C334C(u8 *p, u8 *q, int a, int b)
{
    if (func_021C3394(p, q, b) == 0) {
        func_021C33E8((int)p, (int)q, a);
        return 1;
    }
    return 0;
}

int func_021C3370(u8 *p, void *q)
{
    if (func_021D5B7C(q) == 0) return 1;
    if (func_021D5B48(q) != 0) return 1;
    return 0;
}
