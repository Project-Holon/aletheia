/*
 * function: func_021BD954
 * address: 0x021BD954
 * packet: pkt_ov208_021BD954
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BDD24 0x021BDD24 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };
struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BDD24(char *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BD954(struct Ov208Mgr *m)
{
    func_02030EAC(m->f2c);
    func_021BDD24((char *)m);
    CLACT_DeleteUnit(m->f28);
    func_020307B0(m);
}
