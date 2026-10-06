/*
 * function: func_0217B810
 * address: 0x0217B810
 * packet: pkt_ov018_0217B810
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0217B82C 0x0217B82C thumb ov018
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0217B82C();
extern void func_02082BCC(void *, int, int);
extern void *func_021A3074(u8 *p);
void *func_0217B810(void *a, u8 *pos) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B82C, 0x20);
    p = func_020124E8(t);
    return t;
}
