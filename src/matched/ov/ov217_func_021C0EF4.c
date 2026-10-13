/*
 * function: func_021C0EF4
 * address: 0x021C0EF4
 * packet: pkt_ov217_021C0EF4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021C4058 0x021C4058 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Config { u8 a,b,c,d,e,f,g,h; u32 i,j; };
struct Record { struct Config config; u32 a,b,handle,active; };
extern const char d_021C4058[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap)
{
    struct Record *p = func_02030734(heap,32,0,d_021C4058,55);
    p->config = *config;
    p->a=a;
    p->b=b;
    p->handle=BMP_WIN_Create(config->a,config->b,config->c,config->d,config->e,config->h,0);
    p->active=1;
    return p;
}
