/*
 * function: func_021DED58
 * address: 0x021DED58
 * packet: pkt_ov170_021DED58
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEB40 0x021DEB40 thumb ov170
 *   func_02021640 0x02021640 thumb
 *   func_021DEB90 0x021DEB90 thumb ov170
 *   func_02041B6C 0x02041B6C arm
 */
extern void func_021DEB40(char *p, int a, int b);
extern void func_02021640(void *p, int a, int b, int c, int d, int e, unsigned short f);
extern void func_021DEB90(char *p, int a, int b, int c, int d);
extern void func_02041B6C(unsigned bit);
typedef struct {
    char pad[0xA178];
    signed char box;
    unsigned char flip;
} Work;
#define WORK(p) (*(Work **)((p) + 0x2C))
void func_021DED58(char *p, int a)
{
    int offset;
    int bank;
    if (WORK(p)->flip == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    WORK(p)->flip ^= 1;
    func_021DEB40(p, a, offset);
    func_02021640(*(void **)((char *)WORK(p) + 0x6C), 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    func_021DEB90(p, a, WORK(p)->box, offset, bank);
    func_02041B6C(3);
}
