/*
 * function: func_02163418
 * address: 0x02163418
 * packet: pkt_ov010_02163418
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 * symbols:
 *   func_0216DC00 0x0216DC00 thumb ov010
 *   func_021AB41C 0x021AB41C thumb ov021
 *   func_0216D900 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 */
typedef struct { int x, y, z; } V;
typedef struct { char pad[10]; unsigned short f; } S;
extern int func_0216DC00(void *a0);
extern int func_021AB41C(unsigned short);
extern void func_0216D900(int, const V *);
extern V d_021714D0;
static inline void vzero(V *p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}
void func_02163418(int a, S *s)
{
    V v;
    V *pz;
    if (func_0216DC00((void *)a) == 0 && func_021AB41C(s->f) != 0) {
        v = d_021714D0;
        func_0216D900(a, &v);
        return;
    }
    {
        unsigned char buf[12];
        V *z = (V *)buf;
        vzero(z);
        func_0216D900(a, z);
    }
}
