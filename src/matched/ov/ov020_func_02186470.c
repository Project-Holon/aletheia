/*
 * function: func_02186470
 * address:  0x02186470
 * packet:   pkt_ov020_02186470
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 (wD9r lane166): EXACT. The tests use the items local (items + i * 0x18), the body
 *   calls spell the address again as base + 8 + i * 0x18, as in the matched siblings ov010 02161DC4
 *   and ov020 021862A8 (a = p + 8 for the tests, p + 8 + i * 0x18 for the result). The second spelling
 *   is a separate invariant in the if body; LICM probably hoists it before the (u16)id conversion, so the
 *   items web is a late temp that interferes with id and takes r4 (a0 r4, id r5 as in the image).
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02186BA8  0x02186BA8  thumb
 *   func_02013DE0  0x02013DE0  thumb
 *   func_02186B2C  0x02186B2C  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020127A4(int a);
extern u32 func_02012AC8(u32 p);
extern char *func_020127C4(int a);
extern int func_02161ECC(char *p);
extern int func_02186BA8(char *p);
extern int func_02013DE0(u16 id);
extern void func_02186B2C(char *q, char *src);
extern void func_02161E78(char *p);
extern void func_02161E60(char *p, int a);

void func_02186470(int a0)
{
    char *q;
    u32 id;
    char *base;
    char *items;
    u16 key;
    int i;

    id = func_02012AC8(func_020127A4(a0));
    base = func_020127C4(a0);
    i = 0;
    q = base + 0xF8;
    items = base + 8;
    key = id;
    for (; i < 10; i++) {
        if (func_02161ECC(items + i * 0x18) != 0 && func_02186BA8(items + i * 0x18) != 0 && func_02013DE0(key) == 0) {
            func_02186B2C(q, base + 8 + i * 0x18);
            func_02161E78(base + 8 + i * 0x18);
        }
    }
    func_02161E60(base, 0);
}
