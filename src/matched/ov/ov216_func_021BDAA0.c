/*
 * function: func_021BDAA0
 * address: 0x021BDAA0
 * packet: pkt_ov216_021BDAA0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDAD8 0x021BDAD8 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Tcbl; struct TcblNode; struct S02030FB4;
typedef void (*TcblFunc)(struct TcblNode *,void *);
typedef struct Work{int arg;u8 *owner;int *counter;} Work;
extern struct TcblNode *func_020311B8(struct Tcbl *,TcblFunc,u32,u32);
extern void *func_02031290(struct S02030FB4 *);
extern void func_02082BCC(void *,u32,u32);
extern void func_021BDAD8(int,int **);
void func_021BDAA0(u8 *p,int arg,int *counter)
{
    Work *work;
    work=func_02031290((struct S02030FB4 *)func_020311B8(*(struct Tcbl **)(p+24),(TcblFunc)func_021BDAD8,12,0));
    func_02082BCC(work,0,12);
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}
