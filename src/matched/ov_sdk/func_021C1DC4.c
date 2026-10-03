/*
 * function: func_021C1DC4
 * address:  0x021C1DC4
 * packet:   pkt_021C1DC4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021BD5A8  0x021BD5A8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D4C68  0x021D4C68  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   dat_021DE59C   0x021DE59C  data
 *   func_021CBC90  0x021CBC90  arm
 *   func_021C2A3C  0x021C2A3C  arm
 */

typedef unsigned char u8;

struct D {
    u8  f0;
    u8  pad01[3];
    int f4;
};

extern int  func_021D5580(int x);
extern void func_021BD5A8(void);
extern void func_021BD138(void);
extern void func_021D4C68(int x);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(void *p);
extern struct D dat_021DE59C;
extern void func_021CBC90(void);
extern void func_021C2A3C(void);

void func_021C1DC4(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (func_021D5580(0) != 0)
        return;
    func_021BD5A8();
    func_021BD138();
    func_021D4C68(dat_021DE59C.f4);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);
    switch (dat_021DE59C.f0) {
    case 0:
        func_021C0E50(1, 0);
        func_021C0E40(func_021CBC90);
        return;
    case 1:
        func_021C0E50(0, 0);
        func_021C0E40(func_021C2A3C);
        return;
    }
}
