/*
 * function: func_021BAE00
 * address: 0x021BAE00
 * packet: pkt_ov217_021BAE00
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_021BBAD0 0x021BBAD0 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BBD68 0x021BBD68 thumb ov217
 *   func_021BC128 0x021BC128 thumb ov217
 *   func_021BC6F4 0x021BC6F4 thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BC6EC 0x021BC6EC thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021BC428 0x021BC428 thumb ov217
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_02035C08(const void *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);
extern void func_020061E4(u32);
extern void *func_021C09B8(void *);
extern u32 func_021BC6D0(void *);
extern void func_021BBAD0(u32);
extern void func_021BB934(u8 *,u32);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *,u32);
extern void func_021BBD68(u8 *);
extern u32 func_021BC128(u32);
extern u32 func_021BC6F4(u32 a0, u32 a1);
extern u32 func_021BBAA4(u32,u8);
extern void func_021BC6EC(void *,u8);
extern void func_021BC580(char *,int);
extern int func_021BC06C(char *);
extern int func_021BC428(void *);
/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void func_021BAE00(u8 *p)
{
    u32 keys=func_020362DC();
    int sel=func_02035C08(p+0x64);
    int flag;
    u32 a,b;
    flag=func_02035C08(func_021C09B8(*(void **)p));
    TOUCHPANEL_GetPointCont(&a,&b);
    if(func_021BC6D0(p)!=0 || flag==0) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,1);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if(keys&2) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,0);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(func_021BC6F4((u32)p,(u8)sel)==1) {
                func_021BBAA4((u32)p,sel);
                func_021BC6EC(p,p[0x32]);
                func_020061E4(0x54c);
                func_021BC580((char *)p,2);
                func_021BC06C((char *)p);
                func_021BC128((u32)p);
                func_021BB91C(p);
                func_021BB910(p,7);
                return;
            }
        }
    } else {
        if(TOUCHPANEL_HitCont(p+0x90)==0 || func_02035C08(p+0x90)==0) {
            if(func_021BC428(p)==1) {
                func_021BB91C(p);
                func_021BB910(p,4);
                func_021BB910(p,1);
            }
        }
    }
}
