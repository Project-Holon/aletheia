/*
 * function: func_021DBCA8
 * address: 0x021DBCA8
 * packet: pkt_ov183_021DBCA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 */
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,void *);
extern void func_021DBD7C(void);
void func_021DBCA8(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE784(*(int *)(*(char **)(p+0xd0)+0xc),2,3,0);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+0xc))) *state=2;
        break;
    case 2:
        func_021FD73C(task,func_021DBD7C);
        break;
    }
}
