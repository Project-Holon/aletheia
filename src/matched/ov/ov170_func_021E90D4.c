/*
 * function: func_021E90D4
 * address: 0x021E90D4
 * packet: pkt_ov170_021E90D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021DE728 0x021DE728 thumb ov170
 *   func_021EC94C 0x021EC94C thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 */
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021DE728(unsigned char *p);
extern void func_021EC94C(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED55C(char **p, int flag);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E90D4(unsigned char *p)
{
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021DE728(p);
    func_021EC94C(*(char **)(WORK(p) + 0xA190));
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    return 0x5A;
}
