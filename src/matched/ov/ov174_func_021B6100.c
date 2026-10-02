/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov174_021B6100
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Store the two one-valued fields before committing the task handle; scheduler hoists its store after movs r1,#1.
 * symbols:
 *   func_021B63DC 0x021B63DC thumb ov174
 *   func_021B655C 0x021B655C thumb ov174
 *   func_021B6594 0x021B6594 thumb ov174
 *   func_021B6760 0x021B6760 thumb ov174
 *   func_021B63B0 0x021B63B0 thumb ov174
 *   func_020490F4 0x020490F4 arm
 *   func_021B6C70 0x021B6C70 thumb ov174
 *   func_020056A0 0x020056A0 thumb
 *   func_02012984 0x02012984 thumb
 *   func_02011400 0x02011400 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct RtcTime{unsigned hour,minute,second;};
extern void func_021B63DC(u8 *),func_021B655C(u8 *),func_021B6594(u8 *),func_021B6760(u8 *),func_021B63B0(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_021B6C70(u8 *,int),*func_020056A0(unsigned,unsigned,unsigned);
extern u8 func_02012984(void *),func_02011400(unsigned,unsigned);
extern void func_0203F4CC(struct RtcTime *),func_0203D34C(unsigned,unsigned);
void func_021B6100(u8 *p)
{
 struct RtcTime time; unsigned config,lo,mid,hi; u8 i; void *task; unsigned one;
 func_021B63DC(p);
 *(void **)(p+24)=func_020490F4(131,*(u16 *)p);
 func_021B655C(p);func_021B6594(p);func_021B6760(p);
 config=func_02012984(*(void **)(*(u8 **)(p+48)+4));
 lo=func_02011400(config,0);mid=func_02011400(config,2);hi=func_02011400(config,3);
 func_0203F4CC(&time);
 if(time.hour>=lo && time.hour<mid) *(unsigned *)(p+16)=0;
 else if(time.hour>=mid && time.hour<hi) *(unsigned *)(p+16)=1;
 else *(unsigned *)(p+16)=2;
 for(i=0;i<*(int *)(p+8);i++) *(void **)(p+28+i*4)=func_021B6C70(p,i);
 task=func_020056A0((unsigned)func_021B63B0,(unsigned)p,8);
 one=1;*(u8 *)(p+13)=one;*(int *)(p+52)=one;
 *(void **)(p+4)=task;*(u8 *)(p+137)=0;
 *(u8 *)(p+14)=0;*(int *)(p+20)=0;*(int *)(p+44)=0;*(u8 *)(p+12)=0;
 func_0203D34C(0,*(u16 *)p);
}
