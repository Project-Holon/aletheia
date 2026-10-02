/*
 * function: func_021D38E0
 * address: 0x021D38E0
 * packet: pkt_ov093_021D38E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A declared one-word S local assigned from c[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast S lvalue at
 * c+2 compiled 30 bytes with the wrong frame and redundant address add.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6034 0x021D6034 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9934(char *, u8);
typedef struct { int x; } S;
extern void func_021D6034(u8 *, int, S);
int func_021D38E0(u32 *a, int b, u32 *c)
{
    int m;
    S s;

    m = func_021B9934((char *)a[1], c[0]);
    s.x = c[2];
    func_021D6034((u8 *)m, c[1], s);
    return 1;
}
