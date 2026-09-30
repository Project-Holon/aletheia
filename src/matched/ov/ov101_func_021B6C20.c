/*
 * function: func_021B6C20
 * address: 0x021B6C20
 * packet: pkt_ov101_021B6C20
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B74B8 0x021B74B8 data a4
 *   func_02031348 0x02031348 arm
 */
typedef struct Row { int a,b; int (*create)(int,int); void (*destroy)(int,int); } Row;
extern const Row d_021B74B8[];
extern void func_02031348(int,int,int,int);
int func_021B6C20(int *p,int index,int heap,int arg)
{
    int result;
    switch(p[1]) {
    case 0:
        if(d_021B74B8[index].create) result=d_021B74B8[index].create(heap,arg);
        else result=0;
        p[2]=result;
        p[1]=1;
        break;
    case 1:
        func_02031348(p[0],d_021B74B8[index].a,d_021B74B8[index].b,p[2]);
        p[1]=2;
        break;
    case 2:
        if(d_021B74B8[index].destroy) d_021B74B8[index].destroy(p[2],arg);
        p[1]=3;
        break;
    case 3:
        p[1]=0;
        return 1;
    }
    return 0;
}
