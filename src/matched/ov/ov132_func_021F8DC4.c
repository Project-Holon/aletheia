/*
 * function: func_021F8DC4
 * address: 0x021F8DC4
 * packet: pkt_ov132_021F8DC4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Vec { int x, y, z; };
struct Slots { u8 pad[0x44]; void *slots[4]; };
extern const struct Vec d_021FDBE0;
extern void *func_021F5164(u32);
struct Object;
extern void func_021F5438(void **p, int b);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern void *func_021F709C(u16,void *,void *,void *,u32);
extern void *func_021F760C(void *,void *);
extern void func_021F8054(void *,void *,const struct Vec *);
void func_021F8DC4(u8 *p)
{
    struct Vec pos;
    u8 i;
    pos = d_021FDBE0;
    *(void **)(p+0x34)=func_021F5164(*(u16 *)p);
    func_021F5438(*(void **)(p+0x34),0x20000);
    *(void **)(p+0x38)=func_021F48C0(*(u32 *)(p+0xac),36,*(u16 *)p);
    *(void **)(p+0x40)=func_021F709C(*(u16 *)p,p,*(void **)(p+0x34),*(void **)(p+0x38),*(u32 *)(p+0xac));
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=func_021F760C(*(void **)(p+0x40),*(void **)(*(u8 **)(p+0x30)+4+i*4));
        func_021F8054(*(void **)(p+0x40),((struct Slots *)p)->slots[i],&pos);
        pos.z-=0x1e000;
    }
}
