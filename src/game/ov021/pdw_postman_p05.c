/*
 * file:     pdw_postman_p05.c
 * unit:     yes
 * function: func_021B7C90
 * address:  0x021B7C90
 * packet:   pkt_ov021_021B7C90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B7DE0  0x021B7DE0  thumb
 *   func_021B7EE4  0x021B7EE4  thumb
 *   func_021B8028  0x021B8028  thumb
 *   func_021B80E0  0x021B80E0  thumb
 *   func_021B810C  0x021B810C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Mgr { u8 pad00[0x1C]; u8 *f1C; };

extern void func_021B7EE4(void *p, void *r);
extern void func_021B80E0(void *p, int a, void *key);
struct Sub;
extern void func_021B810C(struct Sub *o);
extern void func_021B8028(void *p, void *q);
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021B7DE0(void *p, void *r);

int func_021B7C90(struct Mgr *m, void *r, void *key, void *q)
{
    func_021B7EE4(m->f1C, r);
    func_021B80E0(m->f1C, 4, key);
    func_021B810C((struct Sub *)m->f1C);
    func_021B8028(m->f1C, q);
    if (func_0203EFC8(r, m->f1C + 0x5C, 8) == 0)
        return 0;
    return func_021B7DE0(m->f1C, m->f1C + 0x5C);
}
