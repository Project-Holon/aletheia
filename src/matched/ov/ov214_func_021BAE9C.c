/*
 * function: func_021BAE9C
 * address: 0x021BAE9C
 * packet: pkt_ov214_021BAE9C
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   site 0x021BB658 data ov214
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_02030CBC(u32,void *);
extern void *func_02021518(u32);
extern void func_02021EE4(void *,int);
extern void func_0202155C(void *,u32,u32,u32);
extern void func_020216D4(void *,u32,u32,u32);
extern const char site[];
void func_021BAE9C(int unused,char *p)
{
    *(void **)(p+732)=func_02030734(*(u16 *)p,func_02030CB0(2),1,site,2403);
    *(void **)(p+728)=func_02030CBC(2,*(void **)(p+732));
    *(void **)(p+736)=func_02021518(*(u16 *)p);
    func_02021EE4(*(void **)(p+736),1);
    func_0202155C(*(void **)(p+736),0,448,*(u16 *)p);
    func_0202155C(*(void **)(p+736),2,448,*(u16 *)p);
    func_020216D4(*(void **)(p+736),0,0,448);
    func_020216D4(*(void **)(p+736),2,0,448);
    *(u32 *)(p+744)=2;
    *(u32 *)(p+740)=0;
}
