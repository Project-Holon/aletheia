/*
 * function: func_021F3B18
 * address: 0x021F3B18
 * packet: pkt_ov194_021F3B18
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: eight-byte coordinate pair assignment loads both words before either store.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_020061E4 0x020061E4 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */

typedef unsigned int u32;
typedef struct {int x,y;} Pair;
extern u32 func_020362DC(void);
extern int func_021F2828(char *,int,int *);
extern int func_020355C4(void);
extern int func_021F2818(char *,int,int);
extern void func_020061E4(int);
extern void func_020355D8(unsigned);
extern void func_021F1A1C(char *,int,int *,int,int);
int func_021F3B18(char *p,int *out) {
    int changed=0;
    int rect[4];
    if (*(int *)(p+0x118)==0) {
        if (func_020362DC()&1) {
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1; out[1]=1;
        }
        if (func_020362DC()&4) {
            out[0]=*(int *)(p+0x100)+3;
            if (out[0]>5) out[0]=2;
            func_021F2828(p,out[0],(int *)(p+0xd8));
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1;
        }
        if (changed && func_020355C4()==1) {
            if (func_021F2818(p,(int)(p+0xd8),(int)rect)) {
                func_020061E4(1352); func_020355D8(0);
                func_021F1A1C(p+0x24,1,rect,*(int *)(p+0x104),*(int *)(p+0x100));
                return 0;
            }
        }
    }
    return changed;
}
