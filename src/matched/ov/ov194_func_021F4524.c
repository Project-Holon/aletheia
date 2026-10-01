/*
 * function: func_021F4524
 * address: 0x021F4524
 * packet: pkt_ov194_021F4524
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045874 0x02045874 arm
 *   func_021F2328 0x021F2328 thumb ov194
 *   func_0204589C 0x0204589C arm
 *   func_021F253C 0x021F253C thumb ov194
 *   func_02045838 0x02045838 arm
 *   func_02045808 0x02045808 arm
 *   func_020458F8 0x020458F8 arm
 */
extern int func_02045874(unsigned,unsigned);
extern int func_021F2328(char *,int);
extern int func_0204589C(int,int);
extern int func_021F253C(int);
extern void func_02045838(int,int);
extern void func_02045808(int);
extern int func_020458F8(unsigned);
void func_021F4524(char *p) {
    int text;
    char *obj;
    *(int *)(*(char **)(p+0x2c4)+28)=0;
    text=func_02045874(*(unsigned *)(*(char **)(p+0x2c4)+32),30);
    func_021F2328(p+0x68,*(int *)(*(char **)(p+0x2c4)+32));
    if (func_0204589C(text,*(int *)(*(char **)(p+0x2c4)+32)))
        *(int *)(*(char **)(p+0x2c4)+28)=1;
    if (!func_021F253C((int)(p+0x68))) {
        func_02045838(*(int *)(*(char **)(p+0x2c4)+32),text);
        *(int *)(*(char **)(p+0x2c4)+28)=1;
    }
    func_02045808(text);
    if (!func_020458F8(*(unsigned *)(*(char **)(p+0x2c4)+32))) {
        obj=*(char **)(p+0x2c4);
        if (*(int *)obj!=0 && *(int *)obj!=3) *(int *)(obj+28)=1;
    }
}
