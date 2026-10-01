/*
 * function: func_021B99E4
 * address: 0x021B99E4
 * packet: pkt_ov205_021B99E4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Fourth parameter u16 restores the entry spill and delayed reload;
 *   unsigned moved the spill to +0010 and reloaded it before stack args.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 */
typedef unsigned short u16;
extern void *func_020457B0(unsigned,unsigned);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,unsigned);
extern void func_02045CAC(void *,unsigned,void *);
extern void func_0201F02C(void *,unsigned,void *);
extern void func_0201F250(void *,void *,void *);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,unsigned,unsigned,void *,void *,unsigned,void *,unsigned,u16,u16);
extern void func_02045808(void *);
extern void func_0201F73C(void *,int,int,int);
void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind)
{
    void *buffer;
    buffer=func_020457B0(1024,*(u16 *)p);
    func_02043B5C(func_02045770(*(void **)(p+28)),15);
    func_02045CAC(*(void **)(p+20),entry,buffer);
    func_0201F02C(*(void **)(p+24),0,*(void **)(p+8));
    func_0201F250(*(void **)(p+24),*(void **)(p+12),buffer);
    *(void **)(p+32)=func_0201CCE4(*(void **)(p+28),index,kind,*(void **)(p+12),*(void **)(p+16),func_02012FFC(),*(void **)(p+36),0,*(u16 *)p,3855);
    func_02045808(buffer);
    func_0201F73C(*(void **)(p+28),2,1,12);
}
