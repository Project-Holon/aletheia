/*
 * function: func_021BEA48
 * address: 0x021BEA48
 * packet: pkt_ov203_021BEA48
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: 64 bytes are existing matched func_021BEAB8, pkt_ov203_021BEAB8.
 * symbols:
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   TCBL_DeleteTask 0x02031194 arm
 */
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0208068C(int);
extern void func_02082AC0(unsigned,void *,unsigned);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *);
void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c)
{
    func_0207D4B0(a,b,c);func_0208068C(s[0]);
    switch(s[1]){
    case 2:func_02082AC0(0,(void *)0x06800000,0x20000);break;
    case 6:func_02082AC0(0,(void *)0x06820000,0x20000);break;
    case 10:func_02082AC0(0,(void *)0x06840000,0x20000);break;
    case 14:func_02082AC0(0,(void *)0x06860000,0x20000);break;
    default:func_0208068C(0);break;
    }
    TCBL_DeleteTask((struct TcblNode *)s[13]);
}
