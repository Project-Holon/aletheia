/*
 * function: func_021E03B0
 * address: 0x021E03B0
 * packet: pkt_ov183_021E03B0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   d_020A7370 0x020A7370 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int d_020A7370;
extern int func_021FC20C(char *);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC7C4(char *,void *,void *,u16);
extern void *func_02045EC0(void *,u32);
extern void *func_020457B0(u32,u32);
extern u8 func_02025B64(u32);
extern void func_0201F048(void *,u32,u32);
extern void func_0201F094(void *,u32,u32,u32);
extern void func_0201F250(void *,void *,void *);
extern void func_02045808(void *);
void func_021E03B0(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char **)(q+8));
    second=func_021FC214(*(char **)(q+8));
    switch(mode) {
    case 0:
        if(*(int *)(q+0x18)!=19)func_021FC754(*(char **)(p+0x24),(void *)second,(void *)(*(int *)(q+0x18)+205),(void *)first,0x3da0);
        else func_021FC754(*(char **)(p+0x24),(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(*(u16 *)(q+0x14)!=0xffff)func_021FC754(*(char **)(p+0x2c),(void *)d_020A7370,(void *)(u32)*(u16 *)(q+0x14),(void *)first,0x3da0);
        else func_021FC754(*(char **)(p+0x2c),(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(*(u8 *)(q+0x16)==255 && *(u8 *)(q+0x17)==255) {
            func_021FC754(*(char **)(p+0x34),(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char **)(q+8));
        data=func_02045EC0((void *)second,24);
        text=func_020457B0(128,*(u16 *)(p+0x54));
        if(!func_02025B64(*(u8 *)(q+0x16)))func_0201F048((void *)ws,0,*(u8 *)(q+0x16));
        else func_0201F094((void *)ws,0,*(u8 *)(q+0x16),*(u8 *)(q+0x17));
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(*(char **)(p+0x34),text,(void *)first,0x3da0);
        func_02045808(data);func_02045808(text);
        break;
    }
}
