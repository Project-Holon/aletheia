/*
 * function: func_021B6C4C
 * address: 0x021B6C4C
 * packet: pkt_ov172_021B6C4C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6EC4 0x021B6EC4 thumb ov172
 *   func_021B6C78 0x021B6C78 thumb ov172
 *   func_021B6ECC 0x021B6ECC thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021B6EC4(void *, int);
typedef struct Stroke Stroke;
extern void func_021B6C78(u16 *o, const Stroke *e);
extern void func_021B6ECC(void *, u16 *);

void func_021B6C4C(char *p)
{
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) do {
        func_021B6C78((u16 *)p, (const Stroke *)func_021B6EC4(p, *(u16 *)(p + 6)));
        func_021B6ECC(p, (u16 *)(p + 6));
    } while (*(u16 *)(p + 6) != *(u16 *)(p + 4));
}
