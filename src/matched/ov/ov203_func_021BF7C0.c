/*
 * function: func_021BF7C0
 * address: 0x021BF7C0
 * packet: pkt_ov203_021BF7C0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BF8E8 0x021BF8E8 thumb ov203
 *   func_021BF964 0x021BF964 thumb ov203
 *   d_021C3D4C 0x021C3D4C data a4
 */
typedef struct {unsigned short heap,alternate;int config;int ended;int done;int previous;int index;char flags[4];char *owner;int task;int text;int assets;int extra;} Context;
extern Context *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_021BF8E8(Context *);
extern int func_021BF964(Context *,char *,int *);
extern const char d_021C3D4C[];
Context *func_021BF7C0(char *owner,unsigned heap)
{
    Context *p;
    p=func_02030734(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=*(int *)(owner+0x78);p->previous=-1;
    func_021BF8E8(p);
    p->ended=func_021BF964(p,owner,&p->index);
    return p;
}
