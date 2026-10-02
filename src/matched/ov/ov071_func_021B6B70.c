/*
 * function: func_021B6B70
 * address: 0x021B6B70
 * packet: pkt_ov071_021B6B70
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
struct Obj;
extern u32 func_0201C6C4(struct PrintSys *, void *);
extern void func_020257D0(struct Obj *);
int func_021B6B70(void **p, u8 *q)
{
    if (q[12] == 1) {
        if (func_0201C6C4(p[2], *(void **)(q + 8)) == 0) {
            func_020257D0(*(struct Obj **)(q + 4));
            q[12] = 0;
            return 1;
        }
    }
    return 0;
}
