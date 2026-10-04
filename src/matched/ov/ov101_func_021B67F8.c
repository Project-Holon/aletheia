/*
 * function: func_021B67F8
 * address: 0x021B67F8
 * packet: pkt_ov101_021B67F8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
struct Data;
extern void func_021B658C(void *p, struct Data *out);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
int func_021B67F8(int *p,int resource)
{
    switch(p[1]) {
    case 0:
        if(resource) func_021B658C((void *)resource,(struct Data *)p[10]); else return 1;
        if(func_021B64B8(p[0],0x1003,44,p[10],255,0,0,1)) p[1]=1;
        break;
    case 1:
        if(p[9]) { p[9]=0; p[1]=0; return 1; }
        break;
    }
    return 0;
}
