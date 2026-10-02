/*
 * function: func_02173D00
 * address: 0x02173D00
 * packet: pkt_ov011_02173D00
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_02175F34 0x02175F34 thumb ov011
 *   func_02175914 0x02175914 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_0203D378(void);
typedef unsigned short u16;
typedef struct Ent {
    u16 h[8];
    u8 f10, f11, f12, pad13;
    u8 f14[0x14];
} Ent;
void func_02175F34(void *w, Ent *tbl, u32 arg, int idx);
void func_02175914(int a, int b);

void func_02173D00(u32 a, int b, int *c, u8 *d)
{
    if (func_0203D378()) {
        func_02175F34(d, (Ent *)(d + 0x1ac), a, *c);
        func_02175914((int)(d + 0x1ac), *c);
    }
}
