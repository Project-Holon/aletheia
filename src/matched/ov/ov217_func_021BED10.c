/*
 * function: func_021BED10
 * address: 0x021BED10
 * packet: pkt_ov217_021BED10
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing: two alignment bytes at 021BED9A.
 * Lever: compute +8 input subrecord within loop to preserve entry scheduling.
 * symbols:
 *   func_021BF7E0 0x021BF7E0 thumb ov217
 *   func_021BEC34 0x021BEC34 thumb ov217
 *   func_021C10E8 0x021C10E8 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Item { u8 id,pad[3]; u32 value; u8 x,y,z,a,b,c,pad2[2]; };
struct Input { u16 id; u8 x,y,z,pad; u16 a; u32 b; };
extern u32 func_021BF7E0(void *);
extern void func_021BEC34(u32);
extern void func_021C10E8(u8 *p, u8 *tab, int n);
void func_021BED10(u8 *p,int mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+708+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    func_021C10E8((u8 *)object,(u8 *)items,count);
}
