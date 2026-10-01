/*
 * function: func_021E2D70
 * address: 0x021E2D70
 * packet: pkt_ov119_021E2D70
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02011510 0x02011510 thumb
 *   func_020115EC 0x020115EC thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02011510(u32,u32,u32,u32);
extern void func_020115EC(void *,int);
void func_021E2D70(char *p,unsigned mode)
{
    switch(mode) {
    case 0:
        *(void **)(p+0x90)=func_02011510(*(u16 *)(p+0xba),0x67,0x38,10);
        *(void **)(p+0x94)=func_02011510(*(u16 *)(p+0xba),0x67,0x39,10);
        *(void **)(p+0x98)=func_02011510(*(u16 *)(p+0xba),0x67,0x36,10);
        *(void **)(p+0x9c)=func_02011510(*(u16 *)(p+0xba),0x67,0x37,10);
        break;
    case 1:
        *(void **)(p+0x90)=func_02011510(*(u16 *)(p+0xba),0x67,0x3f,10);
        *(void **)(p+0x94)=func_02011510(*(u16 *)(p+0xba),0x67,0x3e,10);
        *(void **)(p+0x98)=func_02011510(*(u16 *)(p+0xba),0x67,0x36,10);
        break;
    case 2:
        *(void **)(p+0x90)=func_02011510(*(u16 *)(p+0xba),0x67,0x3d,10);
        *(void **)(p+0x94)=func_02011510(*(u16 *)(p+0xba),0x67,0x3c,10);
        break;
    case 3:
        *(void **)(p+0x90)=func_02011510(*(u16 *)(p+0xba),0x67,0x3b,10);
        *(void **)(p+0x94)=func_02011510(*(u16 *)(p+0xba),0x67,0x3a,10);
        *(void **)(p+0x9c)=func_02011510(*(u16 *)(p+0xba),0x67,0x37,10);
        func_020115EC(*(void **)(p+0x9c),0x2b5000);
        break;
    }
}
