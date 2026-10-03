/*
 * function: func_0217E178,func_0217E1B8
 * unit: yes
 * address: 0x0217E178
 * packet: pkt_ov176_0217E178
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CDBC 0x0203CDBC arm
 */
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
int func_0217E178(int *p)
{
    switch (*p) {
    case 0:
        if (func_0203CD98()) {
            func_0203CEAC(0);
            *p = 1;
        } else {
            *p = 2;
        }
        break;
    case 1:
        if (func_0203CDBC())
            *p = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}
int func_0217E1B8(int *p) { *p = 0; return 1; }
