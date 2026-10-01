/*
 * function: func_021BC560
 * address: 0x021BC560
 * packet: pkt_ov208_021BC560
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   d_021C8D98 0x021C8D98 data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {void *task,*memory,*slots;u16 mask,pad;u32 mode;} PalFade;
extern const char d_021C8D98[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_02030CB0(u32);
extern void *func_02030CBC(u32,void *);
extern void *func_02021518(u32);
extern void func_02021EE4(void *,u32);
extern void func_0202155C(void *,u32,u32,u32);
PalFade *func_021BC560(u32 heap,u16 mask)
{
    PalFade *p=func_02030734(heap,20,1,d_021C8D98,0x1e5);
    p->memory=func_02030734(heap,func_02030CB0(2),1,d_021C8D98,0x1e8);
    p->task=func_02030CBC(2,p->memory);
    p->slots=func_02021518(heap);
    func_02021EE4(p->slots,1);
    p->mask=mask;
    if(p->mask&1)func_0202155C(p->slots,0,0x1a0,heap);
    if(p->mask&4)func_0202155C(p->slots,2,0x100,heap);
    if(p->mask&2)func_0202155C(p->slots,1,0x1a0,heap);
    if(p->mask&8)func_0202155C(p->slots,3,0x1c0,heap);
    p->mode=0;
    return p;
}
