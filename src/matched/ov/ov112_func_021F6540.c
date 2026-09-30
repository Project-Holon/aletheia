/*
 * function: func_021F6540
 * address: 0x021F6540
 * packet: pkt_ov112_021F6540
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes follow the compiled body.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02063A54 0x02063A54 arm
 *   func_02063E54 0x02063E54 arm
 */
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void func_02030EAC(void *);
extern void func_02063A54(void *,void *,int,void *);
extern void func_02063E54(void *,void *,int,void *);
void func_021F6540(void *a, void **p)
{
    if(p[8]) *(u32 *)((char *)p[8]+236) &= ~4u;
    if(p[4]) { func_02063A54(p[0],p[6],0,p[2]); func_020307B0(p[4]); }
    if(p[1]) { func_02063E54(p[1],p[7],0,p[3]); func_020307B0(p[5]); }
    func_020307B0(p);
    if(a) func_02030EAC(a);
}
