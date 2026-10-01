/*
 * function: func_021FC014
 * address: 0x021FC014
 * packet: pkt_ov132_021FC014
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0201134C(void *);
extern void *func_021F9DC4(void *, u8);
extern void func_021F9F74(void *, u16, void *);
int func_021FC014(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    struct { int x, y, z; } vec;
    obj = *(char **)p;
    a = func_0201134C(*(void **)(p + 4));
    b = func_0201134C(*(void **)(p + 4));
    c = func_0201134C(*(void **)(p + 4));
    d = func_0201134C(*(void **)(p + 4));
    e = func_0201134C(*(void **)(p + 4));
    target = func_021F9DC4(*(void **)(obj + 0x34), (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    func_021F9F74(target, (u16)b, &vec);
    return 0;
}
