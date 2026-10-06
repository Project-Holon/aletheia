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
#include "../include/Obj08099.h"
typedef unsigned short u16;
typedef struct { u16 x,y; } Point;
extern void func_020414EC(unsigned);
extern void func_020409B4(unsigned);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void *,const Point *,u16);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021DE0DC(char *p)
{
    Point pt;
    func_020414EC(4);
    func_020409B4(4);
    func_0204B3DC(((struct Obj08099 *)p)->f1C,0);
    pt.x=184;
    pt.y=112;
    func_0204B404(((struct Obj08099 *)p)->f20,&pt,((struct Obj08099 *)p)->f98);
    func_0204B3DC(((struct Obj08099 *)p)->f20,0);
    func_02040588(6,0);
}
