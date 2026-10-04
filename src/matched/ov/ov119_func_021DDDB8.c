/*
 * function: func_021DDDB8
 * address: 0x021DDDB8
 * packet: pkt_ov119_021DDDB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDBF0 0x021DDBF0 thumb ov119
 */

typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void func_021DD080(void *a, void *b, void *c);
extern void func_021D8E84(void *,int);
extern void func_021DDBF0(char *p);

void func_021DDDB8(unsigned char *p)
{
    unsigned char v=14;
    if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&v))) {
        func_021DD080(func_020399A8(),(void *)29,p);
        func_021D8E84(p,(int)func_021DDBF0);
    }
}
