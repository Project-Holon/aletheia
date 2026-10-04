/*
 * function: func_021BB4F4
 * address: 0x021BB4F4
 * packet: pkt_ov110_021BB4F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * lever: signed loop counter; string pointer declared before counter.
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB1F8 0x021BB1F8 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
extern u32 func_021BAC44(u8 *);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021BB1F4(void);
extern void func_021BB1F8(u32,void *);
extern void func_021BB224(u32,int *,int *);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,u32);
extern void func_02045334(struct Descriptor *);
extern void func_02045808(struct U16Vec *vec);
u8 *func_021BB4F4(u8 *p,u8 *q) {
    u32 n,w,a;
    void *str;
    int i;
    int x,y;
    w=func_021BAC44(*(u8 **)p);
    a=func_020450F0(1,1,8,30,14,12,1);
    str=func_020457B0(4,42);
    func_02043B5C(func_02045770((struct Descriptor *)a),15);
    n=func_021BB1F4();
    for(i=0;i<n;i++) {
        func_021BB1F8(i,str);
        func_021BB224(i,&x,&y);
        func_0201DD78(1,2,15);
        func_0201C7A4(func_02045770((struct Descriptor *)a),x+5,y,str,w);
    }
    func_02045334((struct Descriptor *)a);
    func_02045808(str);
    p+=0x90;
    *(u32 *)p=a;
    return q+0x1a4;
}
