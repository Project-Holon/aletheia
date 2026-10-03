/*
 * function: func_021B6278
 * address: 0x021B6278
 * packet: pkt_ov173_021B6278
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id,value;} Row;
extern const Row d_021B81FC[],d_021B81EC[];
extern u32 func_0201C440(void *);
struct MsgBank;
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021B6278(u8 *p)
{
    int i;
    const Row *r;
    u8 *q;
    *(u32 *)(p+0x218)=func_0201C440((void *)79);
    *(void **)(p+0x1dc)=func_02027F60(4,10,*(u32 *)(p+0x60),*(u32 *)(p+0x218),79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];q=p+i*12;
        *(void **)(q+0x1e4)=func_02045EC0(*(void **)(p+0x44),r->id);
        *(u16 *)(q+0x1e8)=14819;
        *(u32 *)(q+0x1ec)=r->value;
    }
    for(i=0;i<2;i++) {
        r=&d_021B81EC[i];q=p+i*12;
        *(void **)(q+0x1fc)=func_02045EC0(*(void **)(p+0x44),r->id);
        *(u16 *)(q+0x200)=14819;
        *(u32 *)(q+0x204)=r->value;
    }
    *(u32 *)(p+0x220)=0;*(u32 *)(p+0x224)=0;
}
