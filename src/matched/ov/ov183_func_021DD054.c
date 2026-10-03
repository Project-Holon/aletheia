/*
 * function: func_021DD054
 * address: 0x021DD054
 * packet: pkt_ov183_021DD054
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(int,int);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
void func_021DD054(char *p, char *q)
{
    int i;
    char *slot;
    if(*(int *)(p+0xd8)) {
        if(*(void **)(p+0x28)) { func_021FC734(*(void **)(p+0x28)); *(int *)(p+0x28)=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(*(void **)(slot+0x1c)) { func_021FB494(*(void **)(slot+0x1c)); *(int *)(slot+0x1c)=0; }
        }
        func_020409B4(4);
        func_021FC0C8(*(int *)(q+0x10),6);
        func_021FBDA4(*(int *)(q+0x10),5);
        *(int *)(p+0xd8)=0;
    }
}
