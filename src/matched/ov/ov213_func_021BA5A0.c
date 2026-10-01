/*
 * function: func_021BA5A0
 * address: 0x021BA5A0
 * packet: pkt_ov213_021BA5A0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: source kind,a,b emits image a,kind,b stores and both entry copies; source a,kind,b left115 differing bytes.
 * symbols:
 *   func_021BA750 0x021BA750 thumb ov213
 *   func_021BA71C 0x021BA71C thumb ov213
 *   func_0204B3DC 0x0204B3DC arm
 * domain: loop index is exactly 0,1,2; each switch arm initializes both coordinates before use.
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_021BA750(void *,int,u8),*func_021BA71C(void *,int,int,u16);
extern void func_0204B3DC(void *,unsigned);
typedef struct {int pad0;const void *owner;void *other;u16 a,b;void *one,*two,*objects[3];char pad24[2];u8 kind;} Context;
void func_021BA5A0(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind)
{
    int i,x,y;
    p->owner=owner;p->other=other;
    p->kind=kind;p->a=a;p->b=b;
    p->one=func_021BA750((void *)owner,0,p->a);
    p->two=func_021BA750((void *)owner,1,p->b);
    for(i=0;i<3;i++) {
        switch(i) {
        case 0:x=206;y=152;break;
        case 1:x=50;y=40;break;
        case 2:x=128;y=96;break;
        }
        p->objects[i]=func_021BA71C((void *)owner,x,y,7);
        func_0204B3DC(p->objects[i],0);
    }
}
