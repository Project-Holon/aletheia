/*
 * function: func_021DA038
 * address: 0x021DA038
 * packet: pkt_ov121_021DA038
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const source parameter and the original heap stack argument to 0201F878.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   d_021DF78C 0x021DF78C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 word[13];} Config;
extern const char d_021DFBA0[];
extern const Config d_021DF78C;
struct Cfg;
struct Descriptor;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
extern void *func_020450F0(u8,u16,u16,u8,u8,u8,u8);
extern void func_0201F73C(void *,int,int,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(void *,u32,u32,u32,u16);
extern void *func_0201FF30(Config *,u16,u16,u32);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u8 v);
void *func_021DA038(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    func_02082BCC(out,0,24);
    *(u32 *)(out+4)=*(u32 *)(p+8);
    *(void **)out=func_020450F0(*(u16 *)(p+0x1c),19,(u8)(17-(u8)(*(u32 *)(p+0x18)*2)),12,(u8)(*(u32 *)(p+0x18)*2),*(u16 *)(p+0x1e),1);
    func_0201F73C(*(void **)out,2,*(u16 *)(p+0x22),*(u16 *)(p+0x20));
    q=*(void **)out;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    *(void **)(out+8)=*(void **)out;
    out[12]=0;
    *(void **)(out+20)=func_0201F81C(*(u32 *)(p+0x18),heap);
    for(i=0;i<*(u32 *)(p+0x18);i++)
        func_0201F878(*(void **)(out+20),*(u32 *)p,*(u32 *)(p+12+i*4),i,heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)(out+20);
    *(u16 *)((u8 *)&cfg+0x10)=*(u32 *)(p+0x18);
    *(u16 *)((u8 *)&cfg+0x12)=*(u32 *)(p+0x18);
    cfg.word[3]=*(u32 *)out;
    cfg.word[9]=*(u32 *)p;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=*(u32 *)(p+8);
    cfg.word[12]=*(u32 *)(p+4);
    *(void **)(out+16)=func_0201FF30(&cfg,0,0,heap);
    func_02020CF8(*(void **)(out+16),heap);
    func_02020D10(*(void **)(out+16),0);
    return out;
}
