/*
 * function: func_021B8AD0
 * address: 0x021B8AD0
 * packet: pkt_ov106_021B8AD0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return, before 0x021B8B4C.
 * lever: allocation declared before table keeps allocation in ip and table spilled;
 * table assignments repeat the data source to retain both stores without a reload.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B7F7C 0x021B7F7C thumb ov106
 *   func_02049EB4 0x02049EB4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
extern u32 func_021B7F7C(u8 *,u32);
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern void func_020307B0(void *);
void func_021B8AD0(u8 *p,u8 *a,u16 b) {
    void *data;
    void *allocation;
    int table;
    u16 x,y;
    int i,j;
    func_02082BCC(p,0,384);
    x=func_021B7F7C(a,1);
    y=func_021B7F7C(a,0);
    allocation=func_02049EB4(77,5,0,(u32)&data,b);
    table=(int)data;
    table=(int)data+12;
    for(i=0;i<3;i++) {
        for(j=0;j<32;j++) {
            *(u16 *)(p+i*64+j*2)=*(u16 *)(table+i*64+j*2)+x;
            *(u16 *)(p+i*64+j*2+192)=*(u16 *)(table+i*64+j*2)+y;
        }
    }
    func_020307B0(allocation);
}
