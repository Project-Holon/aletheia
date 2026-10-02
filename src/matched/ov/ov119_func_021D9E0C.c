/*
 * function: func_021D9E0C
 * address: 0x021D9E0C
 * packet: pkt_ov119_021D9E0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9DC4 0x021D9DC4 thumb ov119
 */

typedef unsigned short u16;

extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021D8E84(void *,int);
extern void func_021D9DC4(void *);
void func_021D9E0C(char *p)
{
    int v = 0;
    if (*(int *)(p+0xF88) == *(int *)(p+0x630)) v=1;
    if (func_0203D3A8(func_020399A8(),0xC16,1,&v))
        func_021D8E84(p,(int)func_021D9DC4);
}
