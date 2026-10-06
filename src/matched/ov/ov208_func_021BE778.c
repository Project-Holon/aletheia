/*
 * function: func_021BE778
 * address: 0x021BE778
 * packet: pkt_ov208_021BE778
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE9C8 0x021BE9C8 thumb
 *   func_021BE8FC 0x021BE8FC thumb
 *   func_020307B0 0x020307B0 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };
struct Node;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02030EAC(struct Node *n);
extern void func_021BE9C8(struct Ov208Mgr *m);
extern void func_021BE8FC(char *p);
extern void func_020307B0(void *p);
void func_021BE778(struct Ov208Mgr *m)
{
    func_0201C6EC(m->f2c);
    func_0201C4C0(m->f2c);
    func_02030EAC(m->f28);
    func_021BE9C8(m);
    func_021BE8FC((char *)m);
    func_020307B0(m);
}
