/*
 * function: func_021DF1DC
 * address: 0x021DF1DC
 * packet: pkt_ov183_021DF1DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045924 0x02045924 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_021FCDAC 0x021FCDAC thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FCE50 0x021FCE50 thumb ov186
 *   func_021DF428 0x021DF428 thumb ov183
 *   func_021DF620 0x021DF620 thumb ov183
 *   d_021E3700 0x021E3700 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {void *text;int id;} Item;
typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config;
typedef struct {u32 w[10];} CfgTpl;
typedef struct {u32 a,b;} Slot;
typedef struct {Slot *list;void *view;void *words;u32 c,d;u8 pad[0xbc];char *base;} Menu;
extern const CfgTpl d_021E3700;
typedef signed short   s16;
struct Bmp;
struct CharBuf;
struct MsgBank;
struct State;
struct StrObj;
struct Strbuf;
struct U16Vec;
struct WordSet;
extern unsigned func_021FC20C(char *);
extern int func_021FC214(char *p);
extern void func_02082BCC(void *,u32,u32);
extern struct WordSet *func_0201EC64(u32 heap);
extern Slot *func_0201F81C(u32,u32);
extern void *func_021FC8C8(const Config *,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_021FCDAC(u8 *p, u16 i, u32 v);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FCE50(char *p);
extern void func_021DF428(struct State *p, u32 mgr, u16 heap);
extern void func_021DF620(struct State *p, int first, short step, u16 heap);
void func_021DF1DC(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap)
{
    unsigned first,second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    Config cfg;
    first=func_021FC20C(res);
    second=func_021FC214(res);
    func_02082BCC(p,0,0xd4);
    p->base=base;
    p->words=func_0201EC64(heap);
    p->c=a5;
    p->d=a6;
    p->list=func_0201F81C(*(u32 *)(base+0x1718),heap);
    for(i=0;i<*(int *)(base+0x1718);i++)p->list[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(Item *)p->list;
    cfg.count=*(u32 *)(base+0x1718);
    cfg.resources=res;
    cfg.manager=mgr;
    cfg.cursor=p->c;
    cfg.other=p->d;
    cfg.selection=sel;
    p->view=func_021FC8C8(&cfg,heap);
    buf1=func_020457B0(0xff,heap);
    msg=func_02045EC0((struct MsgBank *)second,0x7a);
    buf2=func_020457B0(0xff,heap);
    for(i=0;i<*(int *)(base+0x1718);i++){
        bmp=func_02043678(cfg.width,cfg.spacing,0x20,heap);
        func_02043B5C(bmp,0);
        func_0201EFA4(p->words,0,i+1,2,0,1);
        func_0201F250(p->words,buf1,msg);
        func_02045924(buf2,(const u16 *)(base+i*0xc4));
        func_0201C7D0(bmp,(short)(16-func_0201D304(buf1,first,0)),4,buf1,(void *)first,0x3DA0);
        func_0201C7D0(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        func_021FCDAC(p->view,(u16)i,(u32)bmp);
    }
    func_02045808(buf2);
    func_02045808(buf1);
    func_02045808(msg);
    func_021FCE50(p->view);
    func_021DF428((struct State *)p,mgr,heap);
    for(i=0;i<*sel;i++)func_021DF620((struct State *)p,i+1,1,heap);
}
