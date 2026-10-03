/*
 * function: func_021DD38C
 * address: 0x021DD38C
 * packet: pkt_ov171_021DD38C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE76C 0x021DE76C thumb ov171
 *   func_021DCBA4 0x021DCBA4 thumb ov171
 *   func_021DCBE8 0x021DCBE8 thumb ov171
 *   func_021DE080 0x021DE080 thumb ov171
 *   func_021DDFBC 0x021DDFBC thumb ov171
 *   func_020434DC 0x020434DC arm
 */
extern void func_021DE76C(char *, int);
extern void func_021DCBA4(char *);
extern int func_021DCBE8(char *);
extern void func_021DE080(char *, int, int);
extern void func_021DDFBC(char *);
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
int func_021DD38C(char *p)
{
    switch (*(int *)(p + 0xc70)) {
    case 0:
        func_021DE76C(p, 0);
        func_021DCBA4(p);
        func_020434DC(2, 0);
        ++*(int *)(p + 0xc70);
        break;
    case 1:
        if (!func_021DCBE8(p)) {
            func_021DE080(p, 12, 4);
            func_021DE080(p, 13, 5);
            func_021DE080(p, 14, 0);
            func_021DDFBC(p);
            *(int *)(p + 0xc70) = 0;
            return 4;
        }
        break;
    }
    return 8;
}
