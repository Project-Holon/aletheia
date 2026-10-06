/*
 * function: func_021BEEF8
 * address: 0x021BEEF8
 * packet: pkt_ov203_021BEEF8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005E50 0x02005E50 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02031194 0x02031194 arm
 */
typedef struct Task {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task;
struct TcblNode;
extern int func_02005E50(void);
extern void func_02005DE4(void *);
extern int func_02005E64(void),func_02005E9C(void);
typedef unsigned int   u32;
extern void func_02005D28(void);
extern void func_02005D90(int,int);
extern void func_02005DF8(u32 a);
extern void func_02031194(struct TcblNode *);
void func_021BEEF8(struct TcblNode *node,Task *t)
{
    switch(t->done){
    case 0:
        if(func_02005E50()!=0)return;
        ++t->done;
    case 1:
        if(t->a){
            if((unsigned char)t->owner[25]==0){func_02005DE4((void *)1);func_02005E64();t->owner[25]=1;}
        }else {func_02005D28();if(t->mode==1)break;}
        if(t->b){
            if((unsigned char)t->owner[25]!=0){func_02005E9C();func_02005DE4(0);t->owner[25]=0;}
        }else {func_02005D90(t->channel,0xffff);}
        if(t->end!=0)func_02005DF8((unsigned short)t->end);
        break;
    }
    func_02031194(node);
}
