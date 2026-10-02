/*
 * function: func_021F06AC
 * address:  0x021F06AC
 * packet:   pkt_ov033_021F06AC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040618 0x02040618 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0DF0 0x021F0DF0 data ov033 a4
 */

typedef struct {
    unsigned f00;
    unsigned f04[8];
    unsigned f24;
    unsigned f28;
} E;

extern E d_021F0DF0[];
extern void func_02040588(unsigned char, unsigned char);
extern void func_0203FCA0(unsigned char, void *, unsigned char);
extern void func_020414AC(unsigned char);
extern void func_02040618(unsigned char, unsigned, unsigned);
extern void *func_0204B100(unsigned, unsigned, unsigned);
extern void func_0204B270(void *);
extern void func_02043598(unsigned, unsigned);

void func_021F06AC(char *p)
{
    int i;
    unsigned id;
    E *e;
    unsigned j;
    for (i = 4; i <= 7; i++)
        func_02040588(i, 0);
    for (j = 0; j < 2; j++) {
        e = &d_021F0DF0[j];
        id = e->f00;
        func_0203FCA0(id, e->f04, e->f24);
        func_020414AC(id);
        func_02040588(id, e->f28);
        func_02040618(id, 0, 0);
        func_02040618(id, 3, 0);
    }
    *(void **)(p + 0xC) = func_0204B100(8, 0, *(unsigned short *)p);
    func_0204B270(*(void **)(p + 0xC));
    func_02043598(0x10, 1);
}
