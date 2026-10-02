/*
 * function: func_021E40EC
 * address: 0x021E40EC
 * packet: pkt_ov119_021E40EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   d_021E7DD0 0x021E7DD0 data a4
 */
typedef struct { unsigned int w[2]; } Tbl2;
extern const Tbl2 d_021E7DD0;
extern void *func_020490F4(unsigned int, unsigned int);
extern void func_02049990(void *, unsigned int, int, int, int, int, int, int);
extern void func_02040618(int, int, int);
extern void func_0204B3DC(int, int);
extern void func_02049238(void *);
extern void func_02040588(int, int);
void func_021E40EC(char *p, int a1, int a2)
{
    Tbl2 tbl = d_021E7DD0;
    void *v;
    v = func_020490F4(0x66, *(unsigned short *)(p + 0x5F4));
    func_02049990(v, tbl.w[a2], 4, 0, (unsigned short)*(unsigned int *)(p + 0x870), 0, 0, *(unsigned short *)(p + 0x5F4));
    if (a1 != 0) {
        func_02040618(4, 0, 0x80);
    } else {
        func_02040618(4, 0, 0);
    }
    func_0204B3DC(*(int *)(p + 0xF04), 0);
    func_02049238(v);
    func_02040588(4, 1);
}
