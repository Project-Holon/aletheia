/*
 * function: func_021BBBD8
 * address: 0x021BBBD8
 * packet: pkt_ov206_021BBBD8
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 */
typedef struct S {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
void func_021BBBD8(S *p, int i)
{
    if (p->b[i] != 0) {
        func_0204B3B4(p->b[i]);
        func_0204A8D4((u32)p->a[i]);
        p->b[i] = 0;
    }
}
