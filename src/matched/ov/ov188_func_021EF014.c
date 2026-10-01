/*
 * function: func_021EF014
 * address: 0x021EF014
 * packet: pkt_ov188_021EF014
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008494 0x02008494 thumb
 *   func_021EF0F4 0x021EF0F4 thumb ov188
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02008494(void *, void *);
extern void func_021EF0F4(u8 *, u8 *);
void func_021EF014(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        if (*(void **)(a+0x48+i*4)) {
            func_021EF0F4(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            *(u16 *)(p+0x16C8) = 2;
        } else if (*(void **)(a+0x34+i*4)) {
            func_02008494(*(void **)(a+0x34+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            *(u16 *)(p+0x16C8) = 1;
        } else {
            p = b+i*0x44;
            *(u16 *)(p+0x16C8) = 0;
        }
        *(u16 *)(p+0x16CA) = a[0x44+i];
    }
}
