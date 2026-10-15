/*
 * function: WIFIBATTLEMATCH_NET_SetupRegSprite
 * address: 0x021D98E4
 * packet: pkt_ov175_021D98E4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E888C 0x021E888C thumb ov177
 *   func_021E88B0 0x021E88B0 thumb ov177
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } Desc;
extern void MI_CpuFill8(void *, int, u32);
extern u32 func_021E888C(Desc *, int);
extern u32 func_021E88B0(Desc *, int, unsigned char, int, int, int);
void WIFIBATTLEMATCH_NET_SetupRegSprite(u32 *p, int mode) {
    Desc d;
    if (p[12] == 0) {
        MI_CpuFill8(&d, 0, 48);
        d.x0=p[5]; d.x1=p[2]; d.x2=p[4];
        d.a=0; d.b=15; d.c=13; d.d=1;
        switch (mode) {
        case 5: d.pad=1;
        case 0:
            d.x3=52; d.x4=53; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 1:
            d.x3=47; d.x4=48; d.x5=49; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E888C(&d,87); break;
        case 2:
            d.x3=66; d.x4=67; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 3:
            d.x3=75; d.x4=76; d.x5=77; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        case 4:
            d.x3=93; d.x4=94; d.x5=95; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        }
    }
}
