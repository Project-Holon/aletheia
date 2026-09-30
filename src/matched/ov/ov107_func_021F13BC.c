/*
 * unit: yes
 * function: func_021F13BC,func_021F13E8,func_021F13F4,func_021F13F8,func_021F1400
 * address: 0x021F13BC
 * packet: pkt_ov107_021F13BC
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F6E28 0x021F6E28 data ov107 a1
 *   d_021F6EE8 0x021F6EE8 data a4
 */
typedef unsigned short u16;
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
extern const char d_021F6E28[];
extern int d_021F6EE8[];
void *func_021F13BC(void *a,char *p)
{
    if(!*(void **)(p+0x14)) *(void **)(p+0x14)=func_02030734(*(u16 *)p,8,1,d_021F6E28,862);
    return *(void **)(p+0x14);
}
void func_021F13E8(int a,int b,int c,char *p){*(u16 *)(p+0x18)|=2;}
void *func_021F13F4(int a,char *p){return *(void **)(p+0x10);}
int *func_021F13F8(void){return d_021F6EE8;}
int func_021F1400(void){return 2;}
