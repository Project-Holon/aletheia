/*
 * function: func_02156888
 * address:  0x02156888
 * packet:   pkt_02156888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Build a four-argument request out of the second argument's word and pass
 * the two handles the overlay looked up to the arm9 side.
 *
 * symbols:
 *   func_02158768   0x02158768  thumb  ov010
 *   func_021589D0   0x021589D0  thumb  ov010
 *   func_02012374   0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;
struct Evt;
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_02156888(void *a0, void *a1, int a2)
{
    void *r4 = func_02158768(*(u32 *)a1, a2, 0, 0x15);

    func_021589D0((int)r4);
    func_02012374(a0, r4);
}

