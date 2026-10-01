/*
 * function: func_021E131C
 * address: 0x021E131C
 * packet: pkt_ov119_021E131C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 heap;u8 count;u8 pad[3];const void *items;u32 flag;u8 x,y,a,b;} Template;
extern void *func_020457B0(int,u16);
extern void func_02045CAC(void *,int,void *);
extern void *func_02027778(Template *,void *);
extern void func_02045808(void *);
void func_021E131C(char *p,int *ids,int count,int x,int y)
{
    Template t;
    int i;
    t.heap=*(u16 *)(p+0x5f4);
    t.count=count;
    t.items=p+0x650;
    t.flag=1;
    t.x=x;t.y=y;t.a=13;t.b=3;
    for(i=0;i<count;i++) {
        *(void **)(p+(u32)i*12+0x650)=func_020457B0(100,*(u16 *)(p+0x5f4));
        func_02045CAC(*(void **)(p+0x720),ids[i],*(void **)(p+(u32)i*12+0x650));
        *(u16 *)(p+(u32)i*12+0x654)=0x39e3;
        if(ids[i]==5) *(int *)(p+(u32)i*12+0x658)=1;
        else *(int *)(p+(u32)i*12+0x658)=0;
    }
    *(void **)(p+0x64c)=func_02027778(&t,*(void **)(p+0x6b0));
    for(i=0;i<count;i++) func_02045808(*(void **)(p+(u32)i*12+0x650));
}
