/*
 * function: func_021E30EC
 * address: 0x021E30EC
 * packet: pkt_ov119_021E30EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E2B14 0x021E2B14 thumb ov119
 *   func_02047CFC 0x02047CFC arm
 *   func_02048A24 0x02048A24 arm
 *   d_021E7AF4 0x021E7AF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E7AC4 0x021E7AC4 data a4
 */
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec;
typedef struct {void (*call)(char *);u32 other;} Callback;
extern Vec d_021E7AF4;
extern const s16 d_020A1EB8[];
extern Callback d_021E7AC4[];
extern void func_021E2B14(int);
extern void *func_02047CFC(u16,u16,u16);
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
void func_021E30EC(char *p)
{
    *(u16 *)(p+0x824)=0xffff;
    *(u32 *)(p+0x109c)=~0u;
    func_021E2B14(0x91);
    *(void **)(p+0x820)=func_02047CFC(20,20,0x91);
    if (!*(void **)(p+0x83c)) {
        Vec a={0,0,0};
        Vec b={0,0,0};
        Vec c;
        u16 heap;
        heap=*(u16 *)(p+0x5f4);
        c=d_021E7AF4;
        *(void **)(p+0x83c)=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (*(u32 *)(p+0x109c)!=~0u)
        d_021E7AC4[*(u32 *)(p+0x109c)].call(p);
}
