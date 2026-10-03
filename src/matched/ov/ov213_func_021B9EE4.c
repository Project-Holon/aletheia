/*
 * function: func_021B9EE4
 * address: 0x021B9EE4
 * packet: pkt_ov213_021B9EE4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: negative constant multiplication keeps Thumb shift/negate/add; unary negation is folded back into constant-minus-shift.
 * symbols:
 * func_0201AA18 0x0201AA18 thumb
 * func_0201AB28 0x0201AB28 thumb
 * func_021B9E50 0x021B9E50 thumb ov213
 * func_021B9E80 0x021B9E80 thumb ov213
 * func_021B9EB0 0x021B9EB0 thumb ov213
 * func_021BA71C 0x021BA71C thumb ov213
 * func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct C {void *owner,*parent; u8 kind,index,n,count; void *obj[6]; int step; u8 active; u8 pad[3]; const u8 *types;};
extern int func_0201AA18(void*);
extern void *func_0201AB28(void*,u32);
extern int func_021B9E50(u32),func_021B9E80(u32);
extern int func_021B9EB0(void*,u32);
extern void *func_021BA71C(void*,int,int,u16);
extern void func_0204B3DC(void*,u32);
void func_021B9EE4(struct C *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types)
{
    int i,x,y,frame;
    void *entry;
    p->kind=kind;p->index=index;p->owner=owner;
    p->n=func_0201AA18(owner);
    if(func_021B9E50(kind))p->count=6;else p->count=3;
    p->parent=parent;p->step=0;p->types=types;
    for(i=0;i<p->count;i++){
        if(func_021B9E50(kind)){
            x=(s16)((i<<4)+0x88);
            y=(s16)(index==0?0xa8:0x38);
            if(index==0)x*=-1;
        }else{
            switch(index){
            case 0:x=(s16)(i * -16+0x50);y=0x88;break;
            case 1:x=(s16)(i * -16+0x90);y=0xb0;break;
            case 2:x=(s16)((i<<4)+0x80);y=0x30;break;
            case 3:x=(s16)((i<<4)+0xc0);y=0x58;break;
            }
        }
        entry=0;
        if(i<p->n)entry=func_0201AB28(owner,i);
        frame=func_021B9EB0(entry,types[i]);
        if(!func_021B9E80(kind)&&frame!=0xd)frame=0xa;
        p->obj[i]=func_021BA71C(a,x,y,(u16)frame);
        if(func_021B9E80(kind))func_0204B3DC(p->obj[i],0);
        else func_0204B3DC(p->obj[i],1);
    }
}
