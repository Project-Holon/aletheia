/*
 * function: func_021BC3E4
 * address: 0x021BC3E4
 * packet: pkt_ov216_021BC3E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 */
typedef struct { unsigned char a,b,c,pad; unsigned short first,second,third; } Config;
extern void func_02082BCC(void *,int,int);
extern signed int func_0204AC18(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned short e, unsigned short f, unsigned short g);
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021BC3E4(unsigned short *p,int *out,const Config *cfg,void *handle)
{
    func_02082BCC(out,0,12);
    out[0]=func_0204AC18(handle,cfg->first,cfg->a,(unsigned short)(cfg->b<<5),0,cfg->c,*p);
    out[1]=func_0204A6C8((void *)handle,cfg->second,0,cfg->a,*p);
    out[2]=func_0204AF28((void *)handle,cfg->third,cfg->third+1,*p);
}
