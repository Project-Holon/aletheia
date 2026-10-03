/*
 * function: func_02158B00
 * address: 0x02158B00
 * packet: pkt_ov010_02158B00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_02158B6C 0x02158B6C thumb ov010
 *   func_02158768 0x02158768 thumb ov010
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012844(void *);
extern const u8 *func_02162450(void *);
extern int func_02158B6C(void *, const u8 *, int);
extern void *func_02158768(void *, u32, u32, u32);
void *func_02158B00(void *a, u32 b) {
    void *s = func_020120F4(a);
    int msg = func_02158B6C(s, func_02162450(func_02012844(s)), 1);
    if (msg == 0xffff) return 0;
    return func_02158768(a, msg, 0, b);
}
