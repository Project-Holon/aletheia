/*
 * function: func_021FE264
 * address: 0x021FE264
 * packet: pkt_ov135_021FE264
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F7B9C 0x021F7B9C thumb ov135
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_0201ADE4(u32,int,u32);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(u8 *p, int event);
extern void func_021FF318(void *,int,int,int,int);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
void func_021FE264(u8 *p,u32 mode)
{
    u32 h,v;
    switch(mode) {
    case 0: *(u32 *)(p+0x28)=4; break;
    case 1:
        if(*(s16 *)(p+0xB56)!=0) {
            h=(u32)func_0201ADE4((u16)*(s16 *)(p+0xB56),0,0x48);
            v=func_0201AE1C((const struct Personal *)h,0x14);
            func_0201AE14((void *)h);
            *(u32 *)(*(u8 **)(p+0xE00)+0x20)=v;
            if(func_021F7B9C(p+0xB56,*(u32 *)(*(u8 **)(p+0xE00)+0x20))) break;
        }
        *(u32 *)(p+0x28)=7;
        break;
    case 2: *(u32 *)(p+0x28)=10; break;
    case 3: *(u32 *)(p+0x28)=13; break;
    case 4:
        if(*(u32 *)(p+0xD0)) {
            *(u32 *)(p+0x28)=32;
            func_0202208C(0,0,0,0,16,1,0x48);
        }
        break;
    case 5: *(u32 *)(p+0x28)=16; break;
    case 6:
        func_021FF318(p,15,1,0,0xF0F);
        func_021F4E98(p,23,26);
        break;
    }
}
