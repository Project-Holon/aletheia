/*
 * function: func_021DBDF4
 * address: 0x021DBDF4
 * packet: pkt_ov121_021DBDF4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02043678 0x02043678 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[51]; } Record;
extern void func_02082BCC(void *,int,int);
struct Bmp;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
void func_021DBDF4(char *out,const Record *src,char *p,u16 heap)
{
    int flags;
    void *text,*other;
    s16 x,y;
    func_02082BCC(out,0,0xdc);
    if(src) {
        *(int *)out=1;
        *(Record *)(out+4)=*src;
        *(void **)(out+0xd0)=func_02043678(10,2,32,heap);
        flags=src->w[43];
        text=func_020457B0(128,heap);
        other=func_02045EC0(*(void **)(p+28),151);
        func_0201EFA4(*(void **)(p+24),0,(u16)(flags>>16),4,1,1);
        func_0201EFA4(*(void **)(p+24),1,(u8)(flags>>8),2,0,1);
        func_0201EFA4(*(void **)(p+24),2,(u8)flags,2,0,1);
        func_0201F250(*(void **)(p+24),text,other);
        x=40;
        x-=(s16)(func_0201D304(text,*(u32 *)(p+16),0)/2);
        y=8-(s16)(func_0201D42C(text,*(void **)(p+16))/2);
        func_0201C7A4(*(void **)(out+0xd0),x,y,text,*(void **)(p+16));
        func_02045808(text);
        func_02045808(other);
    }
}
