/*
 * function: func_021F62FC
 * address: 0x021F62FC
 * packet: pkt_ov112_021F62FC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { char pad[200]; Vec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; Vec d,e; } Object;
void func_021F62FC(Object *a,Object *b)
{
    b->a=a->a; b->b=a->b; b->c=a->c;
    b->b0=a->b0; b->b1=a->b1; b->b2=a->b2;
    b->h=a->h; b->d=a->d; b->e=a->e;
}
