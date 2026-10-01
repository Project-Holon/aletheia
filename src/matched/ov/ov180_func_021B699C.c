/*
 * function: func_021B699C
 * address: 0x021B699C
 * packet: pkt_ov180_021B699C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B69E6.
 * symbols:
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C95C arm
 *   _fdiv 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef struct { int x,y,z; } Vec;
extern void func_02015C30(int,Vec *);
extern void func_02015C48(int,Vec *);
void func_021B699C(char *p,int v) {
    Vec pos;
    float delta;
    func_02015C30(*(int *)(p+28),&pos);
    if(v>0) delta=0.5f*(float)(v<<12);
    else delta=(float)(v<<12)/0.5f;
    pos.x=pos.x+(int)delta;
    func_02015C48(*(int *)(p+28),&pos);
}
