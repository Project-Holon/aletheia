/*
 * function: func_0217BB58, func_0217BBD4
 * unit: yes
 * address: 0x0217BB58
 * packet: pkt_ov176_0217BB58
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217BBDC 0x0217BBDC thumb ov176
 *   func_0217CC78 0x0217CC78 thumb ov176
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_0217CAE0 0x0217CAE0 thumb ov176
 *   func_0200B078 0x0200B078 thumb
 *   func_02034714 0x02034714 arm
 *   d_0217E618 0x0217E618 data a4
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
extern void func_021E8AA0(int *p, int v);
extern void func_0217BBDC(void),func_0217CC78(void),func_0217C2EC(void),func_0217CAE0(void);
extern int func_0200B078(int,int);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E618[];
void func_0217BB58(int p,int *state,char *q)
{
    switch(*(unsigned *)(q+0x1A0)) {
    case 0: func_021E8AA0((int *)p,(int)func_0217BBDC); break;
    case 1:
        if(func_0200B078(*(int *)(q+0x38),10)==3) func_021E8AA0((int *)p,(int)func_0217CC78);
        else func_021E8AA0((int *)p,(int)func_0217C2EC);
        break;
    case 2: func_021E8AA0((int *)p,(int)func_0217CAE0); break;
    case 3: func_021E8AA0((int *)p,(int)func_0217CC78); break;
    default: func_02034714(d_0217E618,0,d_0217E618); break;
    }
}
extern void func_021E8AA8(int);
void func_0217BBD4(int p) {func_021E8AA8(p);}
