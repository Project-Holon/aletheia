/*
 * function: func_021DD380
 * address: 0x021DD380
 * packet: pkt_ov119_021DD380
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   d_021E80E0 0x021E80E0 data a4
 */
typedef unsigned short u16;
extern void *func_02030734(u16,int,int,void *,u16);
extern int func_020173EC(void);
extern void func_02082D44(void *,const void *,int);
extern const char d_021E80E0[];
void func_021DD380(char *p,int i,void *src)
{
    *(int *)(p+0xfb0+i*4)=i; *(int *)(p+0xfc8+i*4)=i; if(*(void **)(p+0xfe4+i*4)==0) *(void **)(p+0xfe4+i*4)=func_02030734(*(u16 *)(p+0x5f4),func_020173EC(),1,(void *)d_021E80E0,0x122);func_02082D44(src,*(void **)(p+0xfe4+i*4),func_020173EC());
}
