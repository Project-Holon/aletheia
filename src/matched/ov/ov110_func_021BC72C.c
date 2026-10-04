/*
 * function: func_021BC72C
 * address: 0x021BC72C
 * packet: pkt_ov110_021BC72C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC578 0x021BC578 thumb ov110
 *   func_021BC69C 0x021BC69C thumb ov110
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Pt { s16 a, b, x, y; };
extern void func_021BC578(void *src, struct Pt *out);
extern void func_021BC69C(void *p, u32 v);
extern void func_0204B404(void *obj, s16 *pos, u32 flag);
void func_021BC72C(char *p, u32 i)
{
    struct Pt t;
    if (*(u32 *)(p + 0x44) != 0) {
        func_021BC578(p + 0x38 + i * 4, &t);
        t.x = t.a;
        t.y = t.b;
    } else {
        t.x = 0x80;
        t.y = 0x18;
    }
    func_0204B404(*(void **)(p + 0x14), &t.x, 0);
    t.y += 0xC0;
    func_0204B404(*(void **)(p + 0x18), &t.x, 1);
    func_021BC69C(p, 1);
}
