/*
 * function: func_021DC738
 * address: 0x021DC738
 * packet: pkt_ov175_021DC738
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a1
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 */
extern void func_02034714(const char *,int,const char *);
extern const char d_021E2EF8[];
extern void *func_02012944(void *);
extern void *func_0200853C(void *);
extern void *func_021B9800(unsigned,void *,unsigned);
void func_021DC738(char *p,unsigned heap)
{
    if(*(int *)(p+0x121c)!=0) func_02034714(d_021E2EF8,0,d_021E2EF8);
    *(int *)(p+0x12c)=0;
    *(void **)(p+0x121c)=func_021B9800(heap,func_0200853C(func_02012944(*(void **)(p+8))),*(unsigned *)(p+0x10));
}
