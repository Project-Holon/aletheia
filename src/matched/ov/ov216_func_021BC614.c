/*
 * function: func_021BC614
 * address: 0x021BC614
 * packet: pkt_ov216_021BC614
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
typedef struct {short x,y,z;unsigned char a,b;} Position;
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
unsigned func_021BC614(unsigned short *p,unsigned manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag){Position pos;pos.x=x;pos.y=y;pos.z=z;pos.b=b;pos.a=a;return (unsigned)func_0204B294((void *)manager,r[1],r[0],r[2],&pos,flag,*p);}
