/*
 * function: func_021BF168
 * address: 0x021BF168
 * packet: pkt_ov203_021BF168
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BF1CC 0x021BF1CC thumb ov203
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 */
typedef struct Task {char *owner;unsigned reserved;unsigned char done;signed char a,b,c;int start,end,count;unsigned index,mask;} Task;
struct Tcbl;struct TcblNode;struct S02030FB4;
extern struct TcblNode *func_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *);
extern void func_02082BCC(void *,int,int);
extern void func_021BF1CC(void *task, char *work);
extern void func_021BEFC4(char *,int,int,int,int,int,int *);
void func_021BF168(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end)
{
    Task *t;
    t=func_02031290((struct S02030FB4 *)func_020311B8(*(struct Tcbl **)(p+32),(void (*)(struct TcblNode *,void *))func_021BF1CC,32,1));
    func_02082BCC(t,0,32);
    t->owner=p;t->a=a;t->b=b;t->c=c;t->index=index;t->mask=63;t->start=start;t->end=end;
    func_021BEFC4(p,t->index,t->mask,a,b,start,&t->count);
}
