/*
 * function: func_021DF9E8
 * address: 0x021DF9E8
 * packet: pkt_ov119_021DF9E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_020173EC 0x020173EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 low:4;u8 high:4; } Flags;
extern unsigned func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_020173EC(void);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern int func_0203D3F8(unsigned,unsigned,u16,unsigned,void *,int,int,int);
int func_021DF9E8(char *p,void *src,int kind)
{
    unsigned id;
    int one;
    id=func_020399A8();
    if(((Flags *)(p+0x11fb))->low) return 0;
    MI_CpuCopy8(src,*(void **)(p+0x106c),func_020173EC());
    one=1;
    if(!func_0203D3F8(id,255,kind,func_020173EC(),*(void **)(p+0x106c),0,0,one)) return 0;
    ((Flags *)(p+0x11fb))->low=one;
    return one;
}
