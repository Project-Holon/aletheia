/*
 * unit:     no
 * function: func_02062884
 * address:  0x02062884
 * packet:   pkt_02062884
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  02062810 has no witness outside this range
 */

typedef unsigned short u16;
extern int func_020627F0(int *p);
extern int *func_0206285C(int *p, int i);
extern void func_02062810(void *p);
void func_02062884(int *p)
{
    u16 i;
    int base;
    p[1] = (int)((char *)p[1] + (int)p);
    base = func_020627F0(p);
    for (i = 0; i < *(u16 *)p; i++) {
        int *e = func_0206285C(p, i);
        e[1] = (int)((char *)e[1] + base);
    }
    if (p[3] != 0) {
        int *q;
        p[3] = (int)((char *)p[3] + (int)p);
        q = (int *)p[3];
        q[1] = (int)((char *)q[1] + (int)q);
        p[3] = (int)q;
    }
    if (p[5] == 0)
        return;
    p[5] = (int)((char *)p[5] + (int)p);
    func_02062810((void *)p[5]);
}
