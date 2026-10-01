/*
 * function: func_021BC340
 * address: 0x021BC340
 * packet: pkt_ov110_021BC340
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BC456.
 * lever: struct-indexed fields and id,running,font declaration order.
 * prototype: 021BF708 leaves returned r0 live and forwards the caller's r1 heap input to 0202441C.
 * symbols:
 *   func_021BF708 0x021BF708 thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BC458 0x021BC458 thumb ov110
 *   func_021BC490 0x021BC490 thumb ov110
 *   func_021BC58C 0x021BC58C thumb ov110
 *   func_021BF6F0 0x021BF6F0 thumb ov110
 *   func_021BC5BC 0x021BC5BC thumb ov110
 *   func_021BC484 0x021BC484 thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201D304 0x0201D304 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned u32;
typedef struct { s16 x,y; } Pair;
typedef struct { void *root; u8 *state; u8 pad[0x14]; void *items[2][2]; u8 gap[12]; Pair pos[2]; u16 ids[2]; int count; u8 parser[12]; u16 id; } Obj;
extern void *func_021BF708(u8 *,u32);
extern u32 func_021BAC44(u8 *);
extern void func_021BC458(void *,u8 *);
extern int func_021BC490(void *,void *);
extern void func_0201DD78(u32,u32,u32);
extern void *func_02045770(void *);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern u32 func_0201D304(void *,u32,u32);
extern void func_021BC58C(void *,Pair *);
extern int func_021BF6F0(u8 *,int);
extern void func_021BC5BC(u8 *,void *,Pair *,int,void *);
extern void func_021BC484(void *);
extern void func_02045808(void *);
int func_021BC340(Obj *p,void *desc,u8 bank)
{
    void *str;
    u16 id;
    int running,count,x,y;
    u32 font;
    str=func_021BF708(p->state,42);
    font=func_021BAC44(p->root);
    running=1;
    count=0; y=0; x=0;
    func_021BC458(p->parser,(u8 *)p);
    do {
        switch(func_021BC490(p->parser,str)) {
        case 0:
            func_0201DD78(1,2,15);
            func_0201C7A4(func_02045770(desc),x,y,str,(void *)font);
            x+=func_0201D304(str,font,0);
            break;
        case 1: {
            id=p->id;
            p->ids[count]=id;
            p->pos[count].x=x+50;
            p->pos[count].y=y+8;
            func_021BC58C(desc,&p->pos[count]);
            func_021BC5BC((u8 *)p,desc,&p->pos[count],func_021BF6F0(p->state,id),p->items[count][bank]);
            count++;
            x+=100;
            break;
        }
        case 2: y+=16; x=0; break;
        case 3: running=0; break;
        }
    } while(running);
    func_021BC484(p->parser);
    func_02045808(str);
    return count;
}
