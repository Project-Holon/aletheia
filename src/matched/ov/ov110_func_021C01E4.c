/*
 * function: func_021C01E4
 * address: 0x021C01E4
 * packet: pkt_ov110_021C01E4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C05B0 0x021C05B0 thumb ov110
 *   func_0203133C 0x0203133C arm
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x43 data
 */
extern void func_021C05B0(void *);
struct PrintSys;
struct Rec;
struct S020314B8;
struct S020315D4;
extern void func_0203133C(struct S020314B8 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int);
extern void func_02034A5C(void *);
extern char ov067_id[];
int func_021C01E4(void *p, int a, int b, char *q) {
    func_021C05B0(q);
    func_0203133C(*(void **)(q+0xac));
    func_0201C6EC(*(void **)(q+0x5c));
    func_0201C4C0(*(void **)(q+0x5c));
    func_02045C04(*(void **)(q+0x60));
    func_0201D83C(*(void **)(q+0x58));
    func_020315D4(p);
    func_020306F0(0x51);
    func_02034A5C(ov067_id);
    return 1;
}
