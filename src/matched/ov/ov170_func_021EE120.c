/*
 * function: func_021EE120
 * address: 0x021EE120
 * packet: pkt_ov170_021EE120
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Param {void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12;u32 f14;};
extern void *func_02025538(u32,void *);
extern void *func_02043678(u32,u32,u32,u32);
extern void *func_020255A0(void *,const struct Param *);
extern void func_02025774(void *,u32);
void func_021EE120(char *p)
{
    struct Param s;
    u32 i;
    *(void **)p=func_02025538(76,*(void **)(p+0x9E70));
    *(void **)(p+8)=func_02043678(12,2,32,76);
    s.bmp=*(void **)(p+8);s.x=0;s.y=0;
    s.f8=*(u32 *)(p+0xA120);s.fc=0;
    s.f10=4;s.f11=1;s.f12=65535;s.f14=0;
    *(void **)(p+4)=func_020255A0(*(void **)p,&s);
    func_02025774(*(void **)(p+4),0);
    for (i=7;i<=8;i++) {
        ((void **)(p+4))[i*2+1]=func_02043678(12,2,32,76);
        s.bmp=((void **)(p+4))[i*2+1];s.x=36;s.y=20;s.f11=3;
        ((void **)(p+4))[i*2]=func_020255A0(*(void **)p,&s);
    }
    for (i=0;i<6;i++) {
        ((void **)(p+4))[(i+1)*2+1]=func_02043678(2,1,32,76);
        s.bmp=((void **)(p+4))[(i+1)*2+1];s.x=316;s.y=i*34+2;s.f11=1;
        ((void **)(p+4))[(i+1)*2]=func_020255A0(*(void **)p,&s);
    }
}
