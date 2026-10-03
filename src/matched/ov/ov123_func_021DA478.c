/*
 * function: func_021DA478
 * address: 0x021DA478
 * packet: pkt_ov123_021DA478
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 * symbols:
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_021DA45C 0x021DA45C thumb ov123
 *   func_021D9958 0x021D9958 thumb ov123
 *   func_021D92CC 0x021D92CC thumb ov123
 *   func_021DA308 0x021DA308 thumb ov123
 *   func_021DA434 0x021DA434 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov114_id[];
extern int func_02034AC4(int);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u8,u32);
struct Big;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern int func_0200853C(void *);
extern int func_0203CD98(void);
extern u8 *func_021B9800(int,int,int);
extern void func_02156DC4(int,int);
extern void func_021DA45C(char *);
extern char *func_021D9958(int);
extern u8 *func_021D92CC(u32,u32);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_02005D90(int,int);
extern void func_021DA308(char *);
extern void func_021DA434(char *);
extern void func_021DA034(char *,int,int);
int func_021DA478(void *a,int unused,char *q)
{
    char *p;
    func_02034AC4((int)ov114_id);
    p=func_0203159C(a,0x74,*(u16 *)(q+8));
    func_02082BCC(p,0,0x74);
    *(u16 *)p=*(u16 *)(q+8);
    *(void **)(p+0x1c)=func_02012EBC(*(void **)q);
    *(void **)(p+0x20)=*(void **)q;
    *(int *)(p+0x28)=func_0200853C(func_02012944(*(void **)q));
    if(func_0203CD98()) {
        *(void **)(p+8)=func_021B9800(*(u16 *)(q+8),*(int *)(p+0x28),*(int *)(q+4));
        func_02156DC4((int)func_021DA45C,(int)p);
    }
    *(void **)(p+12)=func_021D9958(*(u16 *)p);
    *(void **)(p+16)=func_021D92CC(*(u16 *)p,87);
    func_0202208C(0,1,1,0,6,1,*(u16 *)p);
    func_02005D90(0x483,0xffff);
    switch(*(int *)(q+12)) {
    case 0: func_021DA034(p,(int)func_021DA308,0x276); break;
    case 1: func_021DA034(p,(int)func_021DA434,0x279); break;
    }
    *(int *)(q+16)=0;
    return 1;
}
