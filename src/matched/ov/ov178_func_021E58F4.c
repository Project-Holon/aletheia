/*
 * function: func_021E58F4
 * address: 0x021E58F4
 * packet: pkt_ov178_021E58F4
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov175_id 0x000000AF data a1
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021DC200 0x021DC200 thumb ov175
 *   func_021DC240 0x021DC240 thumb ov175
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 */
typedef unsigned short u16;
typedef unsigned long u32;
extern int func_0203CD98(void),func_02157170(void *,void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern char *func_021D9DC8(u32,void *,u32,u16);
extern u32 func_021DC200(char *,u32),func_021DC240(char *,u32);
extern void func_021D9EA0(u32);
extern unsigned char ov067_id[],ov114_id[],ov175_id[];
int func_021E58F4(char **out,u32 *ctx,u32 *state)
{
    if(func_0203CD98()) {
        switch(func_02157170((void *)1,(void *)1)) {
        case 0:break;
        case 1:case 4:ctx[2]=3;return 1;
        case 2:case 3:default:ctx[2]=1;return 1;
        }
    }
    switch(*state) {
    case 0:func_02039C68((struct Link *)func_020399A8(),16,36);++*state;break;
    case 1:if(func_02039CB4((struct Link *)func_020399A8(),16,36))++*state;break;
    case 2:func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);func_02034AC4((int)ov175_id);
        *out=func_021D9DC8(ctx[5],**(void ***)ctx,0,88);++*state;break;
    case 3:func_02039C68((struct Link *)func_020399A8(),17,36);++*state;break;
    case 4:if(func_02039CB4((struct Link *)func_020399A8(),17,36))++*state;break;
    case 5:if(func_021DC200(*out,ctx[3]))++*state;break;
    case 6:if(func_021DC240(*out,ctx[4]))++*state;break;
    case 7:func_02039C68((struct Link *)func_020399A8(),18,36);++*state;break;
    case 8:if(func_02039CB4((struct Link *)func_020399A8(),18,36))++*state;break;
    case 9:func_021D9EA0((u32)*out);*out=0;
        func_02034A5C((int)ov175_id);func_02034A5C((int)ov114_id);func_02034A5C((int)ov067_id);++*state;break;
    case 10:func_02039C68((struct Link *)func_020399A8(),19,36);++*state;break;
    case 11:if(func_02039CB4((struct Link *)func_020399A8(),19,36))return 1;break;
    }
    return 0;
}
