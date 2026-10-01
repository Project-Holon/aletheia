/*
 * function: func_021B9C00
 * address: 0x021B9C00
 * packet: pkt_ov223_021B9C00
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021B95A0 0x021B95A0 thumb ov223
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 *   d_021BC790 0x021BC790 data a2
 */
typedef unsigned short u16;
struct TableRow { u16 h[5]; };
extern const struct TableRow d_021BC790[];
extern int func_021B95A0(int,int);
extern void *func_021BC52C(void *);
extern void func_02011B8C(void *,void *);
void func_021B9C00(char *p,unsigned index)
{
    u16 value;
    int coordinate;
    value=d_021BC790[index].h[0];
    if(value!=0) coordinate=(int)((float)(value<<12)+0.5f);
    else coordinate=(int)((float)(value<<12)-0.5f);
    func_021B95A0(*(int *)(p+64),coordinate);
    func_02011B8C(func_021BC52C(*(void **)(p+20)),*(void **)(p+64));
    *(unsigned *)(p+68)=index;
    *(int *)(p+72)=0;
    *(unsigned *)(p+76)=value;
}
