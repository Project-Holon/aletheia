/*
 * function: func_021E214C
 * address: 0x021E214C
 * packet: pkt_ov183_021E214C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E21E0 0x021E21E0 thumb ov183
 */
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern void func_021E21E0(int task, int *state, char *p);
void func_021E214C(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(*(int *)(*(char **)(p+0x20)+4),2,3,0); *state=1; break;
    case 1: if (func_021FE7B0(*(int **)(*(char **)(p+0x20)+4))) *state=2; break;
    case 2: func_021FD73C(task,(int)func_021E21E0); break;
    }
}
