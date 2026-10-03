/*
 * function: func_021DDE2C
 * address: 0x021DDE2C
 * packet: pkt_ov183_021DDE2C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021DE000 0x021DE000 thumb ov183
 *   func_021DE02C 0x021DE02C thumb ov183
 *   func_021DE058 0x021DE058 thumb ov183
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E336C 0x021E336C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Position { short x,y,z;u8 a,b; };
struct Triple { int a,b,c; };
struct Record { u8 a,b,c,d;int value; };
extern const struct Record d_021E336C[];
extern void func_021FBE54(char *,unsigned,unsigned),func_021FB964(int,int,int);
extern int func_021FC20C(char *),func_021FC214(char *);
extern void *func_02082BCC(void *,int,unsigned);
extern int func_021FC124(int,int,struct Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(int,u8,u8,u8,u8,u8,void *,u16);
extern int func_021DE000(int,int),func_021DE02C(int,int),func_021DE058(int,int);
extern void func_021FC754(void *,int,int,int,u16);
void func_021DDE2C(char *p,char *q)
{
 int first,second,i,id;
 struct Triple triple;
 struct Position pos;
 const struct Record *rec;
 char *slot;
 func_021FBE54(*(char **)(q+8),6,*(u16 *)(p+0x7c));
 func_021FB964(*(int *)(q+8),9,*(u16 *)(p+0x7c));
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 func_02082BCC(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 func_021FC124(*(int *)(q+8),6,&triple);
 *(void **)(p+0x20)=func_021FB378(&pos,4,0x60,1,*(int *)(q+4),*(int *)p,first,second,&triple,*(u16 *)(p+0x7c));
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=p+i*4;
  *(void **)(slot+0x24)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  switch(i){
   case 0: if(func_021DE000(*(int *)(q+0x10),*(int *)(q+0x14))) id=0x83;else id=0x7e;break;
   case 1: if(func_021DE02C(*(int *)(q+0x10),*(int *)(q+0x14))) id=0x84;else id=0x7f;break;
   case 2: if(func_021DE058(*(int *)(q+0x10),*(int *)(q+0x14))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  func_021FC754(*(void **)(slot+0x24),second,id,first,0x3da0);
 }
}
