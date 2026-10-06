/*
 * function: func_021BC30C, func_021BC348
 * unit: yes
 * trailing: parent-cleared Thumb follower 021BC348 is movs r0,#13; bx lr.
 * address: 0x021BC30C
 * packet: pkt_ov223_021BC30C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB3AC 0x021BB3AC thumb ov223
 *   func_021BAEE0 0x021BAEE0 thumb ov223
 *   func_021BAB74 0x021BAB74 thumb ov223
 *   func_021B9848 0x021B9848 thumb ov223
 *   func_021BC498 0x021BC498 thumb ov223
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 */
extern int func_021BB3AC(int *);
extern void func_021BAEE0(char *p);
extern void func_021BAB74(int *);
extern void func_021B9848(int *);
extern void func_021BC498(unsigned *);
struct Node;
extern void func_02030EAC(struct Node *n);
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *);
int func_021BC30C(int *p)
{
    func_021BB3AC(p); func_021BAEE0((char *)p); func_021BAB74(p); func_021B9848(p);
    func_02030EAC((void *)p[8]); func_0201C6EC((struct PrintSys *)p[7]); func_0201C4C0((struct PrintSys *)p[7]);
    func_0201D83C((void *)p[6]); func_021BC498((unsigned *)p[5]);
    return 13;
}
int func_021BC348(void) { return 13; }
