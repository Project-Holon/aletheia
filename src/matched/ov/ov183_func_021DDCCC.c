/*
 * function: func_021DDCCC
 * address: 0x021DDCCC
 * packet: pkt_ov183_021DDCCC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring the text object before the loop index fixes r4/r5.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_0200DC08 0x0200DC08 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0200DABC 0x0200DABC thumb
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021DE084 0x021DE084 thumb ov183
 *   d_021E338C 0x021E338C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record { u8 a,b,c,d; int value; };
struct Triple { int a,b,c; };
extern const struct Record d_021E338C[];
extern int func_021FC20C(char *),func_021FC214(char *),func_021FC21C(char *);
struct U16Vec;
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
typedef unsigned int   u32;
struct U16Vec;
struct WordSet;
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC7C4(char *,void *,void *,u16);
extern int func_0200DC08(int),func_02045EC0(int,int),func_0200DABC(int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(void *,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern int func_021FC124(int,int,struct Triple *);
extern void func_021DE084(char *,void *,const char *,unsigned,short,short,u16);
void func_021DDCCC(char *p,char *q)
{
 int first,second,third,v,text;
 void *obj;
 int i;
 char *slot;
 const struct Record *rec;
 struct Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),13,*(u16 *)(p+0x7c));
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; slot=p+i*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  if(i==4){
   v=func_0200DC08(*(int *)(q+0x10));
   text=func_02045EC0(second,rec->value);
   obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
   func_0201EFA4((void *)third,0,v,2,1,1);
   func_0201F250((void *)third,obj,(void *)text);
   func_02045808((struct U16Vec *)text);
  }else obj=(void *)func_02045EC0(second,rec->value);
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  func_02045808((struct U16Vec *)((int)obj));
 }
 v=func_0200DABC(*(int *)(q+0x10));
 func_021FC124(*(int *)(q+8),13,&triple);
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}
