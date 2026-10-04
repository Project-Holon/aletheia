/*
 * function: func_021C04D0
 * address: 0x021C04D0
 * packet: pkt_ov099_021C04D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021B9B64(char *);
extern void func_021C23C8(void *a, void *b);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C23D8(char *,int);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
typedef enum { K274=0x274 } Off;
int func_021C04D0(char *p,int ret) {
    int r;
    Off o;
    r=func_021BA858(p);
    o=K274;
    func_021B9B64(p+o);
    if(r==-1)return ret;
    if(r==0){
        func_021C23C8(p,(void *)(-1));
        func_021C18C8(p,2,5);
        func_021C23D8(p,1);
        *(int *)(p+(o-0xa8))=158;
    } else {
        func_021C2408(p);
        func_021BA8EC(p);
        *(int *)(p+(o-0xa8))=11;
    }
    return ret;
}
