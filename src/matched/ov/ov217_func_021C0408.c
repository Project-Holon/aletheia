/*
 * function: func_021C0408
 * address: 0x021C0408
 * packet: pkt_ov217_021C0408
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 * symbols:
 *   d_021C37FC 0x021C37FC data a4
 *   func_021BF9FC 0x021BF9FC thumb ov217
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Arg { s16 x,y,z; u8 a,b; };
struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };
struct Obj;
extern const struct Entry d_021C37FC[];
extern u32 func_021BF9FC(void *,u32);
extern u32 func_021BF9F0(void *,u32);
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B3DC(struct Obj *,u32);
void func_021C0408(u8 *p)
{
    struct Arg arg;
    const struct Entry *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BF9FC(p,q->c);
        b=func_021BF9F0(p,q->d);
        c=func_021BF9F0(p,q->e);
        d=func_021BF9F0(p,q->f);
        dest=p+i*4;
        *(u32 *)(dest+0x394)=func_0204B294(a,b,c,d,(u32)&arg,q->g,*(u16 *)(p+4));
        func_0204B3DC(*(struct Obj **)(dest+0x394),0);
    }
}
