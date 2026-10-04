/*
 * function: func_021DB1BC
 * address: 0x021DB1BC
 * packet: pkt_ov119_021DB1BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021E4AA4 0x021E4AA4 thumb ov119
 *   func_021DB4B4 0x021DB4B4 thumb ov119
 *   func_021DB7AC 0x021DB7AC thumb ov119
 */
extern int func_021E4DBC(char *);
extern int func_021D8AF4(int,char *);
extern int func_021D8B0C(int,int);
typedef unsigned int   u32;
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021E4AA4(int,int);
extern int func_021DB4B4(int);
extern void func_021DB7AC(char *,int,int);
int func_021DB1BC(char *p,int kind)
{
    int index=func_021E4DBC(p);
    int outer;
    for(outer=0;outer<*(int *)(p+0x634);outer++) {
        int inner;
        index++;
        if(index>=*(int *)(p+0x634)) index=0;
        for(inner=0;inner<5;inner++) {
            int a=func_021D8AF4(index,p);
            int b=func_021D8B0C(index,inner);
            int obj=(int)func_021D8DD0((void *)(*(int *)(p+0x828)),a,b,p);
            if(obj && func_021E4AA4(func_02017E88((void *)obj,0xab,0),kind) && !func_02017E88((void *)obj,0x4c,0)) {
                *(short *)(p+0x1080)+=1;
                *(short *)(p+0x107c)=func_021DB4B4(index)-0x20;
                *(int *)(p+0x1084)=1;
                func_021DB7AC(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}
