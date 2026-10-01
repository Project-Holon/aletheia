/*
 * function: func_021D9980
 * address: 0x021D9980
 * packet: pkt_ov131_021D9980
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   func_021DBA90 0x021DBA90 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02049EF4(u32,u32,u32,void *,u16);
extern void *func_021DBA90(u16,void *);
void func_021D9980(u8 *a,u8 *p,u32 resource)
{
    *(void **)(p+0x38)=func_02049EF4(resource,72,0,p+0x34,*(u16 *)a);
    *(void **)(p+0x40)=func_02049EF4(resource,73,0,p+0x3c,*(u16 *)a);
    *(void **)(p+0x48)=func_02049EF4(resource,74,0,p+0x44,*(u16 *)a);
    *(void **)(p+0x50)=func_02049EF4(resource,75,0,p+0x4c,*(u16 *)a);
    *(void **)(p+0x58)=func_02049EF4(resource,76,0,p+0x54,*(u16 *)a);
    *(void **)(p+0xa4)=func_021DBA90(*(u16 *)a,*(void **)(a+0x174));
}
