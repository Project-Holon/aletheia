/*
 * function: func_021F74F8
 * address: 0x021F74F8
 * packet: pkt_ov135_021F74F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F7964 0x021F7964 thumb ov135
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_021F79EC 0x021F79EC thumb ov135
 *   func_021F7840 0x021F7840 thumb ov135
 *   func_021F76BC 0x021F76BC thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 */
typedef unsigned char u8;
extern void func_021F7964(u8 *p);
extern void func_021F99D0(u8 *p);
extern void func_021F79EC(void *p);
extern void func_021F7840(void *p);
extern void func_021F76BC(void);
extern void func_022000E4(void *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021F4EC8(u8 *p);
int func_021F74F8(u8 *p)
{
    func_021F7964(p);
    func_021F99D0(*(void **)(p + 0xDE4));
    func_021F79EC(p);
    func_021F7840(p);
    func_021F76BC();
    func_022000E4(p);
    func_0204B3DC((struct Obj *)*(unsigned *)(p + 0xD38), 0);
    func_021F4EC8(p);
    return 0;
}
