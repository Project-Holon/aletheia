/*
 * function: func_021BA4E8
 * address: 0x021BA4E8
 * packet: pkt_ov214_021BA4E8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor; struct PrintSys;
struct S { u8 pad[0x8C]; struct Descriptor *descriptors[2]; struct Descriptor *other1,*other2; u32 flags[2]; };
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
struct Cfg;
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021BA4E8(void *unused,struct S *p)
{
    u8 i;
    struct Descriptor *d;
    for (i=0;i<=1;i++) {
        if (p->flags[i]==0) {
            if (func_0201C6C4(*(struct PrintSys **)((char *)p+0x10),func_02045770(p->descriptors[i]))==0) {
                d=p->descriptors[i];
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                p->flags[i]=1;
            }
        }
    }
    if (*(u32 *)((char *)p+0xA4)==0) {
        if (func_0201C6C4(*(struct PrintSys **)((char *)p+0x14),func_02045770(p->other1))==0) {
            d=p->other1;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            *(u32 *)((char *)p+0xA4)=1;
        }
    }
    if (*(u32 *)((char *)p+0xA8)==0) {
        if (func_0201C6C4(*(struct PrintSys **)((char *)p+0x18),func_02045770(p->other2))==0) {
            d=p->other2;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            *(u32 *)((char *)p+0xA8)=1;
        }
    }
}
