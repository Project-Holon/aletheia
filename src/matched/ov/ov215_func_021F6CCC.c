/*
 * function: func_021F6CCC
 * address: 0x021F6CCC
 * packet: pkt_ov215_021F6CCC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02016028 0x02016028 thumb
 *   func_02015EE8 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   func_02015E4C 0x02015E4C thumb
 *   func_02063000 0x02063000 arm
 *   func_020173B4 0x020173B4 thumb
 *   func_021F6D0C 0x021F6D0C thumb ov215
 */
/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void func_02016028(void *,unsigned);
extern void *func_02015EE8(void *);
struct Obj;
extern void func_02064CBC(struct Obj *x);
extern void func_02015E4C(void *);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern int func_020173B4(void *);
extern int func_021F6D0C(char *);
void func_021F6CCC(char *p,unsigned flag,int enable)
{
    void *obj;
    func_02016028(*(void **)(p+52),flag);
    obj=func_02015EE8(*(void **)(p+52));
    func_02064CBC(obj);
    func_02015E4C(*(void **)(p+52));
    if(enable) {
        func_02063000((int)obj,1,(int)p,(int)func_021F6D0C);
        *(int *)(p+56)=0;
    } else func_020173B4(*(void **)(p+52));
}
