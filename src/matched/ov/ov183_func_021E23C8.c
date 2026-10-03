/*
 * function: func_021E23C8
 * address: 0x021E23C8
 * packet: pkt_ov183_021E23C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3900 0x021E3900 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct MsgBank; struct U16Vec; struct WordSet;
typedef struct { u8 a,b,c,d; void *value; } Rec;
typedef struct { u32 index; u8 f4[8]; char *owner; u8 f10[8]; u32 base; } Input;
extern const Rec d_021E3900[];
extern void *func_021FD12C(int,int,u16);
extern struct WordSet *func_021FC21C(char *);
extern int func_021FC214(char *);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201EE0C(struct WordSet *,u32,const void *,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_021FD19C(void *,char *,void *);
extern void func_02045808(struct U16Vec *);
extern void func_021FB964(int,int,u16);
extern int func_021FC20C(char *);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
void func_021E23C8(char *p,const Input *q) {
    struct WordSet *ws;
    struct U16Vec *str,*expanded;
    int font,bank,i;
    const Rec *r;
    char *slot;
    u32 tmp1,tmp;
    u16 *tmp2;
    if(!*(void **)(p+4)) *(void **)(p+4)=func_021FD12C((int)q->owner,*(int *)p,*(u16 *)(p+28));
    ws=func_021FC21C(q->owner);
    str=func_02045EC0((struct MsgBank *)func_021FC214(q->owner),321);
    tmp2=(u16 *)(p+28);
    expanded=func_020457B0(128,*tmp2);
    tmp1=q->base;
    tmp=q->index;
    func_0201EE0C(ws,0,*(void **)(q->base+tmp*4+16),
        *(u32 *)(tmp1+tmp*4+32),1,2);
    func_0201F250(ws,expanded,str);
    func_021FD19C(*(void **)(p+4),q->owner,expanded);
    func_02045808(expanded); func_02045808(str);
    func_021FB964((int)q->owner,30,*(u16 *)(p+28));
    font=func_021FC20C(q->owner);
    bank=func_021FC214(q->owner);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i]; slot=p; slot=slot+i*4;
        *(void **)(slot+12)=func_021FC6A4(4,r->a,r->b,r->c,r->d,14,*(void **)p,*(u16 *)(p+28));
        func_021FC754(*(char **)(slot+12),(void *)bank,r->value,(void *)font,0x3da0);
    }
}
