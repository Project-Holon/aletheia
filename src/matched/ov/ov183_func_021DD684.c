/*
 * function: func_021DD684
 * address: 0x021DD684
 * packet: pkt_ov183_021DD684
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 the clamp is written n = (n > 9999) ? 9999 : n; the extra reads change the spill slot order of select, number1, number2 (was 10 bytes off with the if form).
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021DE000 0x021DE000 thumb ov183
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_0200DB44 0x0200DB44 thumb
 *   func_0200DAC4 0x0200DAC4 thumb
 *   func_0200DAD8 0x0200DAD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_0200DABC 0x0200DABC thumb
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021DE084 0x021DE084 thumb ov183
 *   d_021E33C0 0x021E33C0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record{u8 a,b,c,d;int value;};
struct Triple{int a,b,c;};
extern const struct Record d_021E33C0[];
typedef unsigned int   u32;
struct Blk1AC;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern int func_021DE000(void *p, char *q);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u16 func_0200DAD8(struct Blk1AC *p, u32 i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FC7C4(char *,void *,void *,u16);
extern u16 func_0200DABC(struct Blk1AC *p);
extern int func_021FC124(int,int,struct Triple *);
extern void func_021DE084(char *,void *,const char *,unsigned,short,short,u16);
void func_021DD684(char *p,char *q)
{
 int first,second,third,index,v;
 const struct Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 struct Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),10,*(u16 *)(p+0x7c));
 select=func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];slot=p+index*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  func_021FC868(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?0x83:0x7e);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  func_02045808(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 func_021FC124(*(int *)(q+8),13,&triple);
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}
