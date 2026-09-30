/*
 * function: func_021BD264
 * address: 0x021BD264
 * packet: pkt_ov110_021BD264
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_020282AC 0x020282AC thumb
 *   func_021BCD80 0x021BCD80 thumb ov110
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { void *s; u16 x,pad; int flag; } Record;
typedef struct { u8 pad[0x30]; void *bank; void *a[3]; Record records[3]; void *windows[3]; } Object;
extern void *func_02045EC0(void *,unsigned);
extern void *func_02027FEC(void *,void *,u8,int,u8,u16);
extern void func_020282AC(void *,void *,int,int,u16);
extern void func_021BCD80(void *);
extern void func_020409B4(int);
void func_021BD264(Object *p) {
    int i;
    for(i=0;i<3;i++) {
        p->records[i].s=func_02045EC0(p->bank,i+18);
        p->records[i].x=0x39e3;
        p->records[i].flag=i==2;
        p->windows[i]=func_02027FEC(p->a[i],&p->records[i],5+9*i,21,9,42);
        func_020282AC(p->windows[i],p->a[i],8,0x3545,0x7b2c);
    }
    func_021BCD80(p);
    func_020409B4(0);
}
