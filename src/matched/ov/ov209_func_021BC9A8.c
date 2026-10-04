/*
 * function: func_021BC9A8
 * address: 0x021BC9A8
 * packet: pkt_ov209_021BC9A8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0200CA8C 0x0200CA8C thumb
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_02049238 0x02049238 arm
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045874 0x02045874 arm
 *   func_02045808 0x02045808 arm
 *   data_021BE7AC 0x021BE7AC data a4
 *   data_020A7370 0x020A7370 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Template {u8 head[20];u16 count,pad16;u8 index,pad19;u16 start;u32 p1c,p20;void *p24;};
struct Inputs {u32 p0;void *save;u16 pad8,count;u16 *ids;};
struct Context {struct Inputs *in;u8 pad4[0xc2c-4];void *list;u32 padc30;u32 visible;};
extern const struct Template data_021BE7AC;
extern void *data_020A7370;
extern void *func_020490F4(u32,u16);
struct Blk37;
struct MsgBank;
struct U16Vec;
extern u16 func_0200CA8C(struct Blk37 *p);
extern void *func_021B7754(struct Template *,u32);
extern void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void func_02049238(void *);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
void func_021BC9A8(struct Context *p)
{
    struct Template tmpl;
    void *arc,*str;
    u32 species,i;
    arc=func_020490F4(159,0x806b);
    species=func_0200CA8C((*(struct Inputs **)p)->save);
    tmpl=data_021BE7AC;
    tmpl.count=649;tmpl.p24=p;
    for(i=0;i<(*(struct Inputs **)p)->count;i++){
        if(species==(*(struct Inputs **)p)->ids[i]){
            if(i>(*(struct Inputs **)p)->count-7){
                tmpl.index=i-((*(struct Inputs **)p)->count-7);
                tmpl.start=i-tmpl.index;
            }else if(i<7){tmpl.index=i;}
            else{tmpl.start=i;}
            break;
        }
    }
    p->list=func_021B7754(&tmpl,107);
    if(p->in->count<7)p->visible=p->in->count;else p->visible=7;
    func_021B7A10(p->list,(u32)arc,66,0,0);
    func_021B7A10(p->list,(u32)arc,67,0,1);
    func_021B7A10(p->list,(u32)arc,68,0,2);
    func_021B7A4C(p->list,arc,48,2,3);
    func_02049238(arc);
    for(i=0;i<(*(struct Inputs **)p)->count;i++){
        if(func_0200CED4((*(struct Inputs **)p)->save,(*(struct Inputs **)p)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs **)p)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=func_02045874(str,107);
            func_02045808(str);
            func_021B79E4(p->list,0,0x20000000|(*(struct Inputs **)p)->ids[i]);
        }else if(func_0200D064((*(struct Inputs **)p)->save,(*(struct Inputs **)p)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs **)p)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=func_02045874(str,107);
            func_02045808(str);
            func_021B79E4(p->list,1,0x10000000|(*(struct Inputs **)p)->ids[i]);
        }else{
            *(void **)((u32)p+i*4+0x4c)=func_02045EC0(*(void **)((u8 *)p+0x3c),7);
            func_021B79E4(p->list,2,(*(struct Inputs **)p)->ids[i]);
        }
    }
}
