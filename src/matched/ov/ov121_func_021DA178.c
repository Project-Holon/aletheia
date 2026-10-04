/*
 * function: func_021DA178
 * address: 0x021DA178
 * packet: pkt_ov121_021DA178
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern int func_0201C6C4(u32,u32);
extern void func_02045334(u32);
typedef signed int     s32;
struct Obj;
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020350(struct Obj *obj, u32 what);
int func_021DA178(char *p)
{
    u32 q = *(u32 *)(p+4);
    int r;
    if (*(u8 *)(p+12)) {
        if (func_0201C6C4(q,(u32)func_02045770((struct Descriptor *)*(u32 *)(p+8))) == 0) {
            func_02045334(*(u32 *)(p+8));
            *(u8 *)(p+12)=0;
        }
    }
    r=func_020200CC(*(void **)(p+16));
    if (r == -2) r=func_02020350(*(void **)(p+16),2)-1;
    return r;
}
