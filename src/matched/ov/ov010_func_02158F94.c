/*
 * function: func_02158F94
 * address: 0x02158F94
 * packet: pkt_ov010_02158F94
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_0216D588 0x0216D588 thumb ov010
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_02158FD0(int a0, u32 a1, int a2);
extern u16 func_0216D588(void *);
void func_02158F94(void *p, void *q, int a2)
{
    *(void **)((char *)p + 8) = q;
    if (q != 0) {
        u16 *r = (u16 *)func_02158FD0((int)p, 0x8011, a2);
        *r = func_0216D588(q);
    }
}
