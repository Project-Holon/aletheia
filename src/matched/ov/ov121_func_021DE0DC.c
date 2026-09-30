/*
 * function: func_021DE0DC
 * address: 0x021DE0DC
 * packet: pkt_ov121_021DE0DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned short u16;
typedef struct { u16 x,y; } Point;
extern void func_020414EC(unsigned);
extern void func_020409B4(unsigned);
extern void func_0204B3DC(void *,unsigned);
extern void func_0204B404(void *,const Point *,u16);
extern void func_02040588(unsigned,unsigned);
void func_021DE0DC(char *p)
{
    Point pt;
    func_020414EC(4);
    func_020409B4(4);
    func_0204B3DC(*(void **)(p+0x1c),0);
    pt.x=184;
    pt.y=112;
    func_0204B404(*(void **)(p+0x20),&pt,*(unsigned *)(p+0x98));
    func_0204B3DC(*(void **)(p+0x20),0);
    func_02040588(6,0);
}
