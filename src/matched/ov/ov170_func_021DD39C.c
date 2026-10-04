/*
 * function: func_021DD39C
 * address: 0x021DD39C
 * packet: pkt_ov170_021DD39C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021DD314 0x021DD314 thumb ov170
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_0201747C 0x0201747C thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 */
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021DD314(void *, int, int);
extern void func_021EDAB0(void *, int);
typedef unsigned int   u32;
struct Mon;
struct Party;
struct PartyMon;
extern void *func_0201747C(struct Mon *p, u32 heap);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_020307B0(void *);
void func_021DD39C(unsigned char *p, unsigned short *q)
{
    void *m;
    m = func_0201747C((struct Mon *)func_021DD2D0((void ***)p,p[0x17],q[2]),0x804c);
    func_0201A98C((*(void ***)p)[2],m);
    func_021DD314(p,p[0x17],q[2]);
    func_020307B0(m);
    func_021EDAB0(p,p[0x17]);
}
