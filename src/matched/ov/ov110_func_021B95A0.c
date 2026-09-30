/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov110_021B95A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020247A8 0x020247A8 thumb
 *   func_021B9608 0x021B9608 thumb ov110
 *   func_021B98A0 0x021B98A0 thumb ov110
 *   d_021C3B80 0x021C3B80 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u16,u32,u32,const char *,u32);
extern void *func_020247A8(u32);
extern void func_021B9608(void *);
extern void func_021B98A0(void *);
extern const char d_021C3B80[];
void *func_021B95A0(u32 heap,void *save)
{
    char *p;
    int i;
    p=func_02030734(heap,0x1E50,0,d_021C3B80,88);
    *(void **)p=save;
    *(void **)(p+4)=func_020247A8(heap);
    for(i=0;i<226;i++) *(u8 *)(p+0x1D6E + i)=0;
    func_021B9608(p);
    func_021B98A0(p);
    return p;
}
