/*
 * function: func_021C0698
 * address: 0x021C0698
 * packet: pkt_ov099_021C0698
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020200CC 0x020200CC thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 */
extern void func_021B9B64(char *);
extern int func_021BA928(char *);
extern int func_020200CC(int);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BA8EC(char *);
extern void func_021C23C8(char *,int);
extern void func_021C23D8(char *,int);
extern void *func_021BA8BC(void *);
extern void func_0202020C(int,int,void *);
extern void func_0201F868(int);
typedef enum { K274=0x274 } Off;
int func_021C0698(char *p,int ret) {
    int r;
    Off o=K274;
    func_021B9B64(p+o);
    if(!func_021BA928(p))return ret;
    r=func_020200CC(*(int *)(p+0xbc));
    switch(r) {
    case -1: return ret;
    case -2:
        func_020061E4(1356);
        *(int *)(p+(o-0xa8))=28;
        break;
    default:
        func_020061E4(1356);
        func_021C18C8(p,2,r);
        *(int *)(p+(o-0xa8))=11;
        func_021BA8EC(p);
        break;
    }
    if(*(int *)(p+0x1cc)==11){func_021C23C8(p,-1);func_021C23D8(p,1);}
    *(void **)(p+0x1a4)=func_021BA8BC(*(void **)(p+0x1a4));
    func_0202020C(*(int *)(p+0xbc),0,p+0x234+2* *(unsigned short *)(p+0x240));
    func_0201F868(*(int *)(p+0xb8));
    return ret;
}
