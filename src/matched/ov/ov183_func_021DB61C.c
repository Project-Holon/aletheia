/*
 * unit: yes
 * function: func_021DB61C, func_021DB690
 * address: 0x021DB61C
 * packet: pkt_ov183_021DB61C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DB690 0x021DB690 thumb ov183
 *   func_021FD744 0x021FD744 thumb ov186
 */
extern void func_021FE794(int,int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021FEE9C(int);
extern void func_021FEE4C(int);
extern void func_021F9BF4(int,int);
extern void func_021FD73C(int *,void *);
extern void func_021DB690(int *);
extern void func_021FD744(int *);
void func_021DB61C(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE794(*(int *)(*(char **)(p+0x1c)+8),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int **)(*(char **)(p+0x1c)+8))) *state=2;
        break;
    case 2:
        func_021FEE9C(*(int *)(*(char **)(p+0x1c)+0x14));
        func_021FEE4C(*(int *)(*(char **)(p+0x1c)+0x14));
        func_021F9BF4(*(int *)(*(char **)(p+0x1c)+0x10),1);
        func_021FD73C(task,func_021DB690);
        break;
    }
}
void func_021DB690(int *task)
{
    func_021FD744(task);
}
