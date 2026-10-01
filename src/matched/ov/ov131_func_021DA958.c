/*
 * function: func_021DA958
 * address: 0x021DA958
 * packet: pkt_ov131_021DA958
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA996.
 * symbols:
 *   func_021DA998 0x021DA998 thumb ov131
 *   func_021DABCC 0x021DABCC thumb ov131
 *   func_021DAEE4 0x021DAEE4 thumb ov131
 *   func_021DB140 0x021DB140 thumb ov131
 *   func_02035C38 0x02035C38 arm
 */
typedef unsigned char u8;
extern int func_021DA998(u8 *,u8 *);
extern void func_021DABCC(u8 *,u8 *);
extern int func_021DAEE4(u8 *,u8 *);
extern void func_021DB140(u8 *,u8 *);
extern int func_02035C38(void);
void func_021DA958(u8 *a,u8 *b) {
    if ((*(u8 **)(a+8))[13] != 2) {
        if (func_021DA998(a,b)==0) func_021DABCC(a,b);
    } else {
        if (func_021DAEE4(a,b)==0) func_021DB140(a,b);
    }
    if (func_02035C38()==0) *(int *)(b+28)=0;
}
