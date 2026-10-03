/*
 * function: func_021BB31C
 * address: 0x021BB31C
 * packet: pkt_ov225_021BB31C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 * symbols:
 *   func_021BB504 0x021BB504 thumb ov225
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_02028178 0x02028178 thumb
 *   func_02028230 0x02028230 thumb
 *   func_021BB53C 0x021BB53C thumb ov225
 */
typedef unsigned char u8;
extern void func_021BB504(char *);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *p);
extern unsigned func_021BA154(char *p);
extern void func_02028178(char *);
extern unsigned func_02028230(char *);
extern int func_021BB53C(char *);
int func_021BB31C(char *p)
{
    int done = 0;
    u8 i;
    if (*(signed char *)(p+0x1c)==0) done=1;
    else if (*(signed char *)(p+0x1c)>0) {
        if (*(signed char *)(p+0x1c)==1) func_021BB504(p);
        --*(signed char *)(p+0x1c);
    }
    if (*(unsigned *)(p+0x18)==0 || *(unsigned *)(p+0x18)==2) {
        func_021B9FBC(*(char **)(*(char **)(p+4)+0x34));
        if (*(unsigned *)(p+0x18)==0) {
            if (func_021BA158(*(char **)(*(char **)(p+4)+0x34))!=-1)
                *(unsigned *)(p+0x18)=2;
        } else {
            int result=func_021BA154(*(char **)(*(char **)(p+4)+0x34));
            if (result!=-1) {
                switch (result) {
                case 1: *(unsigned *)(*(char **)(p)+4)=1; break;
                case 0: *(unsigned *)(*(char **)(p)+4)=0; break;
                }
                *(unsigned *)(p+0x18)=1;
                *(signed char *)(p+0x1c)=1;
            }
        }
    }
    if (*(unsigned *)(p+0x18)==0 || *(unsigned *)(p+0x18)==3) {
        for (i=0;i<2;i++) func_02028178(*(char **)(p+0xc+i*4));
        if (*(unsigned *)(p+0x18)==0) {
            if (func_021BB53C(p)) *(unsigned *)(p+0x18)=3;
        } else {
            if (func_02028230(*(char **)(p+0xc+**(u8 **)p*4))) {
                unsigned value;
                if (**(u8 **)p==0) value=2;
                else if (**(u8 **)p==1) value=3;
                else goto finish;
                *(unsigned *)(*(char **)p+4)=value;
finish:
                *(unsigned *)(p+0x18)=1;
                *(signed char *)(p+0x1c)=1;
            }
        }
    }
    return done;
}
