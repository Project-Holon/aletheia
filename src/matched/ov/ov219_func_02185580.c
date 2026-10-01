/*
 * function: func_02185580
 * address: 0x02185580
 * packet: pkt_ov219_02185580
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204767C 0x0204767C arm
 *   func_02185728 0x02185728 thumb ov219
 *   func_02185824 0x02185824 thumb ov219
 *   d_02185E18 0x02185E18 data a2
 */
typedef unsigned short u16;
typedef struct {u16 index,member;} Entry;
extern const Entry d_02185E18[];
extern void *func_02046DB8(unsigned,unsigned),*func_02047400(void *,unsigned,void *),*func_0204767C(unsigned,unsigned *,int);
extern int func_02046FF8(int *);
extern void func_02185728(void *),func_02185824(void *);
void func_02185580(char *p)
{
    unsigned i;
    char *row;
    *(void **)(p+0xC374)=func_02046DB8(197,0);
    func_02046FF8(*(int **)(p+0xC374));
    *(void **)(p+0xC38C)=func_02047400(*(void **)(p+0xC374),0,*(void **)(p+0xC374));
    *(void **)(p+0xC3A4)=func_0204767C(*(unsigned *)(p+0xC38C),0,0);
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        *(void **)(row+0xC378)=func_02046DB8(197,d_02185E18[i].member);
        func_02046FF8(*(int **)(row+0xC378));
        *(void **)(row+0xC390)=func_02047400(*(void **)(row+0xC378),0,*(void **)(row+0xC378));
        *(void **)(row+0xC3A8)=func_0204767C(*(unsigned *)(row+0xC390),0,0);
    }
    func_02185728(p);
    func_02185824(p);
}
