/*
 * function: func_021E02E8
 * address: 0x021E02E8
 * packet: pkt_ov119_021E02E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008FEC 0x02008FEC thumb
 *   func_02008FFC 0x02008FFC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   func_021E017C 0x021E017C thumb ov119
 *   func_021E01E0 0x021E01E0 thumb ov119
 *   func_021E0240 0x021E0240 thumb ov119
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void * func_02012EBC(void *);
extern void *func_02008FEC(void *);
extern void *func_02012F2C(void *);
extern int func_02012FCC(int p0);
extern void *func_02007AF4(void *,u32);
extern void *func_02012F98(void *);
extern u32 func_02008FFC(void),func_02008C20(void),func_02007AEC(void *);
extern void func_02082D44(const void *,void *,u32),func_020307B0(void *),func_021E017C(void *,void *),func_021E01E0(void *,void *),func_021E0240(void *,void *),func_0201AC2C(void *,void *),func_020086F8(void *,void *),func_02007B5C(void *),func_02082BCC(void *,int,u32);
void func_021E02E8(char *p)
{
    void *dest,*src;
    u32 n;
    dest=*(void **)(p+0x60c);
    if(dest) {
        src=*(void **)(p+0x82c);
        func_02012EBC(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    dest=*(void **)(p+0x610);
    if(dest) {
        src=func_02012F2C(*(void **)(p+0x82c));
        n=func_02008C20();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    if(*(void **)(p+0x614)) func_021E017C(*(void **)(p+0x82c),*(void **)(p+0x614));
    if(*(void **)(p+0x618)) func_021E01E0(*(void **)(p+0x82c),*(void **)(p+0x618));
    if(*(void **)(p+0x61c)) func_021E0240(*(void **)(p+0x82c),*(void **)(p+0x61c));
    if(*(void **)(p+0x620)) {
        func_0201AC2C(*(void **)(p+0x620),*(void **)(p+0x838));
        func_020086F8((void *)func_02012FCC((int)(*(void **)(p+0x82c))),p+0x628);
        func_020307B0(*(void **)(p+0x620));
        *(int *)(p+0x620)=0;
    }
    if(*(void **)(p+0x624)) {
        n=func_02007AEC(*(void **)(p+0x624));
        src=func_02007AF4(*(void **)(p+0x828),*(u16 *)(*(char **)(p+8)+0x28));
        func_02082D44(*(void **)(p+0x624),src,n);
        func_020307B0(*(void **)(p+0x624));
    }
    if(*(int *)(p+0x62c)) func_02007B5C(func_02012F98(*(void **)(p+0x82c)));
    func_02082BCC(p+0x60c,0,0x24);
}
