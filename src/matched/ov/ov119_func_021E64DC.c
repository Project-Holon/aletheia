/*
 * function: func_021E64DC
 * address: 0x021E64DC
 * packet: pkt_ov119_021E64DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(int,unsigned int,unsigned int);
void func_021E64DC(int p, int i, int j, int x, int y, void *q) {
    Create c;
    c.x=x; c.y=y; c.z=1; c.a=0; c.b=0;
    *(int *)(p+0xf20)=(int)func_0204B294((void *)*(int *)(p+0x9c4),*(int *)(p+i*20+j*4+0x9cc),*(int *)(p+0x87c),*(int *)(p+0x8ac),&c,1,*(u16 *)(p+0x5f4));
    func_0204B6F4(*(int *)(p+0xf20),func_0201BBE8(q),1);
}
