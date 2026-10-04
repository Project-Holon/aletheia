/*
 * function: func_021BA268
 * address: 0x021BA268
 * packet: pkt_ov213_021BA268
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BA2DE..021BA2E0 is two zero alignment bytes; following021BA2E0 already filed separately.
 * lever: logical owner,a,b,c,zero field order restores stack-load scheduling; const owner and typed destination alone did not.
 * symbols:
 *   func_021B9EE4 0x021B9EE4 thumb ov213
 *   func_020457B0 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_02008550 0x02008550 thumb
 *   func_021BA200 0x021BA200 thumb ov213
 *   func_021B9E80 0x021B9E80 thumb ov213
 *   func_021BA330 0x021BA330 thumb ov213
 */
extern void func_021B9EE4(char *,void *,unsigned char,unsigned char,void *,void *,const void *);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern unsigned func_021BA200(unsigned,unsigned);
extern int func_021B9E80(unsigned);
extern void func_021BA330(void *,int);
typedef struct {const char *owner;void *a,*b;int c;unsigned char kind,index;char pad12[2];unsigned v14;void *v18;unsigned v1C;char sub[48];int v50;} Context;
void func_021BA268(Context *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c)
{
    void *first,*second;
    int value;
    value=c;first=a;second=b;
    p->owner=owner;p->a=first;p->b=second;
    p->c=value;p->v50=0;
    p->kind=kind;p->index=index;
    func_021B9EE4(p->sub,*(void **)owner,kind,index,a,b,owner+10);
    p->v18=func_020457B0(16,116);
    func_02008500(*(void **)(p->owner+4),p->v18);
    p->v14=func_02008550(*(void **)(p->owner+4));
    p->v1C=func_021BA200(kind,index);
    if(func_021B9E80(p->kind)==0) func_021BA330(p,p->c);
}
