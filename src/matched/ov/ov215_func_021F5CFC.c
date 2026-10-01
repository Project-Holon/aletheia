/*
 * function: func_021F5CFC
 * address: 0x021F5CFC
 * packet: pkt_ov215_021F5CFC
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_021F67B0 0x021F67B0 thumb ov215
 *   func_021F62C8 0x021F62C8 thumb ov215
 *   func_021F6114 0x021F6114 thumb ov215
 *   func_021F5E38 0x021F5E38 thumb ov215
 *   func_021F5DA8 0x021F5DA8 thumb ov215
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021F6474 0x021F6474 thumb ov215
 * Empty 5DA8 still receives both visibly loaded arguments.
 */
typedef unsigned int u32;
extern void func_021F67B0(u32);
extern void func_021F62C8(u32,char *);
extern void func_021F6114(u32,char *);
extern void func_021F5E38(u32,char *);
extern void func_021F5DA8(u32,char *);
extern void func_02030EAC(u32);
extern void func_0201C6EC(u32);
extern void func_0201C4C0(u32);
extern void func_0201D83C(u32);
extern void func_021F6474(u32);
void func_021F5CFC(u32 a,char *p)
{
    func_021F67B0(*(u32 *)(p+128));
    func_021F62C8(a,p);
    func_021F6114(a,p);
    func_021F5E38(a,p);
    func_021F5DA8(a,p);
    func_02030EAC(*(u32 *)(p+40));
    func_0201C6EC(*(u32 *)(p+12));
    func_0201C4C0(*(u32 *)(p+12));
    func_0201D83C(*(u32 *)(p+8));
    func_021F6474(*(u32 *)(p+4));
}
