/*
 * function: func_021BBE34
 * address: 0x021BBE34
 * packet: pkt_ov206_021BBE34
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BBDA8 0x021BBDA8 thumb ov206
 */
typedef struct S {
    char pad0[8];
    int f8;
    char pad0c[0xac - 0xc];
    void *last[2];
    int index;
} S;
extern void func_0204B3DC(void *, int);
extern void func_021BBDA8(S *, int);
void func_021BBE34(S *p, int v)
{
    func_0204B3DC(p->last[p->index], v);
    if (p->f8 == 0)
        v = 0;
    func_021BBDA8(p, v);
}
