/*
 * function: func_021F3C40
 * address: 0x021F3C40
 * packet: pkt_ov194_021F3C40
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_021F3364 0x021F3364 thumb ov194
 *   func_020061E4 0x020061E4 thumb
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
extern unsigned func_021F2614(char *,int *,unsigned short *);
extern int func_021F3364(char *,int);
extern void func_020061E4(int);
extern int func_021F2818(char *,int,int);
extern void func_021F1A1C(char *,int,int *,int,int);
void func_021F3C40(char *p,int *input) {
    unsigned code;
    int rect[4];
    if (input[1]) code=func_021F2614(p,(int *)(p+0xd8),(unsigned short *)(p+0xfc));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
        if (func_021F3364(p,code-2)) {
            func_020061E4(1611);
            *(int *)(p+0xe4)=2; *(int *)(p+0xe8)=6;
        }
        break;
    }
    if (func_021F2818(p,(int)(input+2),(int)rect))
        func_021F1A1C(p+0x24,2,rect,*(int *)(p+0x104),*(int *)(p+0x100));
}
