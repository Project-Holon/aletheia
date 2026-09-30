/*
 * function: func_021BEADC
 * address: 0x021BEADC
 * packet: pkt_ov110_021BEADC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021BE580 0x021BE580 thumb ov110
 *   func_021BE934 0x021BE934 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BD808(u8 *,void *);
extern u32 func_020362DC(void);
extern void func_020061E4(int);
extern int func_021B9C90(void *,int);
extern void func_021BE580(u8 *,void *);
extern void func_021BE934(u8 *,void *);
void func_021BEADC(u8 *p,void *q) {
    if(func_021BD808(p,q)) {
        if(p[105]==0) {
            if(*(u32 *)(p+112)==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
        } else {
            if(*(u32 *)(p+112)==0) { func_020061E4(1352); return; }
        }
    }
    if(func_021B9C90(*(void **)(p+20),30)) {
        if(*(u32 *)(p+112)==0) func_021BE580(p,q);
        else func_021BE934(p,q);
    }
}
