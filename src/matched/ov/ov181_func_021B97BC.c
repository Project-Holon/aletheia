/*
 * function: func_021B97BC
 * address: 0x021B97BC
 * packet: pkt_ov181_021B97BC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9CC8 0x021B9CC8 thumb ov181
 *   func_021BA5E8 0x021BA5E8 thumb ov181
 *   func_021BA6F0 0x021BA6F0 thumb ov181
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021BA2AC 0x021BA2AC thumb ov181
 *   func_021BA390 0x021BA390 thumb ov181
 *   d_021BABD0 0x021BABD0 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
typedef int (*Command)(char *,char *);
extern const Command d_021BABD0[];
extern void func_021B9CC8(char *);
extern int func_021BA5E8(char *),func_021BA6F0(char *);
extern int func_02005F38(void);
extern void func_02005E30(u32);
extern int func_021BA2AC(char *,int);
extern void func_021BA390(char *);
int func_021B97BC(char *p) {
    char *row;
    if(*(u32 *)(p+0x2ec)==0) {
        for(;;) {
            row=*(char **)(p+0x2d4)+*(u16 *)(p+0x2d8)*16;
            if(*(u16 *)(p+0x2d8)==*(u32 *)((u32)p+*(u8 *)(p+0x2bb)*8+0xbc)) {
                func_021B9CC8(p);
                (*(u8 *)(p+0x2bb))++;
                *(u16 *)(p+0x2da)=*(u16 *)(row+4);
                *(u32 *)(p+0x2ec)=1;
                *(u16 *)(p+0x2d8)+=2;
                break;
            }
            if(d_021BABD0[*(u8 *)(row+6)](p,row)==1) {
                (*(u16 *)(p+0x2d8))++;
                break;
            }
            (*(u16 *)(p+0x2d8))++;
        }
    }
    switch(*(u32 *)(p+0x2ec)) {
    case 1:
        if(*(s16 *)(p+0x2da)<=0) {
            *(s16 *)(p+0x2da)=0; *(u32 *)(p+0x2ec)=0;
        } else if(*(u8 *)(p+0x2d2)==1) *(s16 *)(p+0x2da)-=4;
        else (*(s16 *)(p+0x2da))--;
        break;
    case 2: if(func_021BA5E8(p)==0) *(u32 *)(p+0x2ec)=0; break;
    case 3: if(func_021BA6F0(p)==0) *(u32 *)(p+0x2ec)=0; break;
    case 5:
        if(func_02005F38()==1) func_02005E30(64);
        return func_021BA2AC(p,2);
    }
    func_021BA390(p);
    return 4;
}
