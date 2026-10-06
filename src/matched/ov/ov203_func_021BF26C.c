/*
 * function: func_021BF26C
 * address: 0x021BF26C
 * packet: pkt_ov203_021BF26C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDF88 0x021BDF88 thumb ov203
 */
struct Triple{unsigned short x,y,z;};
extern void func_021BDF88(char *p, int a, int b);
void func_021BF26C(unsigned unused,char **q,unsigned *v){struct Triple t;t.x=v[1];t.y=v[2];t.z=v[3];func_021BDF88(*q,(unsigned char)v[0],(int)&t);}
