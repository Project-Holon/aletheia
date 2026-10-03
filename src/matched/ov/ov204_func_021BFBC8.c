/*
 * function: func_021BFBC8
 * address: 0x021BFBC8
 * packet: pkt_ov204_021BFBC8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204784C 0x0204784C arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned short u16;
extern void *func_02048A18(void *,int);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);
void func_021BFBC8(char *p,unsigned value)
{
    void *ctl;
    int frame;
    float f;
    ctl=func_02048A18(*(void **)(p+8),*(u16 *)(p+16));
    if(value!=0) f=0.5f+(float)(value<<12);
    else f=(float)(value<<12)-0.5f;
    frame=(int)f;
    func_0204784C(ctl,0,&frame);
    func_0204784C(ctl,1,&frame);
    func_0204784C(ctl,2,&frame);
}
