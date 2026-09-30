/*
 * function: func_021D6720
 * address: 0x021D6720
 * packet: pkt_ov123_021D6720
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6C48 0x021D6C48 thumb ov123
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Pos { short x,y; };
struct Pair { int a,b; };
extern const struct Pos d_021DA730;
extern const struct Pair d_021DA750;
extern void func_021D6C48(u8 *, int, void *);
extern void func_0204B404(void *, struct Pos *, u16);
extern void func_0204B5AC(void *, struct Pair *);
extern void func_0204B92C(void *, unsigned int);
extern void func_0204B3DC(void *, unsigned int);
extern void func_0204B688(void *, unsigned int);
extern void func_0204B570(void *, unsigned int);
void func_021D6720(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    func_021D6C48(p,i,*(void **)(p+0xb4));
    h = *(void **)(p+0xb4);
    pos = d_021DA730; pair = d_021DA750;
    func_0204B404(h,&pos,0); func_0204B5AC(h,&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}
