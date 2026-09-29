/*
 * function: func_0216C7FC
 * address:  0x0216C7FC
 * packet:   pkt_ov010_0216C7FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blockers: func_02012EFC (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EFC  0x02012EFC  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4
 */

extern int func_020120F4(int);
extern int func_02012EFC(void);
extern int func_0200DF40(void);
extern int func_0200DF4C(int);
extern int func_020146F8(int, int, char *, char *, int *);
extern void func_02012374(int, int);
extern char d_021BA650[];
extern char id_00000045[];

int func_0216C7FC(int a, int *st, int *o)
{
    int t;
    switch (*st) {
    case 0:
        o[2] = func_020120F4(o[1]);
        t = func_02012EFC();
        o[3] = func_0200DF40();
        o[4] = func_0200DF4C(t);
        func_02012374(a, func_020146F8(o[1], o[0], id_00000045, d_021BA650, &o[2]));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
