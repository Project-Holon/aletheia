/*
 * function: func_021BBC38
 * address: 0x021BBC38
 * packet: pkt_ov206_021BBC38
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB4E0 0x021BB4E0 thumb ov206
 *   func_021BBAB0 0x021BBAB0 thumb ov206
 *   func_021BBDA8 0x021BBDA8 thumb ov206
 *   func_021BAA4C 0x021BAA4C thumb ov206
 */
typedef unsigned short u16;
typedef struct S {
    char pad0[8];
    int f8;
    u16 fc;
    u16 fe;
    char pad10[0xd0];
    int fe0;
    char pad[0x190 - 0xe4];
} S;
extern void func_021BB4E0(S *, int, int);
extern void func_021BBAB0(S *, int, int, int);
extern void func_021BBDA8(S *, int);
extern void func_021BAA4C(S *);
void func_021BBC38(S *p)
{
    func_021BB4E0(p, 6, p->fe0);
    func_021BBAB0(p, p->fc, p->fe, *(int *)((char *)p + 0x190));
    func_021BBDA8(p, p->f8);
    func_021BAA4C(p);
}
