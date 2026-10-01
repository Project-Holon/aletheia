/*
 * function: func_021EEEA4
 * address: 0x021EEEA4
 * packet: pkt_ov170_021EEEA4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_021EF5E8 0x021EF5E8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE408 0x021EE408 thumb ov170
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb ov170
 */
extern unsigned char func_020260E0(void *);
extern unsigned func_02025DE8(void *);
extern int func_021EF5E8(int);
extern void func_020260E4(void *, unsigned char);
extern void func_021EE408(char *, int);
extern unsigned func_0203633C(void);
extern void func_021DD238(char *);
#define WORK(p) (*(char **)((p)+0x2c))
#define OBJ(p) (*(void **)(WORK(p)+0x70))
unsigned func_021EEEA4(char *p)
{
    unsigned char sel=func_020260E0(OBJ(p));
    unsigned r=func_02025DE8(OBJ(p));
    if(func_021EF5E8(*(int *)(WORK(p)+0x74))==0) {
        if(r>=0x22 && r<=0x23) {
            func_020260E4(OBJ(p),sel);
            func_021EE408(p,sel);
            return -1;
        }
        if(r==0x21) {
            func_020260E4(OBJ(p),sel);
            return 0x21;
        }
    } else if(r==0x1e || r==0x21) {
        func_020260E4(OBJ(p),sel);
        func_021EE408(p,sel);
        return -1;
    }
    if(r==-1) {
        if(func_0203633C()&0x200) { func_021DD238(p); return 0x1f; }
        if(func_0203633C()&0x100) { func_021DD238(p); return 0x20; }
    }
    return r;
}
