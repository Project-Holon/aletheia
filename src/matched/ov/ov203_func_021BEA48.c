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
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   TCBL_DeleteTask 0x02031194 arm
 */
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0208068C(int);
extern void MIi_CpuClearFast(unsigned,void *,unsigned);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *);
void func_021BEA48(int *s,unsigned a,unsigned b,unsigned c)
{
    GX_SetGraphicsMode(a,b,c);func_0208068C(s[0]);
    switch(s[1]){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    default:func_0208068C(0);break;
    }
    TCBL_DeleteTask((struct TcblNode *)s[13]);
}
