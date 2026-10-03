/*
 * function: func_021C0A94
 * address: 0x021C0A94
 * packet: pkt_ov099_021C0A94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 */
extern int func_021BA928(char *,int);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BAAB8(char *,int,int);
extern void func_021BA8EC(char *);
extern void func_021BC090(char *);
int func_021C0A94(char *p,int ret) {
    int r;
    if(!func_021BA928(p,ret))return ret;
    r=func_021BA858(p);
    if(r==-1)return ret;
    if(r==0){
        func_021BAAB8(p,74,0);
        *(int *)(p+0x1cc)=21;
    }else {
        func_021BA8EC(p);
        func_021BAAB8(p,14,0);
        func_021BC090(p);
        *(int *)(p+0x1cc)=136;
    }
    return ret;
}
