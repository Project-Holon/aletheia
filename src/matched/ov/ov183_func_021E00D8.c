/*
 * function: func_021E00D8
 * address: 0x021E00D8
 * packet: pkt_ov183_021E00D8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u32 words[10];} Config;
typedef struct {int a,b,c;} Triple;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
typedef struct {u8 a,b,c,d;u16 file;} Record;
typedef struct Slot Slot;
extern const Config d_021E3780;
extern const Record d_021E372E[];
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(int,int,u16);
extern Slot *func_0201F81C(u32,u32);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FC21C(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FC8C8(Config *,u32);
extern void func_02082BCC(void *,u32,u32);
extern int func_021FC124(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
int func_021E00D8(char *p,char *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char **)(q+8));
    second=func_021FC214(*(char **)(q+8));
    func_021FB964(*(int *)(q+8),28,*(u16 *)(p+0x54));
    text=func_020457B0(128,*(u16 *)(p+0x54));
    v=func_02012944(*(void **)(q+0x10));
    a=func_0200856C(v);b=func_02008570(v);
    ws=func_021FC21C(*(char **)(q+8));
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    func_02045808(data);
    *(Slot **)(p+0x14)=func_0201F81C(1,*(u16 *)(p+0x54));
    func_0201F898(*(Slot **)(p+0x14),(u32)text,0,*(u16 *)(p+0x54));
    func_02045808(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)(p+0x14);cfg.words[1]=1;
    cfg.words[5]=*(u32 *)(q+8);cfg.words[6]=*(u32 *)(q+4);
    *(void **)(p+0x18)=func_021FC8C8(&cfg,*(u16 *)(p+0x54));
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)(q+8),6,&triple);
    params.a=d_021E372E[0].a;params.b=d_021E372E[0].b;params.c=d_021E372E[0].c;params.flag=1;
    *(void **)(p+0xc)=func_021FB378(&params,d_021E372E[0].file,96,1,*(int *)(q+4),*(int *)(p+0x44),first,second,&triple,*(u16 *)(p+0x54));
    return 1;
}
