/*
 * function: func_021CC438
 * address:  0x021CC438
 * packet:   pkt_ov093_021CC438
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CC49C  0x021CC49C  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern int func_021CC49C(void *p, int id);
extern int func_021D5B68(void *m);
typedef signed char    s8;
extern int func_021D5D14(s8 *p, int i, int sign);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);

int func_021CC438(char *p, void *m, int c, u8 d, u32 e)
{
    int id;
    u8 *r;

    id = func_021D5440(m);
    if (func_021CC49C(p + 0x1ab8, id) != 6) {
        if (func_021D5B68(m) == 0 && func_021D5D14(m, e, d) != 0) {
            r = (u8 *)func_021C88A4(p, 14, id);
            r[0xf] = 1;
            r[0x10] = id;
            *(u32 *)(r + 4) = e;
            r[0xc] = d;
            r[0xe] = 1;
            func_021C88C8(p, r);
            return 1;
        }
    }
    return 0;
}
