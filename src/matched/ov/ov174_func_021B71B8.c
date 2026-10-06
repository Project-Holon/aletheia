/*
 * function: func_021B71B8
 * address: 0x021B71B8
 * packet: pkt_ov174_021B71B8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B7380 0x021B7380 data ov174 a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u8 x,y; } Pair;
extern const Pair d_021B7380[];
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 *func_02012944(void *);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
void func_021B71B8(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    *(u32 *)(q+0x18)=func_020450F0(0,(u8)(d_021B7380[q[0]].x+2),(u8)(d_021B7380[q[0]].y+1),12,2,12,1);
    func_02043B5C(func_02045770(*(void **)(q+0x18)),0);
    func_02045334(*(void **)(q+0x18));
    func_02045374(*(void **)(q+0x18));
    func_020409B4(0);
    s=func_02045EC0(*(void **)(p+0x68),q[2]);
    if(q[2]==0 || q[2]==5){
        dst=func_020457B0(128,*(u16 *)p);
        save=func_02012944(*(void **)(*(u8 **)(p+0x30)+4));
        ws=func_0201EC64(*(u16 *)p);
        func_0201F02C(ws,0,save);
        func_0201F250(ws,dst,s);
        func_02045808(s);
        func_0201ED04(ws);
        s=dst;
    }
    q[7]=func_0201D304(s,*(u32 *)(p+0x60),0);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16)((96-q[7])/2+1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16)((96-q[7])/2-1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16)((96-q[7])/2),2,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16)((96-q[7])/2),0,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16)((96-q[7])/2),1,(u32)s,*(u32 *)(p+0x60),0x400);
    func_02045808(s);
    *(u32 *)(q+0x14)=1;
}
